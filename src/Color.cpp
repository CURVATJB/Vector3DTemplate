#include "Color.h"

Color::Color()
{

}

Color::Color(const double& red, const double& green, const double& blue, const double& alpha)
{
	m_red = red;
	m_green = green;
	m_blue = blue;
	m_alpha = alpha;
}

Color::Color(const Color& color)
{
	m_red = color.Red();
	m_green = color.Green();
	m_blue = color.Blue();
	m_alpha = color.Alpha();
}

Color& Color::operator=(const Color& color)
{
	m_red = color.Red();
	m_green = color.Green();
	m_blue = color.Blue();
	m_alpha = color.Alpha();
	return *this;
}

Color& Color::operator+=(const Color& color)
{
	m_red += color.Red();
	m_green += color.Green();
	m_blue += color.Blue();
	m_alpha += color.Alpha();
	return *this;
}

Color& Color::operator-=(const Color& color)
{
	m_red -= color.Red();
	m_green -= color.Green();
	m_blue -= color.Blue();
	m_alpha -= color.Alpha();
	return *this;
}

Color& Color::operator*=(const Color& color)
{
	m_red *= color.Red();
	m_green *= color.Green();
	m_blue *= color.Blue();
	m_alpha *= color.Alpha();
	return *this;
}

Color& Color::operator*=(const double& val)
{
	m_red *= val;
	m_green *= val;
	m_blue *= val;
	m_alpha *= val;
	return *this;
}

Color& Color::operator/=(const double& val)
{
	m_red /= val;
	m_green /= val;
	m_blue /= val;
	m_alpha /= val;
	return *this;
}

double Color::Red() const
{
	return m_red;
}

double Color::Green() const
{
	return m_green;
}

double Color::Blue() const
{
	return m_blue;
}

double Color::Alpha() const
{
	return m_alpha;
}

void Color::SetRed(const double& red)
{
	m_red = red;
}

void Color::SetGreen(const double& green)
{
	m_green = green;
}

void Color::SetBlue(const double& blue)
{
	m_blue = blue;
}

void Color::SetAlpha(const double& alpha)
{
	m_alpha = alpha;
}

Color Color::Average(const Color& color) const
{
	return Color((m_red + color.Red()) / 2, (m_green + color.Green()) / 2, (m_blue + color.Blue()) / 2, m_alpha);
}

double Color::Brightness() const
{
	const double i = 0.0;
	return i;
}
