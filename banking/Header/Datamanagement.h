#pragma once
#include<string>
#include <iostream>
#include<fstream>
#include <any>
#include<map>
#include<vector>
#include "Header/json_map.h"




class datamanagement
{
private:
	std::string filename;
	std::ifstream jsonFile;
    struct json_map jsonmap;
	std::string stringFile;
    std::vector<struct json_map> nestedMaps;
    enum Cases {
        INTERMIDIATE,
        OPENING_BRACE,
        CLOSING_BRACE,
        QUOTES,
        FIRST_BRACE,
        INT,
        COMMA

        //others...
    };
    int vectorSize();
    bool loadfile();
	
public:
    void parsefile(std::string filename = "");
    datamanagement(std::string filename);
    template<class... Args>
    auto getValue(Args... args)
    {
        std::string value;
        struct json_map* pt = &nestedMaps[0];
        for (auto arg : { args... })
        {
           
            std::string type = (*pt).data[arg].type().name();
            std::string stringType = typeid(std::string).name();
            if (!stringType.compare(type))
            {
                value = (*pt).getdata<std::string>(arg);
            }

            else
            {
                pt = (*pt).getdata<struct json_map*>(arg);
               
            }
            
        }
        return value;
    }
private:
	
    


};

