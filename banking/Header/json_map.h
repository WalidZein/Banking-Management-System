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

	bool compareJson_map(struct json_map dataInput, struct json_map* comparerMap = NULL) 
	{
        int nest = 0; // monitors the nesting level
        bool equality = true;
       
        std::map<std::string, std::any>::iterator it;
        auto rit = dataInput.data.rbegin(); // reverse iterator to check the last element
        
        if (comparerMap == NULL)  // if no pointer to a json_map is provided use the currrent object
        {
            comparerMap = this;
        }

        if ((!dataInput.data.empty() && comparerMap->data.empty()) || (dataInput.data.empty() && !comparerMap->data.empty())) // if one is empty but not the other they are not equal
        {
            equality = false;

        }
        

        for (it = dataInput.data.begin(); it != dataInput.data.end(); it++)
        {
            if (equality == false)
            {
                return false;
            }
            std::string key = it->first;
            std::any val = it->second;
            if (key == "00REFEREANCEDONTUSEKEYINFILE") //settings key nit for user use
            {
                continue;
            }
            std::string comparerType = comparerMap->data[key].type().name(); 
            std::string compareeType = val.type().name();
            std::string stringType = typeid(std::string).name();
            std::string json_mapType = typeid(struct json_map*).name();
            if (!stringType.compare(comparerType) && !stringType.compare(compareeType)) // if value is a string
            {
                std::string comparer = comparerMap->getdata<std::string>(key);
                std::string comparee = dataInput.getdata<std::string>(key);
                equality = equality && (!comparer.compare(comparee));


            }
            else if (!json_mapType.compare(comparerType) && !json_mapType.compare(json_mapType)) // if value is a map
            {

                nest++;
                struct json_map temp = *(dataInput.getdata<struct json_map*>(key));
                const auto itholder = it;
                equality = equality && (compareJson_map(temp, comparerMap->getdata<struct json_map*>(key)));

            }
            else // if value is neither string or json_map then they are not equal 
            {
                equality = false;
                return equality;
            }

        }

        
        return equality;
	}
};