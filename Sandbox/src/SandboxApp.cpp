#include <Mimic.h>

class Sandbox : public Mimic::Application {

public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Mimic::Application* Mimic::CreateApplication() {
	return new Sandbox();
}