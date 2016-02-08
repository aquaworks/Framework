# pragma once

# include <string>
# include <vector>
# include <sstream>

# include "../Typedef.hpp"

namespace Aquaworks
{
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
		namespace String
		{
			std::wstring Create();
			std::wstring Create(char const* value);
			std::wstring Create(std::string const& value);
			std::wstring Create(wchar_t const* value);
			std::wstring Create(std::wstring const& value);
			std::wstring Create(f64 value);
			std::wstring Create(f32 value);
			std::wstring Create(u64 value);
			std::wstring Create(u64 value);
			std::wstring Create(s64 value);
			std::wstring Create(u32 value);
			std::wstring Create(s32 value);

			std::wstring Create(Transform::Point2 const& value);
			std::wstring Create(Transform::Point3 const& value);
			std::wstring Create(Transform::Point4 const& value);
			std::wstring Create(Transform::Vector2 const& value);
			std::wstring Create(Transform::Vector3 const& value);
			std::wstring Create(Transform::Vector4 const& value);
			std::wstring Create(Transform::Matrix const& value);
			std::wstring Create(Transform::Quaternion const& value);
			std::wstring Create(Transform::Pose const& value);

			template <typename Type, typename ...Args>
			std::wstring Create(Type const& value, Args&& ...args)
			{
				return Create(value) + Create(std::forward<Args>(args)...);
			}

			std::vector<std::string> Split(std::string const& str, char delim);
			std::vector<std::wstring> Split(std::wstring const& str, wchar_t delim);

			template <typename Type>
			Type ToValue(std::string const& str)
			{
				std::stringstream stream(str);
				Type value;
				stream >> value;
				return value;
			}

			template <typename Type>
			Type ToValue(std::wstring const& str)
			{
				std::wstringstream stream(str);
				Type value;
				stream >> value;
				return value;
			}

			std::wstring ToWide(std::string const& narrow);

			std::string ToNarrow(std::wstring const& wide);
		}
	}
}
