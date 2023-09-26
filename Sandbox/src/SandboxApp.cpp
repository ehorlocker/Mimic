#include <Mimic.h>

class Sandbox : public Mimic::Application {

public:
	Sandbox() {
		std::string x = "bvlasd";
	}

	~Sandbox() {

	}
};

Mimic::Application* Mimic::CreateApplication() {
	return new Sandbox();
}