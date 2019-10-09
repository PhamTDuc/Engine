#pragma once

#ifdef ENGINE_PLATFORM_WINDOW
	#ifdef ENGINE_BUILD_DLL
		#define ENGINE_API __declspec(dllexport)
		#define IMGUI_API __declspec( dllexport )
	#else
		#define ENGINE_API __declspec(dllimport)
		#define IMGUI_API __declspec( dllimport )
	#endif
#else
	#error "GUINEA ENGINE ONLY SUPORT 64BIT WINDOW PLATFORM"
#endif