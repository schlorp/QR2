#pragma once

#include "QRPanel.h"
#include "CustomTextInputBox.h"

class App{
public:
	App();
	~App();

	void Update();
	void Draw();

private:
	bool showQRCode;
	bool showMessageBox;

	char textValue[100];
	char* textValuePtr;

	CustomTextInputBox textInputBox;
	QRPanel qrPanel;
};