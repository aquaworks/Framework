# pragma once

# include "../Utility/Optional.hpp"

namespace Aquaworks
{
	namespace Scene
	{
		struct FadeState
		{
		public:

			enum Identifier
			{
				Out,
				Wait,
				In,
			};

		public:

			FadeState();
			FadeState(float out, float wait, float in, bool isSwallow = true);

		public:

			bool IsEnabled(Identifier const& identifier) const;

		public:

			float count[3];
			bool isSwallow;
		};
	}
}
