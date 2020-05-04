// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>


namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;

 private:
  size_t page_number_ = 0;
  size_t question_number_ = 0;
  std::vector<char> user_answers_;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
