#include "stdafx.h"
#include "CppUnitTest.h"

#include "../tanks/HandledException.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace sandboxTests
{		
	TEST_CLASS(HandledExceptionTests)
	{
	public:
		
		TEST_METHOD(HandledExceptionShouldCallExceptionHandler)
		{
			bool wasCalled = false;
			HandledException ex;
			
			ex.handle([&wasCalled]() { wasCalled = true; });

			Assert::IsTrue(wasCalled);
		}

	};
}