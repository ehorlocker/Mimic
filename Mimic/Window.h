#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Mimic {

	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Mimic Engine",
			uint32_t width = 1600,
			uint32_t height = 900)
			: Title(title), Width(width), Height(height)
		{}
	};

	// Interface for a desktop window
	class Window {
	public:
		// callback function for window events
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual ulint32_t GetWidth() const = 0;
		virtual 

	};

}