# include "Utility/Console.hpp"

# include "Transform/Point2.hpp"
# include "Transform/Point3.hpp"
# include "Transform/Point4.hpp"
# include "Transform/Vector2.hpp"
# include "Transform/Vector3.hpp"
# include "Transform/Vector4.hpp"
# include "Transform/Matrix.hpp"
# include "Transform/Quaternion.hpp"
# include "Transform/Pose.hpp"

# include <string>

using namespace Utility;
using namespace Transform;

void main()
{
	std::string str = "���Ƃ��";
	int i = 123;
	float f = 1.08f;
	double d = 3.141592;
	const wchar_t* wstr = L"�킢�ǂ������";

	Point2 p2;
	Point3 p3;
	Point4 p4;
	Vector2 v2;
	Vector3 v3;
	Vector4 v4;
	Matrix m;
	Quaternion q;
	Pose p;

	Console::Println(" --- ��̏o�� ---");
	Console::Println();

	Console::Println(" --- �g�ݍ��݌^�o�� ---");
	Console::Println(str);
	Console::Println(i);
	Console::Println(f);
	Console::Println(d);
	Console::Println(wstr);

	Console::Println(" --- ���[�U�[��`�^�o�� ---");
	Console::Println(p2);
	Console::Println(p3);
	Console::Println(p4);
	Console::Println(v2);
	Console::Println(v3);
	Console::Println(v4);
	Console::Println(m);
	Console::Println(q);
	Console::Println(p);

	Console::Println(" --- �A���o�� ---");
	Console::Println(str, i, f, d, wstr);
}
