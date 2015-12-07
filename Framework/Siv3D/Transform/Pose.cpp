#include "Pose.hpp"

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
		return *this;
	}

	Pose Pose::Affine(Vector3 const& position, Quaternion const& rotation, Vector3 const& scaling)
	{
		return { position, rotation, scaling };
	}

	Pose& Pose::Move(Vector3 const& translation)
	{
		return *this = Moved(translation);
	}

	Pose& Pose::Rotate(Quaternion const& rotation)
	{
		return *this = Rotated(rotation);
	}

	Pose& Pose::Scale(Vector3 const& scaling)
	{
		return *this = Scaled(scaling);
	}

	Pose Pose::Moved(Vector3 const& translation) const
	{
		return { position + translation, rotation, scaling };
	}

	Pose Pose::Rotated(Quaternion const& rotation) const
	{
		return { position, rotation * rotation, scaling };
	}

	Pose Pose::Scaled(Vector3 const& scaling) const
	{
		return { position, rotation, scaling * scaling };
	}

	Matrix Pose::ToMatrix() const
	{
		return Matrix::Scaling(scaling) * Quaternion::ToMatrix(rotation) * Matrix::Translation(position);
	}

	Pose Pose::operator * (Pose const& other)
	{
		return { this->position + other.position, this->rotation * other.rotation, this->scaling * other.scaling };
	}
}
