#pragma once

#include "QRPanel.h"
#include "CustomTextInputBox.h"
#include "colorpanel.h"

class App{
public:
	App();
	~App();

	void Update();
	void Draw();

private:
	bool showQRCode;
	bool showMessageBox;
	bool showColorOptions;

	char textValue[100];
	char* textValuePtr;

	Color* qrColor;

	CustomTextInputBox textInputBox;
	QRPanel qrPanel;
	ColorPanel colorPanel;
};