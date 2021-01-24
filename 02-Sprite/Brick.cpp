#include "Brick.h"
void PCBrick::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x;
	t = y;
	r = x + BRICK_WIDTH;
	b = y + BRICK_WIDTH;
}

void PCBrick::Render(){

}

void PCBrick::Update() {
}