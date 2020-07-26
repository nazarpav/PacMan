#include "Enemy.h"

void Enemy::FrameFunc(int x, int y)
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
		this->sprite->SetTexture(texture2);
	}
}

Enemy::Enemy(HGE* hge,std::string Path) : BaseObject(hge, Path.c_str())
{
	Color = hge->Random_Int(4278190080, 4294967295);
	this->textureSize = 40;
	this->sprite->SetColor(Color);
	texture2Up = hge->Texture_Load("PacmanTexture/GhostUp.png");
	texture2 = texture2Up;
	direction = Up;
	saveDirection = direction;
	texture2Rights = hge->Texture_Load("PacmanTexture/GhostRights.png");
	texture2Down = hge->Texture_Load("PacmanTexture/GhostDown.png");
	texture2Left = hge->Texture_Load("PacmanTexture/GhostLeft.png");
}

Enemy::~Enemy()
{
}
