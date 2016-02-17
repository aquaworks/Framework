# pragma once

# include "Vector3.hpp"
# include "Quaternion.hpp"

namespace Aquaworks
{
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

			static Pose Translate(Vector3 const& position);
			static Pose Rotate(Quaternion const& rotation);
			static Pose Scale(Vector3 const& scaling);
			static Pose Translate(Pose const& pose, Vector3 const& position);
			static Pose Rotate(Pose const& pose, Quaternion const& rotation);
			static Pose Scale(Pose const& pose, Vector3 const& scaling);

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
}
