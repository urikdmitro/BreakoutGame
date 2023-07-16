#include "shader.h"
#include "cstring"
#include <exception>

Shader::Shader(const std::string &vertex_source,
               const std::string &fragment_source,
               const std::string &geometry_source) {

  this->id_ = glCreateProgram();

  unsigned int vertex_shader_id = CompileShader(vertex_source);
  glAttachShader(this->id_, vertex_shader_id);

  unsigned int fragment_shader_id = CompileShader(fragment_source);
  glAttachShader(this->id_, fragment_shader_id);

  unsigned int geometry_shader_id;
  if (!geometry_source.empty()) {
    geometry_shader_id = CompileShader(geometry_source);
    glAttachShader(this->id_, geometry_shader_id);
  }

  glLinkProgram(this->id_);

  glDeleteShader(vertex_shader_id);
  glDeleteShader(fragment_shader_id);
  if (!geometry_source.empty())
    glDeleteShader(geometry_shader_id);
}

unsigned int Shader::CompileShader(const std::string &name) {

  char *shader_source_buffer = new char[name.length()];
  std::strcpy(shader_source_buffer, name.c_str());

  unsigned int shader_id = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(shader_id, 1, &shader_source_buffer, NULL);
  glCompileShader(shader_id);

  return shader_id;
}
