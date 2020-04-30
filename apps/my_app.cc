// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
#include <dlib/svm.h>
#include <dlib/any.h>
#include <dlib/svm_threaded.h>
#include <mylibrary/response.h>
#include <mylibrary/organizer.h>


namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() { }

void MyApp::setup() {
  dlib::camera_transform();
  // Store all the training data in a logical manner
  mylibrary::Organizer data_organizer = mylibrary::Organizer();
  std::vector<std::vector<std::string>> training_responses;
  training_responses = data_organizer.CreateRawResponse(
      "/home/hrishi/Cinder/my-projects/final-project-hcd3/data/trainingresponses");
  std::vector<int> training_answers;
  training_answers = data_organizer.CreateAnswer(
      "/home/hrishi/Cinder/my-projects/final-project-hcd3/data/traininganswers");
  std::vector<mylibrary::Response> responses;
  responses = data_organizer.CreateRealResponse(training_responses, training_answers);

  for (mylibrary::Response r : responses) {
    std::cout << r.choices[0] << " : " << r.answer << std::endl;
  }
}

void MyApp::update() { }

void MyApp::draw() { }

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
