#pragma once

#include "OpenGl.h"

class Texture2D
{
public:
	Texture2D() = delete;
	Texture2D( const Texture2D&) = delete;
	Texture2D& operator=(const Texture2D&) = delete;

	Texture2D(const GLuint width, const GLuint height, const unsigned char* data, const size_t channels = 4,
		const GLenum filter = GL_LINEAR, const GLenum wrapMode = GL_CLAMP_TO_EDGE);

	Texture2D(Texture2D&& other);
	Texture2D& operator=(const Texture2D&& other);

	~Texture2D();

	void bind() const;

private:
	GLuint _ID;
	GLenum _mode;
	size_t _width;
	size_t _height;
};