#pragma once
#include "pch.h"
#include <string>
#include "pystring/pystring.h"

using namespace std;

class Utils {
public:
	string read_to_string(const string& path);

	string datapath = string(getenv("USERPROFILE")) + "\\betterncm";

	bool check_legal_file_path(const string& path);
	void write_file_text(const string& path, const string& text);
} utils;

string Utils::read_to_string(const string& path) {
	std::ifstream t(path);
	std::stringstream buffer;
	buffer << t.rdbuf();
	return string(buffer.str());
}

bool Utils::check_legal_file_path(const string& path) {
	return pystring::find(path, "..") == -1;
}

void Utils::write_file_text(const string& path, const string& text) {
	ofstream file;
	file.open(path);
	file << text;
	file.close();
}