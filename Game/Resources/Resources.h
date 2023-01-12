#pragma once

#include <filesystem>
#include <vector>
#include <map>
#include <string>
#include "Game/Texture/Texture.h"

namespace fs = std::filesystem;

class Resources {
public:
	Resources() = delete;
	Resources(std::string directoryName, std::string fileFormat);

private:
	std::map<std::string, Texture> file;
	std::vector<Texture> tex;
	int size;

public:
	Texture& operator[](const std::string& filename);
	Texture& operator[](const size_t& index);

	int GetSize() const;
};