#include <d3dx9.h>

#include "debug.h"
#include "Game.h"
#include "GameObject.h"

//#define BRICK_TEXTURE_PATH L"brick.png"
//#define MARIO_TEXTURE_PATH L"mario.png"

//LPDIRECT3DTEXTURE9 texMario = NULL;
//LPDIRECT3DTEXTURE9 texBrick = NULL;

#define MARIO_START_X 10.0f
#define MARIO_START_Y 130.0f
#define MARIO_START_VX 0.1f
/*
	Initialize game object and load a texture
*/
CGameObject::CGameObject(float x, float y, LPDIRECT3DTEXTURE9 tex)
{
	this->x = x;
	this->y = y;
	this->texture = tex;
}

void CGameObject::Render()
{
	CGame::GetInstance()->Draw(x, y, texture);
}

CGameObject::~CGameObject()
{
	if (texture != NULL) texture->Release();
}

#define MARIO_VX 0.1f
#define MARIO_WIDTH 14

void CMario::Update(DWORD dt)
{
	/*x += vx*dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	if (x <= 0 || x >= BackBufferWidth - MARIO_WIDTH) {
		
		vx = -vx;

		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= BackBufferWidth - MARIO_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
		}
	}*/
	y += vy * dt;

	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();
	int BackBufferHeight = CGame::GetInstance()->GetBackBufferHeight();
	CGame* game = CGame::GetInstance();
	LPDIRECT3DTEXTURE9 texBrick = game->LoadTexture(L"brick.png");
	LPDIRECT3DTEXTURE9 texMario = game->LoadTexture(L"mario.png");

	CMario *mario = new CMario(MARIO_START_X, MARIO_START_Y, MARIO_START_VX, MARIO_START_VX, texMario);
	if (y <= 0 || y >= BackBufferHeight - MARIO_WIDTH) {
		vy = -vy;
		mario->Render();
		if (y <= 0)
		{
			y = 0;
		}
		else if (x >= BackBufferHeight - MARIO_WIDTH)
		{
			y = (float)(BackBufferHeight - MARIO_WIDTH);
		}
	}
}
