#pragma once

#include "qrmethods.h"
#include "draggablepanel.h"
#include "tinyfiledialogs.h"
#include <iostream>

class QRPanel : public DraggablePanel {
public:
	QRPanel(int _x, int _y, int _width, int _height);
	QRPanel() = default;
	~QRPanel();

	void GenerateQRForPanel(char* text);

	const char* GetPreferredFilePath();
	void ExportQRAsPNG();

	void Timer();
	void DrawSavedText();

	void Update() override;
	void Draw();

protected:
	Texture2D* qrTexture;
	
	Vector2 downloadButtonSize;

	float drawSavedTextTime = 2; // time in milliseconds
	float currentSavedTextTime = 0;
	float startTimerTime = 0;

	bool startTimer = false;
	bool showSavedText = false;
};