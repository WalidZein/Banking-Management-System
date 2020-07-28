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
    datamanagement(std::string filename);
    void parsefile(std::string filename = "");
    std::string writeData(struct json_map dataInput = {std::map<std::string,std::any>()});
    std::string getStringFile();
    struct json_map getJson_map();

    template<class... Args>
    auto getValue(Args... args) // takes a list of string arguments corresponding to key path
    {
        std::string value;
        struct json_map* pt = &nestedMaps[0]; // points to the highest level json_map in the vector
        for (auto arg : { args... }) 
        {
           
            std::string type = (*pt).data[arg].type().name();
            std::string stringType = typeid(std::string).name();
            if (!stringType.compare(type)) // if data is string
            {
                value = (*pt).getdata<std::string>(arg);
            }

            else // if json_map
            {
                pt = (*pt).getdata<struct json_map*>(arg);
               
            }
            
        }
        return value;
    }

    template<class... Args>
    void setValue(Args... args) // takes in a list of dtring arguments (key path) and last element is the new value (needs editting for better code)
    {
        struct json_map* pt = &nestedMaps[0];
        std::string keyPath[] = { args... }; //unpacking args into an array
        int arraySize = (sizeof(keyPath) / sizeof(keyPath[0])) - 1;
        std::string value = keyPath[arraySize];  //last element of array is the new value
        
        for (int i = 0; i < arraySize; i++)
        {
            std::string key = keyPath[i];
            std::string type = (*pt).data[key].type().name();
            std::string stringType = typeid(std::string).name();
            if (!stringType.compare(type)) // if current value is string  then new value replaces it.
            {
                (*pt).data[key] = value;
            }

            else 
            {
                pt = (*pt).getdata<struct json_map*>(key);

            }

        }
        
    }
private:
	
    


};

