#pragma once
#include <type_traits>

#include "TVecteur3D.h"


template<typename T>
class TPlane
{
	static_assert(std::is_arithmetic<T>::value);

public:
	TPlane()
	{
		m_normal = TVecteur3D<T>();
		m_distance = 0;
	}

	TPlane(const TVecteur3D<T> normal, const T& distance) :m_normal(normal), m_distance(distance)
	{
	}

	auto GetNormal() const { return m_normal; }
	auto GetDistance() const { return m_distance; }
	
private:
	TVecteur3D<T> m_normal;
	T m_distance;
};
