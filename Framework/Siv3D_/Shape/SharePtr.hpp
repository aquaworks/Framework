# pragma once

# include <memory>

namespace Shape
{
	class IShape;

	using ShapePtr = std::shared_ptr<IShape>;
}
