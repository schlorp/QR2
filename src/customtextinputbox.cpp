#include "customtextinputbox.h"
#include "raygui.h"
#include <iostream>

CustomTextInputBox::CustomTextInputBox(Rectangle bounds, const char* title, const char* message, const char* buttons, char* textValue, int textValueMaxLen, bool *secretViewActive) {
	this->width = (int)bounds.width;
	this->height = (int)bounds.height;
	this->panelPosition = { bounds.x, bounds.y };
	
	this->title = title;
	this->message = message;
	this->buttons = buttons;
	this->textValue = textValue;
	this->textValueMaxLen = textValueMaxLen;
	this->secretViewActive = secretViewActive;

	this->textValue[0] = 0;
}

CustomTextInputBox::~CustomTextInputBox() {
}

void CustomTextInputBox::Draw() {
	result = GuiTextInputBox(Rectangle{ panelPosition.x, panelPosition.y, (float)width, (float)height }, title, message, buttons, textValue, textValueMaxLen, secretViewActive);
}

int CustomTextInputBox::GetResult() const {
	if (IsKeyPressed(KEY_ENTER)) {
		std::cout << "Enter pressed!" << std::endl;
		return 1;
	}
	
	return result;
}