#pragma once

#include "GameObject.h"

#define MARIO_WIDTH 150

class CMario : public CGameObject
{
protected:
	float vx;
	float vy;
public:
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	CMario(float x, float y, float vx, float vy);
	void Update(DWORD dt);
	void Render();
};