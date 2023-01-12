#pragma once

#include <filesystem>
#include <vector>
#include <map>
#include <string>

namespace fs = std::filesystem;

class FilePath {
public:
	FilePath() = delete;

	/// <summary>
	/// �f�B���N�g�����ɂ������̃t�@�C���`���̃t�@�C���S�Ă�
	/// <para>�f�B���N�g������̃p�X��ۑ�����</para>
	/// </summary>
	/// <param name="directoryName">�f�B���N�g���̖��O</param>
	/// <param name="fileFormat">�ۑ��������t�@�C���`��</param>
	FilePath(std::string directoryName, std::string fileFormat);

private:
	std::map<fs::path, std::string> file;

public:
	/// <summary>
	/// �t�@�C���`�����������t�@�C���̖��O�����邱�Ƃł��̃t�@�C���̃p�X���擾
	/// </summary>
	/// <param name="filname">�t�@�C���`�����������t�@�C���̖��O</param>
	/// <returns>�t�@�C���p�X</returns>
	const std::string& operator[](const std::string& filename);

	std::map<fs::path, std::string> getFile() const;
};