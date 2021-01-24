#pragma once
#include "GameObject.h"

#define BRICK_WIDTH 16
#define BRICK_HEIGHT 16
class PCBrick : public CGameObject
{
	int height, width;
	public:

		PCBrick() {
			this->height = 0;
			this->width = 0;
		}
		PCBrick(int Height, int Width) {
			this->width = Width;
			this->height = Height;
		}
		virtual void Render();
		virtual void Update();
		virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
};

