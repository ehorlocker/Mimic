#pragma once

#include "Core.h"
#include "Window.h"
#include "WindowsWindow.h"
//#include "WindowsWindow.h"

namespace Mimic {
	class MIMIC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}