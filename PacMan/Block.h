#pragma once
#include <hge.h>
#include <hgesprite.h>
#include <hgefont.h>
#include <string>
#include "BaseObject.h"
class Block:public BaseObject
{
public:
	Block(HGE* hge,int x,int y);
	~Block()override;
};

