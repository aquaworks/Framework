# pragma once

# include "FadeState.hpp"

namespace Aquaworks
{
	namespace Scene
	{
		template <typename Identifier>
		class ISceneMediator
		{
		public:

			virtual void Change(Identifier const& identifier, FadeState const& state) = 0;
			virtual void Replace(Identifier const& identifier, FadeState const& state) = 0;
			virtual void Push(Identifier const& identifier, FadeState const& state) = 0;
			virtual void Pop(FadeState const& state) = 0;

			virtual void Change(Identifier const& identifier, f32 t, bool isSwallow = true) = 0;
			virtual void Replace(Identifier const& ientifier, f32 t, bool isSwallow = true) = 0;
			virtual void Push(Identifier const& ientifier, f32 t, bool isSwallow = true) = 0;
			virtual void Pop(f32 t, bool isSwallow = true) = 0;

		public:

			virtual void Change(Identifier const& identifier) = 0;
			virtual void Replace(Identifier const& ientifiere) = 0;
			virtual void Push(Identifier const& ientifier) = 0;
			virtual void Pop() = 0;
		};
	}
}
