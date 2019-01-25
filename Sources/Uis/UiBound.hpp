#pragma once

#include "Maths/Vector2.hpp"

namespace acid
{
	/// <summary>
	/// A rectangle made of a position and dimension.
	/// </summary>
	class ACID_EXPORT UiBound
	{
	public:
		/// <summary>
		/// Constructor for rectangle.
		/// </summary>
		/// <param name="position"> The object screen position. </param>
		/// <param name="reference"> The reference pivot vertex (<seealso cref="#TopLeft"/>, <seealso cref="#CentreLeft"/>, <seealso cref="#BottomLeft"/>, ETC). </param>
		/// <param name="aspectPosition"> The if the x position will change with display width. </param>
		/// <param name="aspectSize"> The if the width will scale with display width. </param>
		/// <param name="dimensions"> The object dimensions. </param>
		explicit UiBound(const Vector2 &position = Vector2(0.0f, 0.0f), const Vector2 &reference = TopLeft, const bool &aspectPosition = true, const bool &aspectSize = true, const Vector2 &dimensions = Vector2(1.0f, 1.0f));

		/// <summary>
		/// Gets the bounds position in the current screen space.
		/// </summary>
		/// <returns> The position in screen space. </returns>
		Vector2 GetScreenPosition(const float &aspectRatio) const;

		/// <summary>
		/// Gets the bounds dimensions in the current screen space.
		/// </summary>
		/// <returns> The dimensions in screen space. </returns>
		Vector2 GetScreenDimensions(const float &aspectRatio) const;

		const Vector2 &GetPosition() const { return m_position; }

		void SetPosition(const Vector2 &position) { m_position = position; }

		const Vector2 &GetReference() const { return m_reference; }

		void SetReference(const Vector2 &reference) { m_reference = reference; }

		const bool &IsAspectPosition() const { return m_aspectPosition; }

		void SetAspectPosition(const bool &aspectPosition) { m_aspectPosition = aspectPosition; }

		const bool &IsAspectSize() const { return m_aspectSize; }

		void SetAspectSize(const bool &aspectSize) { m_aspectSize = aspectSize; }

		const Vector2 &GetDimensions() const { return m_dimensions; }

		void SetDimensions(const Vector2 &dimensions) { m_dimensions = dimensions; }

		bool operator==(const UiBound &other) const;

		bool operator!=(const UiBound &other) const;

		static const Vector2 TopLeft;
		static const Vector2 TopCentre;
		static const Vector2 TopRight;
		static const Vector2 CentreLeft;
		static const Vector2 Centre;
		static const Vector2 CentreRight;
		static const Vector2 BottomLeft;
		static const Vector2 BottomCentre;
		static const Vector2 BottomRight;

		static const UiBound Screen;

		Vector2 m_position;
		Vector2 m_reference;
		bool m_aspectPosition;
		bool m_aspectSize;
		Vector2 m_dimensions;
	};
}
