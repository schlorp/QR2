#pragma once
#include "raylib.h"

class DraggablePanel{
public:
	DraggablePanel();
	virtual void Update();

protected:
	Vector2 panelPosition;
	Vector2 mousePosition;

	Vector2 mouseOffset;
	
	bool dragWindow = false;

	int width;
	int height;

	virtual void MovePanel();
};