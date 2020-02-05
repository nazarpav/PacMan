#include <hge.h>
#include <hgesprite.h>
#include <hgefont.h>
#include "Game.h"

HGE* hge = nullptr;
Game* game;
bool frame_func()
{
	game->FrameFunc();
	return game->isGame;
}


bool render_func()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	game->RenderFunc();
	hge->Gfx_EndScene();
	return game->isGame;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_LOGFILE, "hgePacMan.log");
	hge->System_SetState(HGE_FRAMEFUNC, frame_func);
	hge->System_SetState(HGE_RENDERFUNC, render_func);
	hge->System_SetState(HGE_TITLE, "PacMan");
	hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_WINDOWED, false);
	hge->System_SetState(HGE_SCREENWIDTH, 1920);
	hge->System_SetState(HGE_SCREENHEIGHT, 1080);
	hge->System_SetState(HGE_SCREENBPP, 32);

	if (hge->System_Initiate())
	{
		game = new Game(hge);
		hge->System_Start();
	}
	else
	{
		MessageBox(NULL, hge->System_GetErrorMessage(), "Error",
			MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
	}

	hge->System_Shutdown();
	hge->Release();
	return 0;
}
