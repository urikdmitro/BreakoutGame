#include "window_glfw.h"

WindowGLFW::WindowGLFW(const WindowProperties &window_properties)
    : window_properties_(window_properties), glfw_window_(nullptr) {

  glfwInit();

  glfw_window_ =
      glfwCreateWindow(window_properties_.width, window_properties_.height,
                       window_properties_.title.c_str(), nullptr, nullptr);

  glfwMakeContextCurrent(glfw_window_);
  glfwSetFramebufferSizeCallback(glfw_window_, nullptr);
}

WindowGLFW::~WindowGLFW() {
  glfwDestroyWindow(glfw_window_);
  glfwTerminate();
}

int WindowGLFW::GetWidth() { return window_properties_.width; }

int WindowGLFW::GetHeight() { return window_properties_.height; }

void WindowGLFW::Update() {
  glfwSwapBuffers(glfw_window_);
  glfwPollEvents();
}
