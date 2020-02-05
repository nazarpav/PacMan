#include "Game.h"

void Game::Control()
{
	if (player->GetX() < 0)
		player->SetX(1920 - 64);
	else if (player->GetX() > 1920 - TEXTURESIZE)
		player->SetX(0);
	else if (player->GetY() < 0)
		player->SetY(1080 - 64);
	else if (player->GetY() > 1080 - TEXTURESIZE)
		player->SetY(0);
	switch (hge->Input_GetKey())
	{
	case HGEK_ESCAPE:
		isGame = true;
		break;
	case HGEK_LEFT:
		player->SetDirection(Left);
		break;
	case HGEK_RIGHT:
		player->SetDirection(Rights);
		break;
	case HGEK_UP:
		player->SetDirection(Up);
		break;
	case HGEK_DOWN:
		player->SetDirection(Down);
		break;
	}

	if (player->GetDirection() == Up)
	{
		player->SetY(player->GetY() - speed);
		for (int i = 0; i < BlockOnMap.size(); i++)
			if (CheckCollision(player, BlockOnMap[i]))
			{
				player->SetY(player->GetY() + speed);
				return;
			}
	}
	else if (player->GetDirection() == Down)
	{
		player->SetY(player->GetY() + speed);
		for (int i = 0; i < BlockOnMap.size(); i++)
			if (CheckCollision(player, BlockOnMap[i]))
			{
				player->SetY(player->GetY() - speed);
				return;
			}
	}
	else if (player->GetDirection() == Left)
	{
		player->SetX(player->GetX() - speed);
		for (int i = 0; i < BlockOnMap.size(); i++)
			if (CheckCollision(player, BlockOnMap[i]))
			{
				player->SetX(player->GetX() + speed);
				return;
			}
	}
	else if (player->GetDirection() == Rights)
	{
		player->SetX(player->GetX() + speed);
		for (int i = 0; i < BlockOnMap.size(); i++)
			if (CheckCollision(player, BlockOnMap[i]))
			{
				player->SetX(player->GetX() - speed);
				return;
			}
	}
}

void Game::RenderMap()
{
	for (int i = 0; i < BlockOnMap.size(); i++)
	{
		BlockOnMap[i]->RenderFunc();
	}
}

void Game::CreateMap()
{
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 41; j++)
		{
			if (TileMap[i][j] == '0')
				BlockOnMap.push_back(new Block(hge,j* TEXTURESIZE, i * TEXTURESIZE));
		}
	}
}

Direction Game::RandomEnemyMoving()
{
	switch (hge->Random_Int(0, 3))
	{
	case 0:
		return Up;
		break;
	case 1:
		return Rights;
		break;
	case 2:
		return Down;
		break;
	case 3:
		return Left;
		break;
	}
}

bool Game::CheckCollision(BaseObject* obj1, BaseObject* obj2)
{
	int f1ax = obj1->GetX();
	int f1ay = obj1->GetY();
	int f1bx = obj1->GetX() + obj1->GetTextureSize();
	int f1by = obj1->GetY();
	int f1cx = obj1->GetX() + obj1->GetTextureSize();
	int f1cy = obj1->GetY() + obj1->GetTextureSize();
	int f1dx = obj1->GetX();
	int f1dy = obj1->GetY() + obj1->GetTextureSize();

	int f2ax = obj2->GetX();
	int f2ay = obj2->GetY();
	int f2cx = obj2->GetX() + obj2->GetTextureSize();
	int f2cy = obj2->GetY() + obj2->GetTextureSize();

	if (
		f1ax > f2ax&& f1ax <f2cx &&
		f1ay>f2ay&& f1ay < f2cy
		||
		f1bx > f2ax&& f1bx <f2cx &&
		f1by>f2ay&& f1by < f2cy
		||
		f1cx > f2ax&& f1cx <f2cx &&
		f1cy>f2ay&& f1cy < f2cy
		||
		f1dx > f2ax&& f1dx <f2cx &&
		f1dy > f2ay&& f1dy < f2cy
		)
		return true;

	return false;
}

void Game::FrameFunc()
{
	Control();
	player->FrameFunc(player->GetX(), player->GetY());
	for (int i = 0; i < MAXQUANTITYENEMYONMAP; i++)
	{
		if (ListEnemy[i]->GetX() < 0)
			ListEnemy[i]->SetX(1920 - 64);
		else if (ListEnemy[i]->GetX() > 1920 - TEXTURESIZE)
			ListEnemy[i]->SetX(0);
		else if (ListEnemy[i]->GetY() < 0)
			ListEnemy[i]->SetY(1080 - 64);
		else if (ListEnemy[i]->GetY() > 1080 - TEXTURESIZE)
			ListEnemy[i]->SetY(0);
		if (hge->Timer_GetTime() > SaveTimeForMoving + ClockRandomMoving+hge->Random_Float(0.05f,0.1f))
		{
			SaveTimeForMoving = hge->Timer_GetTime();
			ListEnemy[i]->SetDirection(RandomEnemyMoving());
		}

		if (ListEnemy[i]->GetDirection() == Up)
		{
			ListEnemy[i]->SetY(ListEnemy[i]->GetY() - speed);
			for (int j = 0; j < BlockOnMap.size(); j++)
				if (CheckCollision(ListEnemy[i], BlockOnMap[j]))
				{
					ListEnemy[i]->SetY(ListEnemy[i]->GetY() + speed);
					return;
				}
		}
		else if (ListEnemy[i]->GetDirection() == Down)
		{
			ListEnemy[i]->SetY(ListEnemy[i]->GetY() + speed);
			for (int j = 0; j < BlockOnMap.size(); j++)
				if (CheckCollision(ListEnemy[i], BlockOnMap[j]))
				{
					ListEnemy[i]->SetY(ListEnemy[i]->GetY() - speed);
					return;
				}
		}
		else if (ListEnemy[i]->GetDirection() == Left)
		{
			ListEnemy[i]->SetX(ListEnemy[i]->GetX() - speed);
			for (int j = 0; j < BlockOnMap.size(); j++)
				if (CheckCollision(ListEnemy[i], BlockOnMap[j]))
				{
					ListEnemy[i]->SetX(ListEnemy[i]->GetX() + speed);
					return;
				}
		}
		else if (ListEnemy[i]->GetDirection() == Rights)
		{
			ListEnemy[i]->SetX(ListEnemy[i]->GetX() + speed);
			for (int j = 0; j < BlockOnMap.size(); j++)
				if (CheckCollision(ListEnemy[i], BlockOnMap[j]))
				{
					ListEnemy[i]->SetX(ListEnemy[i]->GetX() - speed);
					return;
				}
		}
		ListEnemy[i]->FrameFunc(ListEnemy[i]->GetX(), ListEnemy[i]->GetY());
	}	
}


void Game::RenderFunc()
{
	RenderMap();
	player->RenderFunc();
	for (size_t i = 0; i < MAXQUANTITYENEMYONMAP; i++)
	{
		ListEnemy[i]->RenderFunc();
	}
}

Game::Game(HGE* hge)
{
	this->hge = hge;
	isGame = false;
	player = new Player(hge,"PacmanTexture/Pacman1.png");
	player->SetX(48*4);
	player->SetY(48*4);
	for (size_t i = 0; i < MAXQUANTITYENEMYONMAP; i++)
	{
		ListEnemy[i] =new Enemy(hge, "PacmanTexture/GhostUp.png");
		ListEnemy[i]->SetX(48 * 4);
		ListEnemy[i]->SetY(48 * 4);
	}
	CreateMap();
}


Game::~Game()
{

}
