// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/app/App.h>
//#include <dlib/svm.h>
#include <dlib/any.h>
#include <dlib/svm_threaded.h>
#include <mylibrary/response.h>
#include <mylibrary/organizer.h>

#include <iostream>
#include <vector>

typedef dlib::matrix<char, 2, 1> my_type;

namespace myapp {

using cinder::app::KeyEvent;

const char kNormalFont[] = "Arial Unicode MS";

MyApp::MyApp() { }

void MyApp::setup() {
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

  // Machine Learning algorithms
  typedef dlib::one_vs_one_trainer<dlib::any_trainer<my_type>, int> ovo_trainer;
  ovo_trainer trainer;

  // Binary classification trainer objects
  // Use kernel ridge regression and support vector machine
  typedef dlib::polynomial_kernel<my_type> poly_kernel;
  typedef dlib::radial_basis_kernel<my_type> rbf_kernel;

  dlib::svm_nu_trainer<poly_kernel> poly_trainer;
  dlib::krr_trainer<rbf_kernel> rbf_trainer;
  poly_trainer.set_kernel(poly_kernel('a', 1, 2));
  rbf_trainer.set_kernel(rbf_kernel('a'));

  // Calibrates each trainer to use the kernel objects above
  /*trainer.set_trainer(rbf_trainer);
  trainer.set_trainer(poly_trainer, 1, 2);

  dlib::randomize_samples(data_organizer.raw_char_responses, training_answers);
  std::cout << "Result: \n" << cross_validate_multiclass_trainer(trainer,
      data_organizer.raw_char_responses, training_answers, 5) << std::endl;*/
}

void MyApp::update() { }

void MyApp::draw() {
  DrawBackground();
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const cinder::Color color = cinder::Color::black();

  size_t row = 0;
  if (page_number_ == 0) {
    PrintText("Game Over :(", color, size, {center.x, center.y - 200});
  } else if (page_number_ == 1) {
    std::cout << " Page 1" << std::endl;
  } else if (page_number_ == 2) {
    std::cout << " Page 2" << std::endl;
  } else if (page_number_ == 3) {
    std::cout << " Page 3" << std::endl;
  } else if (page_number_ == 4) {
    std::cout << " Page 4" << std::endl;
  } else if (page_number_ == 5) {
    std::cout << " Page 5" << std::endl;
  } else if (page_number_ == 6) {
    std::cout << " Page 6" << std::endl;
  } else {
    std::cout << " Page 7" << std::endl;
  }
}

void MyApp::PrintText(const std::string& text, const cinder::Color& color,
    const cinder::ivec2& size, const cinder::vec2& loc) {
  cinder::gl::color(color);

  auto box = cinder::TextBox()
      .alignment(cinder::TextBox::CENTER)
      .font(cinder::Font(kNormalFont, 30))
      .size(size)
      .color(color)
      .backgroundColor(cinder::ColorA(0, 0, 0, 0))
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void MyApp::DrawBackground() const {
  cinder::gl::clear(cinder::Color(0.313, 0.859, 0.391));
}

void MyApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    // Allows the user to toggle between pages
    case KeyEvent::KEY_LEFT:
    case KeyEvent::KEY_p: {
      if (page_number_ != 0) {
        page_number_--;
      }
      break;
    }

    case KeyEvent::KEY_RIGHT:
    case KeyEvent::KEY_n: {
      if (page_number_ != 7) {
        page_number_++;
      }
      break;
    }

    case KeyEvent::KEY_a: {
      // When the user selects answer choice A
      user_answers_[question_number_] = mylibrary::kChoiceA;
      question_number_++;
      break;
    }
    case KeyEvent::KEY_b: {
      // When the user selects answer choice B
      user_answers_[question_number_] = mylibrary::kChoiceB;
      question_number_++;
      break;
    }
    case KeyEvent::KEY_c: {
      // When the user selects answer choice C
      user_answers_[question_number_] = mylibrary::kChoiceC;
      question_number_++;
      break;
    }

  }
}

}  // namespace myapp
