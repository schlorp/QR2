#include "app.h"
#include "raygui.h"

App::App(){
	showQRCode = false;
	showMessageBox = false;
	showColorOptions = false;

	textValue[100] = { 0 };
	textValuePtr = textValue;

	qrColor = new Color{ 0, 0, 0, 255 };

	textInputBox = CustomTextInputBox(Rectangle{ 350, 70, 250, 250 }, "Text Input Box", "Enter text or URL:", "OK;Cancel", textValuePtr, 100, 0);
	qrPanel = QRPanel(100, 100, 200, 220, qrColor);
	colorPanel = ColorPanel(qrColor, 200, 200, Vector2{ 100, 100 });
}

App::~App(){
}

void App::Update(){
	if (showQRCode)
	{
		qrPanel.Update();
	}
	if (showMessageBox)
	{
		textInputBox.Update();
	}
	if (showColorOptions)
	{
		colorPanel.Update();
	}
}

void App::Draw(){
	BeginDrawing();
		ClearBackground(DARKGRAY);

		if (GuiButton(Rectangle{ 24, 24, 120, 30 }, "Generate QR Code")){
			showMessageBox = true;
		}
		if (GuiButton(Rectangle{ 24, 60, 120, 30 }, "#026#Change Color")){
			showColorOptions = !showColorOptions;
		}

		if (showMessageBox)
		{
			textInputBox.Draw();
			
			int result = textInputBox.GetResult();
			
			if (result == 1)
			{
				showMessageBox = false;

				qrPanel.GenerateQRForPanel(textValuePtr);

				showQRCode = true;
			}
			else if (result >= 0){
				showMessageBox = false;
			}
		}

		if (showColorOptions)
		{
			colorPanel.Draw();

			int result = colorPanel.GetResult();

			if (result > 0){
				showColorOptions = false;
			}
		}

		if (showQRCode)
		{
			qrPanel.Draw();
		}

	EndDrawing();
}