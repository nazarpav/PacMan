#pragma once
#include <hge.h>
#include <hgesprite.h>
#include <hgefont.h>
#include <string>

class BaseObject
{
protected:
	HGE* hge;
	hgeSprite* sprite;
	int x,y;
	int textureSize;
public:
	int GetTextureSize()
	{
		return this->textureSize;
	}
	int GetX()
	{
		return this->x;
	}
	int GetY()
	{
		return this->y;
	}
	virtual void FrameFunc(int x,int y);
	void RenderFunc();
	BaseObject(HGE* hge, std::string path);
	virtual ~BaseObject();
};

