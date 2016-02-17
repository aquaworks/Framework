# include <Siv3D.hpp>

# include "Aquaworks/Transform/Quaternion.hpp"
# include "Aquaworks/Shapes/Sphere.hpp"
# include "Aquaworks/Utility/Math.hpp"

void Main()
{
	using namespace Aquaworks;

	// 回転用クォータニオン
	Transform::Quaternion q = Transform::Quaternion::Rotation(Transform::Vector3::Up(), 0.0f);

	// 固定姿勢用クォータニオン
	Transform::Quaternion r = Transform::Quaternion::Rotation(Transform::Vector3::Right(), Utility::Math::Div2Pi);

	float deltaTime = 0.0166667f;
	float elapsedTime = 0.0f;

	// モデル
	Shapes::ShapePtr shape = std::make_shared<Shapes::Sphere>(Transform::Pose::Identity(), 0.5f);

	Transform::Vector3 v { 0, 2, 0 };

	GUI gui { GUIStyle::Default };
	gui.addln(L"Slider", GUISlider::Create(0.0, 1.0, 0.0));
	gui.show();

	Transform::Vector4 red { 1.0f, 0.0f, 0.0f, 1.0f };
	Transform::Vector4 blue { 0.0f, 0.0f, 1.0f, 1.0f };



	while (System::Update())
	{
		Graphics3D::FreeCamera();

		Line3D(Vec3::Zero, { 2.0, 0.0, 0.0 }).drawForward(Palette::Red);
		Line3D(Vec3::Zero, { 0.0, 2.0, 0.0 }).drawForward(Palette::Green);
		Line3D(Vec3::Zero, { 0.0, 0.0, 2.0 }).drawForward(Palette::Blue);

		q = Transform::Quaternion::Rotation(Transform::Vector3::Forward(), elapsedTime * Utility::Math::Pi);
		shape->Repose(Transform::Pose(v * q, Transform::Quaternion::Identity(), Transform::Vector3::One()));
		// shape->Render(red);

		r = Transform::Quaternion::Rotation(Transform::Vector3::Right(), elapsedTime * Utility::Math::Pi);
		shape->Repose(Transform::Pose(v * r, Transform::Quaternion::Identity(), Transform::Vector3::One()));
		// shape->Render(blue);

		float t = elapsedTime / 3;
		if (Utility::Math::Abs(elapsedTime) > 3)
		{
			deltaTime *= -1;
		}
		shape->Repose(Transform::Pose(v * Utility::Math::Lerp(q, r, t), Transform::Quaternion::Identity(), Transform::Vector3::One()));
		shape->Render(Utility::Math::Lerp(red, blue, t));

		elapsedTime += deltaTime;
	}
}
