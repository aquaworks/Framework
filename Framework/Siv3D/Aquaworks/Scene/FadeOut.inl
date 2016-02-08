namespace Aquaworks
{
	namespace Scene
	{
		template <typename Identifier>
		class FadeOut final : public IScene<Identifier>
		{
		public:

			FadeOut(FadeState const& fadeState, std::function<void()> const& operation)
				: m_fadeState(fadeState)
				, m_currentCount(fadeState.count[FadeState::Identifier::Out])
				, m_operation(operation)
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
				m_operation();

				if (m_fadeState.IsEnabled(FadeState::Identifier::Wait))
				{
					manager->PushOperation([fadeState = m_fadeState, manager = manager] ()
					{
						manager->PushOp(manager->Create<FadeWait<Identifier>>(fadeState));
					});
					return;
				}

				if (m_fadeState.IsEnabled(FadeState::Identifier::In))
				{
					manager->PushOperation([fadeState = m_fadeState, manager = manager] ()
					{
						manager->PushOp(manager->Create<FadeIn<Identifier>>(fadeState));
					});
					return;
				}
			}

			virtual void Render() const override
			{
				f32 t = Utility::Math::Saturate(1 - m_currentCount / m_fadeState.count[FadeState::Identifier::Out]);
				m_texture.draw(Alpha((s3d::uint32)(255 * t)));
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
			std::function<void()> const m_operation;
			Image m_image;
			DynamicTexture m_texture;
		};
	}
}
