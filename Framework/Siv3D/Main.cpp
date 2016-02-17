# include <Siv3D.hpp>

# include "Aquaworks/Transform/Quaternion.hpp"
# include "Aquaworks/Shapes/Sphere.hpp"
# include "Aquaworks/Utility/Math.hpp"

# include "Aquaworks/Typedef.hpp"

void Main()
{
	using namespace Aquaworks;

	// 回転用クォータニオン
	Transform::Quaternion q = Transform::Quaternion::Rotation(Transform::Vector3::Up(), 0.0f);

	// 固定姿勢用クォータニオン
	Transform::Quaternion r = Transform::Quaternion::Rotation(Transform::Vector3::Right(), Utility::Math::Div2Pi);

	// 時間経過用変数
	f32 deltaTime = 0.0166667f;
	f32 elapsedTime = 0.0f;

	// モデル
	Shapes::ShapePtr shape = std::make_shared<Shapes::Sphere>(Transform::Pose::Identity(), 0.5f);

	// 回転用基準ベクトル
	Transform::Vector3 v { 0, 2, 0 };

	// 色
	Transform::Vector4 red { 1.0f, 0.0f, 0.0f, 1.0f };
	Transform::Vector4 blue { 0.0f, 0.0f, 1.0f, 1.0f };

	while (System::Update())
	{
		Graphics3D::FreeCamera();
		RenderAxis();

		// Repose
		q = Transform::Quaternion::Rotation(Transform::Vector3::Forward(), elapsedTime * Utility::Math::Pi);
		shape->Repose(Transform::Pose::Translate(v * q));
		shape->Render(red);

		// Repose
		r = Transform::Quaternion::Rotation(Transform::Vector3::Right(), elapsedTime * Utility::Math::Pi);
		shape->Repose(Transform::Pose::Translate(v * r));
		shape->Render(blue);

		elapsedTime += deltaTime;

		shape->Repose(Transform::Pose::Translate(v * Utility::Math::Lerp(q, r, 0.5f)));
		Transform::Vector4 color = Utility::Math::Lerp(red, blue, 0.5f);
		color.a = 1.0f;
		shape->Render(color);
	}
}

void RenderAxis()
{
	Line3D(Vec3::Zero, { 2.0, 0.0, 0.0 }).drawForward(Palette::Red);
	Line3D(Vec3::Zero, { 0.0, 2.0, 0.0 }).drawForward(Palette::Green);
	Line3D(Vec3::Zero, { 0.0, 0.0, 2.0 }).drawForward(Palette::Blue);
}
