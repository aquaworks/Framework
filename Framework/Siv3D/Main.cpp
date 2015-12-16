# include <Siv3D.hpp>

namespace Utility
{
	// タグ
	struct Comparable
	{

	};

	template <typename Type1, typename Type2>
	bool operator == (Type1 const& left, Type2 const& right)
	{
		return !(left != right);
	}

	template <typename Type1, typename Type2>
	bool operator != (Type1 const& left, Type2 const& right)
	{
		return !(left == right);
	}



	template <typename Type1, typename Type2>
	bool operator < (Type1 const& left, Type2 const& right)
	{
		return !(left >= right);
	}



	template <typename Type1, typename Type2>
	bool operator <= (Type1 const& left, Type2 const& right)
	{
		return !(left > right);
	}



	template <typename Type1, typename Type2>
	bool operator > (Type1 const& left, Type2 const& right)
	{
		return !(left <= right);
	}



	template <typename Type1, typename Type2>
	bool operator >= (Type1 const& left, Type2 const& right)
	{
		return !(left < right);
	}


}

class Data : private Utility::Comparable
{
public:

	Data(int data)
		: m_data(data)
	{

	}

public:

	bool operator == (Data const& other) const
	{
		return this->m_data == other.m_data;
	}

	bool operator >= (Data const& other) const
	{
		return this->m_data >= other.m_data;
	}

private:

	int m_data;
};

template <typename Type>
Type Lerp(Type const& begin, Type const& end, double t)
{
	return begin + (end - begin) * t;
}

void Main()
{

}
