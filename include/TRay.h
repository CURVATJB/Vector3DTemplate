#pragma once
#include <type_traits>

#include "TPoint.h"
#include "TVecteur3D.h"

template<typename T>
class TRay
{
	static_assert(std::is_arithmetic<T>::value);

public:
	TRay()
	{
		m_origin = TPoint<T>();
		m_direction = TVecteur3D<T>();
	}

	TRay(const TPoint<T>& origin, const TVecteur3D<T>& direction) : m_origin(origin), m_direction(direction)
	{
	}

	auto GetOrigin() const { return m_origin; }
	auto GetDirection() const { return m_direction; }

private:
	TPoint<T> m_origin;
	TVecteur3D<T> m_direction;
};
