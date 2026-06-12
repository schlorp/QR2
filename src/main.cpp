#include "raylib.h"
#include <iostream>
#include "app.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

void SetupWindowIcon() {
    Image Icon = LoadImage("resources/windowIcon.png");
    SetWindowIcon(Icon);
    UnloadImage(Icon);
}

int main()
{
    InitWindow(1200, 800, "QR Code Generator - raylib + raygui + qrcodegen");

    SetupWindowIcon();

    SetTargetFPS(60);

    GuiLoadStyle("resources/genesis.rgs");

    App app = App();

    while (!WindowShouldClose())
    {
        app.Update();

        app.Draw();
    }

    CloseWindow();
    return 0;
}



//to do
// - drag panels - check
// - dyanamic panel size based on qr code size - check
// - make own textinputbox class that supports other features - check
// - drag class that can be used to drag any panel or window in the application - check
// - qrpanel class that can be reused and has options for the qr code generation and display - check
// - make app class and move all the logic there, make main just initialize and run the app class - check 
// - generate qr code when enter is pressed in the text input box instead of having to click the ok button - check
// - download qr code as png with button in qrpanel - check
// - add option of where to save the png file, instead of just saving it in the project folder with a default name - check
// - add "saved" text when png is downloaded, so the user knows that the download was successful - check
// - add error handling for file operations and qr code generation - check
//      - Error correction level: add option to choose the error correction level of the generated qr code, this will allow users to create qr codes that are more resilient to damage or distortion, the error correction level can be implemented by allowing users to select from different levels (L, M, Q, H) which correspond to different amounts of error correction data being included in the qr code, higher levels will make the qr code more robust but also increase its size - check
//      - Color options: add options to customize the colors of the qr code, such as the color of the modules and the background color - check


//advanced features (upcoming updates)
// - add support for multiple qr codes and a gallery to view them
// - copy paste support 
// - add support for encoding different types of data (url, email, phone number, etc.) and not just plain text
// - add more options for qr code generation (error correction level, size, color, logo, etc.)
//      - QR code Size: add option to choose the size of the generated qr code, as in how many pixels each module (square) of the qr code should be, this will allow users to generate larger or smaller qr codes based on their needs
//      - Logo embedding: add option to embed a logo or image in the center of the qr code, this is a popular feature that allows users to personalize their qr codes and make them more recognizable, it can be implemented by allowing users to upload an image and then overlaying it on top of the generated qr code while ensuring that the qr code remains scannable