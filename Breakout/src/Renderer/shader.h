#ifndef BREAKOUT_SRC_RENDERER_SHADER_
#define BREAKOUT_SRC_RENDERER_SHADER_

#include "glad/glad.h"
#include "glm/gtc/type_ptr.hpp"
#include <string>

class Shader {
private:
  GLuint program_id_;

  GLuint CompileShader(const std::string &shader_source);
  GLuint CheckShaderCompileStatus(GLuint shader_id);
  GLuint CheckShaderProgramCompileStatus(GLuint program_id);

public:
  Shader() = default;
  Shader(const std::string &vertex_source, const std::string &fragment_source,
         const std::string &geometry_source);

  ~Shader();

  GLuint CompileProgram(const std::string &vertex_source,
                        const std::string &fragment_source,
                        const std::string &geometry_source);

  GLuint GetProgramId();
  Shader &Bind();
  Shader &Unbind();

  void SetUniform(const std::string &uniform_name, GLfloat value);
  void SetUniform(const std::string &uniform_name, GLint value);
  void SetUniform(const std::string &uniform_name, const glm::vec2 &value);
  void SetUniform(const std::string &uniform_name, const glm::vec3 &value);
  void SetUniform(const std::string &uniform_name, const glm::vec4 &value);
  void SetUniform(const std::string &uniform_name, const glm::mat2 &value);
  void SetUniform(const std::string &uniform_name, const glm::mat3 &value);
  void SetUniform(const std::string &uniform_name, const glm::mat4 &value);
};

#endif // BREAKOUT_SRC_RENDERER_SHADER_
