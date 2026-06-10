#include "draggablepanel.h"

DraggablePanel::DraggablePanel(){
}

void DraggablePanel::Update() {
	MovePanel();
}

void DraggablePanel::MovePanel(){
	mousePosition = GetMousePosition();

	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !dragWindow)
	{
		if (CheckCollisionPointRec(mousePosition, Rectangle{ (float)panelPosition.x, (float)panelPosition.y, (float)width, 24 }))
		{
			dragWindow = true;

			mouseOffset.x = mousePosition.x - panelPosition.x;
			mouseOffset.y = mousePosition.y - panelPosition.y;
		}
	}

	if (dragWindow)
	{            
		panelPosition.x = mousePosition.x - mouseOffset.x;
		panelPosition.y = mousePosition.y - mouseOffset.y;

		if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) dragWindow = false;
	}
}