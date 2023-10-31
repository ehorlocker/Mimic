#include <Mimic.h>

class ExampleLayer : public Mimic::Layer {
public:
	ExampleLayer()
		: Layer("Example") {

	}

	~ExampleLayer() {}

	void OnUpdate() override {
		MZ_INFO("ExampleLayer::OnUpdate()");
	}

	void OnEvent(Mimic::Event& event) override {
		MZ_TRACE("{0}", event);
	}
};

class Sandbox : public Mimic::Application {

public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

Mimic::Application* Mimic::CreateApplication() {
	return new Sandbox();
}