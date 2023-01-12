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
	/// ディレクトリ内にある特定のファイル形式のファイル全ての
	/// <para>ディレクトリからのパスを保存する</para>
	/// </summary>
	/// <param name="directoryName">ディレクトリの名前</param>
	/// <param name="fileFormat">保存したいファイル形式</param>
	FilePath(std::string directoryName, std::string fileFormat);

private:
	std::map<fs::path, std::string> file;

public:
	/// <summary>
	/// ファイル形式を除いたファイルの名前を入れることでそのファイルのパスを取得
	/// </summary>
	/// <param name="filname">ファイル形式を除いたファイルの名前</param>
	/// <returns>ファイルパス</returns>
	const std::string& operator[](const std::string& filename);

	std::map<fs::path, std::string> getFile() const;
};