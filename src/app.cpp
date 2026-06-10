#include "app.h"
#include "raygui.h"

App::App(){
	showQRCode = false;
	showMessageBox = false;

	textValue[100] = { 0 };
	textValuePtr = textValue;

	textInputBox = CustomTextInputBox(Rectangle{ 350, 70, 250, 250 }, "Text Input Box", "Enter text or URL:", "OK;Cancel", textValuePtr, 100, 0);
	qrPanel = QRPanel(100, 100, 200, 220);
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
}

void App::Draw(){
	BeginDrawing();
		ClearBackground(DARKGRAY);

		if (GuiButton(Rectangle{ 24, 24, 120, 30 }, "Generate QR Code"))
		{
			showMessageBox = true;
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

		if (showQRCode)
		{
			qrPanel.Draw();
		}

	EndDrawing();
}