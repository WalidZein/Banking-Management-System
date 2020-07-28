#include "pch.h"
#include "CppUnitTest.h"
#include "../banking/datamanagement.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BankingTest
{
	TEST_CLASS(DataManagementTest)
	{
	public:
		//tests loading a json file
		TEST_METHOD(stringFileTest)
		{
			
			datamanagement testob("C:/Users/wilyx11/Desktop/projects/C++/Banking_management_system/banking/Test/testFile.json");
			testob.parsefile();
			std::string stringFile = testob.getStringFile();
			std::string stringFileEx = "{\"id\":\"123\",\"username\":\"wilyx11\",\"accountinfo\":{\"birth\":\"20/11/1999\",\"phonenumber\":\"5404044\",\"account\":{\"balance\":400,\"transactions\":{}}}}";
			bool comparesion =!stringFile.compare(stringFileEx);
			Assert::IsTrue(comparesion);
		}
		//tests loading a non exsisting file
		TEST_METHOD(Json_map)
		{

			datamanagement testob("C:/Users/wilyx11/Desktop/projects/C++/Banking_management_system/banking/Test/testFile.json");
			testob.parsefile();
			std::map<std::string, std::any> map0;
			std::map<std::string, std::any> map1;
			std::map<std::string, std::any> map2;
			std::map<std::string, std::any> map3;
			struct json_map json_map0;
			struct json_map json_map1;
			struct json_map json_map2;
			struct json_map json_map3;

			map0["00REFEREANCEDONTUSEKEYINFILE"] = &json_map1;
			map1["00REFEREANCEDONTUSEKEYINFILE"] = &json_map2;
			

			json_map0 = { map0 };
			
			std::string value = "400";
			map1["balance"] = value;
			map1["transactions"] = &json_map0;
			json_map1 = { map1 };

			
			map2["account"] = &json_map1;
			value = "5404044";
			map2["phonenumber"] = value;
			value = "20/11/1999";
			map2["birth"] = value;
			json_map2 = { map2 };
			


			
			value = "123";
			map3["id"] = value;
			value = "wilyx11";
			map3["username"] = value;
			map3["accountinfo"] = &json_map2;
			json_map3 = { map3 };
			
			struct json_map json_mapEx = json_map3;
			struct json_map json_mapRL = testob.getJson_map();

			bool compare = json_mapEx.compareJson_map(json_mapRL);
			Assert::IsTrue(compare);
			

			



		}

		TEST_METHOD(writeMapString)
		{

			datamanagement testob("C:/Users/wilyx11/Desktop/projects/C++/Banking_management_system/banking/Test/testFile.json");
			testob.parsefile();
			std::string outputStringFileEx = "{\"accountinfo\":{\"account\":{\"balance\":\"400\",\"transactions\":{}},\"birth\":\"20/11/1999\",\"phonenumber\":\"5404044\"},\"id\":\"123\",\"username\":\"wilyx11\"}";
			std::string outputStringFile = testob.writeData();
			bool comparesion = !outputStringFile.compare(outputStringFileEx);
			Assert::IsTrue(comparesion);




			

		}
	};
}
