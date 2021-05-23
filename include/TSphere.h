#pragma once
#include <type_traits>

#include "TPoint.h"
#include "TVecteur3D.h"


template<typename T>
class TSphere
{
	static_assert(std::is_arithmetic<T>::value);

public:
	TSphere()
	{
		m_center = TPoint<T>();
		m_radius = 0;
	}

	TSphere(const TPoint<T>& center, const T& radius) : m_center(center), m_radius(radius)
	{
	}

	auto GetCenter() const { return m_center; }
	auto GetRadius() const { return m_radius; }

	auto GetNormalAtPoint(const TPoint<T>& point)
	{
		TVecteur3D<T> tmp(m_center, point);
		return tmp.Normalized();
	}
	
private:
	TPoint<T> m_center;
	T m_radius;
};
