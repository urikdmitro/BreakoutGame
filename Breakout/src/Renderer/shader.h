#ifndef BREAKOUT_SRC_RENDERER_SHADER_
#define BREAKOUT_SRC_RENDERER_SHADER_

#include "glad/glad.h"
#include "glm/glm/glm.hpp"
#include <string>

class Shader {
private:
  unsigned int program_id_;

  unsigned int CompileShader(const std::string &shader_source);
  unsigned int CheckShaderCompileErrors(unsigned int shader_id);
  unsigned int CheckShaderProgramCompileErrors(unsigned int program_id);

public:
  Shader() = default;
  Shader(const std::string &vertex_source, const std::string &fragment_source,
         const std::string &geometry_source);

  ~Shader();

  unsigned int CompileProgram(const std::string &vertex_source,
                              const std::string &fragment_source,
                              const std::string &geometry_source);

  unsigned int GetId();
  Shader &Bind();
  Shader &Unbind();

  void SetUniform(const std::string &uniform_name, float value);
  void SetUniform(const std::string &uniform_name, int value);
  void SetUniform(const std::string &uniform_name, const glm::vec2 &value);
  void SetUniform(const std::string &uniform_name, const glm::vec3 &value);
  void SetUniform(const std::string &uniform_name, const glm::vec4 &value);
  void SetUniform(const std::string &uniform_name, const glm::mat2 &value);
  void SetUniform(const std::string &uniform_name, const glm::mat3 &value);
  void SetUniform(const std::string &uniform_name, const glm::mat4 &value);
};

#endif // BREAKOUT_SRC_RENDERER_SHADER_
