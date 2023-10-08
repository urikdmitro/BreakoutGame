#include "window_glfw.h"
#include "log.h"

WindowGLFW::WindowGLFW(const WindowProperties &window_properties)
    : window_properties_(window_properties), window_(nullptr) {

  glfwInit();

  window_ =
      glfwCreateWindow(window_properties_.width, window_properties_.height,
                       window_properties_.title.c_str(), nullptr, nullptr);

  // TODO: make assertion or macro
  if (window_ == NULL)
    LOG_GLOBAL_FATAL("Failed to create GLFW window");
  else
    LOG_GLOBAL_INFO("Created GLFW window");

  glfwMakeContextCurrent(window_);
  glfwSetFramebufferSizeCallback(window_, nullptr);
}

WindowGLFW::~WindowGLFW() {
  glfwDestroyWindow(window_);
  glfwTerminate();
  LOG_GLOBAL_INFO("Destroyed GLFW window");
}

int WindowGLFW::GetWidth() { return window_properties_.width; }

int WindowGLFW::GetHeight() { return window_properties_.height; }

void WindowGLFW::Update() {
  glfwSwapBuffers(window_);
  glfwPollEvents();
}
