#include "window_glfw.h"

WindowGLFW::WindowGLFW(const WindowProperties &window_properties) {
  window_properties_.height = window_properties.height;
  window_properties_.width = window_properties.width;
  window_properties_.title = window_properties.title;

  glfwInit();
  window_ =
      glfwCreateWindow(window_properties_.width, window_properties_.height,
                       window_properties_.title.c_str(), nullptr, nullptr);
}

WindowGLFW::~WindowGLFW() {
  glfwDestroyWindow(window_);
  glfwTerminate();
}

int WindowGLFW::GetWidth() { return window_properties_.width; }

int WindowGLFW::GetHeight() { return window_properties_.height; }

void WindowGLFW::Update() { glfwPollEvents(); }
