#include "Renderer.h"

Renderer* Renderer::_instance;

Renderer::Renderer()
{
	if (Renderer::_instance == nullptr)
		Renderer::_instance = this;

	glEnable(GL_DEPTH_TEST);
	DG_ENGINE_INFO("Renderer initialized successfully");
}

void Renderer::SetClearColor(const glm::vec4& color)
{
	glClearColor(color.x, color.y, color.z, color.w);
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
	glViewport(x, y, width, height);
}

void Renderer::Draw(const Shader& shader, const VertexBuffer& vertexBuffer)
{
	vertexBuffer.Bind();
	shader.Bind();
	glDrawElements(GL_TRIANGLES, vertexBuffer._indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::DrawVertices(const Shader& shader, const VertexBuffer& vertexBuffer)
{
	vertexBuffer.Bind();
	shader.Bind();
	glDrawArrays(GL_TRIANGLES, 0, vertexBuffer.GetVertexCount());
}