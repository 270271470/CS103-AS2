#include <sstream>
#include "FileOps.h"

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

bool fileExists(const string& filename) {
    ifstream ifile(filename.c_str());
    return ifile.good();
}