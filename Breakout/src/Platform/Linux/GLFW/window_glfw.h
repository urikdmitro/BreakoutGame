#ifndef BREAKOUT_SRC_PLATFORM_LINUX_GLFW_WINDOW_H_
#define BREAKOUT_SRC_PLATFORM_LINUX_GLFW_WINDOW_H_

#include "GLFW/glfw3.h"
#include "window.h"

class WindowGLFW : public WindowI {
private:
  WindowProperties window_properties_;
  GLFWwindow *window_;

public:
  WindowGLFW(const WindowProperties &window_properties);
  ~WindowGLFW();
  int GetWidth() override;
  int GetHeight() override;
  void Update() override;
};

#endif // BREAKOUT_SRC_PLATFORM_LINUX_GLFW_WINDOW_H_
