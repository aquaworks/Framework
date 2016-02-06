# pragma once

# include "IWorld.hpp"

# include <unordered_map>

namespace Aquaworks
{
	namespace Graphics
	{
		class Renderer;
	}

	namespace Actor
	{
		class World;
		using WorldPtr = std::unique_ptr<World>;

		class World : public IWorld
		{
		public:

			World();

		public:

			static WorldPtr Create();

		public:

			virtual ActorPtr& Add(Layer const& layer, ActorPtr& actor) override;

			virtual ActorPtr& Add(Layer const& layer, ActorPtr&& actor) override;

			virtual ActorRef Find(ActorSelector const& selector) const override;

			virtual void Remove(ActorSelector const& selector) override;

		public:

			void Update(float deltaTime);

			void Collide();

			void Render(Graphics::Renderer const& renderer) const;

		private:

			ActorPtr m_root;
			std::unordered_map<Layer, ActorRef> m_layers;
		};
	}
}
