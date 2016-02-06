# pragma once

template <typename Identifier>
class ISceneMediator
{
public:

	virtual void Change(Identifier const& identifier, float t, bool isSwallow = true) = 0;
	virtual void Replace(Identifier const& ientifier, float t, bool isSwallow = true) = 0;
	virtual void Push(Identifier const& ientifier, float t, bool isSwallow = true) = 0;
	virtual void Pop(float t, bool isSwallow = true) = 0;

public:

	virtual void Change(Identifier const& identifier) = 0;
	virtual void Replace(Identifier const& ientifiere) = 0;
	virtual void Push(Identifier const& ientifier) = 0;
	virtual void Pop() = 0;
};
