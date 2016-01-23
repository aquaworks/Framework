# pragma once

namespace Utility
{
	/// <summary>�͈͂�\���N���X</summary>
	template <typename Type>
	class Range
	{
	public:

		Range(Type const& begin, Type const& end)
			: begin(begin)
			, end(end)
		{
			
		}

	public:

		/// <summary>�܂܂�Ă��邩��Ԃ�</summary>
		bool IsIncluded(Type const& value) const
		{
			return begin <= value && value <= end;
		}

		/// <summary>�܂܂�Ă��Ȃ�����Ԃ�</summary>
		bool IsExcluded(Type const& value) const
		{
			return value < begin || end < value;
		}

	private:

		Type begin;
		Type end;
	};
}