//
// Created by hrishi on 4/30/20.
//

#ifndef FINALPROJECT_ORGANIZER_H
#define FINALPROJECT_ORGANIZER_H

#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

#include "response.h"

namespace mylibrary {
/**
 * Represents the class that sorts data from external files into objects
 * that can be utilized by the multiclass classifier.
 */
// 0-4 inclusive.
constexpr size_t kNumAnswers = 4;
// Selection A, B, or C
constexpr size_t kNumSelections = 3;
// Laplace smoothing value 'k'
const double kLapalce = 1.0;

class Organizer {
 public:
  // Returns a 2D vector representing the responses in trainingresponses
  std::vector<std::vector<std::string>> CreateRawResponse(const std::string &file);
  // Returns a vector of all the answers in traininganswers
  std::vector<int> CreateAnswer(const std::string &file);
  // Returns a vector of Response objects
  std::vector<Response> CreateRealResponse(const std::vector<std::vector<std::string>>
                                     &training_responses, std::vector<int> training_answers);
  // Returns the probability of each answer
  double AnswerOccurProbability(const int &answer);
  // Returns the amount of that each selection occurs based on the question and answer(region)
  double NumberOfAnswers(int question, int answer, char selection);
  // Fill up the probs_ arrary with the probabilities from the training
  void FillProbsArray();
  // Returns the probability of the response being that answer(region)
  double CalculateProb(const Response &response, const int &answer);
  // Returns the answer(region) that the user response most likely is
  int PredictUserAnswer(const Response &response);

  // All of the responses in the external files
  std::vector<Response> real_responses;
  // The raw responses in char form
  std::vector<std::vector<char>> raw_char_responses;
  // The amount of each answer
  double answer_amount [kNumAnswers + 1];
  // The probabilities we get from the training
  double probs_[mylibrary::kResponseLength][kNumAnswers + 1][kNumSelections];
  // The probability of each answer occurring
  std::vector<double> answer_occur_probs;

};

}  // namespace mylibrary

#endif  // FINALPROJECT_ORGANIZER_H
