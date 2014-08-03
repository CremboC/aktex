#pragma once

#include <unordered_map>
#include <functional>

using std::function;

using std::unordered_map;

namespace types
{
	template<class K, class V>
	using HashMap = unordered_map < K, V > ;

	template<class K, class... V>
	using Func = function < K(V...) > ;
}