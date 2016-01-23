# include "Console.hpp"

# include "String.hpp"

# include "Transform/Point2.hpp"
# include "Transform/Point3.hpp"
# include "Transform/Point4.hpp"
# include "Transform/Vector2.hpp"
# include "Transform/Vector3.hpp"
# include "Transform/Vector4.hpp"
# include "Transform/Matrix.hpp"
# include "Transform/Quaternion.hpp"
# include "Transform/Pose.hpp"

namespace Utility
{
	namespace Console
	{
		void Print()
		{

		}

		void Print(std::wstring const& value)
		{
			std::cout << String::ToNarrow(value);
		}

		void Println()
		{
			Print();
			Break();
		}

		void Break()
		{
			std::cout << std::endl;
		}
	}
}
