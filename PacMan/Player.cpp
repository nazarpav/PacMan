#include "Player.h"



void Player::FrameFunc(int x, int y)
{
	this->x = x;
	this->y = y;
	if (saveDirection != direction)
	{
		switch (direction)
		{
		case Up:
			texture2 = texture2Up;
			break;
		case Rights:
			texture2 = texture2Rights;
			break;
		case Down:
			texture2 = texture2Down;
			break;
		case Left:
			texture2 = texture2Left;
			break;
		}
		saveDirection = direction;
	}
	if (hge->Timer_GetTime() < saveTime + (isMaxAnimationSpeed ? animationTime2 : animationTime1))
	{
		return;
	}
	else
	{
		saveTime = hge->Timer_GetTime();
	}
	if(animation)
	this->sprite->SetTexture(texture1);
	else
	this->sprite->SetTexture(texture2);
	animation = !animation;
}

Player::Player(HGE* hge, std::string Path) : Enemy(hge, Path)
{
	PacmanSound= hge->Effect_Load("Sounds/pacman_chomp.wav");
	PacmanSoundBoost = hge->Effect_Load("Sounds/pacman_extrapac.wav");
	hge->Effect_PlayEx(PacmanSound,50,0,1.0F,true);
	boostSpeed=3;
	speed = 2;
	this->sprite->SetColor(0xFFFFFF00);
	animation = false;
	isMaxAnimationSpeed = false;
	this->textureSize = 40;
	texture1 = hge->Texture_Load("PacmanTexture/Pacman1.png");
	texture2Up = hge->Texture_Load("PacmanTexture/Pacman2Up.png");
	texture2 = texture2Up;
	direction = Up;
	saveDirection = direction;
	texture2Rights = hge->Texture_Load("PacmanTexture/Pacman2Rights.png");
	texture2Down = hge->Texture_Load("PacmanTexture/Pacman2Down.png");
	texture2Left = hge->Texture_Load("PacmanTexture/Pacman2Left.png");
}


Player::~Player()
{
}
