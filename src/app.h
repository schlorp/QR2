#pragma once

#include "qrcodegen.hpp"

#include "QRPanel.h"
#include "CustomTextInputBox.h"
#include "colorpanel.h"

using namespace qrcodegen;

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

	QrCode::Ecc errorCorrectionLevel = QrCode::Ecc::LOW;

	CustomTextInputBox textInputBox;
	QRPanel qrPanel;
	ColorPanel colorPanel;
};