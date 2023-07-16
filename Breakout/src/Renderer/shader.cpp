#include "shader.h"
#include "cstring"

Shader::Shader(const std::string &vertex_source,
               const std::string &fragment_source,
               const std::string &geometry_source) {

  unsigned int vertex_shader_id CompileShader(vertex_source);

  char *vertex_source_buffer = new char[vertex_source.length()];
  std::strcpy(vertex_source_buffer, vertex_source.c_str());

  vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(vertex_shader_id, 1, &vertex_source_buffer, NULL);
  glCompileShader(vertex_shader_id);
  // checkCompileErrors(vertex_shader_id, "VERTEX");

  fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader_id, 1, &fragmentSource, NULL);
  glCompileShader(fragment_shader_id);
  checkCompileErrors(fragment_shader_id, "FRAGMENT");

  if (geometrySource != nullptr) {
    gShader = glCreateShader(GL_GEOMETRY_SHADER);
    glShaderSource(gShader, 1, &geometrySource, NULL);
    glCompileShader(gShader);
    checkCompileErrors(gShader, "GEOMETRY");
  }

  this->ID = glCreateProgram();
  glAttachShader(this->ID, vertex_shader_id);
  glAttachShader(this->ID, fragment_shader_id);
  if (geometrySource != nullptr)
    glAttachShader(this->ID, gShader);
  glLinkProgram(this->ID);
  checkCompileErrors(this->ID, "PROGRAM");

  glDeleteShader(vertex_shader_id);
  glDeleteShader(fragment_shader_id);
  if (geometrySource != nullptr)
    glDeleteShader(gShader);
}

unsigned int Shader::CompileShader(const std::string &name) {

  char *shader_source_buffer = new char[name.length()];
  std::strcpy(shader_source_buffer, name.c_str());

  unsigned int shader_id = glCreateShader(GL_VERTEX_SHADER);

  glShaderSource(shader_id, 1, &shader_source_buffer, NULL);
  glCompileShader(shader_id);

  return shader_id;
}
