#include "pch.h"
#include "CppUnitTest.h"
#include "../banking/datamanagement.cpp"
#include "CppUnitTest.h"
#include <functional>
#include <assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			datamanagement test("C:\\Users\\wilyx11\\Desktop\\projects\\C++\\Banking_management_system\\banking\\testFile.json");
			int testFileReturn = test.loadfile();
			Assert::AreEqual(1, testFileReturn);
		}
	};
}
