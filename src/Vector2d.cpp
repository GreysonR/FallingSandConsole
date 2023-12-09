#include <iostream>
#include <cmath>
#include "Vector2d.h"
#include <string>

// Constructors and equality
Vector2d::Vector2d(double x, double y) {
	this->x = x;
	this->y = y;
}
Vector2d::Vector2d(Vector2d& vector) {
	this->x = vector.x;
	this->y = vector.y;
}
Vector2d& Vector2d::set(Vector2d vector) {
	this->x = vector.x;
	this->y = vector.y;
	return *this;
}
bool operator==(const Vector2d& vectorA, const Vector2d& vectorB) {
	return Vector2d::approximatelyEqual(vectorA.x, vectorB.x) && Vector2d::approximatelyEqual(vectorA.y, vectorB.y);
}

// Addition
Vector2d operator+(const Vector2d& vectorA, const Vector2d& vectorB) {
	return { vectorA.x + vectorB.x, vectorA.y + vectorB.y };
}
Vector2d operator+(const Vector2d& vector, const double scalar) {
	return { vector.x + scalar, vector.y + scalar };
}
Vector2d operator+(const double scalar, const Vector2d& vector) {
	return vector + scalar;
}
Vector2d& operator+=(Vector2d& vectorA, const Vector2d& vectorB) {
	vectorA.x += vectorB.x;
	vectorA.y += vectorB.y;
	return vectorA;
}

// Subtraction and negatives
Vector2d operator-(const Vector2d& vectorA, const Vector2d& vectorB) {
	return { vectorA.x - vectorB.x, vectorA.y - vectorB.y };
}
Vector2d operator-(const Vector2d& vector, const double scalar) {
	return { vector.x - scalar, vector.y - scalar };
}
Vector2d operator-(const double scalar, const Vector2d& vector) {
	return vector - scalar;
}
Vector2d& operator-=(Vector2d& vectorA, const Vector2d& vectorB) {
	vectorA.x -= vectorB.x;
	vectorA.y -= vectorB.y;
	return vectorA;
}
Vector2d Vector2d::operator-() const {
	return { -this->x, -this->y };
}

// Multiplication
Vector2d operator*(const Vector2d& vectorA, const Vector2d& vectorB) {
	return { vectorA.x * vectorB.x, vectorA.y * vectorB.y };
}
Vector2d operator*(const Vector2d& vector, const double scalar) {
	return { vector.x * scalar, vector.y * scalar };
}
Vector2d operator*(const double scalar, const Vector2d& vector) {
	return vector * scalar;
}

// Division
Vector2d operator/(const Vector2d& vectorA, const Vector2d& vectorB) {
	return { vectorA.x / vectorB.x, vectorA.y / vectorB.y };
}
Vector2d operator/(const Vector2d& vector, const double scalar) {
	return vector * (1 / scalar);
}
Vector2d operator/(const double scalar, const Vector2d& vector) {
	return { scalar / vector.x, scalar / vector.y };
}

// Vector specific math
double Vector2d::length() const {
	return sqrt(this->x * this->x + this->y * this->y);
}
Vector2d Vector2d::normal() const {
	return { this->y, -this->x };
}
Vector2d Vector2d::normalize() const {
	double length = this->length();
	if (length == 0) {
		length = 1;
	}
	return { this->x / length, this->y / length };
}
double Vector2d::dot(Vector2d& vector) const {
	return this->x * vector.x + this->y * vector.y;
}
double Vector2d::cross(Vector2d& vector) const {
	return this->x * vector.y - this->y * vector.x;
}

// Printing
std::string Vector2d::toString() const {
	return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
}
std::ostream& operator<<(std::ostream& out, const Vector2d& vector) {
	out << vector.toString();
	return out;
}
