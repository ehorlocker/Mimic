#pragma once

#include "Core.h"

namespace Mimic {
	class MIMIC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}

