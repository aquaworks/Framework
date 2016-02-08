namespace Aquaworks
{
	namespace Scene
	{
		template <typename Identifier>
		class FadeWait final : public IScene<Identifier>
		{
		public:

			FadeWait(FadeState const& fadeState)
				: m_fadeState(fadeState)
				, m_currentCount(fadeState.count[FadeState::Identifier::Wait])
			{
				m_image.resize(640, 480);
				m_image.fill(Palette::Black);
				m_texture.fill(m_image);
			}

			virtual void Initialize() override
			{

			}

			virtual void Update(f32 deltaTime) override
			{
				m_currentCount -= deltaTime;
				if (m_currentCount > 0)
				{
					return;
				}

				auto manager = dynamic_cast<SceneManager<Identifier>*>(GetSceneManager());

				manager->Pop();

				if (m_fadeState.IsEnabled(FadeState::Identifier::In))
				{
					manager->PushOperation([fadeState = m_fadeState, manager = manager] ()
					{
						manager->PushOp(manager->Create<FadeIn<Identifier>>(fadeState));
					});
				}
			}

			virtual void Render() const override
			{
				m_texture.draw();
			}

			virtual void Post() override
			{

			}

			virtual void Finalize() override
			{

			}

			virtual bool IsSwallow() const override
			{
				return m_fadeState.isSwallow;
			}

		private:

			FadeState const m_fadeState;
			f32 m_currentCount;
			Image m_image;
			DynamicTexture m_texture;
		};
	}
}
