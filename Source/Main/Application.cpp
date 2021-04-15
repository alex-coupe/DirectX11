#include "Application.h"
#include "../ImGui/imgui.h"

Application::Application(HINSTANCE& hInstance)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	m_window = std::make_unique<Window>(hInstance, 1900, 1020);
	m_renderer = std::make_unique<Renderer>(m_window->GetInitialWidth(), m_window->GetInitialHeight(),m_window->GetHandle());
}

void Application::Update()
{
	while (m_window->Update())
	{
		m_renderer->ProcessFrame();
	}
}

Application::~Application()
{
	m_window.reset();
	m_renderer.reset();
	ImGui::DestroyContext();
}
