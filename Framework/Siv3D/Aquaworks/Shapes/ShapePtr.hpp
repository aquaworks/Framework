# pragma once

# include <memory>

namespace Aquaworks
{
	namespace Shapes
	{
		class IShape;

		using ShapePtr = std::shared_ptr<IShape>;
	}
}
