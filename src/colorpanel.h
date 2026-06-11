#include "draggablepanel.h"

class ColorPanel : public DraggablePanel {
public:
	ColorPanel(Color* color, int width, int height, Vector2 position);
	ColorPanel() = default;

	~ColorPanel();

	void CreateColorTexture();

	void Draw();
	int GetResult() const;
private:
	int result;

	Color* qrColor;

	Vector2 colorPickerSize;
	Vector2 colorTextureSize;
	Texture2D* colorTexture;
};