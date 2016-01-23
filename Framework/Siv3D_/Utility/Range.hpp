# pragma once

namespace Utility
{
	/// <summary>”ÍˆÍ‚ð•\‚·ƒNƒ‰ƒX</summary>
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

		/// <summary>ŠÜ‚Ü‚ê‚Ä‚¢‚é‚©‚ð•Ô‚·</summary>
		bool IsIncluded(Type const& value) const
		{
			return begin <= value && value <= end;
		}

		/// <summary>ŠÜ‚Ü‚ê‚Ä‚¢‚È‚¢‚©‚ð•Ô‚·</summary>
		bool IsExcluded(Type const& value) const
		{
			return value < begin || end < value;
		}

	private:

		Type begin;
		Type end;
	};
}