# include <Siv3D.hpp>

# include "Aquaworks/Transform/Quaternion.hpp"
# include "Aquaworks/Shapes/Sphere.hpp"
# include "Aquaworks/Utility/Math.hpp"

# include "Aquaworks/Typedef.hpp"


void RenderAxis()
{
	Line3D(Vec3::Zero, { 2.0, 0.0, 0.0 }).drawForward(Palette::Red);
	Line3D(Vec3::Zero, { 0.0, 2.0, 0.0 }).drawForward(Palette::Green);
	Line3D(Vec3::Zero, { 0.0, 0.0, 2.0 }).drawForward(Palette::Blue);
}

void Main()
{
	using namespace Aquaworks;

	Model model { L"新本.obj" };
	for (auto&& node : model.nodes())
	{
		if (!node.material.diffuseTextureName.isEmpty &&
			!TextureAsset::IsRegistered(node.material.diffuseTextureName))
		{
			TextureAsset::Register(node.material.diffuseTextureName,
				node.material.diffuseTextureName, TextureDesc::For3D);
		}
	}

	Graphics3D::SetRasterizerState(RasterizerState::WireframeCullBack);

	while (System::Update())
	{
		Graphics3D::FreeCamera();

		for (auto&& node : model.nodes())
		{
			if (node.material.diffuseTextureName.isEmpty)
			{
				node.mesh.draw();
			}
			else
			{
				node.mesh.draw(TextureAsset(node.material.diffuseTextureName));
			}
		}
	}
}
