# pragma once

# include <random>

# include "../Typedef.hpp"

namespace Aquaworks
{
	namespace Utility
	{
		namespace Random
		{
			std::mt19937& GetEngine();
			u32 Range(u32 min, u32 max);
			f32 Rangef(f32 min, f32 max);
			f32 Normal();
			f32 Bool(f32 p);
			u32 Weight(std::vector<u32> const& weights);
		}
	}
}
