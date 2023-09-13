#pragma once

#ifdef MZ_PLATFORM_WINDOWS
	#ifdef MZ_BUILD_DLL
		#define MIMIC_API __declspec(dllexport)
	#else
		#define MIMIC_API __declspec(dllimport)
	#endif
#else
	#error Mimic only supports Windows
#endif

#define BIT(x) (1 << x)