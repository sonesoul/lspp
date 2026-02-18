#pragma once
#include <tuple>

template<typename... Types>
struct TypeUnion {
private:
	
	std::tuple<Types...> _t;

public:
	TypeUnion(Types... defaults) : 
		_t(defaults...) {
	}

	template<typename T>
	inline T& get() {
		return std::get<T>(_t);
	}
	template<typename T>
	inline void set(T v) {
		std::get<T>(_t) = v;
	}
};