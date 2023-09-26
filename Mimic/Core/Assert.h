#ifdef MZ_ENABLE_ASSERTS
	#define MZ_ASSERT(x, ...) { if(!(x)) { MZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
	#define MZ_CORE_ASSERT(x, ...) { if(!(x)) { MZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
#else
	#define MZ_ASSERT(x,...)
	#define MZ_CORE_ASSERT(x,...)
#endif