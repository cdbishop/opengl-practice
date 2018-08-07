#include "Shader.hpp"

Shader::Shader(unsigned int program)
	:_program(program) 
{
}

Shader::~Shader()
{
}

unsigned int Shader::GetId()
{
	return _program;
}
