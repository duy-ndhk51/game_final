#pragma once

#include <Windows.h>
#include <d3dx9.h>
#include <vector>

#include "Sprites.h"


using namespace std;

class CGameObject
{
protected:
	float x; 
	float y;
public: 
	CGameObject();
	CGameObject(float x, float y);
	void RenderBoundingBox();
	void SetPosition(float x, float y) { this->x = x, this->y = y; }
	float GetX() { return x; }
	float GetY() { return y; }
	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom) = 0;

	virtual void Update(DWORD dt) = 0;
	virtual void Render() = 0;
};

