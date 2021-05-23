#pragma once
#include <ostream>

class Color
{

	friend Color operator+(const Color& color, const Color& color2);
	friend Color operator-(const Color& color, const Color& color2);
	friend Color operator*(const Color& color, const Color& color2);
	friend Color operator*(const Color& color, const double& val);
	friend Color operator*(const double& val, const Color& color);
	friend Color operator/(const Color& color, const double& val);
	friend std::ostream& operator<<(std::ostream& os, const Color& color);

public:

	Color();

	Color(const double& red, const double& green, const double& blue, const double& alpha);

	Color(const Color& color);

	~Color() = default;

	Color& operator=(const Color& color);
	Color& operator+=(const Color& color);
	Color& operator-=(const Color& color);
	Color& operator*=(const Color& color);
	Color& operator*=(const double& val);
	Color& operator/=(const double& val);

	double Red() const;
	double Green() const;
	double Blue() const;
	double Alpha() const;

	void SetRed(const double& red);
	void SetGreen(const double& green);
	void SetBlue(const double& blue);
	void SetAlpha(const double& alpha);

	Color Average(const Color& color) const;
	double Brightness() const;
private:

	double m_red;
	double m_green;
	double m_blue;
	double m_alpha;
};
