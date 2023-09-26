#include "WindowsWindow.h"

namespace Mimic {

	static bool s_GLFWInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}
	
	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		MZ_CORE_INFO("Creating window{0} ({1}, {2})", props.Title, props.Width, props.Height);

		// if GLFW is not initialized, initlaize it
		if (!s_GLFWInitialized) {
			int success = glfwInit();
			MZ_CORE_ASSERT(success, "Could not initlize GLFW!");

			s_GLFWInitialized = true;
		}

		// TODO: figure this out lmao
		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		// why can we pass in m_Data, is this exact format what glfw supports?
		// it seems to convenient
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate() {
		// TODO: find out what these do, maybe go through glfw series
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled) {
		// what is swap interval?
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const {
		return m_Data.VSync;
	}
}