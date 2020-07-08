#pragma once
#include<string>
#include <iostream>
#include<fstream>
#include <any>
#include<map>

using namespace std;

struct json_map {

   std::map<std::string, std::any> data;
   std::string getdatas(std::string key);
   std::map<std::string, std::any> getdata(std::string key);
   std::map<std::string, std::any> getdataj(std::string key);


};

class datamanagement
{
private:
	std::string filename;
	std::ifstream jsonFile;
    struct json_map jsonmap;
	std::string stringFile;
	
public:
	bool loadfile();
    struct json_map parsefile(std::string filename = "");
    datamanagement(std::string filename);

private:
	int mapnumber();
    


};

