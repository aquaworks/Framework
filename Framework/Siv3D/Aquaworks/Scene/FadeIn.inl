namespace Aquaworks
{
	namespace Scene
	{
		template <typename Identifier>
		class FadeIn final : public IScene<Identifier>
		{
		public:

			FadeIn(FadeState const& fadeState)
				: m_fadeState(fadeState)
				, m_currentCount(fadeState.count[FadeState::Identifier::In])
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
				float t = Utility::Math::Saturate(m_currentCount / m_fadeState.count[FadeState::Identifier::In]);
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
			float m_currentCount;
			Image m_image;
			DynamicTexture m_texture;
		};
	}
}
