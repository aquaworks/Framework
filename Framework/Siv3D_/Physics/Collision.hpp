# pragma once

# include <vector>

namespace Transform
{
	class Vector3;
}

namespace Utility
{
	template <typename Type>
	class Optional;
}

namespace Physics
{
	namespace Collision
	{
		bool SphereSphere(Transform::Vector3 const& center1, float radius1, Transform::Vector3 const& center2, float radius2);
		bool SpherePlane(Transform::Vector3 const& center, float radius, Transform::Vector3 const& normal, float distance);
		bool SphereSegment(Transform::Vector3 const& center, float radius, Transform::Vector3 const& begin, Transform::Vector3 const& end);
		bool SegmentPlane(Transform::Vector3 const& begin, Transform::Vector3 const& end, Transform::Vector3 const& normal, float distance);
		bool SegmentSegment(Transform::Vector3 const& begin1, Transform::Vector3 const& end1, Transform::Vector3 const& begin2, Transform::Vector3 const& end2, float distance);
		bool CapsuleCapsule(Transform::Vector3 const& begin1, Transform::Vector3 const& end1, float radius1, Transform::Vector3 const& begin2, Transform::Vector3 const& end2, float radius2);
		bool CapsulePlane(Transform::Vector3 const& begin, Transform::Vector3 const& end, float radius, Transform::Vector3 const& normal, float distance);

		Utility::Optional<float> RatioSegmentPlane(Transform::Vector3 const& begin, Transform::Vector3 const& end, Transform::Vector3 const& normal, float distance);
		bool PolygonInside(std::vector<Transform::Vector3> const& vertices, Transform::Vector3 const& point);
	}
}
