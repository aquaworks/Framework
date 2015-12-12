# include <Siv3D.hpp>

# include "Shape/Sphere.hpp"
# include "Shape/Mesh.hpp"
# include "Shape/Segment.hpp"
# include "Shape/Capsule.hpp"

template <typename Type>
Type Lerp(Type const& begin, Type const& end, double t)
{
	return begin + (end - begin) * t;
}

void Main()
{
	Shape::ShapePtr capsule = std::make_shared<Shape::Capsule>(
		Transform::Pose::Identity(), Transform::Vector3(0.0f, 1.0f, 0.0f), Transform::Vector3(0.0f, -1.0f, 0.0f), 1.0f);

	Shape::ShapePtr sphere = std::make_shared<Shape::Sphere>(
		Transform::Pose::Identity(), 1.0f);

	Shape::ShapePtr segment = std::make_shared<Shape::Segment>(
		Transform::Pose::Identity(), Transform::Vector3(-1.0f, 0.0f, 0.0f), Transform::Vector3(1.0f, 0.0f, 0.0f));

	std::vector<Transform::Vector3> vertices =
	{
		{ -1.0f, -1.0f, 0.0f },
		{ -1.0f, 1.0f, 0.0f },
		{ 1.0f, 1.0f, 0.0f },
		{ 1.0f, -1.0f, 0.0f },
	};
	std::vector<size_t> indices =
	{
		0, 1, 2,
		3, 0, 2,
	};
	Shape::ShapePtr mesh = std::make_shared<Shape::Mesh>(
		Transform::Pose::Identity(), vertices, indices);

	Shape::ShapePtr empty = Shape::IShape::Empty();

	Shape::ShapePtr box = Shape::Mesh::Box({ 1.0f, 1.0f, 1.0f });

	Shape::ShapePtr plane = Shape::Mesh::Plane({ 1.0f, 1.0f });

	Shape::ShapePtr shape = empty;

	while (s3d::System::Update())
	{
		if (s3d::Input::Key1.clicked)
		{
			shape = capsule;
		}
		if (s3d::Input::Key2.clicked)
		{
			shape = sphere;
		}
		if (s3d::Input::Key3.clicked)
		{
			shape = segment;
		}
		if (s3d::Input::Key4.clicked)
		{
			shape = mesh;
		}
		if (s3d::Input::Key5.clicked)
		{
			shape = box;
		}
		if (s3d::Input::Key6.clicked)
		{
			shape = plane;
		}
		if (s3d::Input::Key7.clicked)
		{
			shape = empty;
		}

		s3d::Graphics3D::FreeCamera();

		shape->Render();
	}
}
