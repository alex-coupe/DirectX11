#pragma once
#include "RenderingSystem.h"

class Renderer {
public:
	Renderer(int64_t width, int64_t height, HWND handle);
	void ProcessFrame();
private:
	std::shared_ptr<Direct3D> m_direct3d;
	void CreateTestTriangle();
};