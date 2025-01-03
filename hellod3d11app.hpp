#pragma once

#include <d3d11.h>
#include <dxgi1_3.h>
#include <wrl.h>

#include "application.h"

class HelloD3D11App final : public Application 
{
	template <typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;

public:
	HelloD3D11App(const std::string& title);
	~HelloD3D11App() override;

protected:
	bool Initialize() override;
	bool Load() override;
	void OnResize(int32_t width, int32_t height) override;
	void Update() override;
	void Render() override;

private:
	bool CreateSwapchainResources();
	void DestroySwapchainResources();

	ComPtr<ID3D11Device> _device = nullptr;
	ComPtr<ID3D11DeviceContext> _deviceContext = nullptr;
	ComPtr<IDXGIFactory2> _dxgiFactory = nullptr;
	ComPtr<IDXGISwapChain1> _swapChain = nullptr;
	ComPtr<ID3D11RenderTargetView> _renderTarget = nullptr;
};