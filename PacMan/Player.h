#pragma once
#include <hge.h>
#include <hgesprite.h>
#include <hgefont.h>
#include <string>
#include "BaseObject.h"
#include "Direction.h"
#include "Enemy.h"

class Player :public Enemy
{
	HTEXTURE texture1;
	bool animation;
	bool isMaxAnimationSpeed;
	float animationTime1 = 0.1f;
	float animationTime2 = 0.7f;
public:
	void FrameFunc(int x, int y)override;
	Player(HGE* hge, std::string Path);
	~Player()override;
};

