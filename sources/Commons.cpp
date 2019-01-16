#include "stdafx.h"

#include "Commons.hpp"

using namespace std;

bool IsSpace(char ch)
{
	return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}

int FindEnd(const string& s, int startInd, char openSym, char closeSym)
{
	int counter = 0;
	int i = startInd;
	do
	{
		char sym = s[i++];
		if (sym == openSym)
			++counter;
		else if (sym == closeSym)
			--counter;
	} while (i < s.length() && counter != 0);

	return i;
}

// Находит позицию первого непробельного символа, начиная с current.
int MissSpaces(const string&s, int current)
{
	while (current < s.length() && IsSpace(s[current]))
		++current;

	return current;
}

string GetString(const string &s, int start)
{
	int endStr = start + 1;
	while (endStr < s.length() && s[endStr] != '\"')
		++endStr;

	if (endStr == s.length())
		throw exception("String is not valid!");

	return s.substr(start + 1, endStr - start - 1);
}

bool IsNum(char ch)
{
	return ch >= '0' && ch <= '9';
}

pair<double, int> GetNumWithLen(const string &s, int start)
{
	double result;

	int cur = start;
	bool isDouble = false;
	while (cur < s.length() && IsNum(s[cur]))
		++cur;

	if (cur == s.length())
		throw exception("String is not valid!");

	if (s[cur] == '.')
	{
		++cur;
		while (cur < s.length() && IsNum(s[cur]))
			++cur;
	}

	if (cur == s.length())
		throw exception("String is not valid!");


	stringstream ss;
	string str = s.substr(start, cur - start);
	ss << str;
	ss >> result;

	return pair(result, cur - start);
}
