# pragma once

# include "ActorPtr.hpp"
# include "Layer.hpp"

# include <functional>

namespace Aquaworks
{
	namespace Actor
	{
		using ActorSelector = std::function<bool(ActorPtr const&)>;

		class IWorld
		{
		public:

			virtual ActorPtr& Add(Layer const& layer, ActorPtr& actor) = 0;
			virtual ActorPtr& Add(Layer const& layer, ActorPtr&& actor) = 0;
			virtual ActorRef Find(ActorSelector const& selector) const = 0;
			virtual void Remove(ActorSelector const& selector) = 0;
		};
	}
}
