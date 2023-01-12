#include "Texture.h"
#include <Novice.h>
#include "DxLib.h"
#include <assert.h>
#include <fstream>

Texture::Texture(std::string fileName):
	fileName(fileName),
	width(0),
	height(0),
	textureHandle(Novice::LoadTexture(fileName.c_str())),
	drawPos(0)
{
	FILE* fp;
	errno_t error = fopen_s(&fp, fileName.c_str(), "rb");
	if (fp == NULL) {
		assert("ファイル読み込み失敗");
	}
	fseek(fp, 16L, SEEK_SET);
	fread(&width, sizeof(int), 1, fp);
	fread(&height, sizeof(int), 1, fp);
	fclose(fp);

	width = ((width & 0xFF000000) >> 24) | ((width & 0x00FF0000) >> 8) | ((width & 0x0000FF000000) << 8) | ((width & 0x000000FF) << 24);
	height = ((height & 0xFF000000) >> 24) | ((height & 0x00FF0000) >> 8) | ((height & 0x0000FF000000) << 8) | ((height & 0x000000FF) << 24);

	spriteSize = width;
}

Texture::Texture() {
	spriteSize = 0;
	width = 0;
	height = 0;

	textureHandle = 0;

	drawPos = 0;
}

void Texture::Set(std::string  fileName_) {
	fileName = fileName_;

	textureHandle = Novice::LoadTexture(fileName.c_str());

	FILE* fp;
	errno_t error = fopen_s(&fp, fileName.c_str(), "rb");
	if (fp == NULL) {
		assert("ファイル読み込み失敗");
	}
	fseek(fp, 16L, SEEK_SET);
	fread(&width, sizeof(int), 1, fp);
	fread(&height, sizeof(int), 1, fp);
	fclose(fp);

	width = ((width & 0xFF000000) >> 24) | ((width & 0x00FF0000) >> 8) | ((width & 0x0000FF000000) << 8) | ((width & 0x000000FF) << 24);
	height = ((height & 0xFF000000) >> 24) | ((height & 0x00FF0000) >> 8) | ((height & 0x0000FF000000) << 8) | ((height & 0x000000FF) << 24);

	spriteSize = width;

	drawPos = 0;
}

const Texture& Texture::operator=(const Texture& texture) {
	spriteSize = texture.spriteSize;
	width = texture.width;
	height = texture.height;

	textureHandle = texture.textureHandle;

	drawPos = 0;

	return *this;
}

void Texture::setLoadTexture() {
	textureHandle = Novice::LoadTexture(fileName.c_str());
}