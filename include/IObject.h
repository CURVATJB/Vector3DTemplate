#pragma once
#include <type_traits>
#include "Color.h"
#include "TRay.h"


template<typename T>
class IObject
{
	static_assert(std::is_arithmetic<T>::value);
public:
	virtual ~IObject() = default;

	virtual Color GetColor() const = 0;
	virtual double FindIntersection(const TRay<T>& ray) = 0;
	virtual TVecteur3D<T> GetNormalAt(const TPoint<T>& point) = 0;
};
