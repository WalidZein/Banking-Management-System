#pragma once
#include<string>
#include <iostream>
#include<fstream>
#include <any>
#include<map>
#include<vector>



struct json_map {

	std::map<std::string, std::any> data;

	template<typename A>
	A getdata(std::string key)
	{


		return std::any_cast<A>(data[key]);



	}

};