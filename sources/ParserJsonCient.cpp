#include "pch.h"
#include <iostream>

#include "../JsonParserLib/Json.hpp"
#include "../JsonParserLib/Task3.hpp"

#include <any>


using namespace std;

const char * const json_data = R"(
{
    "lastname" : "Ivanov",
    "firstname" : "Ivan",
    "age" : 25,
    "islegal" : false,
    "marks" : [
    	4,5,5,5,2,3
    ],
    "address" : {
    	"city" : "Moscow",
        "street" : "Vozdvijenka"
    }
})";

const char * const task3_data = R"(
[
    ["Si-9.15", "RTS-9.15", "GAZP-9.15"],
    [100024, 100027, 100050],
    ["Futures contract for USD/RUB", "Futures contract for index RTS", "Futures contract for Gazprom shares"]
]
)";

template <typename T, typename R>
void EXPECT_EQ(T l, R r, string name = "")
{
	if (l != r)
		cout << name + " is failed\n";
	else
		cout << name + " is OK \n";
}

int main()
{
	Json object = Json::parse(json_data);
	EXPECT_EQ(std::any_cast<std::string>(object["lastname"]), "Ivanov");
	EXPECT_EQ(std::any_cast<bool>(object["islegal"]), false);
	EXPECT_EQ(std::any_cast<double>(object["age"]), 25);

	auto marks = std::any_cast<Json>(object["marks"]);
	EXPECT_EQ(std::any_cast<double>(marks[0]), 4);
	EXPECT_EQ(std::any_cast<double>(marks[1]), 5);

	auto address = std::any_cast<Json>(object["address"]);
	EXPECT_EQ(std::any_cast<std::string>(address["city"]), "Moscow");
	EXPECT_EQ(std::any_cast<std::string>(address["street"]), "Vozdvijenka");
	
	Json my_json = Transform(task3_data);
	
	EXPECT_EQ(any_cast<string>(any_cast<Json>(my_json[0])["ticker"]), "Si-9.15");
	EXPECT_EQ(any_cast<string>(any_cast<Json>(my_json[1])["ticker"]), "RTS-9.15");
	EXPECT_EQ(any_cast<string>(any_cast<Json>(my_json[2])["ticker"]), "GAZP-9.15");
	EXPECT_EQ(any_cast<double>(any_cast<Json>(my_json[0])["id"]), 100024);
	EXPECT_EQ(any_cast<double>(any_cast<Json>(my_json[1])["id"]), 100027);
	EXPECT_EQ(any_cast<double>(any_cast<Json>(my_json[2])["id"]), 100050);
	EXPECT_EQ(any_cast<string>(any_cast<Json>(my_json[0])["description"]), "Futures contract for USD/RUB");
	EXPECT_EQ(any_cast<string>(any_cast<Json>(my_json[1])["description"]), "Futures contract for index RTS");
	EXPECT_EQ(any_cast<string>(any_cast<Json>(my_json[2])["description"]), "Futures contract for Gazprom shares");

}
