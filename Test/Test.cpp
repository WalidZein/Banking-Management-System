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
		TEST_METHOD(LoadFileTrue)
		{
			
			datamanagement testob("C:/Users/wilyx11/Desktop/projects/C++/Banking_management_system/banking/Test/testFile.json");
			bool testFileReturn = testob.loadfile();

			Assert::IsTrue(testFileReturn);
					
		}
		//tests loading a non exsisting file
		TEST_METHOD(LoadFileFalse)
		{

			datamanagement testob("C:/Users/wilyx11/Desktop/projects/C++/Banking_management_system/banking/Test/testFile.jso");
			bool testFileReturn = testob.loadfile();

			Assert::IsFalse(testFileReturn);

		}
	};
}
