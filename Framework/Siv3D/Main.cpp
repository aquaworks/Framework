# include <Siv3D.hpp>

# include "Shape/Sphere.hpp"
# include "Shape/Mesh.hpp"
# include "Shape/Segment.hpp"
# include "Shape/Capsule.hpp"

# include "Utility/Math.hpp"
# include "Utility/Easing.hpp"

template <typename Type>
Type Lerp(Type const& begin, Type const& end, double t)
{
	return begin + (end - begin) * t;
}

void Main()
{
	Shape::ShapePtr capsule = std::make_shared<Shape::Capsule>(
		Transform::Pose::Identity(), Transform::Vector3(0.0f, 0.0f, 0.0f), Transform::Vector3(0.0f, 0.0f, 0.0f), 1.0f);

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

	Shape::ShapePtr box = Shape::Mesh::BoxNormal({ 1.0f, 1.0f, 1.0f });

	Shape::ShapePtr plane = Shape::Mesh::Plane({ 1.0f, 1.0f });

	Shape::ShapePtr shape = empty;

	Transform::Pose pose = Transform::Pose::Identity();

	double t = 0.0;
	double delta = 0.0166667;

	while (s3d::System::Update())
	{
		// Update

		// camera
		s3d::Graphics3D::FreeCamera();

		// shape
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

		// pose
		pose.Rotate(Transform::Quaternion::Rotation(Transform::Vector3::Right(), Utility::Math::ToRadian(1.0)));
		Transform::Vector3 begin { -3.0f, 0.0f, 0.0f };
		Transform::Vector3 end { +3.0f, 0.0f, 0.0f };
		Transform::Vector3 pos = begin + (end - begin) * (float)Utility::EaseSine::InOut(t);
		Transform::Pose origin = pose.Moved(pos);
		origin = pose;

		// timer
		t += delta;
		if (t > 1.0)
		{
			t = 1.0;
			delta *= -1.0;
		}
		if (0.0 < t)
		{
			t = 0.0;
			delta *= -1.0;
		}

		// Render
		// shape
		auto reshape = shape->Reshape(origin);
		auto rasterizer = s3d::Graphics3D::GetRasterizerState();
		rasterizer = s3d::RasterizerState::WireframeNone;
		s3d::Graphics3D::SetRasterizerState(rasterizer);
		reshape->Render();
		rasterizer = s3d::RasterizerState::Default3D;
		s3d::Graphics3D::SetRasterizerState(rasterizer);

		// bounding sphere
		rasterizer = s3d::Graphics3D::GetRasterizerState();
		rasterizer = s3d::RasterizerState::WireframeNone;
		s3d::Graphics3D::SetRasterizerState(rasterizer);
		reshape->BoundingSphere()->Render(Transform::Vector4(0.0f, 1.0f, 0.0f, 0.5f));
		rasterizer = s3d::RasterizerState::Default3D;
		s3d::Graphics3D::SetRasterizerState(rasterizer);
	}
}
