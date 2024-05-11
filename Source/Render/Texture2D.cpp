#include "Texture2D.h"

Texture2D::Texture2D(const GLuint width, const GLuint height, const unsigned char* data, const size_t channels, const GLenum filter,
	const GLenum wrapMode)
	: _width {width}, _height {height}
{
	switch (channels)
	{
		case 4:
			_mode = GL_RGBA;
			break;
		case 3:
			_mode = GL_RGB;
			break;
		default:
			_mode = GL_RGBA;
			break;
	}

	glGenTextures(1, &_ID);
	glBindTexture(GL_TEXTURE_2D, _ID);
	glTexImage2D(GL_TEXTURE_2D, 0, _mode, _width, _height, 0, _mode, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
}

Texture2D::Texture2D(Texture2D&& other)
{
	_ID = other._ID;
	_mode = other._mode;
	_width = other._width;
	_height = other._height;

	other._ID = 0;
}


Texture2D::~Texture2D()
{
	glDeleteTextures(1,&_ID);
}

Texture2D& Texture2D::operator=(const Texture2D&& other)
{
	glDeleteTextures(1,&other._ID);
	_ID = other._ID;
	_mode = other._mode;
	_width = other._width;
	_height = other._height;
	return *this;
}

void Texture2D::bind() const
{
	glBindTexture(GL_TEXTURE_2D, _ID);
}
