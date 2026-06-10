#include "qrmethods.h"

QrCode QRMethods::EncodeText(char *text, QrCode::Ecc errCorLvl){
	QrCode qr = QrCode::encodeText(text, errCorLvl);
	return qr;
}

Texture2D* QRMethods::DrawQRToTexture(QrCode* qr, int qrModuleScale){
    int qrCodeSize = qr->getSize();
    int qrCodeScale = qrModuleScale;
    int width = qrCodeSize * qrCodeScale;
    int height = qrCodeSize * qrCodeScale;

    Color* pixels = new Color[width * height];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int qrX = x / qrCodeScale;
            int qrY = y / qrCodeScale;
            bool isDark = qr->getModule(qrX, qrY);
            pixels[y * width + x] = isDark ? BLACK : WHITE;
        }
    }

    Image img;
    img.data = pixels;
    img.width = width;
    img.height = height;
    img.format = PIXELFORMAT_UNCOMPRESSED_R8G8B8A8;
    img.mipmaps = 1;

    Texture2D* texture = new Texture2D;
    *texture = LoadTextureFromImage(img);

    delete[] pixels;
    return texture;
};