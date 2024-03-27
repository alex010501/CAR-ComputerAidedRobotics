#ifndef FBO_CLASS_H
#define FBO_CLASS_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class FrameBuffer
{
private:
	GLuint m_FBO;
	GLuint m_texture;
	GLuint m_RBO;

public:
	FrameBuffer(float p_width, float p_height);
	~FrameBuffer();
	GLuint getFrameTexture();
	void RescaleFrameBuffer(float p_width, float p_height);
	void Bind() const;
	void Unbind() const;
};

#endif