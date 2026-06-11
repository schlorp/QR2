#pragma once
#include "colorpanel.h"
#include "raygui.h"

ColorPanel::ColorPanel(Color* color, int width, int height, Vector2 position) {
	qrColor = color;

	this->width = width;
	this->height = height;
	this->panelPosition = position;

	colorPickerSize = Vector2{ 120, 120 };
	colorTextureSize = Vector2{ (float)width - 40, 20 };
	colorTexture = new Texture2D;

	result = 0;
}

ColorPanel::~ColorPanel(){
}

void ColorPanel::CreateColorTexture(){
	Color* pixels = new Color[(int)(colorTextureSize.x * colorTextureSize.y)];

	for (int y = 0; y < colorTextureSize.y; y++) {
		for (int x = 0; x < colorTextureSize.x; x++) {
			pixels[y * (int)colorTextureSize.x + x] = *qrColor;
		}
	}
	
	Image img;
	img.data = pixels;
	img.width = (int)colorTextureSize.x;
	img.height = (int)colorTextureSize.y;
	img.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
	img.mipmaps = 1;
	
	*colorTexture = LoadTextureFromImage(img);
}

void ColorPanel::Draw(){
	result = GuiWindowBox(Rectangle{ panelPosition.x, panelPosition.y, (float)width, (float)height }, "QR Color Options");

	int diffX = width - colorPickerSize.x;
	GuiColorPicker(Rectangle{ panelPosition.x + diffX / 2 - 15, panelPosition.y + 40, colorPickerSize.x, colorPickerSize.y }, "QR Code Color", qrColor);

	CreateColorTexture();

	diffX = width - (int)colorTextureSize.x;
	DrawTextureRec(*colorTexture, Rectangle{ 0, 0, colorTextureSize.x, colorTextureSize.y }, 
		Vector2{ panelPosition.x + diffX / 2, panelPosition.y + height - colorTextureSize.y - 5 }, WHITE);
}

int ColorPanel::GetResult() const {
	return result;
}