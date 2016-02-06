template <typename Identifier>
class FadeIn final : public IScene<Identifier>
{
public:

	FadeIn(float fadeCount, bool isSwallow = false)
		: m_fadeCount(fadeCount)
		, m_currentCount(fadeCount)
		, m_isSwallow(isSwallow)
	{
		m_image.resize(640, 480);
		m_image.fill(Palette::Black);
		m_texture.fill(m_image);
	}

	virtual void Initialize() override
	{

	}

	virtual void Update(float deltaTime) override
	{
		m_currentCount -= deltaTime;
		if (m_currentCount > 0)
		{
			return;
		}

		GetSceneManager()->Pop();
	}

	virtual void Render() const override
	{
		m_texture.draw(Alpha((s3d::uint32)(m_currentCount / m_fadeCount * 255)));
	}

	virtual void Post() override
	{

	}

	virtual void Finalize() override
	{

	}

	virtual bool IsSwallow() const override
	{
		return m_isSwallow;
	}

private:

	float const m_fadeCount;
	float m_currentCount;
	bool const m_isSwallow;
	Image m_image;
	DynamicTexture m_texture;
};
