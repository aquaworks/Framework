namespace Aquaworks
{
	template <typename Identifier>
	class FadeOut final : public IScene<Identifier>
	{
	public:

		FadeOut(float fadeCount, std::function<void()> const& operation, bool isSwallow = false)
			: m_fadeCount(fadeCount)
			, m_currentCount(fadeCount)
			, m_operation(operation)
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
			m_operation();

			auto manager = dynamic_cast<SceneManager<Identifier>*>(GetSceneManager());
			manager->PushOperation([count = m_fadeCount, isSwallow = m_isSwallow, manager = manager] ()
			{
				manager->PushOp(manager->Create<FadeIn<Identifier>>(count, isSwallow));
			});
		}

		virtual void Render() const override
		{
			m_texture.draw(Alpha((s3d::uint32)((1 - m_currentCount / m_fadeCount) * 255)));
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
		std::function<void()> const m_operation;
		bool const m_isSwallow;
		Image m_image;
		DynamicTexture m_texture;
	};
}
