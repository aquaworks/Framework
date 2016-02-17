# include "Pose.hpp"

# pragma warning (push)
# pragma warning (disable : 4458)

namespace Aquaworks
{
	namespace Transform
	{
		Pose Pose::Identity()
		{
			static Pose identity;
			return identity;
		}

		Pose Pose::Empty()
		{
			static Pose empty { Vector3::Zero(), Quaternion::Identity(), Vector3::Zero() };
			return empty;
		}

		Pose::Pose()
			: position(Vector3::Zero())
			, rotation(Quaternion::Identity())
			, scaling(Vector3::One())
		{

		}

		Pose::Pose(Pose const& transform)
			: position(transform.position)
			, rotation(transform.rotation)
			, scaling(transform.scaling)
		{

		}

		Pose::Pose(Vector3 const& position, Quaternion const& rotation, Vector3 const& scaling)
			: position(position)
			, rotation(rotation)
			, scaling(scaling)
		{

		}

		Pose::Pose(Pose&& transform)
			: position(transform.position)
			, rotation(transform.rotation)
			, scaling(transform.scaling)
		{

		}

		Pose& Pose::operator = (Pose const& transform)
		{
			position = transform.position;
			rotation = transform.rotation;
			scaling = transform.scaling;
			return *this;
		}

		Pose Pose::Affine(Vector3 const& position, Quaternion const& rotation, Vector3 const& scaling)
		{
			return { position, rotation, scaling };
		}

		Pose Pose::Translate(Vector3 const& position)
		{
			return { position, Quaternion::Identity(), Vector3::One() };
		}

		Pose Pose::Rotate(Quaternion const& rotation)
		{
			return { Vector3::Zero(), rotation, Vector3::One() };
		}

		Pose Pose::Scale(Vector3 const& scaling)
		{
			return { Vector3::Zero(), Quaternion::Identity(), scaling };
		}

		Pose Pose::Translate(Pose const& pose, Vector3 const& position)
		{
			return Affine(pose.position + position, pose.rotation, pose.scaling);
		}

		Pose Pose::Rotate(Pose const& pose, Quaternion const& rotation)
		{
			return Affine(pose.position, pose.rotation * rotation, pose.scaling);
		}

		Pose Pose::Scale(Pose const& pose, Vector3 const& scaling)
		{
			return Affine(pose.position, pose.rotation, pose.scaling * scaling);
		}

		Matrix Pose::ToMatrix(Pose const& pose)
		{
			return Matrix::Transformation(pose.position, pose.rotation, pose.scaling);
		}

		Pose Pose::operator * (Pose const& other) const
		{
			return { this->position + other.position, this->rotation * other.rotation, this->scaling * other.scaling };
		}
		Vector3 operator * (Vector3 const& v, Pose const& pose)
		{
			return v * Pose::ToMatrix(pose);
		}
		Vector3& operator *= (Vector3& v, Pose const& pose)
		{
			return v *= Pose::ToMatrix(pose);
		}
	}
}

# pragma warning(pop)
