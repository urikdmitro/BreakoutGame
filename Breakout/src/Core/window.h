#ifndef BREAKOUT_SRC_CORE_WINDOW_H_
#define BREAKOUT_SRC_CORE_WINDOW_H_

#include <string>

struct WindowProperties {
  int width;
  int height;
  std::string title;
};

class WindowI {
private:
public:
  virtual ~WindowI() = default;
  virtual int GetWidth() = 0;
  virtual int GetHeight() = 0;
  virtual void Update() = 0;
};

#endif // BREAKOUT_SRC_CORE_WINDOW_H_
