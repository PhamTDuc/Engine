#include "Logging.h"


namespace Engine {
	std::shared_ptr<spdlog::logger> Logging::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logging::s_ClientLogger;

	void Logging::Init(){
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("CORE");
		s_CoreLogger->set_level(spdlog::level::trace);


		s_ClientLogger = spdlog::stdout_color_mt("CLIENT");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}