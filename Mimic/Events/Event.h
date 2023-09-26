#pragma once

#include "Core.h"
#include "Base.h"

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

	// Base class for all events, example implementations can be
	// found in ApplicationEvent.h
	class Event {
	public:
		virtual ~Event() = default;

		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	};

	class EventDispatcher {
	public:
		EventDispatcher(Event& event) : m_Event(event) {}

		/* 
		 * This implemtation of Dispatch is the new git version and
		 * works just fine :)
		 * 
		 * note: F typename is decided by compiler b/c func argument
		 */
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