#pragma once

bool IsSpace(char ch);
int FindEnd(const std::string& s, int startInd, char openSym, char closeSym);
int MissSpaces(const std::string&s, int current);
std::string GetString(const std::string &s, int start);
bool IsNum(char ch);
std::pair<double, int> GetNumWithLen(const std::string &s, int start);
