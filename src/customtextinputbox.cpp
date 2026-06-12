#include "customtextinputbox.h"
#include "raygui.h"

CustomTextInputBox::CustomTextInputBox(Rectangle bounds, const char* title, const char* message, const char* buttons, 
	char* textValue, int textValueMaxLen, bool *secretViewActive) {

	this->width = (int)bounds.width;
	this->height = (int)bounds.height;
	this->panelPosition = { bounds.x, bounds.y };
	
	this->title = title;
	this->message = message;
	this->buttons = buttons;
	this->textValue = textValue;
	this->textValueMaxLen = textValueMaxLen;
	this->secretViewActive = secretViewActive;

	this->errorCorrectionLevel = QrCode::Ecc::LOW;

	this->textValue[0] = 0;
}

CustomTextInputBox::~CustomTextInputBox() {
}

void CustomTextInputBox::CreateButtons() {
	int buttonCount = 0;
	const char* tempButtons = buttons;
	while (*tempButtons) {
		if (*tempButtons == ';') {
			buttonCount++;
		}
		tempButtons++;
	}
	buttonCount++; // for the last button

	int buttonWidth = (width - 20) / buttonCount; // 10 padding on each side

	for (int i = 0; i < buttonCount; i++) {
		const char* buttonText = buttons;
		for (int j = 0; j < i; j++) {
			while (*buttonText && *buttonText != ';') {
				buttonText++;
			}
			if (*buttonText == ';') {
				buttonText++;
			}
		}

		char buttonLabel[64];
		int labelIndex = 0;
		while (*buttonText && *buttonText != ';' && labelIndex < 63) {
			buttonLabel[labelIndex++] = *buttonText;
			buttonText++;
		}
		buttonLabel[labelIndex] = '\0';

		if (GuiButton(Rectangle{ panelPosition.x + 15 + i * buttonWidth, panelPosition.y + height - 45, (float)buttonWidth - 10, 30 }, buttonLabel)) {
			result = i + 1; // Button indices start at 0
		}
	}
}

void CustomTextInputBox::Draw() {
	result = -1; // reset result each frame

	GuiWindowBox(Rectangle{ panelPosition.x, panelPosition.y, (float)width, (float)height }, title);

	GuiLabel(Rectangle{ panelPosition.x + 10, panelPosition.y + 30, (float)width - 20, 20 }, message);
	if (GuiTextBox(Rectangle{ panelPosition.x + 10, panelPosition.y + 50, (float)width - 20, 20 }, textValue, textValueMaxLen, textBoxEdit))
		textBoxEdit = !textBoxEdit; 

	GuiLabel(Rectangle{ panelPosition.x + 10, panelPosition.y + 70, (float)width - 20, 20 }, "Error correction level:");
	if (GuiDropdownBox(Rectangle{ panelPosition.x + 10, panelPosition.y + 90, (float)width - 20, 20 }, "LOW;MEDIUM;QUARTILE;HIGH", selectedOption, dropDownEdit)) 
		dropDownEdit = !dropDownEdit;

	CreateButtons();
}

int CustomTextInputBox::GetResult() const {
	if (IsKeyPressed(KEY_ENTER)) {
		std::cout << "Enter pressed!" << std::endl;
		return 1;
	}
	
	return result;
}

QrCode::Ecc CustomTextInputBox::GetErrorCorrectionLevel() const {
	switch (*selectedOption) {
		case 0:
			return QrCode::Ecc::LOW;
		case 1:
			return QrCode::Ecc::MEDIUM;
		case 2:
			return QrCode::Ecc::QUARTILE;
		case 3:
			return QrCode::Ecc::HIGH;
		default:
			return QrCode::Ecc::LOW;
	}
}