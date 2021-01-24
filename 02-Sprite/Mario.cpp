#include "Game.h"
#include "Mario.h"
#include "debug.h"
#include <random>

CMario::CMario(float x, float y, float vx, float vy):CGameObject(x, y)
{
	this->vx = vx;
	this->vy = vy;
};

void CMario::Update(DWORD dt)
{
	x += 2.0f * vx * dt;
	y += 2.0f * vy * dt;
	
	int BackBufferWidth = CGame::GetInstance()->GetBackBufferWidth();

	int res = (rand() % (5 - 1)) + 601;
	int dau = rand() & 1 ? -1 : 1;
	int dau2 = rand() & 1 ? -1 : 1;

	if (x <= 0 || x >= BackBufferWidth - MARIO_WIDTH || y <= 0 || y >= BackBufferWidth - MARIO_WIDTH) {
		vx = dau * vx;
		vy = dau2 * vy;
		if (x <= 0)
		{
			x = 0;
		}
		else if (y <= 0) {
			y = 0;
		}
		else if (x >= BackBufferWidth - MARIO_WIDTH)
		{
			x = (float)(BackBufferWidth - MARIO_WIDTH);
		}
		else if (y >= BackBufferWidth - MARIO_WIDTH) {
			y = (float)(BackBufferWidth - MARIO_WIDTH);
		}
	}
}

void CMario::Render()
{
	LPANIMATION ani;

	//[RED FLAG][TODO]: Student needs to think about how to associate this animation/asset to Mario!!
	/*if (vx>0) ani = CAnimations::GetInstance()->Get(500);
	else ani = CAnimations::GetInstance()->Get(501);*/
	ani = CAnimations::GetInstance()->Get(500);

	ani->Render(x, y);
}