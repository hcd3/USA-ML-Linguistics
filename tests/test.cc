// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>

#include <mylibrary/organizer.h>
#include <mylibrary/response.h>


/**
 * Testing Strategy
 *
 * Unit test the non-GUI portions of the program
 */

/**
 * Methods in the Organizer class-----------------------------------------------
 */
TEST_CASE("Test CreateRawResponse", "[create-raw-response]") {
  // No training response file
  mylibrary::Organizer data_organizer = mylibrary::Organizer();
  REQUIRE(data_organizer.CreateRawResponse("fakefile").empty());

  // Training response file exists
  std::vector<std::vector<std::string>> training_responses;
  training_responses = data_organizer.CreateRawResponse(
      "/home/hrishi/Cinder/my-projects/final-project-hcd3/data/trainingresponses");
  std::vector<std::string> first_response;
  first_response.emplace_back("b");
  first_response.emplace_back("a");
  first_response.emplace_back("b");
  first_response.emplace_back("a");
  first_response.emplace_back("b");
  first_response.emplace_back("a");
  REQUIRE(training_responses.at(1) == first_response);
}

TEST_CASE("Test CreateAnswer", "[create-answer]") {
  // No training answer file
  mylibrary::Organizer data_organizer = mylibrary::Organizer();
  REQUIRE(data_organizer.CreateAnswer("nofile").empty());

  // Training answer file exists
  std::vector<int> training_answers;
  training_answers = data_organizer.CreateAnswer(
      "/home/hrishi/Cinder/my-projects/final-project-hcd3/data/traininganswers");
  REQUIRE(training_answers.at(243) == 3);
}

TEST_CASE("Test CreateRealResponse", "[create-real-response]") {
  mylibrary::Organizer data_organizer = mylibrary::Organizer();
  std::vector<std::vector<std::string>> training_responses;
  training_responses = data_organizer.CreateRawResponse(
      "/home/hrishi/Cinder/my-projects/final-project-hcd3/data/trainingresponses");
  std::vector<int> training_answers;
  training_answers = data_organizer.CreateAnswer(
      "/home/hrishi/Cinder/my-projects/final-project-hcd3/data/traininganswers");
  std::vector<mylibrary::Response> responses;
  responses = data_organizer.CreateRealResponse(training_responses, training_answers);
  REQUIRE(responses.at(399).answer == 4);
}

/**
 * Constructor and instance fields for Response class --------------------------
 */
TEST_CASE("Response class", "[response-class]") {
  // Test empty response
  std::vector<std::string> string_vector;
  mylibrary::Response response1 = mylibrary::Response(string_vector, 3);
  REQUIRE(response1.answer == 3);
  REQUIRE(response1.choices.empty());

  // Test responses stored in a vector
  mylibrary::Organizer data_organizer = mylibrary::Organizer();
  std::vector<std::vector<std::string>> training_responses;
  training_responses = data_organizer.CreateRawResponse(
      "/home/hrishi/Cinder/my-projects/final-project-hcd3/data/trainingresponses");
  std::vector<int> training_answers;
  training_answers = data_organizer.CreateAnswer(
      "/home/hrishi/Cinder/my-projects/final-project-hcd3/data/traininganswers");
  std::vector<mylibrary::Response> responses;
  responses = data_organizer.CreateRealResponse(training_responses, training_answers);
  std::vector<char> first_response;
  first_response.push_back('b');
  first_response.push_back('a');
  first_response.push_back('b');
  first_response.push_back('a');
  first_response.push_back('b');
  first_response.push_back('a');
  REQUIRE(responses.at(0).choices == first_response);
  REQUIRE(responses.at(0).answer == 1);
}
