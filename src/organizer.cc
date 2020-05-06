//
// Created by hrishi on 4/30/20.
//

#include <mylibrary/organizer.h>
#include <mylibrary/response.h>

#include <fstream>
#include <iostream>

namespace mylibrary {
// Use every 6 lines of the trainingresponses file to create response
std::vector<std::vector<std::string>> Organizer::CreateRawResponse(
    const std::string &file) {
  // Create a brand new file stream
  std::ifstream file_stream;
  file_stream.open(file);
  std::vector<std::vector<std::string>> training_responses;

  if (file_stream.is_open()) {
    int line_counter = 0;
    std::string line;
    std::vector<std::string> response_as_string;

    // Takes in each line from trainingimages file
    while(getline(file_stream, line)) {
      response_as_string.push_back(line);
      line_counter++;

      if (line_counter == kResponseLength) {
        training_responses.push_back(response_as_string);
        response_as_string.clear(); // Reset the image
        line_counter = 0;
      }
    }
    file_stream.close();
  } else {
    std::cerr << "Your file couldn't be opened or doesn't exist." << std::endl;
  }

  return training_responses;
}

// Returns a vector<int> corresponding to the region they are from
std::vector<int> Organizer::CreateAnswer(const std::string &file) {
  // Create a brand new file stream
  std::ifstream file_stream;
  file_stream.open(file);
  std::vector<int> training_answer;

  if (file_stream.is_open()) {
    std::string line;
    // Takes in each line from traininganswers file
    while(getline(file_stream, line)) {
      training_answer.push_back(std::stoi(line));
    }
    file_stream.close();
  } else {
    std::cerr << "Your file couldn't be opened or doesn't exist." << std::endl;
  }

  // Initializes the amount of each answer
  for (int a : training_answer) {
    double amount = Organizer::answer_amount[a] + 1;
    Organizer::answer_amount[a] = amount;
  }
  Organizer::answer_amount[0] = 0;

  // Return geographical regions as a vector of ints
  return training_answer;
}

// Combines string responses and their corresponding answer (region) to form
// a vector of true responses
std::vector<Response> Organizer::CreateRealResponse(const std::vector<std::vector<std::string>>
                                          &training_responses, std::vector<int> training_answers) {
  std::vector<Response> responses;
  std::vector<std::vector<char>> raw_responses;
  int counter = 0;

  for (const std::vector<std::string> &response_as_string : training_responses) {
    try {
      Response new_response = Response(response_as_string, training_answers.at(counter));
      responses.push_back(new_response);
      raw_responses.push_back(new_response.choices);
      counter++;
    }
    catch (const std::out_of_range &exception){
      std::cout << "Out of range exception: " << exception.what() << std::endl;
    }
  }

  // Stores complete responses with answers as well as without for ML model
  raw_char_responses = raw_responses;
  real_responses = responses;
  return responses;
}

double Organizer::AnswerOccurProbability(const int &answer) {
  double total_answers = 0;
  for (double i : Organizer::answer_amount) {
    total_answers += i;
  }

  return (Organizer::answer_amount[answer] / total_answers);
}

double Organizer::NumberOfAnswers(int question, int answer, char selection) {
  double num_of_answers = 0.0;

  for (auto & response : real_responses) {
    if (response.answer == answer && response.choices.at(question) == selection) {
      num_of_answers++;
    }
  }

  return num_of_answers;
}

void Organizer::FillProbsArray() {
  for (int question = 0; question < mylibrary::kResponseLength; question++) {
    for (int answer = 1; answer <= kNumAnswers; answer++) {
      double numerator1 = kLapalce + Organizer::NumberOfAnswers(question, answer, 'a');
      double numerator2 = kLapalce + Organizer::NumberOfAnswers(question, answer, 'b');
      double numerator3 = kLapalce + Organizer::NumberOfAnswers(question, answer, 'c');
      double denominator = (2.0*kLapalce) + Organizer::answer_amount[answer];
      probs_[question][answer][0] = numerator1 / denominator;
      probs_[question][answer][1] = numerator2 / denominator;
      probs_[question][answer][2] = numerator3 / denominator;
    }
  }

  // Fills out the answer_occur_probs array
  for (int i = 1; i <= kNumAnswers; i++) {
    Organizer::answer_occur_probs.push_back(Organizer::AnswerOccurProbability(i));
  }
}

double Organizer::CalculateProb(const Response &response, const int &answer) {
  double probability = 0.0;
  for (int question = 0; question < mylibrary::kResponseLength; question++) {
    char selection = response.choices.at(question);
    if (selection == 'a') {
      probability += log(probs_[question][answer][0]);
    } else if (selection == 'b') {
      probability += log(probs_[question][answer][1]);
    } else {
      probability += log(probs_[question][answer][2]);
    }
  }
  return probability + log(answer_occur_probs.at(answer - 1)); //TODO plus one cuz of stuff
}

int Organizer::PredictUserAnswer(const Response &response) {
  int answer = 0;
  double max_prob = -999.9;
  for (int a = 1; a <= kNumAnswers; a++) {
    double probability = Organizer::CalculateProb(response, a);
    if (probability >= max_prob) {
      max_prob = probability;
      answer = a;
    }
  }
  return answer;
}

}  // namespace mylibrary