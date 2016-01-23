# include "Transform/Vector3.hpp"
# include "Utility/Math.hpp"

# include <Siv3D.hpp>

void Main()
{
	const Font font { 32 };

	while (System::Update())
	{
		Transform::Vector3 v { 10.0f, 0.0f, 0.0f };
		v = Transform::Vector3::Rotate(v, Transform::Vector3::Forward(), Utility::Math::ToRadian(90.0));
		font(Transform::Vector3::ToString(v)).draw();
	}
}
