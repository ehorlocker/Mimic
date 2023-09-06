#pragma once
#include "Core.h"
#include <spdlog/spdlog.h>
#include <memory>

namespace Mimic {
	class Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define MZ_CORE_TRACE(...)	::Mimic::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MZ_CORE_INFO(...)	::Mimic::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MZ_CORE_WARN(...)	::Mimic::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MZ_CORE_ERROR(...)	::Mimic::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MZ_CORE_FATAL(...)	::Mimic::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MZ_TRACE(...)	::Mimic::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MZ_INFO(...)	::Mimic::Log::GetClientLogger()->info(__VA_ARGS__)
#define MZ_WARN(...)	::Mimic::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MZ_ERROR(...)	::Mimic::Log::GetClientLogger()->error(__VA_ARGS__)
#define MZ_FATAL(...)	::Mimic::Log::GetClientLogger()->critical(__VA_ARGS__)


