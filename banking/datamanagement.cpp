
#include "Header/Datamanagement.h"







datamanagement::datamanagement(std::string filename) {
    this->filename = filename;

}

std::string datamanagement::getStringFile()
{
    return stringFile;
}

bool datamanagement::loadfile() {

    jsonFile.open(this->filename);
    if (jsonFile.is_open())
    {
        std::cout << "File is loaded" << std::endl;
        
        return true;
    }
    else
    {
        std::cout << "File Failed to open" << std::endl;
        return false;
    }


};

int datamanagement::vectorSize() {
    loadfile();
    int numofmaps = 0;
    std::string line;
    while (getline(jsonFile, line, '\n')) {
        for (auto it = line.begin(); it != line.cend(); it++) {
            if (*it == '{')
            {
                numofmaps++;

            }
            if (!isspace(*it))
            {
                stringFile.push_back(*it);
            }
            
        }
        
    }
    return numofmaps;
}

void datamanagement::parsefile(std::string filename) {
   int i = vectorSize(); //num of json_maps in the vector
   std::cout << std::endl << stringFile;
     
    //std::string line = "{\"username\":\"walidzein\",\"password\":{\"damn\":{\"another\":\"wowwww\"}}}";
    const std::string KEYREF = "00REFEREANCEDONTUSEKEYINFILE";
    struct json_map temp = { std::map<std::string, std::any>() }; //creates a new json_map temp
    int case_num = FIRST_BRACE; //first case for the first brace
    auto it = stringFile.cbegin();
    nestedMaps.resize(i);//vector that stores the keys for nested maps
    int mapElement = 0;
    int mapPosition = 0;
    std::string key; // stores the current key
    std::string value =""; // stores the current value associated with the key
    double valueD;
    int lastElement ;
    struct json_map* mapPt;
    bool valueIden = false; //identifies if a the value is a string
    bool valueDIden = false; //identifies if the value is a number
    bool mapIden = false; //identifies if the value is a map
    bool inParent = false;
    while (it < stringFile.cend()) //iterates through the line
    {

        switch (case_num) {
            //for the intial open brace, checks if the first character of the file is on open brace if yes the json map is intialized
        case FIRST_BRACE:

            if (*it == '{')
            {

                jsonmap = { std::map<std::string, std::any>() };
                nestedMaps[0] = { jsonmap };
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
            

            break;

        case OPENING_BRACE:

           

            temp.data[KEYREF] = &nestedMaps[mapPosition]; //adds a pointer to the parent json_map
            nestedMaps[mapElement+1] = { temp };//adds the temp to the vector of maps
            nestedMaps[mapPosition].data[key] = &nestedMaps[mapElement+1]; //adds refrance to the child map with the associated key which will always be the last json_map in the vector 
            
            mapElement++;
            mapPosition++;

            mapIden = true;
            key = "";
            value = "";
            valueD = 0;
            valueIden = false;
            valueDIden = false;
            inParent = false;
            case_num = INTERMIDIATE;
            break;
            // for closing brace either it maps the end of the file or end of a nested map.
        case CLOSING_BRACE:
            if (it == stringFile.cend() - 1)
            {
                it++;
            }

            if (valueIden && !inParent)
            {
                nestedMaps[mapElement].data[key] = value;
            }
            else if (valueDIden && !inParent)
            {
                nestedMaps[mapElement].data[key] = valueD;
            }
            else if (valueIden && inParent)
            {
                nestedMaps[mapPosition].data[key] = value;
            }
            else if (valueDIden && inParent)
            {
                nestedMaps[mapPosition].data[key] = valueD;
            }

            if (mapIden)
            {
                mapPosition--;
                auto ittemp = it+1;
                while (isspace(*ittemp)) 
                {
                    ittemp++;
                }
                if (*ittemp == ',') 
                {
                    inParent = true;
                }
                else
                {
                    inParent = false;
                }
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
            if (valueIden && !inParent)
            {
                nestedMaps[mapElement].data[key] = value;
            }
            else if (valueDIden && !inParent)
            {
                nestedMaps[mapElement].data[key] = valueD;
            }
            else if (valueIden && inParent)
            {
                nestedMaps[mapPosition].data[key] = value;
            }
            else if (valueDIden && inParent)
            {
                nestedMaps[mapElement].data[key] = value;
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

    /*struct json_map *mape=  any_cast<struct json_map*>(nestedMaps[0].data["password"]);
    struct json_map *mapee = any_cast<struct json_map*>((*mape).data["damn"]);*/
    
    
    
    
    
    
}

std::string datamanagement::writeData(struct json_map dataInput)
{
    int nest = 0;
    std::string jsonString = "{";
    if (dataInput.data.empty())
    {
        dataInput = nestedMaps[0];
    }
    std::map<std::string, std::any>::iterator it;
    auto rit = dataInput.data.rbegin();
    
    
    for (it = dataInput.data.begin(); it != dataInput.data.end(); it++ )
    {
        bool comma = (it != dataInput.data.begin())  && (nest > 0);
        if (comma) 
        {
            jsonString.append(",");
            nest--;
        }
        std::string key = it->first;
        std::any val = it->second;
        if (key == "00REFEREANCEDONTUSEKEYINFILE")
        {
            continue;
        }
        jsonString.append("\"").append(key).append("\"").append(":");
        std::string type = val.type().name();
        std::string stringType = typeid(std::string).name();
        if (!stringType.compare(type))
        {
            std::string stringValue = dataInput.getdata<std::string>(key);
            jsonString.append("\"").append(stringValue).append("\"");
            
            comma = (it != std::prev(rit.base()));
                if (comma)
                {
                    jsonString.append(",");
                }
                
            
        }
        else
        {
            
            nest++;
           struct json_map temp = *(dataInput.getdata<struct json_map*>(key));
            const auto itholder = it;
            jsonString.append(writeData(temp));
            
        }

    }

    jsonString.append("}");
    return jsonString;

}




//json_map datamanagement::parsefile(string filename = "") {
//
//
//}


