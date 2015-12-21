# include <Siv3D.hpp>

# include "Actor/IActor.hpp"

# include "Shape/Sphere.hpp"
# include "Shape/Capsule.hpp"
# include "Shape/Segment.hpp"
# include "Shape/Mesh.hpp"

# include "Graphics/Renderer.hpp"

# include "Utility/Easing.hpp"
# include "Utility/Math.hpp"
# include "Utility/MemoryCast.hpp"

class WireFrame
{
public:
	WireFrame()
		: m_state(s3d::Graphics3D::GetRasterizerState())
	{
		s3d::Graphics3D::SetRasterizerState(s3d::RasterizerState::WireframeBack);
	}
	virtual ~WireFrame()
	{
		s3d::Graphics3D::SetRasterizerState(m_state);
	}
	operator bool() const
	{
		return true;
	}
private:
	s3d::RasterizerState m_state;
};

template <typename Type>
Type Lerp(Type const& begin, Type const& end, double t)
{
	return begin + (end - begin) * t;
}

template <>
Transform::Quaternion Lerp(Transform::Quaternion const& begin, Transform::Quaternion const& end, double t)
{
	using namespace Transform;
	using namespace Utility;

	Vector4 const& q1 = MemoryCast<Vector4>(begin);
	Vector4 const& q2 = MemoryCast<Vector4>(end);

	double dot = Vector4::Dot(q1, q2);
	double squaredInverse = 1.0 - dot * dot;

	if (squaredInverse == 0.0)
	{
		return begin;
	}

	double omega = Math::Acos(dot);

	double sign = 1.0;

	if (dot < 0.0 && Math::HALF_PI < omega)
	{
		omega = Math::Acos(-dot);
		sign = -1.0;
	}

	double sinOmega = Math::Sin(omega);
	double s1 = Math::Sin(omega * (1.0 - t)) / sinOmega;
	double s2 = Math::Sin(omega * t) / sinOmega;

	Vector4 result = q1 * s1 + q2 * s2 * sign;

	return MemoryCast<Quaternion>(result);
}

template <>
Transform::Matrix Lerp(Transform::Matrix const& begin, Transform::Matrix const& end, double t)
{
	using namespace Transform;

	Vector3 p1 = Matrix::Translation(begin);
	Vector3 p2 = Matrix::Translation(end);

	Quaternion r1 = Matrix::ToQuaternion(begin);
	Quaternion r2 = Matrix::ToQuaternion(end);

	Vector3 s1 = Matrix::Scaling(begin);
	Vector3 s2 = Matrix::Scaling(end);

	Vector3 p = Lerp(p1, p2, t);
	Quaternion r = Lerp(r1, r2, t);
	Vector3 s = Lerp(s1, s2, t);

	return Matrix::Transformation(p, r, s);
}

class ShapeActor : public Actor::IActor
{
public:
	ShapeActor(Shape::ShapePtr const& shape)
		: IActor(shape)
		, m_elapsedTime(0.0f)
		, m_perSecond(2.0f)
		, m_isReversed(false)
	{

	}
public:
	void OnUpdate(float deltaTime) override
	{
		using namespace Transform;

		if (1)
		{
			m_elapsedTime += deltaTime;

			if (m_perSecond < m_elapsedTime)
			{
				m_isReversed = !m_isReversed;
				m_elapsedTime = fmod(m_elapsedTime, m_perSecond);
			}
		}

		double t = m_elapsedTime / m_perSecond;
		t = Utility::EaseSine::InOut(t);

		if (0)
		{
			static Vector3 const Begin = Vector3(-10.0f, 0.0f, 0.0f);
			static Vector3 const End = Vector3(10.0f, 0.0f, 0.0f);
			m_transform.position = Lerp(Begin, End, GetProgress(t));
		}

		if (0)
		{
			static Vector3 Axis = Vector3::Up();
			static Quaternion const Begin = Quaternion::Rotation(Vector3::Up(), 90.0f);
			static Quaternion const End = Quaternion::Rotation(Vector3::Forward(), Utility::Math::ToRadian(-90.0));
			m_transform.rotation = Lerp(Begin, End, GetProgress(t));
		}

		if (0)
		{
			static Matrix const Begin = Matrix::Transformation({ -10.0f, 0.0f, 0.0f }, Quaternion::Rotation(Vector3::Up(), Utility::Math::ToRadian(90.0)), Vector3::One());
			static Matrix const End = Matrix::Transformation({ 10.0f, 0.0f, 0.0f }, Quaternion::Rotation(Vector3::Forward(), Utility::Math::ToRadian(90.0)), Vector3::One());
			Matrix lerp = Lerp(Begin, End, GetProgress(t));
			m_transform = Matrix::Decompose(lerp);
		}

		if (1)
		{
			static Matrix const Begin = Matrix::Rotation(Quaternion::Rotation(Vector3::Up(), Utility::Math::ToRadian(0.0)));
			static Matrix const End = Matrix::Rotation(Quaternion::Rotation(Vector3::Up(), Utility::Math::ToRadian(90.0)));
			Matrix lerp = Lerp(Begin, End, GetProgress(t));
			m_transform = Matrix::Decompose(lerp);
		}

		IActor::OnUpdate(deltaTime);
	}
	double GetProgress(double t)
	{
		return m_isReversed ? 1.0f - t : t;
	}

	void OnRender(Graphics::Renderer const& renderer) const override
	{
		if (WireFrame wire { })
		{
			WorldShape()->BoundingSphere()->Render();
		}

		IActor::OnRender(renderer);
	}
private:
	float m_elapsedTime;
	float m_perSecond;
	bool m_isReversed;
};

void Main()
{
	using namespace Utility;
	using namespace Transform;

	Graphics::Renderer renderer;

	double const DeltaTime = 0.016666666;

	auto q = Quaternion::Rotation(Vector3::Up(), Math::ToRadian(90.0));
	auto m = Matrix::Rotation(q);
	auto mq = Matrix::ToQuaternion(m);

	Shape::Capsule capsule =
		Shape::Capsule(Matrix::Decompose(Matrix::Rotation(q)), { 3.0f, 0.0, 0.0f }, { -3.0f, 0.0f, 0.0f }, 1.0f);

	double elapsedTime = 0.0;

	while (s3d::System::Update())
	{
		auto t = Lerp(q, mq, elapsedTime);

		capsule.Reshape(Pose::Affine(Vector3::Zero(), t, Vector3::One()))->Render(Vector4::One());

		elapsedTime += DeltaTime;
		if (1.0 < elapsedTime)
		{
			elapsedTime -= 1.0;
		}
	}
}
