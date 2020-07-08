


#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "header/Datamanagement.h"
#include <list>


std::string json_map::getdatas(std::string key) {
    return std::any_cast<string>(data[key]);


}
std::map<std::string, std::any>  json_map::getdata(std::string key) {
    return std::any_cast<std::map<std::string, std::any>>(data[key]);


}



datamanagement::datamanagement(std::string filename) {
    this->filename = filename;

}

bool datamanagement::loadfile() {

    jsonFile.open(this->filename);
    if (jsonFile.is_open())
    {
        std::cout << "File is loaded" << std::endl;
        string line;
        getline(jsonFile, line);
        cout << line.data();
        return true;
    }
    else
    {
        std::cout << "File Failed to open" << std::endl;
        return false;
    }


};

struct json_map datamanagement::parsefile(std::string filename) {

    static enum Cases {
        INTERMIDIATE,
        OPENING_BRACE,
        CLOSING_BRACE,
        QUOTES,
        FIRST_BRACE,
        INT,
        COMMA

        //others...
    };
    std::string line = "{\"username\":\"walidzein\",\"password\":{\"damn\":{\"another\":\"wowwww\"}}}";
    const std::string KEYREF = "REFEREANCEDONTUSEKEYINFILE";
    struct json_map temp = { std::map<std::string, std::any>() }; //creates a new json_map temp
    int case_num = FIRST_BRACE; //first case for the first brace
    auto it = line.cbegin();
    std::list<struct json_map> nestedMaps;//vector that stores the keys for nested maps
    string key; // stores the current key
    string value; // stores the current value associated with the key
    double valueD;
    struct json_map* mapPt = &jsonmap;
    bool valueIden = false; //identifies if a the value is a string
    bool valueDIden = false; //identifies if the value is a number
    bool mapIden = false; //identifies if the value is a map
    while (it < line.cend()) //iterates through the line
    {

        switch (case_num) {
            //for the intial open brace, checks if the first character of the file is on open brace if yes the json map is intialized
        case FIRST_BRACE:

            if (*it == '{')
            {

                jsonmap = { std::map<std::string, std::any>() };
                nestedMaps.push_back(jsonmap);
                mapPt = &nestedMaps.front();
                std::cout << endl << &nestedMaps.front();
            }
            case_num = INTERMIDIATE;

            break;

            //itermidiate case between all the cases
        case INTERMIDIATE:
            it++;
            if (*it == '{')
            {
                case_num = OPENING_BRACE;
            }
            else if (*it == '}')
            {
                case_num = CLOSING_BRACE;
            }
            else if (*it == '\'' || *it == '\"')
            {
                case_num = QUOTES;
                it++;
            }
            else if (*it == ',')
            {
                case_num = COMMA;
            }
            else if (*it == ':')
            {
                valueIden = true;

            }
            else if (isdigit(*it))
            {
                case_num = INT;
            }
            else
            {
                it++;
            }

            break;

        case OPENING_BRACE:


            std::cout << endl << "parent: " << mapPt;
            temp.data[KEYREF] = mapPt; //adds a pointer to the parent json_map
            nestedMaps.push_back(temp); //adds the temp to the vector of maps
            std::cout << endl << "child: " << &nestedMaps.back();

            //mapPt->data[key] = &nestedMaps.back(); //adds refrance to the child map with the associated key which will always be the last json_map in the vector 
           // std::cout << endl << &nestedMaps.back() << endl;
            mapPt++;
            std::cout << endl << "mapPt of child: " << mapPt;

            mapIden = true;
            key = "";
            value = "";
            valueD = 0;
            valueIden = false;
            valueDIden = false;
            case_num = INTERMIDIATE;
            break;
            // for closing brace either it maps the end of the file or end of a nested map.
        case CLOSING_BRACE:
            if (it == line.cend() - 1)
            {
                it++;
            }

            if (valueIden)
            {
                mapPt->data[key] = value;
            }
            else if (valueDIden)
            {
                mapPt->data[key] = valueD;
            }
            if (mapIden)
            {
                mapPt--;
                mapIden = false;
            }





            //resets value variables 
            key = "";
            value = "";
            valueD = 0;
            valueIden = false;
            valueDIden = false;

            case_num = INTERMIDIATE;

            break;
            //words in qoutes are either keys or string values and are stored accordingly 
        case QUOTES:

            while (*it != '\'' && *it != '\"') { //keep iterating through the characters till end of key/value (when second quote is reached)
                if (!valueIden)
                {
                    key.push_back(*it);
                    it++;
                }
                else
                {
                    value.push_back(*it);
                    it++;
                }

            }

            case_num = INTERMIDIATE;
            break;

        case INT:
            valueDIden = true;
            while (isdigit(*it))
            { //keep iterating through the characters till end of key/value (when second quote is reached)
                value.push_back(*it);
                it++;
            }
            valueD = stoi(value);


            //if a comma is found the value is added to the corresponding key 
        case COMMA:
            if (valueIden)
            {
                mapPt->data[key] = value;
            }
            else if (valueDIden) {
                mapPt->data[key] = valueD;
            }

            //resets value variables 
            key = "";
            value = "";
            valueD = 0;
            valueIden = false;
            valueDIden = false;
            case_num = INTERMIDIATE;


            break;
        default:
            break;

        }
    }

    //struct json_map *mape=  any_cast<struct json_map*>(nestedMaps[0].data["password"]);
    //struct json_map *mapee = any_cast<struct json_map*>((*mape).data["damn"]);
    //struct json_map mapee = (*mape);
    //std::cout << (*mapee).getdatas("another");

    for (std::list<json_map>::iterator vIt = nestedMaps.begin(); vIt != nestedMaps.end(); ++vIt)
    {
        std::cout << &(*vIt) << endl;
    }
    return jsonmap;
}

//json_map datamanagement::parsefile(string filename = "") {
//
//
//}




