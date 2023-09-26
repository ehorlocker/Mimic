#define BIT(x) (1 << x)


// we dont use this yet, this was on the git, but
// I believe it is used later
/*namespace Hazel {
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
}*/