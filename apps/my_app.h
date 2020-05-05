// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <cinder/audio/audio.h>
#include <mylibrary/response.h>
#include <mylibrary/organizer.h>

#include <random>
#include <string>
#include <vector>

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;


 private:
  void DrawBackground() const;
  void PrintText(const std::string& text, const cinder::Color& color,
                        const cinder::ivec2& size, const cinder::vec2& loc,
                        int font_size);
  size_t page_number_ = 0;
  std::vector<char> user_answers_;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
