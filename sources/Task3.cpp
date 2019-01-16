#include "stdafx.h"
#include "Task3.hpp"

using namespace std;

Json Transform(const std::string & s)
{
	Json data(s);

	if (!data.is_array())
		throw exception("Wrong string");

	if (data.GetArrSize() != 3)
		throw exception("Wrong string");

	stringstream ss;

	int size = any_cast<Json>(data[0]).GetArrSize();
	if (size != any_cast<Json>(data[1]).GetArrSize() || size != any_cast<Json>(data[2]).GetArrSize())
		throw exception("Wrong string");

	ss << "[";
	for (int i = 0; i < size; ++i)
	{
		ss << "{";
		ss << "\"ticker\":\"" << any_cast<string>(any_cast<Json>(data[0])[i]) << "\",";
		ss << "\"id\":" << any_cast<double>(any_cast<Json>(data[1])[i]) << ",";
		ss << "\"description\":\"" << any_cast<string>(any_cast<Json>(data[2])[i]) << "\"";
		ss << "}";

		if (i != size - 1)
			ss << ",";
	}

	ss << "]";

	string str;
	getline(ss, str);

	return Json(str);
}
