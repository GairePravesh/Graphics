#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
	:m_Count(count)
{
	glGenBuffers(1, &m_Renderer_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Renderer_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count* sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, & m_Renderer_ID);
}

void IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Renderer_ID);
}

void IndexBuffer::UnBind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


