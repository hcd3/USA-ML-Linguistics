//
// Created by hrishi on 4/28/20.
//

#ifndef FINALPROJECT_RESPONSE_H
#define FINALPROJECT_RESPONSE_H

#include <vector>
#include <string>

namespace mylibrary {
constexpr size_t kResponseLength = 6;  // Number of questions asked
const char kChoiceA = 'a';
const char kChoiceB = 'b';
const char kChoiceC = 'c';
const std::string kNoChoice = "z";

class Response {
 public:
  Response(const std::vector<std::string> &response_as_string, int answer);
  // Convert response to a vector of characters indicating each choice
  std::vector<char> choices;
  // The region each response corresponds to
  int answer;
};


}  // namespace mylibrary

#endif  // FINALPROJECT_RESPONSE_H
