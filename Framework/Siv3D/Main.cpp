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
	Image blackImage { 640, 480, Palette::Black };
	Image transitionImage { L"Aquaworks/TransitionImage/153.png" };

	DynamicTexture texture { transitionImage };

	Texture background { Image(L"Example/Windmill.png").fit({ 640, 480 }) };

	Font const font { 16 };

	SceneManager sceneManager;
	sceneManager.Add<Scene1>(0, font);
	sceneManager.Add<Scene2>(1, font);
	sceneManager.Add<Scene3>(2, font);

	sceneManager.Push(0);

	GUI gui { GUIStyle::Default };
	gui.add(GUIText::Create(L"Red"));
	gui.addln(L"Red", GUISlider::Create(0, 255, 0));
	gui.add(GUIText::Create(L"Green"));
	gui.addln(L"Green", GUISlider::Create(0, 255, 0));
	gui.add(GUIText::Create(L"Blue"));
	gui.addln(L"Blue", GUISlider::Create(0, 255, 0));
	gui.add(GUIText::Create(L"Alpha"));
	gui.addln(L"Alpha", GUISlider::Create(0, 255, 0));
	gui.addln(GUIHorizontalLine::Create());
	gui.add(L"Blend", GUIRadioButton::Create({ L"Default", L"Additive", L"Multiplicative", L"Subtractive", L"Opaque" }, 0));
	gui.show();

	std::vector<BlendState> BlendStateMap =
	{
		BlendState::Default,
		BlendState::Additive,
		BlendState::Multiplicative,
		BlendState::Subtractive,
		BlendState::Opaque,
	};

	while (System::Update())
	{
		sceneManager.Resolve();
		sceneManager.Update(0.016666667f);
		sceneManager.Render();
		sceneManager.Post();

		font(Profiler::FPS()).draw({ 0, 64 });

		background.draw();

		Graphics2D::SetBlendState(BlendStateMap.at(gui.radioButton(L"Blend").checkedItem.value()));
		uint32 red = gui.slider(L"Red").sliderPosition;
		uint32 green = gui.slider(L"Green").sliderPosition;
		uint32 blue = gui.slider(L"Blue").sliderPosition;
		uint32 alpha = gui.slider(L"Alpha").sliderPosition;
		texture.draw(Color(red, green, blue, alpha));
		Graphics2D::SetBlendState(BlendState::Default);
	}
}
