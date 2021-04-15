#pragma once
#include <memory>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include "Window.h"
#include <Windows.h>
#include "../Rendering/Renderer.h"

class Application {
public:
	Application(HINSTANCE& hInstance);
	void Update();
	~Application();
private:
	std::unique_ptr<Window> m_window;
	std::unique_ptr<Renderer> m_renderer;
};