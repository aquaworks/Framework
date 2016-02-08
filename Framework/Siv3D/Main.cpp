# include <Siv3D.hpp>

# include "Aquaworks/Scene/SceneManager.hpp"

using BaseScene = Aquaworks::Scene::IScene<int>;
using SceneManager = Aquaworks::Scene::SceneManager<int>;

class Scene1 : public BaseScene
{
public:
	Scene1(Font const& font)
		: m_font(font)
	{

	}
public:
	virtual void Initialize() override
	{

	}
	virtual void Update(float deltaTime) override
	{
		(void)deltaTime;
		if (Input::Key1.clicked)
		{
			GetSceneManager()->Change(1);
		}
	}
	virtual void Render() const override
	{
		m_font(L"Scene1").draw();
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
	Font const& m_font;
};

class Scene2 : public BaseScene
{
public:
	Scene2(Font const& font)
		: m_font(font)
	{

	}
public:
	virtual void Initialize() override
	{

	}
	virtual void Update(float deltaTime) override
	{
		(void)deltaTime;
		if (Input::Key1.clicked)
		{
			GetSceneManager()->Change(2, 1.0f);
		}
	}
	virtual void Render() const override
	{
		m_font(L"Scene2").draw();
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
	Font const& m_font;
};

class Scene3 : public BaseScene
{
public:
	Scene3(Font const& font)
		: m_font(font)
	{

	}
public:
	virtual void Initialize() override
	{

	}
	virtual void Update(float deltaTime) override
	{
		(void)deltaTime;
		if (Input::Key1.clicked)
		{
			GetSceneManager()->Change(0, Aquaworks::Scene::FadeState(1.0f, 2.0f, 3.0f));
		}
	}
	virtual void Render() const override
	{
		m_font(L"Scene3").draw();
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
	Font const& m_font;
};

void Main()
{
	Font const font { 16 };

	SceneManager sceneManager;
	sceneManager.Add<Scene1>(0, font);
	sceneManager.Add<Scene2>(1, font);
	sceneManager.Add<Scene3>(2, font);

	sceneManager.Push(0);

	while (System::Update())
	{
		sceneManager.Resolve();
		sceneManager.Update(0.016666667f);
		sceneManager.Render();
		sceneManager.Post();
	}
}
