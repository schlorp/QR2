#include "qrcodegen.hpp"
#include "raylib.h"

using namespace qrcodegen;

namespace QRMethods{
	QrCode EncodeText(char *text, QrCode::Ecc errCorLvl);
	
	Texture2D* DrawQRToTexture(QrCode* qr, int qrModuleScale);
};