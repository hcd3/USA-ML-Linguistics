//
// Created by hrishi on 4/28/20.
//

#include <mylibrary/response.h>

namespace mylibrary {
Response::Response(const std::vector<std::string> &response_as_string, const int answer) {
  Response::answer = answer;
  for (const std::string &choice : response_as_string) {
    // Converting each choice to char for easier comparisons later
    choices.push_back(choice[0]);
  }
}

}  // namespace mylibrary