#pragma once

#include "maths.hpp"

namespace Flounder
{
	class vector3;

	/// <summary>
	/// Holds a 2-tuple vector.
	/// </summary>
	class vector2
	{
	public:
		float m_x, m_y;

		/// <summary>
		/// Constructor for vector2.
		/// </summary>
		vector2();

		/// <summary>
		/// Constructor for vector2.
		/// </summary>
		/// <param name="x"> Start x. </param>
		/// <param name="y"> Start y. </param>
		vector2(const float &x, const float &y);

		/// <summary>
		/// Constructor for vector2.
		/// </summary>
		/// <param name="source"> Creates this vector out of a existing one. </param>
		vector2(const vector2 &source);

		/// <summary>
		/// Constructor for vector2.
		/// </summary>
		/// <param name="source"> Creates this vector out of a existing one. </param>
		vector2(const vector3 &source);

		/// <summary>
		/// Deconstructor for vector2.
		/// </summary>
		~vector2();

		/// <summary>
		/// Sets values in the vector.
		/// </summary>
		/// <param name="x"> The new X value. </param>
		/// <param name="y"> The new Y value. </param>
		/// <returns> This. </returns>
		vector2 *set(const float &x, const float &y);

		/// <summary>
		/// Loads from another vector2.
		/// </summary>
		/// <param name="source"> The source vector. </param>
		/// <returns> This. </returns>
		vector2 *set(const vector2 &source);

		/// <summary>
		/// Loads from another vector2.
		/// </summary>
		/// <param name="source"> The source vector. </param>
		/// <returns> This. </returns>
		vector2 *set(const vector3 &source);

		/// <summary>
		/// Adds two vectors together and places the result in the destination vector.
		/// </summary>
		/// <param name="left"> The left source vector. </param>
		/// <param name="right"> The right source vector. </param>
		/// <param name="destination"> The destination vector or nullptr if a new vector is to be created. </param>
		/// <returns> The destination vector. </returns>
		static vector2 *add(const vector2 &left, const vector2 &right, vector2 *destination);

		/// <summary>
		/// Subtracts two vectors from each other and places the result in the destination vector.
		/// </summary>
		/// <param name="left"> The left source vector. </param>
		/// <param name="right"> The right source vector. </param>
		/// <param name="destination"> The destination vector or nullptr if a new vector is to be created. </param>
		/// <returns> The destination vector. </returns>
		static vector2 *subtract(const vector2 &left, const vector2 &right, vector2 *destination);

		/// <summary>
		/// Multiplies two vectors from each other and places the result in the destination vector.
		/// </summary>
		/// <param name="left"> The left source vector. </param>
		/// <param name="right"> The right source vector. </param>
		/// <param name="destination"> The destination vector or nullptr if a new vector is to be created. </param>
		/// <returns> The destination vector. </returns>
		static vector2 *multiply(const vector2 &left, const vector2 &right, vector2 *destination);

		/// <summary>
		/// Divides two vectors from each other and places the result in the destination vector.
		/// </summary>
		/// <param name="left"> The left source vector. </param>
		/// <param name="right"> The right source vector. </param>
		/// <param name="destination"> The destination vector or nullptr if a new vector is to be created. </param>
		/// <returns> The destination vector. </returns>
		static vector2 *divide(const vector2 &left, const vector2 &right, vector2 *destination);

		/// <summary>
		/// Calculates the angle between two vectors.
		/// </summary>
		/// <param name="left"> The left source vector. </param>
		/// <param name="right"> The right source vector. </param>
		/// <returns> The angle between the two vectors, in radians. </returns>
		static float angle(const vector2 &left, const vector2 &right);

		/// <summary>
		/// Calculates the dot product of the two vectors.
		/// </summary>
		/// <param name="left"> The left source vector. </param>
		/// <param name="right"> The right source vector. </param>
		/// <returns> Left dot right. </returns>
		static float dot(const vector2 &left, const vector2 &right);

		/// <summary>
		/// Scales a vector by a scalar and places the result in the destination vector.
		/// </summary>
		/// <param name="source"> The source vector. </param>
		/// <param name="scalar"> The scalar value. </param>
		/// <param name="destination"> The destination vector or nullptr if a new vector is to be created. </param>
		/// <returns> The destination vector. </returns>
		static vector2 *scale(const vector2 &source, const float &scalar, vector2 *destination);

		/// <summary>
		/// Rotates a vector and places the result in the destination vector.
		/// </summary>
		/// <param name="source"> The source vector. </param>
		/// <param name="angle"> The angle to rotate by <b>in degrees</b>. </param>
		/// <param name="destination"> The destination vector or nullptr if a new vector is to be created. </param>
		/// <returns> The destination vector. </returns>
		static vector2 *rotate(const vector2 &source, const float &angle, vector2 *destination);

		/// <summary>
		/// Rotates a vector around a point and places the result in the destination vector.
		/// </summary>
		/// <param name="source"> The source vector. </param>
		/// <param name="angle"> The angle to rotate by <b>in degrees</b>. </param>
		/// <param name="rotationAxis"> The point to rotate the vector around. </param>
		/// <param name="destination"> The destination vector or nullptr if a new vector is to be created. </param>
		/// <returns> The destination vector. </returns>
		static vector2 *rotate(const vector2 &source, const float &angle, const vector2 &rotationAxis, vector2 *destination);

		/// <summary>
		/// Negates a vector and places the result in the destination vector.
		/// </summary>
		/// <param name="source"> The source vector. </param>
		/// <param name="destination"> The destination vector or nullptr if a new vector is to be created. </param>
		/// <returns> The destination vector. </returns>
		static vector2 *negate(const vector2 &source, vector2 *destination);

		/// <summary>
		/// Normalizes a vector and places the result in the destination vector.
		/// </summary>
		/// <param name="source"> The source vector. </param>
		/// <param name="destination"> The destination vector or nullptr if a new vector is to be created. </param>
		/// <returns> The destination vector. </returns>
		static vector2 *normalize(const vector2 &source, vector2 *destination);

		/// <summary>
		/// Gets the length of the vector.
		/// </summary>
		/// <param name="source"> The source vector. </param>
		/// <returns> The length of the vector. </returns>
		static float length(const vector2 &source);

		/// <summary>
		/// Gets the length of the vector.
		/// </summary>
		/// <param name="source"> The source vector. </param>
		/// <returns> The length squared of the vector. </returns>
		static float lengthSquared(const vector2 &source);

		/// <summary>
		/// Gets the maximum vector size.
		/// </summary>
		/// <param name="a"> The first vector to get values from. </param>
		/// <param name="b"> The second vector to get values from. </param>
		/// <param name="destination"> The destination vector or nullptr if a new vector is to be created. </param>
		/// <returns> The destination vector. </returns>
		static vector2 *maxVector(const vector2 &a, const vector2 &b, vector2 *destination);

		/// <summary>
		/// Gets the lowest vector size.
		/// </summary>
		/// <param name="a"> The first vector to get values from. </param>
		/// <param name="b"> The second vector to get values from. </param>
		/// <param name="destination"> The destination vector or nullptr if a new vector is to be created. </param>
		/// <returns> The destination vector. </returns>
		static vector2 *minVector(const vector2 &a, const vector2 &b, vector2 *destination);

		/// <summary>
		/// Gets the maximum value in a vector.
		/// </summary>
		/// <param name="vector"> The value to get the maximum value from. </param>
		/// <returns> The maximum value. </returns>
		static float maxComponent(const vector2 &vector);

		/// <summary>
		/// Gets the lowest value in a vector.
		/// </summary>
		/// <param name="vector"> The value to get the lowest value from. </param>
		/// <returns> The lowest value. </returns>
		static float minComponent(const vector2 &vector);

		/// <summary>
		/// Gets the distance between two points squared.
		/// </summary>
		/// <param name="point1"> The first point. </param>
		/// <param name="point2"> The second point. </param>
		/// <returns> The squared distance between the two points. </returns>
		static float getDistanceSquared(const vector2 &point1, const vector2 &point2);

		/// <summary>
		/// Gets the total distance between 2 vectors.
		/// </summary>
		/// <param name="point1"> The first point. </param>
		/// <param name="point2"> The second point. </param>
		/// <returns> The total distance between the points. </returns>
		static float getDistance(const vector2 &point1, const vector2 &point2);

		/// <summary>
		/// Gets the vector distance between 2 vectors.
		/// </summary>
		/// <param name="point1"> The first point. </param>
		/// <param name="point2"> The second point. </param>
		/// <param name="destination"> The destination vector or nullptr if a new vector is to be created. </param>
		/// <returns> The vector distance between the points. </returns>
		static vector2 *getVectorDistance(const vector2 &point1, const vector2 &point2, vector2 *destination);

		/// <summary>
		/// Gets if the pt (point) is in a triangle.
		/// </summary>
		/// <param name="point"> The point to check. </param>
		/// <param name="v1"> The first triangle vertex. </param>
		/// <param name="v2"> The second triangle vertex. </param>
		/// <param name="v3"> The third triangle vertex. </param>
		/// <returns> If the point is in a triangle. </returns>
		static bool pointInTriangle(const vector2 &point, const vector2 &v1, const vector2 &v2, const vector2 &v3);

		/// <summary>
		/// Translates this vector.
		/// </summary>
		/// <param name="x"> The translation in x. </param>
		/// <param name="y"> the translation in y. </param>
		/// <returns> This. </returns>
		vector2 *translate(const float &x, const float &y);

		/// <summary>
		/// Negates this vector.
		/// </summary>
		/// <returns> This. </returns>
		vector2 *negate();

		/// <summary>
		/// Normalizes this vector.
		/// </summary>
		/// <returns> This. </returns>
		vector2 *normalize();

		/// <summary>
		/// Scales this vector.
		/// </summary>
		/// <param name="scalar"> The scale factor. </param>
		/// <returns> This. </returns>
		vector2 *scale(const float &scalar);

		/// <summary>
		/// Gets if all the components to the vector are zero.
		/// </summary>
		/// <returns> If the vector is zero. </returns>
		bool isZero() const;

		/// <summary>
		/// Gets the length of the vector.
		/// </summary>
		/// <param name="source"> The source vector. </param>
		/// <returns> The length of the vector. </returns>
		float length() const;

		/// <summary>
		/// Gets the length squared of the vector.
		/// </summary>
		/// <param name="source"> The source vector. </param>
		/// <returns> The length squared of the vector. </returns>
		float lengthSquared() const;
	};
}
