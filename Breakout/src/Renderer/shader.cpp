#include "shader.h"
#include "cstring"

Shader::Shader(const std::string &vertex_source,
               const std::string &fragment_source,
               const std::string &geometry_source) {

  Compile(vertex_source, fragment_source, geometry_source);
}

Shader::~Shader() { glDeleteProgram(id_); }

// FIXME: horrible piece of shit, need to fix dublication of the code
unsigned int Shader::Compile(const std::string &vertex_source,
                             const std::string &fragment_source,
                             const std::string &geometry_source) {

  this->id_ = glCreateProgram();
  bool is_compiled;

  unsigned int vertex_shader_id = CompileShader(vertex_source);
  is_compiled = CheckShaderCompileErrors(vertex_shader_id);

  unsigned int fragment_shader_id = CompileShader(fragment_source);
  is_compiled = CheckShaderCompileErrors(fragment_shader_id);

  glAttachShader(this->id_, vertex_shader_id);
  glAttachShader(this->id_, fragment_shader_id);

  unsigned int geometry_shader_id;
  if (!geometry_source.empty()) {
    geometry_shader_id = CompileShader(geometry_source);
    is_compiled = CheckShaderCompileErrors(geometry_shader_id);

    if (is_compiled)
      glAttachShader(this->id_, geometry_shader_id);
  }

  if (is_compiled)
    glLinkProgram(this->id_);

  glDetachShader(id_, vertex_shader_id);
  glDeleteShader(vertex_shader_id);

  glDetachShader(id_, fragment_shader_id);
  glDeleteShader(fragment_shader_id);

  if (!geometry_source.empty()) {
    glDetachShader(id_, geometry_shader_id);
    glDeleteShader(geometry_shader_id);
  }

  return is_compiled;
}

unsigned int Shader::CompileShader(const std::string &name) {

  char *shader_source_buffer = new char[name.length()];
  std::strcpy(shader_source_buffer, name.c_str());

  unsigned int shader_id = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(shader_id, 1, &shader_source_buffer, NULL);
  glCompileShader(shader_id);

  return shader_id;
}

// TODO: methods CheckShaderCompileErrors and CheckShaderProgramCompileErrors
// have similar implementation, need to fix it
unsigned int Shader::CheckShaderCompileErrors(unsigned int shader) {
  int success;
  char infoLog[1024];

  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(shader, 1024, NULL, infoLog);
    // FIXME: add log
    return 0;
  }

  return 1;
}

unsigned int Shader::CheckShaderProgramCompileErrors(unsigned int shader) {
  int success;
  char infoLog[1024];

  glGetProgramiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shader, 1024, NULL, infoLog);
    // FIXME: add log
    return 0;
  }

  return 1;
}
