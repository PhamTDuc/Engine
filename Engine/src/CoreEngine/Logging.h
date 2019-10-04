#pragma once
#include <memory>
#include "CoreHeader.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

//CORE_LOGGER
//CORE_LOGGER
#define CORE_INFO(...)  Engine::Logging::getCoreLogger()->info(__VA_ARGS__)
#define CORE_WARN(...)  Engine::Logging::getCoreLogger()->warn(__VA_ARGS__)
#define CORE_ERROR(...) Engine::Logging::getCoreLogger()->error(__VA_ARGS__)
#define CORE_FATAL(...) Engine::Logging::getCoreLogger()->fatal(__VA_ARGS__)

//CLIENT_LOGGER
//CLIENT_LOGGER
#define CLIENT_INFO(...)  Engine::Logging::getClientLogger()->info(__VA_ARGS__)
#define CLIENT_WARN(...)  Engine::Logging::getClientLogger()->warn(__VA_ARGS__)
#define CLIENT_ERROR(...) Engine::Logging::getClientLogger()->error(__VA_ARGS__)
#define CLIENT_FATAL(...) Engine::Logging::getClientLogger()->fatal(__VA_ARGS__)

namespace Engine {
	class ENGINE_API Logging
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void Init();
		static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; };
		static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }

	};
}

