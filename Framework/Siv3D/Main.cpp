# include <Siv3D.hpp>

# include "Scene/SceneManager.hpp"
# include "Scene/IScene.hpp"

# include "Shapes/Sphere.hpp"
# include "Shapes/Segment.hpp"
# include "Shapes/Mesh.hpp"


using SceneIdentifier = int;

using BaseScene = IScene<SceneIdentifier>;

class Scene1 : public BaseScene
{
public:
	Scene1()
		: m_shape(std::make_shared<Shapes::Sphere>(Transform::Pose::Identity(), 1.0f))
	{

	}
	virtual void Initialize() override
	{

	}
	virtual void Update(float deltaTime) override
	{
		(void)deltaTime;
	}
	virtual void Render() const override
	{
		m_shape->Render();
	}
	virtual void Post() override
	{

	}
	virtual void Finalize() override
	{

	}
	virtual bool IsSwallow() const override
	{
		return true;
	}
private:
	Shapes::ShapePtr m_shape;
};

class Scene2 : public BaseScene
{
public:
	Scene2()
		: m_shape(std::make_shared<Shapes::Segment>(Transform::Pose::Identity(), Transform::Vector3(3.0f, 3.0f, 0.0f), Transform::Vector3(-3.0f, -3.0f, 0.0f)))
	{

	}
	virtual void Initialize() override
	{

	}
	virtual void Update(float deltaTime) override
	{
		(void)deltaTime;
	}
	virtual void Render() const override
	{
		m_shape->Render();
	}
	virtual void Post() override
	{

	}
	virtual void Finalize() override
	{

	}
	virtual bool IsSwallow() const override
	{
		return true;
	}
private:
	Shapes::ShapePtr m_shape;
};

class Scene3 : public BaseScene
{
public:
	Scene3()
		: m_shape(Shapes::Mesh::BoxNormal({ 1.0f, 1.0f, 1.0f }))
	{

	}
	virtual void Initialize() override
	{

	}
	virtual void Update(float deltaTime) override
	{
		(void)deltaTime;
		if (Input::Key1.clicked)
		{
			GetSceneManager()->Change(0, 1.0f, false);
		}
	}
	virtual void Render() const override
	{
		m_shape->Render();
	}
	virtual void Post() override
	{
		
	}
	virtual void Finalize() override
	{

	}
	virtual bool IsSwallow() const override
	{
		return true;
	}
private:
	Shapes::ShapePtr m_shape;
};

void Main()
{
	SceneManager<SceneIdentifier> sceneManager;

	sceneManager.Add<Scene1>(0);
	sceneManager.Add<Scene2>(1);
	sceneManager.Add<Scene3>(2);

	sceneManager.Push(2);

	while (System::Update())
	{
		sceneManager.Resolve();
		sceneManager.Update(0.016667f);
		sceneManager.Render();
		sceneManager.Post();
	}
}
