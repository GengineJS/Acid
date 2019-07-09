#include "Colour.hpp"

#include <iomanip>

namespace acid
{
const Colour Colour::Clear{"#000000", 0.0f};
const Colour Colour::Black{"#000000"};
const Colour Colour::Grey{"#808080"};
const Colour Colour::Silver{"#C0C0C0"};
const Colour Colour::White{"#FFFFFF"};
const Colour Colour::Maroon{"#800000"};
const Colour Colour::Red{"#FF0000"};
const Colour Colour::Olive{"#808000"};
const Colour Colour::Yellow{"#FFFF00"};
const Colour Colour::Green{"#00FF00"};
const Colour Colour::Lime{"#008000"};
const Colour Colour::Teal{"#008080"};
const Colour Colour::Aqua{"#00FFFF"};
const Colour Colour::Navy{"#000080"};
const Colour Colour::Blue{"#0000FF"};
const Colour Colour::Purple{"#800080"};
const Colour Colour::Fuchsia{"#FF00FF"};

Colour::Colour(const float &r, const float &g, const float &b, const float &a) :
	m_r{r},
	m_g{g},
	m_b{b},
	m_a{a}
{
}

Colour::Colour(std::string hex, const float &a) :
	m_a{a}
{
	if (hex[0] == '#')
	{
		hex.erase(0, 1);
	}

	assert(hex.size() == 6);
	auto hexValue{std::stoul(hex, nullptr, 16)};

	m_r = static_cast<float>((hexValue >> 16) & 0xff) / 255.0f;
	m_g = static_cast<float>((hexValue >> 8) & 0xff) / 255.0f;
	m_b = static_cast<float>((hexValue >> 0) & 0xff) / 255.0f;
}

Colour Colour::Add(const Colour &other) const
{
	return {m_r + other.m_r, m_g + other.m_g, m_b + other.m_b, m_a + other.m_a};
}

Colour Colour::Subtract(const Colour &other) const
{
	return {m_r - other.m_r, m_g - other.m_g, m_b - other.m_b, m_a - other.m_a};
}

Colour Colour::Multiply(const Colour &other) const
{
	return {m_r * other.m_r, m_g * other.m_g, m_b * other.m_b, m_a * other.m_a};
}

Colour Colour::Divide(const Colour &other) const
{
	return {m_r / other.m_r, m_g / other.m_g, m_b / other.m_b, m_a / other.m_a};
}

Colour Colour::Scale(const float &scalar) const
{
	return {m_r * scalar, m_g * scalar, m_b * scalar, m_a * scalar};
}

Colour Colour::Lerp(const Colour &other, const float &progression) const
{
	auto ta{*this * (1.0f - progression)};
	auto tb{other * progression};
	return ta + tb;
}

Colour Colour::Normalize() const
{
	auto l{Length()};

	if (l == 0.0f)
	{
		throw std::runtime_error{"Can't normalize a zero length vector"};
	}

	return {m_r / l, m_g / l, m_b / l, m_a / l};
}

float Colour::LengthSquared() const
{
	return m_r * m_r + m_g * m_g + m_b * m_b + m_a * m_a;
}

float Colour::Length() const
{
	return std::sqrt(LengthSquared());
}

Colour Colour::SmoothDamp(const Colour &target, const Colour &rate) const
{
	return Maths::SmoothDamp(*this, target, rate);
}

Colour Colour::GetUnit() const
{
	auto l{Length()};
	return {m_r / l, m_g / l, m_b / l, m_a / l};
}

std::string Colour::GetHex() const
{
	std::stringstream stream;
	stream << "#";

	auto hexValue = ((static_cast<uint32_t>(m_r * 255.0f) & 0xff) << 16) +
		((static_cast<uint32_t>(m_g * 255.0f) & 0xff) << 8) +
		((static_cast<uint32_t>(m_b * 255.0f) & 0xff) << 0);
	stream << std::hex << std::setfill('0') << std::setw(6) << hexValue;

	return stream.str();
}

bool Colour::operator==(const Colour &other) const
{
	return m_r == other.m_r && m_g == other.m_g && m_b == other.m_b && m_a == other.m_a;
}

bool Colour::operator!=(const Colour &other) const
{
	return !(*this == other);
}

const float &Colour::operator[](const uint32_t &index) const
{
	switch (index)
	{
	case 0:
		return m_r;
	case 1:
		return m_g;
	case 2:
		return m_b;
	case 3:
		return m_a;
	default:
		throw std::runtime_error{"Colour index out of bounds!"};
	}
}

float &Colour::operator[](const uint32_t &index)
{
	switch (index)
	{
	case 0:
		return m_r;
	case 1:
		return m_g;
	case 2:
		return m_b;
	case 3:
		return m_a;
	default:
		throw std::runtime_error{"Colour index out of bounds!"};
	}
}

Colour operator+(const Colour &left, const Colour &right)
{
	return left.Add(right);
}

Colour operator-(const Colour &left, const Colour &right)
{
	return left.Subtract(right);
}

Colour operator*(const Colour &left, const Colour &right)
{
	return left.Multiply(right);
}

Colour operator/(const Colour &left, const Colour &right)
{
	return left.Divide(right);
}

Colour operator+(const float &value, const Colour &left)
{
	return Colour{value, value, value, 0.0f}.Add(left);
}

Colour operator-(const float &value, const Colour &left)
{
	return Colour{value, value, value, 0.0f}.Subtract(left);
}

Colour operator*(const float &value, const Colour &left)
{
	return Colour{value, value, value}.Multiply(left);
}

Colour operator/(const float &value, const Colour &left)
{
	return Colour{value, value, value}.Divide(left);
}

Colour operator+(const Colour &left, const float &value)
{
	return left.Add({value, value, value, 0.0f});
}

Colour operator-(const Colour &left, const float &value)
{
	return left.Subtract({value, value, value, 0.0f});
}

Colour operator*(const Colour &left, const float &value)
{
	return left.Multiply({value, value, value});
}

Colour operator/(const Colour &left, const float &value)
{
	return left.Divide({value, value, value});
}

Colour &Colour::operator+=(const Colour &other)
{
	return *this = Add(other);
}

Colour &Colour::operator-=(const Colour &other)
{
	return *this = Subtract(other);
}

Colour &Colour::operator*=(const Colour &other)
{
	return *this = Multiply(other);
}

Colour &Colour::operator/=(const Colour &other)
{
	return *this = Divide(other);
}

Colour &Colour::operator+=(const float &value)
{
	return *this = Add({value, value, value, 0.0f});
}

Colour &Colour::operator-=(const float &value)
{
	return *this = Subtract({value, value, value, 0.0f});
}

Colour &Colour::operator*=(const float &value)
{
	return *this = Multiply({value, value, value});
}

Colour &Colour::operator/=(const float &value)
{
	return *this = Divide({value, value, value});
}

const Metadata &operator>>(const Metadata &metadata, Colour &colour)
{
	// Loads from hex if RGBA is not provided.
	if (metadata.GetChildren().empty())
	{
		std::string hex;
		metadata >> hex;
		colour = hex;
	}
	else
	{
		metadata.GetChild("r", colour.m_r);
		metadata.GetChild("g", colour.m_g);
		metadata.GetChild("b", colour.m_b);
		metadata.GetChild("a", colour.m_a);
	}

	return metadata;
}

Metadata &operator<<(Metadata &metadata, const Colour &colour)
{
	//metadata << colour.GetHex();
	metadata.SetChild("r", colour.m_r);
	metadata.SetChild("g", colour.m_g);
	metadata.SetChild("b", colour.m_b);
	metadata.SetChild("a", colour.m_a);
	return metadata;
}

std::ostream &operator<<(std::ostream &stream, const Colour &colour)
{
	return stream << colour.m_r << ", " << colour.m_g << ", " << colour.m_b << ", " << colour.m_a;
}
}
