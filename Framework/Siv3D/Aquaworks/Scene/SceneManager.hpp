# pragma once

# include "IScene.hpp"
# include "ISceneMediator.hpp"

# include <memory>
# include <unordered_map>
# include <functional>

# include "FadeIn.inl"
# include "FadeWait.inl"
# include "FadeOut.inl"

# include "../Utility/Math.hpp"

namespace Aquaworks
{
	namespace Scene
	{
		template <typename Identifier>
		class SceneManager : public ISceneMediator<Identifier>
		{
		public:

			friend FadeWait<Identifier>;
			friend FadeOut<Identifier>;

			using ScenePtr = std::shared_ptr<IScene<Identifier>>;
			using SceneContainer = std::unordered_map<Identifier, ScenePtr>;
			using SceneStack = std::list<ScenePtr>;

			using Operation = std::function<void()>;
			using OperationStack = std::list<Operation>;

		public:

			SceneManager()
			{

			}

		public:

			template <typename SceneType, typename ...Args>
			ScenePtr Create(Args&& ...args)
			{
				ScenePtr scene = std::make_shared<SceneType>(
					std::forward<Args>(args)...);
				scene->m_sceneManager = this;
				return scene;
			}

			template <typename SceneType, typename ...Args>
			void Add(Identifier const& identifier, Args&& ...args)
			{
				m_scenes.insert(std::make_pair(
					identifier, Create<SceneType>(std::forward<Args>(args)...)));
			}

			void Update(f32 deltaTime)
			{
				for (auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
				{
					(*it)->Update(deltaTime);
					if ((*it)->IsSwallow())
					{
						return;
					}
				}
			}

			void Render() const
			{
				for (auto&& scene : m_stack)
				{
					scene->Render();
				}
			}

			void Resolve()
			{
				for (auto&& op : m_operations)
				{
					op();
				}
				m_operations.clear();
			}

			void Post() const
			{
				for (auto it = m_stack.rbegin(); it != m_stack.rend(); ++it)
				{
					(*it)->Post();
				}
			}

		public:

			virtual void Change(Identifier const& identifier, FadeState const& state) override
			{
				PushOperation([this, identifier, state]
				{
					PushOp(Create<FadeOut<Identifier>>(state, [=] { Change(identifier); }));
				});
			}

			virtual void Replace(Identifier const& identifier, FadeState const& state) override
			{
				(void)identifier;
				(void)state;
			}

			virtual void Push(Identifier const& identifier, FadeState const& state) override
			{
				(void)identifier;
				(void)state;
			}

			virtual void Pop(FadeState const& state) override
			{
				(void)state;
			}

		public:

			virtual void Change(Identifier const& identifier, f32 t, bool isSwallow) override
			{
				PushOperation([this, identifier, t, isSwallow]
				{
					// PushOp(Create<FadeOut<Identifier>>(t, [=] { Change(identifier); }, isSwallow));
					PushOp(Create<FadeOut<Identifier>>(FadeState(t, 0.0f, t, isSwallow), [=] { Change(identifier); }));
				});
			}

			virtual void Replace(Identifier const& identifier, f32 t, bool isSwallow) override
			{
				PushOperation([this, identifier, t, isSwallow]
				{
					// PushOp(Create<FadeOut<Identifier>>(t, [=] { Replace(identifier); }, isSwallow));
					PushOp(Create<FadeOut<Identifier>>(FadeState(t, 0.0f, t, isSwallow), [=] { Replace(identifier); }));
				});
			}

			virtual void Push(Identifier const& identifier, f32 t, bool isSwallow) override
			{
				PushOperation([this, identifier, t, isSwallow]
				{
					// PushOp(Create<FadeOut<Identifier>>(t, [=] { Push(identifier); }, isSwallow));
					PushOp(Create<FadeOut<Identifier>>(FadeState(t, 0.0f, t, isSwallow), [=] { Push(identifier); }));
				});
			}

			virtual void Pop(f32 t, bool isSwallow) override
			{
				PushOperation([this, t, isSwallow]
				{
					// PushOp(Create<FadeOut<Identifier>>(t, [=] { Pop(); }, isSwallow));
					PushOp(Create<FadeOut<Identifier>>(FadeState(t, 0.0f, t, isSwallow), [=] { Pop(); }));
				});
			}

		public:

			virtual void Change(Identifier const& identifier) override
			{
				PushOperation([=]
				{
					ClearOp();
					PushOp(m_scenes.at(identifier));
				});
			}

			virtual void Replace(Identifier const& identifier) override
			{
				PushOperation([=]
				{
					PopOp();
					PushOp(m_scenes.at(identifier));
				});
			}

			virtual void Push(Identifier const& identifier) override
			{
				PushOperation([=]
				{
					PushOp(m_scenes.at(identifier));
				});
			}

			virtual void Pop() override
			{
				PushOperation([=]
				{
					PopOp();
				});
			}

		private:

			void PushOp(ScenePtr const& scene)
			{
				m_stack.push_back(scene);
				scene->Initialize();
			}

			void PopOp()
			{
				m_stack.back()->Finalize();
				m_stack.pop_back();
			}

			void ClearOp()
			{
				size_t size = m_stack.size();
				for (size_t i = 0; i < size; ++i)
				{
					PopOp();
				}
			}

			void PushOperation(Operation const& operation)
			{
				m_operations.emplace_back(operation);
			}

		private:

			SceneContainer m_scenes;
			SceneStack m_stack;
			OperationStack m_operations;
		};
	}
}
