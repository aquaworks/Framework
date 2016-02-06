# pragma once

# include "../Transform/Pose.hpp"

# include "ActorPtr.hpp"
# include "IWorld.hpp"

# include "../Shapes/IShape.hpp"
# include "../Shapes/ShapePtr.hpp"

namespace Aquaworks
{
	namespace Graphics
	{
		class Renderer;
	}

	namespace Actor
	{
		class IActor
		{
		public:

			static double const Gravity;

		public:

			template <typename Type, typename ...Args>
			static ActorPtr Create(Args&& ...args)
			{
				ActorPtr actor = std::make_shared<Type>(std::forward<Args>(args)...);
				actor->m_self = actor;
				return actor;
			}

		public:

			explicit IActor(std::wstring const& name);
			explicit IActor(Transform::Pose const& transform);
			explicit IActor(Shapes::ShapePtr const& shape);
			IActor(std::wstring const& name, Transform::Pose const& transform);
			IActor(std::wstring const& name, Transform::Pose const& transform, Shapes::ShapePtr const& shape);

		public:

			IActor& ChangeShape(Shapes::ShapePtr const& shape);

		public:

			Transform::Pose Local() const;
			Transform::Pose World() const;
			Shapes::ShapePtr const LocalShape() const;
			Shapes::ShapePtr const WorldShape() const;

		public:

			bool IsCollide(ActorPtr const& actor) const;

		public:

			virtual void Update(float deltaTime) final;
			void Collide(ActorPtr const& actor);
			virtual void Render(Graphics::Renderer const& renderer) const final;

		public:

			virtual void OnUpdate(float deltaTime);
			virtual void OnCollide(ActorPtr const& actor);
			virtual void OnRender(Graphics::Renderer const& renderer) const;

		public:

			ActorPtr& Add(ActorPtr& actor);
			ActorPtr& Add(ActorPtr&& actor);
			ActorRef Find(ActorSelector const& selector) const;
			void Remove(ActorSelector const& selector);

		public:

			void Kill();

		protected:

			Children m_children;
			ActorRef m_parent;
			ActorRef m_self;

			Transform::Pose m_previous;
			Transform::Pose m_transform;

			std::wstring m_name;
			bool m_isDead;

			Shapes::ShapePtr m_shape;
		};
	}
}
