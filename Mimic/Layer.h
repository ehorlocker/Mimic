#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Mimic {
	// Layers work to separate things like GUI
	// and scene.
	class MIMIC_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}