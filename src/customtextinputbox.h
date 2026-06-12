#pragma once

#include "draggablepanel.h"

class CustomTextInputBox : public DraggablePanel {
public:
	CustomTextInputBox(Rectangle bounds, const char* title, const char* message, const char* buttons, char* textValue, int textValueMaxLen, bool *secretViewActive);
	CustomTextInputBox() = default;
	
	~CustomTextInputBox();

	void CreateButtons();

	void Draw();

	int GetResult() const;
private:
	const char* title;
	const char* message;
	const char* buttons;
	char* textValue;
	int textValueMaxLen;
	bool *secretViewActive;

	int result = -1; // 0 = no result, 1 = first button, 2 = second button, etc.
	int* selectedOption = new int(0);

	bool dropDownEdit = false;
	bool textBoxEdit = false;
};