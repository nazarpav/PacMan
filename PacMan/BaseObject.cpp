#include "BaseObject.h"

void BaseObject::FrameFunc(int x, int y)
{
	this->x = x;
	this->y = y;
}

void BaseObject::RenderFunc()
{
	sprite->Render(this->x, this->y);
}

BaseObject::BaseObject(HGE* hge, std::string path)
{
	this->hge = hge;
	int SizeTexture = 64;
	sprite = new hgeSprite(hge->Texture_Load(path.c_str()), 0, 0, SizeTexture, SizeTexture);
	//sprite->SetColor(0xFF00A000);
	//sprite->SetHotSpot(sprite->GetWidth()/2, sprite->GetHeight() / 2);
}

BaseObject::~BaseObject()
{
	delete sprite;
}
