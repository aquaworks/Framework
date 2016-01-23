# pragma once

# include <memory>

namespace Shapes
{
	class IShape;

	using ShapePtr = std::shared_ptr<IShape>;
}
