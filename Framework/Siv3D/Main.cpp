
# include <Siv3D.hpp>

void Main()
{
	const s3d::Font font(30);

	while (s3d::System::Update())
	{
		font(L"ようこそ、Siv3D の世界へ！").draw();

		s3d::Circle(s3d::Mouse::Pos(), 50).draw({ 255, 0, 0, 127 });
	}
}
