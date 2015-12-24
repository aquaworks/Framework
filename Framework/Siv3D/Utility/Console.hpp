# pragma once

# include <iostream>

# include "String.hpp"

namespace Transform
{
	class Point2;
	class Point3;
	class Point4;
	class Vector2;
	class Vector3;
	class Vector4;
	class Matrix;
	class Quaternion;
	class Pose;
}

namespace Utility
{
	namespace Console
	{
		void Print();

		void Print(std::wstring const& value);

		template <typename Type>
		void Print(Type const& value)
		{
			Print(String::Create(value));
		}

		template <typename Type, typename ...Args>
		void Print(Type const& value, Args&& ...args)
		{
			Print(value);
			Print(std::forward<Args>(args)...);
		}

		void Println();

		template <typename Type>
		void Println(Type const& value)
		{
			Print(value);
			Break();
		}

		template <typename Type, typename ...Args>
		void Println(Type const& value, Args&& ...args)
		{
			Print(value, std::forward<Args>(args)...);
			Break();
		}

		void Break();
	}
}
