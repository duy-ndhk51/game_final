#include "Mario.h"
#include "debug.h"

void CMario::Update(DWORD dt)
{
	CGameObject::Update(dt);

	// simple fall down
	vy += MARIO_GRAVITY;
	if (y > 100) 
	{
		vy = 0; y = 100.0f;
	}

	// simple screen edge collision!!!
	if (vx > 0 && x > 290) x = 290;
	if (vx < 0 && x < 0) x = 0;
}

void CMario::Render()
{
	int ani;

	//DebugOut(L"fdsg %d", nx);
	if (vx == 0)
	{
		if (nx > 0) {
			ani = MARIO_ANI_IDLE_RIGHT;
			DebugOut(L"nx %d\n", nx);
		}
		else { 
			ani = MARIO_ANI_IDLE_LEFT;
			DebugOut(L"nx %d\n", nx);
		};
	}
	else if (vx > 0) 
		ani = MARIO_ANI_WALKING_RIGHT; 
	else ani = MARIO_ANI_WALKING_LEFT;

	animations[ani]->Render(x, y);
	//DebugOut(L"dissssss %d %d %d", x, y,vx);
}

void CMario::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case MARIO_STATE_WALKING_RIGHT:
		vx = MARIO_WALKING_SPEED;
		nx = 1;
		break;
	case MARIO_STATE_WALKING_LEFT: 
		vx = -MARIO_WALKING_SPEED;
		nx = -1;
		break;
	case MARIO_STATE_JUMP: 
		if (y==100)
			vy = -MARIO_JUMP_SPEED_Y;

	case MARIO_STATE_IDLE: 
		vx = 0;
		break;
	}
}

