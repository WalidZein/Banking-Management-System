// banking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include<fstream>
#include <string>
#include <map>
#include "Header/Datamanagement.h"
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
    test2["walid"] = "no new frineds";
    map<string, any> testn;

    testn["walid"] = "some new frineds";



    //vector<struct custom_map> testvector;
    struct custom_map map1 = { testn };
    struct custom_map map2 = { test2 };
    testn["name"] = map1;
    auto test1 = testn;
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
    bool testbool = testn == test1;
    
    ifstream fileIn("testFile.json");
    string s;
    string text;

    while (getline(fileIn, s, '\n'))
    {
        text.append(s);
    }
    cout << text << endl;
    
    



    //string stest = map2.getDatas("walid");
    //cout << stest;
    //map<string, any> test222 = any_cast<map<string, any>>(testn["name"]);
    //cout << test222["walid"].type().name();
    //struct custom_map map3 = { testn };
    //map3.data["name"] = map2;
    //map2.data["walid"] = "i've changed";
    //map2.data["walid"] = 2;
    ////cout << any_cast<int>(any_cast<struct custom_map>(map3.data["name"]).data["walid"]);
   
    datamanagement tester("testFile.json");
    
   tester.parsefile();
   tester.writeData();
   

   
   
   

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
