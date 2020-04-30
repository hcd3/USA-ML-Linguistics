//
// Created by hrishi on 4/30/20.
//

#ifndef FINALPROJECT_ORGANIZER_H
#define FINALPROJECT_ORGANIZER_H

#include <cstdlib>
#include <vector>
#include <string>

#include "response.h"

namespace mylibrary {
/**
 * Represents the class that sorts data from external files into objects
 * that can be utilized by the multiclass classifier.
 */
class Organizer {
 public:
  // Returns a 2D vector representing the responses in trainingresponses
  std::vector<std::vector<std::string>> CreateRawResponse(const std::string &file);
  // Returns a vector of all the answers in traininganswers
  std::vector<int> CreateAnswer(const std::string &file);
  // Returns a vector of Image objects
  std::vector<Response> CreateRealResponse(const std::vector<std::vector<std::string>>
                                     &training_responses, std::vector<int> training_answers);

  // All of the responses in the external files
  std::vector<Response> real_responses;
};

}  // namespace mylibrary

#endif  // FINALPROJECT_ORGANIZER_H
