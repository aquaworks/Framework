# pragma once

# include "IActor.hpp"

namespace Actor
{
	class Empty : public IActor
	{
	public:

		Empty()
			: IActor(L"", Transform::Pose::Empty())
		{

		}
	};
}
