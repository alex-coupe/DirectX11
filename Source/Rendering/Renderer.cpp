#include "Renderer.h"
#include "../ImGui/imgui.h"
#include "../ImGui/imgui_impl_dx11.h"
#include "../ImGui/imgui_impl_win32.h"
#include "VertexTypes.h"

Renderer::Renderer(int64_t width, int64_t height, HWND handle)
{
	m_direct3d = std::make_shared<Direct3D>(handle, width, height);
}

void Renderer::ProcessFrame()
{
	m_direct3d->BeginFrame();
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	{

		ImGui::Begin("Debug");
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
			1000.0 / float(ImGui::GetIO().Framerate), float(ImGui::GetIO().Framerate));

		ImGui::End();
	}
	CreateTestTriangle();
	m_direct3d->EndFrame();
}

void Renderer::CreateTestTriangle()
{
	std::vector<VertexPos> vertices = {
		{{ 0.0f, 0.5f,0.0f}},
		{{ 0.5f, -0.5f,0.0f}},
		{{-0.5f,-0.5f,0.0f}}


	};

	const std::vector<D3D11_INPUT_ELEMENT_DESC> ied =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	VertexBuffer vertexBuffer(vertices, m_direct3d);
	vertexBuffer.Bind();

	Shader vertexShader(ShaderType::Vertex, L"Source/Rendering/Shaders/Vertex_Solid.hlsl", m_direct3d);
	vertexShader.Bind();

	Shader pixelShader(ShaderType::Pixel, L"Source/Rendering/Shaders/Pixel_Solid.hlsl", m_direct3d);
	pixelShader.Bind();

	InputLayout inputLayout(ied, vertexShader.GetByteCode(), m_direct3d);
	inputLayout.Bind();

	Topology topology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST, m_direct3d);
	topology.Bind();

	m_direct3d->Draw(3, 0);
}
