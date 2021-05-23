#pragma once
#include <ostream>
#include "TPoint.h"

template<typename T>
class TVecteur3D
{
	static_assert(std::is_arithmetic<T>::value);

	template<typename>
	friend auto operator+(const TVecteur3D& vec, const TVecteur3D& vec2);

	template<typename>
	friend auto operator-(const TVecteur3D& vec, const TVecteur3D& vec2);

	template<typename>
	friend auto operator*(const TVecteur3D& vec, const TVecteur3D& vec2);

	template<typename>
	friend auto operator*(const T& val, const TVecteur3D& vec);

	template<typename>
	friend auto operator*(const TVecteur3D& vec, const T& val);

	template<typename>
	friend auto operator/(const TVecteur3D& vec, const T& val);

	friend std::ostream& operator<<(std::ostream& os, const TVecteur3D<int>& vec);
	friend std::ostream& operator<<(std::ostream& os, const TVecteur3D<double>& vec);

public:
	TVecteur3D() :m_x(1), m_y(0), m_z(0) {}

	TVecteur3D(T x, T y, T z) : m_x(x), m_y(y), m_z(z) {}

	TVecteur3D(TPoint<T>& point1, TPoint<T>& point2)
	{
		m_x = point2.X() - point1.X();
		m_y = point2.Y() - point1.Y();
		m_z = point2.Z() - point1.Z();
	}

	T X() { return m_x; }
	T Y() { return m_y; }
	T Z() { return m_z; }

	void SetX(const T& x) { m_x = x; }
	void SetY(const T& y) { m_y = y; }
	void SetZ(const T& z) { m_z = z; }

	auto& operator=(const TVecteur3D& vec)
	{
		m_x = vec.m_x;
		m_y = vec.m_y;
		m_z = vec.m_z;
		return *this;
	}

	auto& operator+=(const TVecteur3D& vec)
	{
		m_x += vec.m_x;
		m_y += vec.m_y;
		m_z += vec.m_z;
		return *this;
	}

	auto& operator-=(const TVecteur3D& vec)
	{
		m_x -= vec.m_x;
		m_y -= vec.m_y;
		m_z -= vec.m_z;
		return *this;
	}

	auto& operator*=(const TVecteur3D& vec)
	{
		TVecteur3D tmp(m_x, m_y, m_z);
		m_x = tmp.m_y * vec.m_z - tmp.m_z * vec.m_y;
		m_y = tmp.m_z * vec.m_x - tmp.m_x * vec.m_z;
		m_z = tmp.m_x * vec.m_y - tmp.m_y * vec.m_x;
		return *this;
	}

	auto& operator*=(const T& val)
	{
		m_x *= val;
		m_y *= val;
		m_z *= val;
		return *this;
	}

	auto& operator/=(const T& val)
	{
		m_x /= val;
		m_y /= val;
		m_z /= val;
		return *this;
	}

	float Magnitude() const
	{
		return std::sqrtf(std::pow(m_x, 2) + std::pow(m_y, 2) + std::pow(m_z, 2));
	}

	auto Normalized() const
	{
		const double tmp = Magnitude();
		return TVecteur3D<double>(m_x / tmp, m_y / tmp, m_z / tmp);
	}

	auto Opposite() const
	{
		return TVecteur3D<T>(-m_x, -m_y, -m_z);
	}

	double DotProduct(const TVecteur3D& vec)
	{
		return m_x * vec.m_x + m_y * vec.m_y + m_z * vec.m_z;
	}

private:
	T m_x;
	T m_y;
	T m_z;
};

template<typename T>
auto operator+(const TVecteur3D<T>& vec, TVecteur3D<T> const& vec2)
{
	TVecteur3D<T> tmp = vec;
	tmp += vec2;
	return tmp;
}

template<typename T>
auto operator-(const TVecteur3D<T>& vec, const TVecteur3D<T>& vec2)
{
	TVecteur3D<T> tmp = vec;
	tmp -= vec2;
	return tmp;
}

template<typename T>
auto operator*(const TVecteur3D<T>& vec, const TVecteur3D<T>& vec2)
{
	TVecteur3D<T> tmp = vec;
	tmp *= vec2;
	return tmp;
}

template<typename T>
auto operator*(const T& val, const TVecteur3D<T>& vec)
{
	TVecteur3D<T> tmp = vec;
	tmp *= val;
	return tmp;
}

template<typename T>
auto operator*(const TVecteur3D<T>& vec, const T& val)
{
	TVecteur3D<T> tmp = vec;
	tmp *= val;
	return tmp;
}

template<typename T>
auto operator/(const TVecteur3D<T>& vec, const T& val)
{
	TVecteur3D<T> tmp = vec;
	tmp /= val;
	return tmp;
}

inline std::ostream& operator<<(std::ostream& os, const TVecteur3D<int>& vec)
{
	os << "(" << vec.m_x << "," << vec.m_y << "," << vec.m_z << ")";
	return os;
}

inline std::ostream& operator<<(std::ostream& os, const TVecteur3D<double>& vec)
{
	os << "[" << vec.m_x << "," << vec.m_y << "," << vec.m_z << "]";
	return os;
}
