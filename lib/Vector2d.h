#ifndef VECTOR2D
#define VECTOR2D

#include <string>

class Vector2d {
	private:
		static bool approximatelyEqual(int a, int b) {
			return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * 0.00001));
		}
	public:
		int x {};
		int y {};

		Vector2d(int x = 0.0, int y = 0.0);
		Vector2d(Vector2d& vector);
		Vector2d& set(Vector2d vector);
		Vector2d& operator=(Vector2d& vector);
		Vector2d& operator=(Vector2d vector);
		friend bool operator==(const Vector2d& vectorA, const Vector2d& vectorB);

		Vector2d operator-() const;

		double length() const;
		Vector2d normal() const;
		Vector2d normalize() const;
		int dot(Vector2d& vector) const;
		int cross(Vector2d& vector) const;

		std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const Vector2d& vector);
};
Vector2d operator+(const Vector2d& vectorA, const Vector2d& vectorB);
Vector2d operator+(const Vector2d& vector, const int scalar);
Vector2d operator+(const int scalar, const Vector2d& vector);
Vector2d& operator+=(Vector2d& vectorA, const Vector2d& vectorB);

Vector2d operator-(const Vector2d& vectorA, const Vector2d& vectorB);
Vector2d operator-(const Vector2d& vector, const int scalar);
Vector2d operator-(const int scalar, const Vector2d& vector);
Vector2d& operator-=(Vector2d& vectorA, const Vector2d& vectorB);

Vector2d operator*(const Vector2d& vectorA, const Vector2d& vectorB);
Vector2d operator*(const Vector2d& vector, const int scalar);
Vector2d operator*(const int scalar, const Vector2d& vector);

Vector2d operator/(const Vector2d& vectorA, const Vector2d& vectorB);
Vector2d operator/(const Vector2d& vector, const int scalar);
Vector2d operator/(const int scalar, const Vector2d& vector);

#endif
