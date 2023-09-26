#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Mimic {

	struct WindowProps {
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Mimic Engine",
			uint32_t width = 1280,
			uint32_t height = 720)
			: Title(title), Width(width), Height(height)
		{}
	};

	// Interface for a desktop window
	class MIMIC_API Window {
	public:
		// callback function for window events
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		// this line is this in git:
		// static Scope<Window> Create(const WindowProps& props = WindowProps());
		// for now we use the one in the video:
		static Window* Create(const WindowProps& props = WindowProps());
	};

}