#include "FilePath.h"

FilePath::FilePath(std::string directoryName, std::string fileFormat) {
	fileFormat = "." + fileFormat;

	for (const fs::directory_entry& x : fs::directory_iterator(directoryName)) {
		if (x.path().extension() == fileFormat) {
			file.insert(std::make_pair(x.path().stem(), "./" + x.path().generic_string()));
		}
	}
}

const std::string& FilePath::operator[](const std::string& filename) {
	return file[filename];
}

std::map<fs::path, std::string> FilePath::getFile() const {
	return this->file;
}