#pragma once

#include "Core.h"
#include <functional>

namespace Mimic {
	/* 
	 * Events in Mimic will be blocking.There is no queue of
	 * events, etc. To ensure functionality in the beginning,
	 * only Window events and KeyPressed will be implemented
	 * before having an interface to test with. 
	 */

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// Create a bit field via macro for EventCategory since an
	// event can be more than one type
	enum EventCategory {
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

	// Since we'll need to override Event a lot, we can make a macro
	// for overriding functions in Event
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
																virtual EventType GetEventType() const override { return GetStaticType(); }\
																virtual const char* GetName() const override { return #type; }
	// Same deal with overriding GetCategoryFlags
#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	// Base class for all events
	class Event {
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher {
	public:
		EventDispatcher(Event& event) : m_event(event) {}

		// F is decided by compiler b/c func
		// this function confuses me a little because I don't
		// understand func's role yet. like.. how does it know
		// what function to dispatch? some use of it will answer this.
		template<typename T, typename F>
		bool Dispatch(const F& func) {
			if (m_Event.GetEventType() == T::GetStaticType()) {

				m_Event.Handled |= func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}