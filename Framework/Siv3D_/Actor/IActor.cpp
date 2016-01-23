# include "IActor.hpp"

# include "Graphics/Renderer.hpp"

# include <algorithm>

namespace Actor
{
	double const IActor::Gravity = 0.02;

	IActor::IActor(std::wstring const& name)
		: IActor(name, Transform::Pose::Identity(), Shape::IShape::Empty())
	{

	}

	IActor::IActor(Transform::Pose const& transform)
		: IActor(L"", transform, Shape::IShape::Empty())
	{

	}

	IActor::IActor(Shape::ShapePtr const& shape)
		: IActor(L"", Transform::Pose::Identity(), shape)
	{

	}

	IActor::IActor(std::wstring const& name, Transform::Pose const& transform)
		: IActor(name, transform, Shape::IShape::Empty())
	{

	}

	IActor::IActor(std::wstring const& name, Transform::Pose const& transform, Shape::ShapePtr const& shape)
		: m_children()
		, m_parent()
		, m_self()
		, m_previous(transform)
		, m_transform(transform)
		, m_name(name)
		, m_isDead(false)
		, m_shape(shape)
	{

	}

	IActor& IActor::ChangeShape(Shape::ShapePtr const& shape)
	{
		m_shape = shape;
		return *this;
	}

	Transform::Pose IActor::Local() const
	{
		return m_transform;
	}

	Transform::Pose IActor::World() const
	{
		Transform::Pose transform = Local();
		if (m_parent.expired())
		{
			return transform;
		}
		return transform * m_parent.lock()->World();
	}

	Shape::ShapePtr const IActor::LocalShape() const
	{
		return m_shape;
	}
	Shape::ShapePtr const IActor::WorldShape() const
	{
		return LocalShape()->Reshape(World());
	}

	bool IActor::IsCollide(ActorPtr const& actor) const
	{
		return WorldShape()->Intersects(*actor->WorldShape());
	}

	void IActor::Update(float deltaTime)
	{
		m_previous = m_transform;
		OnUpdate(deltaTime);
		for (auto&& child : m_children)
		{
			child->Update(deltaTime);
		}
	}

	void IActor::Collide(ActorPtr const& actor)
	{
		// Own vs Other
		if (IsCollide(actor))
		{
			OnCollide(actor);
		}

		// Own vs Other Child
		for (auto&& other : m_children)
		{
			if (IsCollide(other))
			{
				OnCollide(other);
			}
		}

		// Own Child vs Other
		for (auto&& child : m_children)
		{
			child->Collide(actor);
		}
	}

	void IActor::Render(Graphics::Renderer const& renderer) const
	{
		OnRender(renderer);
		for (auto&& child : m_children)
		{
			child->Render(renderer);
		}
	}

	void IActor::OnUpdate(float deltaTime)
	{
		(void)deltaTime;
	}

	void IActor::OnCollide(ActorPtr const& actor)
	{
		(void)actor;
	}

	void IActor::OnRender(Graphics::Renderer const& renderer) const
	{
		renderer.Render(LocalShape(), World());
	}

	ActorPtr& IActor::Add(ActorPtr& actor)
	{
		m_children.push_back(actor);
		return actor;
	}

	ActorPtr& IActor::Add(ActorPtr&& actor)
	{
		m_children.push_back(actor);
		return actor;
	}

	ActorRef IActor::Find(ActorSelector const& selector) const
	{
		if (selector(m_self.lock()))
		{
			return m_self;
		}

		for (auto&& child : m_children)
		{
			ActorRef&& find = child->Find(selector);
			if (!find.expired())
			{
				return find;
			}
		}

		return ActorRef();
	}

	void IActor::Remove(ActorSelector const& selector)
	{
		m_children.erase(
			std::remove_if(m_children.begin(), m_children.end(), selector),
			m_children.end());
		for (auto&& child : m_children)
		{
			child->Remove(selector);
		}
	}

	void IActor::Kill()
	{
		m_isDead = true;
	}
}
