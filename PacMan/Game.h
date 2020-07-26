#pragma once
#include <hge.h>
#include <hgesprite.h>
#include <hgefont.h>
#include <vector>
#include "Block.h"
#include "Enemy.h"
#include "Player.h"


class Game
{
private:
	const int MAXQUANTITYENEMYONMAP = 4;
	HGE* hge;
	Player* player;
	Enemy* ListEnemy[4];
	const int speed = 2;
	float SaveTimeForMoving;
	const float ClockRandomMoving = 0.1f;
	void Control();
	void RenderMap();
	void CreateMap();
	std::vector<Block*> BlockOnMap;
	Direction RandomEnemyMoving();
	bool CheckCollision(BaseObject* obj1, BaseObject* obj2);
public:
	const int TEXTURESIZE = 48;
	bool isGame;
	void FrameFunc();
	void RenderFunc();
	Game(HGE* hge);
	~Game();
private:
	//19*41
	std::string TileMap[19] =
	{
		"0000000000000000000000000000000000000000",//1
		"0___________________0__________________0",//2
		"0_00_00_00_00000000_0_00_00_00_0000000_0",//3
		"0_00_00_00__________0_00_00_00_________0",//4
		"0_00_00_00_00000000_0_00_00_00_0000000_0",//5
		"0__________0___________________________0",//6
		"0000_0_0_0___0_00000_00000_0_00_0_0_0000",//7
		"_____0___0_0_0_0_________0_0_00___0_____",//8
		"0000_0_0_0_0_0_0_________0_0____0_0_0000",//9
		"0____0_0_0_0_0_00000000000_0_00_0_0____0",//10
		"0______________________________________0",//11
		"0000000000000000000_0_000000000000000000",//12
		"0______________________________________0",//13
		"0_00_00_00_00000000_0_00_00_00_0000000_0",//14
		"0_00_00_00__________0_00_00_00_________0",//15
		"0_00_00_00_00000000_0_00_00_00_0000000_0",//16
		"0_0_____0__00____0_______0_______0_____0",//17
		"0____00_______0_____0_________0________0",//18
		"0000000000000000000000000000000000000000"//19
	};
};

