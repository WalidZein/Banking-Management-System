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
			std::string stringFileEx = "{\"id\":\"123\",\"username\":\"wilyx11\",\"accountinfo\":{\"birth\":\"20/11/1999\",\"phonenumber\":\"5404044\",\"account\":{\"balance\":\"400\",\"transactions\":{}}}}";
			bool comparesion =stringFile.compare(stringFileEx);
			Assert::IsTrue(comparesion);
		}
		//tests loading a non exsisting file
		TEST_METHOD(Json_map)
		{

			datamanagement testob("C:/Users/wilyx11/Desktop/projects/C++/Banking_management_system/banking/Test/testFile.json");
			testob.parsefile();

		}

		TEST_METHOD(VectorSize)
		{

			datamanagement testob("C:/Users/wilyx11/Desktop/projects/C++/Banking_management_system/banking/Test/testFile.json");
			

			

		}
	};
}
