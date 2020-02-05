#include "Block.h"

Block::Block(HGE* hge, int x, int y):BaseObject(hge,"PacmanTexture/Block.png")
{
	this->textureSize = 48;
	this->x = x;
	this->y = y;
}


Block::~Block()
{
}
