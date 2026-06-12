#include "qrpanel.h"
#include "raygui.h"

QRPanel::QRPanel(int _x, int _y, int _width, int _height, Color* _qrColor) {
	panelPosition = { (float)_x, (float)_y };
	width = _width;
	height = _height;
	qrColor = _qrColor;

	downloadButtonSize = { 120, 30 };
}

QRPanel::~QRPanel() {
}

void QRPanel::GenerateQRForPanel(char* text, QrCode::Ecc errorCorrectionLevel) {
	QrCode qr = QRMethods::EncodeText(text, errorCorrectionLevel);
    qrTexture = QRMethods::DrawQRToTexture(&qr, 10, qrColor);
}

const char* QRPanel::GetPreferredFilePath() {
	const char* filters[] = {"*.png"};

	const char* savePath = tinyfd_saveFileDialog(
		"Save QR Code",
		"qrcode.png",
		1,
		filters,
		"PNG Image"
	);

	return savePath;
}

void QRPanel::ExportQRAsPNG() {
	const char* savePath = GetPreferredFilePath();

	if (savePath == nullptr)
		return;

	Image qrImage = LoadImageFromTexture(*qrTexture);
	bool exported = ExportImage(qrImage, savePath);
	UnloadImage(qrImage);

	if (exported) {
		startTimer = true;
	} else {
		std::cerr << "Failed to save QR code at: " << savePath << std::endl;
	}
}

void QRPanel::Timer() {
	if (startTimer) {
		if (!showSavedText){
			showSavedText = true;
			startTimerTime = GetTime();
		}
		currentSavedTextTime = GetTime() - startTimerTime;

		if (currentSavedTextTime >= drawSavedTextTime) {
			currentSavedTextTime = 0;
			startTimer = false;
			showSavedText = false;
		}
	}
}

void QRPanel::DrawSavedText() {
	const char* savedText = "Saved!";
	int textWidth = MeasureText(savedText, 20);
	float textPosX = panelPosition.x + width / 2 - textWidth / 2;
	float textPosY = panelPosition.y + height;

	DrawText(savedText, textPosX, textPosY, 20, WHITE);
}

void QRPanel::Update() {
	DraggablePanel::Update();
	Timer();
}

// Magic numbers can be changed with variables or constants, when everything is working and the code is clean and organized, but for now they are here to make the code work and be testable.
void QRPanel::Draw() {
	width = qrTexture->width + 20;
	height = qrTexture->height + downloadButtonSize.y + 45;

	int diffX = width - qrTexture->width;

	int result = GuiPanel(Rectangle{ (float)panelPosition.x, (float)panelPosition.y, (float)width, (float)height }, "QR Code Panel"); 

    DrawTexture(*qrTexture, panelPosition.x + diffX / 2, panelPosition.y + 34, WHITE);

	float buttonPosX = panelPosition.x + width / 2 - downloadButtonSize.x / 2;
	float buttonPosY = panelPosition.y + height - downloadButtonSize.y - 5;

	int resultButton = GuiButton(Rectangle{ buttonPosX, buttonPosY, downloadButtonSize.x, downloadButtonSize.y }, 
		"#006#Download PNG");

	if (resultButton) {
		ExportQRAsPNG();
	}

	if (showSavedText) {
		DrawSavedText();
	}
}
