# include <Siv3D.hpp>

# include "Transform/Transform.hpp"
# include "Shapes/Shapes.hpp"

void Main()
{
	using namespace Shapes;
	using namespace Transform;

	Pose pose = Pose::Identity();

	ShapePtr sphere = std::make_shared<Shapes::Sphere>(pose, 1.0f);
	ShapePtr capsule = std::make_shared<Shapes::Capsule>(pose, Vector3(0.0f, 2.5f, 0.0f), Vector3(0.0f, -2.5f, 0.0f), 0.5f);
	ShapePtr segment = std::make_shared<Shapes::Segment>(pose, Vector3(0.0f, 2.5f, 0.0f), Vector3(0.0f, -2.5f, 0.0f));
	ShapePtr mesh = Shapes::Mesh::BoxNormal({ 0.5f, 0.5f, 0.5f });

	ShapePtr own = mesh->Reshape(Pose::Identity());
	ShapePtr other = capsule->Reshape(Pose::Identity());

	while (System::Update())
	{
		bool isIntersects = own->Intersects(other);

		if (Input::KeyA.pressed)
		{
			pose.Move(Vector3::Left() * 0.1f);
		}
		if (Input::KeyD.pressed)
		{
			pose.Move(Vector3::Right() * 0.1f);
		}
		if (Input::KeyE.pressed)
		{
			pose.Move(Vector3::Up() * 0.1f);
		}
		if (Input::KeyX.pressed)
		{
			pose.Move(Vector3::Down() * 0.1f);
		}
		if (Input::KeyW.pressed)
		{
			pose.Move(Vector3::Forward() * 0.1f);
		}
		if (Input::KeyS.pressed)
		{
			pose.Move(Vector3::Backward() * 0.1f);
		}

		other->Repose(pose);

		own->Render();
		Vector4 color = isIntersects ? Vector4(1.0f, 0.0f, 0.0f, 1.0f) : Vector4(0.0f, 1.0f, 0.0f, 1.0f);
		other->Render(color);
	}
}
