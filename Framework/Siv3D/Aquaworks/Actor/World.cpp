# include "World.hpp"

# include "IActor.hpp"

namespace Aquaworks
{
	namespace Actor
	{
		World::World()
		{
			// Root
			m_root = std::make_shared<IActor>(L"root", Transform::Pose::Empty());

			// Layer
			m_layers.insert(std::make_pair(Layer::None,
				m_root->Add(IActor::Create<IActor>(L"", Transform::Pose::Identity()))));
			m_layers.insert(std::make_pair(Layer::Player,
				m_root->Add(IActor::Create<IActor>(L"", Transform::Pose::Identity()))));
			m_layers.insert(std::make_pair(Layer::Obstacle,
				m_root->Add(IActor::Create<IActor>(L"", Transform::Pose::Identity()))));
		}

		WorldPtr World::Create()
		{
			return std::make_unique<World>();
		}

		ActorPtr& World::Add(Layer const& layer, ActorPtr& actor)
		{
			return m_layers.at(layer).lock()->Add(actor);
		}

		ActorPtr& World::Add(Layer const& layer, ActorPtr&& actor)
		{
			return m_layers.at(layer).lock()->Add(actor);
		}

		ActorRef World::Find(ActorSelector const& selector) const
		{
			return m_root->Find(selector);
		}

		void World::Remove(ActorSelector const& selector)
		{
			m_root->Remove(selector);
		}

		void World::Update(float deltaTime)
		{
			m_root->Update(deltaTime);
		}

		void World::Collide()
		{
			// Player vs Obstacle
			m_layers.at(Layer::Player).lock()->Collide(m_layers.at(Layer::Obstacle).lock());
		}

		void World::Render(Graphics::Renderer const& renderer) const
		{
			m_root->Render(renderer);
		}
	}
}
