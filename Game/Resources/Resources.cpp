#include "Resources.h"

Resources::Resources(std::string directoryName, std::string fileFormat) :
	tex(0),
	size(0)
{
	fileFormat = "." + fileFormat;

	for (const fs::directory_entry& x : fs::directory_iterator(directoryName)) {
		if (x.path().extension() == fileFormat) {
			tex.emplace_back(Texture("./" + x.path().generic_string()));
			file.insert(std::make_pair(x.path().stem().generic_string(), tex[size]));
			size++;
		}
	}
}

Texture& Resources::operator[](const std::string& filename) {
	return file[filename];
}

Texture& Resources::operator[](const size_t& index) {
	return tex[index];
}

int Resources::GetSize() const {
	return size;
}