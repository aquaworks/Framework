# include "Vector2.hpp"
# include "Vector3.hpp"
# include "Vector4.hpp"

void main()
{
	using namespace Transform;

	// Vector2D
	Point2 p2;
	Float2 f2;
	Vector2 v2;

	// Vector3D
	Point3 p3;
	Float3 f3;
	Vector3 v3;

	// Vector4D
	Point4 p4;
	Float4 f4;
	Vector4 v4;

	// Vector2D = Vector2D
	p2 = p2;
	p2 = f2;
	p2 = v2;
	f2 = p2;
	f2 = f2;
	f2 = v2;
	v2 = p2;
	v2 = f2;
	v2 = v2;

	// Vector3D = Vector3D
	p3 = p3;
	p3 = f3;
	p3 = v3;
	f3 = p3;
	f3 = f3;
	f3 = v3;
	v3 = p3;
	v3 = f3;
	v3 = v3;

	// Vector4D = Vector4D
	p4 = p4;
	p4 = f4;
	p4 = v4;
	f4 = p4;
	f4 = f4;
	f4 = v4;
	v4 = p4;
	v4 = f4;
	v4 = v4;

	// Vector3D = Vector4D
	p3 = p4;
	f3 = f4;
	v3 = v4;

	// Vector4D = Vector3D
	v4 = Point4(p3, 0);
	v4 = Float4(f3, 0.0f);
	v4 = Vector4(v3, 0.0);
}
