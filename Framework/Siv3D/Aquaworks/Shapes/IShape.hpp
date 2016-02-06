# pragma once

# include "../Transform/Pose.hpp"

# include "ShapePtr.hpp"

namespace Aquaworks
{
	namespace Shapes
	{
		class Sphere;
		class Capsule;
		class Segment;
		class Mesh;

		class IShape
		{
		public:

			static ShapePtr Empty();

		public:

			IShape(Transform::Pose const& origin);

		public:

			void Repose(Transform::Pose const& pose);
			virtual ShapePtr Reshape(Transform::Pose const& pose) const;
			virtual void Render(Transform::Vector4 const& color = Transform::Vector4::One()) const;
			virtual ShapePtr BoundingSphere() const;

		public:

			virtual bool Intersects(ShapePtr const& shape) const;
			virtual bool Intersects(IShape const& shape) const;
			virtual bool Intersects(Sphere const& shape) const;
			virtual bool Intersects(Capsule const& shape) const;
			virtual bool Intersects(Segment const& shape) const;
			virtual bool Intersects(Mesh const& shape) const;

		public:

			Transform::Pose origin;
		};
	}
}
