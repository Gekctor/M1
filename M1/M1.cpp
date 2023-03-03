
#include <iostream>
#include <cmath>

class Vector
{
public:

	Vector()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	
	operator float()
	{
		return sqrt(x * x + y * y + z * z);
	}

	friend Vector operator+(const Vector& a, const Vector& b);

	friend Vector operator-(const Vector& a, const Vector& b);

	friend Vector operator*(const Vector& a, const float c);

	friend std::ostream& operator<<(std::ostream& out, const Vector& v);

	friend std::istream& operator>>(std::istream& in, Vector& v);

	friend bool operator>(const Vector& a, const Vector& b);

	float operator[](int index)
	{
		switch (index)
		{
			case 0:
				return x;
				break;
			case 1:
				return y;
				break;
			case 2:
				return z;
				break;
			default:
				std::cout << "index error";
				return 0;
				break;
		}
	}

private:
	float x;
	float y;
	float z;
	float c;
};

bool operator>(const Vector& a, const Vector& b)
{
	return false;
}

Vector operator+(const Vector& a, const Vector& b)
{
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector operator-(const Vector& a, const Vector& b)
{
	return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector operator*(const Vector& a, const float c)
{
	return Vector(a.x * c, a.y * c, a.z * c);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	out << ' ' << v.x << ' ' << v.y << ' ' << v.z;
	return out;
}

std::istream& operator>>(std::istream& in, Vector& v)
{
	std::cout << ' ' << "Enter x, y and z values, and press Enter" << '\n';
	in >> v.x >> v.y >> v.z;
	return in;
}

int main()
{
	Vector v1(0, 1, 2);
	Vector v2(3, 4, 5);
	Vector v3;
	Vector v4;
	Vector v5;
	Vector v6;
	float c = 2;
	v3 = v1 + v2;
	v4 = v1 * c;
	v5 = v1 - v2;
	std::cin >> v6;
	std::cout << v3 << '\n';
	std::cout << "v3 lenght " << static_cast<float>(v3) << '\n';
	std::cout << v4 << '\n';
	std::cout << v5 << '\n';
	std::cout << v6;
}