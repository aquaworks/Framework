# pragma once

template <typename Identifier>
class ISceneMediator;

template <typename Identifier>
class SceneManager;

template <typename Identifier>
class IScene
{
protected:

	using MediatorPtr = ISceneMediator<Identifier>*;

public:

	friend SceneManager<Identifier>;

public:

	IScene()
	{

	}

	virtual ~IScene()
	{

	}

public:

	virtual void Initialize() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() const = 0;
	virtual void Post() = 0;
	virtual void Finalize() = 0;
	virtual bool IsSwallow() const = 0;

protected:

	MediatorPtr const GetSceneManager() const
	{
		return m_sceneManager;
	}

private:

	MediatorPtr m_sceneManager;
};
