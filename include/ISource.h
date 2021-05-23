#pragma once
#include <type_traits>

#include "Color.h"
#include "TPoint.h"

template<typename T>
class ISource
{
	static_assert(std::is_arithmetic<T>::value);
public:
	virtual ~ISource() = default;

	virtual TPoint<T> GetLightPosition() const = 0;
	virtual Color GetLightColor() const = 0;
};
