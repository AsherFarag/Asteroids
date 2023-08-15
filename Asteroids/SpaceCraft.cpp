#include "SpaceCraft.h"

SpaceCraft::SpaceCraft()
{
	//AddComponent(new SpriteRenderer(this));
	SpriteRenderer* SR = AddComponent<SpriteRenderer>();
}