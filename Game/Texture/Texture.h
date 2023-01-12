#pragma once

#include <string>

class Texture {
private:
	std::string  fileName;

public:
	Texture(std::string fileName);
	Texture();

	void Set(std::string  fileName);

	int spriteSize;
	int width;
	int height;

	int drawPos;

	int textureHandle;

	const Texture& operator=(const Texture &texture);

	void setLoadTexture();
};