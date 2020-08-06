// banking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<fstream>
#include <string>
#include <map>
#include "Header/Datamanagement.h"
#include "Header/User.h"
#include <string>
#include <any>
#include <vector>
#include<deque>



using namespace std;

//template<typename T>
//struct Node
//{
//    map<string, T> data;
//    struct Node* left, * right, * bottom;
//    Node(map<string, T> data)
//    {
//        this->data = data;
//        left = right = bottom = NULL;
//    }
//
//};


struct custom_map {
    
    map<string, any> data;
    string getDatas(string key) {
        return any_cast<const char*>(data[key]);


    }

    
    
};



int main()
{
    /*cout << endl;
    any a = 5;
    map <string, string> test;
    test["walid"] = "walid";
    map <string, string> test1;

    struct Node<string> root1 = Node<string>(test);
    struct Node<string>* root = &root1;
    auto root2 = Node<string>(test);
    root->data = test1;
    cout << root->data["walid"];*/

    map <string, any> test2;
    string na = "no new frineds";
    test2["walid"] = na;
    string ha = "no new frined";
    map<string, any> testn;

    testn["wali"] = ha;
    struct json_map test = { map<string,any>() };
    test2["test"] = &test;
    cout << test2["test"].type().name() << endl;



    //vector<struct custom_map> testvector;
    struct json_map map1 = { testn };
    struct json_map map2 = { test2 };
    map1.data["what"] = &map2;
    auto map3 = map1;
    auto map4 = map2;
    map4.data["walid"] = ha;
    map3.data["what"] = &map4;
    //map1.compareJson_map(map3);
    //struct custom_map map3 = { map<string,any>() };
    //testvector.push_back(map1);
    //testvector.push_back(map2);
    //testvector.push_back(map3);
    //cout << "0: " << &testvector[0] << endl;
    //cout << "1: " << &testvector[1] << endl;
    //cout << "2: " << &testvector[2] << endl;
    //testvector[1] = map1;
    //testvector[2] = map1;
    //testvector[0].data["james"] = test2;
    //cout << "0: " << &testvector[0] << endl;
    //cout << "1: " << &testvector[1] << endl;
    //cout << "2: " << &testvector[2] << endl;
    //bool testbool = testn == test1;
    
    
    
   bool compare = map1.compareJson_map(map3);
   cout << compare;
    



    //string stest = map2.getDatas("walid");
    //cout << stest;
    //map<string, any> test222 = any_cast<map<string, any>>(testn["name"]);
    //cout << test222["walid"].type().name();
    //struct custom_map map3 = { testn };
    //map3.data["name"] = map2;
    //map2.data["walid"] = "i've changed";
    //map2.data["walid"] = 2;
    ////cout << any_cast<int>(any_cast<struct custom_map>(map3.data["name"]).data["walid"]);
   
    datamanagement tester("C:/Users/wilyx11/Desktop/projects/C++/Banking_management_system/banking//banking/Data/accounts.json");
    
   tester.parsefile();
   //User testuser(&tester, "0");

   

   
   
   

   // print("1ff", "2ff", "3ff");
    
   
    
    //struct custom_map map1 = {};
    //struct custom_map map2 = {};
    //any name = "walid";
    //any map3 = map1;
    //any map4 = map2;
    //cout<< endl <<name.type().name();
    //cout << endl << map4.type().name();


   
   
    




    
    
   

    

    cout << endl;


    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
