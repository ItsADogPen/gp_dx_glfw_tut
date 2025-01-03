#include "hellod3d11app.hpp"

#include <GLFW/glfw3.h>
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

#include <DirectXMath.h>
#include <d3dcompiler.h>

#include <iostream>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "dxguid.lib")

HelloD3D11App::HelloD3D11App(const std::string& title) : Application(title) 
{
	
}

HelloD3D11App::~HelloD3D11App() 
{

}

bool HelloD3D11App::Initialize() 
{
	return true;
}

bool HelloD3D11App::Load() 
{
	return true;
}

bool HelloD3D11App::CreateSwapchainResources() 
{
	return true;
}

void HelloD3D11App::DestroySwapchainResources() 
{

}

void HelloD3D11App::OnResize(const int32_t width, const int32_t height) 
{

}

void HelloD3D11App::Update()
{
}

void HelloD3D11App::Render()
{
}