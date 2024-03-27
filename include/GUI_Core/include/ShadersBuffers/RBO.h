#ifndef RBO_CLASS_H
#define RBO_CLASS_H

#include <glad/glad.h>

class RBO
{
public:
	// Reference ID of the Render Buffer Object
	GLuint ID;
	// Constructor that generates a Render Buffer Object and links it to vertices
	RBO(GLfloat* vertices, GLsizeiptr size);

	// Binds the RBO
	void Bind();
	// Unbinds the RBO
	void Unbind();
	// Deletes the RBO
	void Delete();
};

#endif