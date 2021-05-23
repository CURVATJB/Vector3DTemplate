#pragma once
#include "ISource.h"

template<typename T>
class TLight : public ISource<T>
{
	static_assert(std::is_arithmetic<T>::value);

public:
	TLight() : m_position(), m_color() {}

	TLight(const TPoint<T>& position, const Color& color) : m_position(position), m_color(color) {}

	~TLight() = default;

	TPoint<T> GetLightPosition() const override { return m_position; }
	Color GetLightColor() const override { return m_color; }

private:
	TPoint<T> m_position;
	Color m_color;
};
