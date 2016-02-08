# pragma once

# include "../Utility/Optional.hpp"
# include "../Typedef.hpp"

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
			FadeState(f32 out, f32 wait, f32 in, bool isSwallow = true);

		public:

			bool IsEnabled(Identifier const& identifier) const;

		public:

			f32 count[3];
			bool isSwallow;
		};
	}
}
