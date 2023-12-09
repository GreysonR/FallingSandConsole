#ifndef VECTOR2D
#define VECTOR2D

#include <string>

class Vector2d {
	private:
		static bool approximatelyEqual(double a, double b) {
			return (std::abs(a - b) <= (std::max(std::abs(a), std::abs(b)) * 0.00001));
		}
	public:
		double x {};
		double y {};

		Vector2d(double x = 0.0, double y = 0.0);
		Vector2d(Vector2d& vector);
		Vector2d& set(Vector2d vector);
		friend bool operator==(const Vector2d& vectorA, const Vector2d& vectorB);

		Vector2d operator-() const;

		double length() const;
		Vector2d normal() const;
		Vector2d normalize() const;
		double dot(Vector2d& vector) const;
		double cross(Vector2d& vector) const;

		std::string toString() const;
		friend std::ostream& operator<<(std::ostream& out, const Vector2d& vector);
};
Vector2d operator+(const Vector2d& vectorA, const Vector2d& vectorB);
Vector2d operator+(const Vector2d& vector, const double scalar);
Vector2d operator+(const double scalar, const Vector2d& vector);
Vector2d& operator+=(Vector2d& vectorA, const Vector2d& vectorB);

Vector2d operator-(const Vector2d& vectorA, const Vector2d& vectorB);
Vector2d operator-(const Vector2d& vector, const double scalar);
Vector2d operator-(const double scalar, const Vector2d& vector);
Vector2d& operator-=(Vector2d& vectorA, const Vector2d& vectorB);

Vector2d operator*(const Vector2d& vectorA, const Vector2d& vectorB);
Vector2d operator*(const Vector2d& vector, const double scalar);
Vector2d operator*(const double scalar, const Vector2d& vector);

Vector2d operator/(const Vector2d& vectorA, const Vector2d& vectorB);
Vector2d operator/(const Vector2d& vector, const double scalar);
Vector2d operator/(const double scalar, const Vector2d& vector);

#endif
