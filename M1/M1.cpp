
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

	Vector(float num) = delete;

	Vector(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector(const Vector& other)
	{
		std::cout << "\n Copy constructor \n";
		x = other.x;
		y = other.y;
		z = other.z;
	}

	~Vector()
	{
		if (Info)
		{
			delete Info;
		}
	}

	Vector& operator=(Vector& other)
	{
		std::cout << " operator = ";
		x = other.x;
		y = other.y;
		z = other.z;

		if (other.Info)
		{
			if (Info) delete Info;
			Info = new std::string(*(other.Info));
		}

		return (*this);
	}

	operator float()
	{
		return sqrt(x * x + y * y + z * z);
	}

	friend Vector operator+(const Vector& a, const Vector& b);

	friend std::ostream& operator<<(std::ostream& out, const Vector& v);

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

	std::string* Info;
};

class Array
{
public:
	Array()
	{
		int Rows = 5;
		int Cols = 4;
		int** arr = new int* [Rows];

		for (int i = 0; i < Rows; i++)
		{
			arr[i] = new int[Cols];
		}
		//Заполнение массива
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				arr[i][j] = rand() % 9;
			}
		}
		//Вывод массива
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Cols; j++)
			{
				std::cout << arr[i][j] << "\t";
			}
			std::cout << "\n";
		}

		for (int i = 0; i < Rows; i++)
		{
			delete[] arr[i];
		}

		delete[] arr;
	}

	friend std::ostream& operator<<(std::ostream& out, const Array& a);
};

bool operator>(const Vector& a, const Vector& b)
{
	return false;
}

Vector operator+(const Vector& a, const Vector& b)
{
	return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
	out << ' ' << v.x << ' ' << v.y << ' ' << v.z;
	return out;
}

std::ostream& operator<<(std::ostream& out, const Array& a)
{
	return out;
}

int main()
{
	Vector v1(1, 1, 1);
	Vector v2(2, 2, 2);
	Vector v3;
	Array arr;
	std::cout << v2;
	v3 = v2 = v1;
	std::cout << v2;
	std::cout << arr;
}