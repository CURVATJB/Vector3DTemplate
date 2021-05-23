#pragma once
#include <ostream>

template <typename T>
class TPoint
{
	static_assert(std::is_arithmetic<T>::value);

	friend std::ostream& operator<<(std::ostream& os, const TPoint<int>& point);

	friend std::ostream& operator<<(std::ostream& os, const TPoint<double>& point);

public:

	TPoint() : m_x(0)
	         , m_y(0)
	         , m_z(0)
	{ }

	TPoint(const T& x, const T& y, const T& z) : m_x(x)
	                                           , m_y(y)
	                                           , m_z(z)
	{ }

	TPoint(const TPoint<T>& point)
	{
		m_x = point.X();
		m_y = point.Y();
		m_z = point.Z();
	}

	T X() const { return m_x; }
	T Y() const { return m_y; }
	T Z() const { return m_z; }

	//surcharge operateur
	TPoint<T>& operator=(TPoint<T> const& point)
	{
		m_x = point.X();
		m_y = point.Y();
		m_z = point.Z();
	}

private:
	T m_x;
	T m_y;
	T m_z;
};

inline std::ostream& operator<<(std::ostream& os, const TPoint<int>& point)
{
	os << "(" << point.m_x << "," << point.m_y << "," << point.m_z << ")";
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const TPoint<double>& point)
{
	os << "(" << point.m_x << "," << point.m_y << "," << point.m_z << ")";
	return os;
}
