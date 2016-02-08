#include "FadeState.hpp"

namespace Aquaworks
{
	namespace Scene
	{
		FadeState::FadeState()
			: FadeState(0.0f, 0.0f, 0.0f)
		{

		}

		FadeState::FadeState(f32 out, f32 wait, f32 in, bool isSwallow)
			: count()
			, isSwallow(isSwallow)
		{
			count[Out] = out;
			count[Wait] = wait;
			count[In] = in;
		}
		bool FadeState::IsEnabled(Identifier const& identifier) const
		{
			return count[identifier] > 0.0f;
		}
	}
}
