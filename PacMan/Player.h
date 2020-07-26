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
	int boostSpeed;
	float animationTime1 = 0.1f;
	float animationTime2 = 0.7f;
	int speed;
	HEFFECT PacmanSound;
	HEFFECT PacmanSoundBoost;
	bool isBoostSoundPlayed = false;
public:
	void SetSpeed(int speed)
	{
		this->speed = speed;
	}
	int GetSpeed()
	{
		return this->speed;
	}
	int GetSpeedBoost()
	{
		return this->boostSpeed;
	}
	void PlayBoostSound()
	{
		if (!isBoostSoundPlayed) {
			PacmanSoundBoost = hge->Effect_Load("Sounds/pacman_extrapac.wav");
			hge->Effect_PlayEx(PacmanSoundBoost, 100, 0, 1.0F, true);
			isBoostSoundPlayed = true;
		}
	}
	void StopBoostSound()
	{
		hge->Effect_Free(PacmanSoundBoost);
		isBoostSoundPlayed = false;
	}
	void FrameFunc(int x, int y)override;
	Player(HGE* hge, std::string Path);
	~Player()override;
};

