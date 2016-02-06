# pragma once

# include <memory>
# include <list>

namespace Aquaworks
{
	namespace Actor
	{
		class IActor;

		using ActorPtr = std::shared_ptr<IActor>;
		using ActorRef = std::weak_ptr<IActor>;
		using Children = std::list<ActorPtr>;
	}
}
