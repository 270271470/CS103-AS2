#pragma once

#include <fstream>
#include <vector>

using namespace std;

vector<string> split(const string& s, char delimiter);
bool fileExists(const string& filename);