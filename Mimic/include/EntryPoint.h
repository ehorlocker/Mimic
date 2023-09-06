#pragma once

#ifdef MZ_PLATFORM_WINDOWS

extern Mimic::Application* Mimic::CreateApplication();

int main(int argc, char** argv) {
	Mimic::Log::Init();
	MZ_CORE_WARN("Core Logger Initialized!");
	MZ_INFO("Client Logger Initialized!");

	auto app = Mimic::CreateApplication();
	app->Run();
	delete app;
}

#endif
