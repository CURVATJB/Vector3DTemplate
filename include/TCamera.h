#pragma once
#include <type_traits>

#include "TVecteur3D.h"

template<typename T>
class TCamera
{
	static_assert(std::is_arithmetic<T>::value);

public:

	TCamera() : TCamera(TPoint<T>(), TVecteur3D<T>(1, 0, 0), TVecteur3D<T>(0, 0, 0), TVecteur3D<T>(0, 0, 0)) {}

	TCamera(const TPoint<T>& position, const TVecteur3D<T>& direction, const TVecteur3D<T>& right, const TVecteur3D<T>& down)
		: m_position(position), m_direction(direction), m_right(right), m_down(down) {}


	TCamera(const TCamera<T>& camera)
	{
		m_position = camera.Position();
		m_direction = camera.Direction();
		m_right = camera.Right();
		m_down = camera.Down();
	}

	~TCamera() = default;

	TCamera<T>& operator=(const TCamera<T>& camera)
	{
		m_position = camera.m_position;
		m_direction = camera.m_direction;
		m_right = camera.m_right;
		m_down = camera.m_down;
		return *this;
	}

	TPoint<T> Position() const { return m_position; }
	TVecteur3D<T> Direction() const { return m_direction; }
	TVecteur3D<T> Right() const { return m_right; }
	TVecteur3D<T> Down() const { return m_down; }

	void SetPosition(TPoint<T> position) { m_position = position; }
	void SetDirection(TVecteur3D<T> direction) { m_direction = direction; }
	void SetRight(TVecteur3D<T> right) { m_right = right; }
	void SetDown(TVecteur3D<T> down) { m_down = down; }

private:

	TPoint<T> m_position;
	TVecteur3D<T> m_direction;
	TVecteur3D<T> m_right;
	TVecteur3D<T> m_down;
};
