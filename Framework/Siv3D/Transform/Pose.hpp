# pragma once

# include "Vector3.hpp"
# include "Quaternion.hpp"

namespace Transform
{
	class Pose
	{
	public:

		static Pose Identity();

		static Pose Empty();

	public:

		Pose();

		Pose(Pose const& transform);

		Pose(Vector3 const& position, Quaternion const& rotation, Vector3 const& scaling);

		Pose(Pose&& transform);

		Pose& operator = (Pose const& transform);

	public:

		static Pose Affine(Vector3 const& position, Quaternion const& rotation, Vector3 const& scaling);

	public:

		Pose& Move(Vector3 const& translation);

		Pose& Rotate(Quaternion const& rotation);

		Pose& Scale(Vector3 const& scaling);

		Pose Moved(Vector3 const& translation) const;

		Pose Rotated(Quaternion const& rotation) const;

		Pose Scaled(Vector3 const& scaling) const;

	public:

		static Matrix ToMatrix(Pose const& pose);

	public:

		Pose operator * (Pose const& other) const;

	public:

		Vector3 position;
		Quaternion rotation;
		Vector3 scaling;
	};

	Vector3 operator * (Vector3 const& v, Pose const& pose);
	Vector3& operator *= (Vector3& v, Pose const& pose);
}
