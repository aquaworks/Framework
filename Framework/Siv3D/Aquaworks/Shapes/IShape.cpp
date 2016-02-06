# include "IShape.hpp"

# include "Sphere.hpp"

namespace Aquaworks
{
	namespace Shapes
	{
		ShapePtr IShape::Empty()
		{
			return std::make_shared<IShape>(Transform::Pose::Identity());
		}

		IShape::IShape(Transform::Pose const& origin)
			: origin(origin)
		{

		}

		void IShape::Repose(Transform::Pose const& pose)
		{
			this->origin = pose;
		}

		ShapePtr IShape::Reshape(Transform::Pose const& pose) const
		{
			return std::make_shared<IShape>(origin * pose);
		}

		void IShape::Render(Transform::Vector4 const& color) const
		{
			(void)color;
		}

		ShapePtr IShape::BoundingSphere() const
		{
			Transform::Pose pose;
			pose.Move(origin.position);
			return std::make_shared<Sphere>(pose, 0.0f);
		}

		bool IShape::Intersects(ShapePtr const& shape) const
		{
			return shape->Intersects(*this);
		}

		bool IShape::Intersects(IShape const& shape) const
		{
			(void)shape;
			return false;
		}

		bool IShape::Intersects(Sphere const& shape) const
		{
			(void)shape;
			return false;
		}

		bool IShape::Intersects(Capsule const& shape) const
		{
			(void)shape;
			return false;
		}

		bool IShape::Intersects(Segment const& shape) const
		{
			(void)shape;
			return false;
		}

		bool IShape::Intersects(Mesh const& shape) const
		{
			(void)shape;
			return false;
		}
	}
}
