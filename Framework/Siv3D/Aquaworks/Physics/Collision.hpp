# pragma once

# include <vector>

namespace Aquaworks
{
	namespace Transform
	{
		class Vector3;
	}

	namespace Shapes
	{
		class IShape;
		class Sphere;
		class Capsule;
		class Segment;
		class Mesh;
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

			bool SphereSphere(Shapes::Sphere const& sphere1, Shapes::Sphere const& sphere2);
			bool SphereCapsule(Shapes::Sphere const& sphere, Shapes::Capsule const& capsule);
			bool SphereSegment(Shapes::Sphere const& sphere, Shapes::Segment const& segment);
			bool SphereMesh(Shapes::Sphere const& sphere, Shapes::Mesh const& mesh);

			bool CapsuleCapsule(Shapes::Capsule const& capsule1, Shapes::Capsule const& capsule2);
			bool CapsuleSegment(Shapes::Capsule const& capsule, Shapes::Segment const& segment);
			bool CapsuleMesh(Shapes::Capsule const& capsule, Shapes::Mesh const& mesh);

			bool SegmentSegment(Shapes::Segment const& segment1, Shapes::Segment const& segment2);
			bool SegmentMesh(Shapes::Segment const& segment, Shapes::Mesh const& mesh);

			bool MeshMesh(Shapes::Mesh const& mesh1, Shapes::Mesh const& mesh2);
		}
	}
}
