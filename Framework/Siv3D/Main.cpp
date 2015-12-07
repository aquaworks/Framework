# include <Siv3D.hpp>

# include "Actor/World.hpp"
# include "Actor/IActor.hpp"

# include "Graphics/Renderer.hpp"

# include "Utility/Easing.hpp"

template <typename Type>
class EasingLerp
{
public:
	static Type Lerp(Type const&& begin, Type const&& end, Utility::EasingFunction const& f, double t)
	{
		return begin + (end - begin) * f(t);
	}
};

class Player : public Actor::IActor
{
public:
	Player(Transform::Pose const& pose)
		: Actor::IActor(L"Player", pose)
		, m_origin(pose.position)
		, m_movement(Transform::Vector3::Right() * 3.0f)
		, m_elapsedTime(0.5f)
		, m_loopTime(1.0f)
	{

	}

	virtual void OnUpdate(float deltaTime) override
	{
		m_transform.position =
			EasingLerp<Transform::Vector3>::Lerp(m_origin - m_movement, m_origin + m_movement,
			Utility::EaseBounce::In, m_elapsedTime / m_loopTime);

		m_elapsedTime += deltaTime;
		if (m_elapsedTime > m_loopTime)
		{
			m_elapsedTime -= m_loopTime;
			m_movement *= -1.0f;
		}
	}

private:
	Transform::Vector3 m_origin;
	Transform::Vector3 m_movement;
	float m_elapsedTime;
	float m_loopTime;
};

void Main()
{
	Actor::WorldPtr world = Actor::World::Create();

	world->Add(Actor::Layer::Player, Actor::IActor::Create<Player>(
		Transform::Pose::Identity()));

	Graphics::Renderer renderer;

	while (s3d::System::Update())
	{
		world->Update(0.0166667f);
		world->Render(renderer);
	}
}
