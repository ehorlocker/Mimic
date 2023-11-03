#pragma once

#include "Window.h"
// found in git for graphics context object later:
//#include "Hazel/Renderer/GraphicsContext.h"

#define GLFW_INCLUDE_NONE
#include<glfw/glfw3.h>

namespace Mimic {
	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetHeight() const override { return m_Data.Height; }
		unsigned int GetWidth() const override { return m_Data.Width; }

		void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		virtual void* GetNativeWindow() const { return m_Window; }
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
		
		GLFWwindow* m_Window;
		//Scope<GraphicsContext> m_Context;

		// stores all window data for later use with glfw
		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}