#pragma once
#include <hge.h>
#include <hgesprite.h>
#include <hgefont.h>
#include <string>
#include "BaseObject.h"
#include "Direction.h"
class Enemy :public BaseObject
{
protected:
	HTEXTURE texture2;
	HTEXTURE texture2Up;
	HTEXTURE texture2Rights;
	HTEXTURE texture2Down;
	HTEXTURE texture2Left;
	float saveTime;
	Direction saveDirection;
	Direction direction;
	uint32_t Color;
public:
	void SetX(int x)
	{
		this->x = x;
	}
	void SetY(int y)
	{
		this->y = y;
	}
	int GetX()
	{
		return this->x;
	}
	int GetY()
	{
		return this->y;
	}
	void SetDirection(Direction direction)
	{
		this->direction = direction;
	}
	Direction GetDirection()
	{
		return this->direction;
	}
	virtual void FrameFunc(int x, int y)override;
	Enemy(HGE* hge, std::string Path);
	virtual~Enemy()override;
};