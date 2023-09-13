#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Mimic {
	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		MZ_TRACE(e);
		while (true);
	}
}