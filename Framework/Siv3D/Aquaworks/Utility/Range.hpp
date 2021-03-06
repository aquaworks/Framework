# pragma once

namespace Aquaworks
{
	namespace Utility
	{
		/// <summary>範囲を表すクラス</summary>
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

			/// <summary>含まれているかを返す</summary>
			bool IsIncluded(Type const& value) const
			{
				return begin <= value && value <= end;
			}

			/// <summary>含まれていないかを返す</summary>
			bool IsExcluded(Type const& value) const
			{
				return value < begin || end < value;
			}

		private:

			Type begin;
			Type end;
		};
	}
}
