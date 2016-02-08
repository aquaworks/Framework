# include "Random.hpp"
# include "Math.hpp"
# include <numeric>

namespace Aquaworks
{
	namespace Random
	{
		std::mt19937& GetEngine()
		{
			static std::mt19937 mt { std::random_device()() };
			return mt;
		}

		u32 Range(u32 min, u32 max)
		{
			return std::uniform_int_distribution<u32>(min, max)(GetEngine());
		}

		f32 Rangef(f32 min, f32 max)
		{
			return std::uniform_real_distribution<f32>(min, max)(GetEngine());
		}

		f32 Normal()
		{
			return Rangef(0.0f, 1.0f);
		}

		f32 Bool(f32 p)
		{
			return std::bernoulli_distribution(p)(GetEngine());
		}

		u32 Weight(std::vector<u32> const& weights)
		{
			auto copy = weights;
			std::qsort(copy.data(), copy.size(), sizeof(u32),
				[] (void const* p1, void const* p2)
			{
				return *(u32*)p2 > *(u32*)p1 ? 1 : -1;
			});

			u32 sum = std::accumulate(copy.begin(), copy.end(), (u32)0);
			u32 r = (u32)Utility::Math::Floor((f32)(Normal() * sum));

			for (u32 i = 0; i < copy.size(); ++i)
			{
				sum += copy[i];
				if (r < sum)
				{
					return i;
				}
			}

			return (u32)-1;
		}

	}
}
