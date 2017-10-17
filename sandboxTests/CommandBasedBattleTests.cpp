#include "stdafx.h"

#include <functional>

#include "CppUnitTest.h"

#include "../tanks/CommandBasedBattle.h"
#include "../tanks/IBattleCommandInvoker.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace fakeit;

namespace sandboxTests
{
	TEST_CLASS(CommandBasedBattleTests)
	{
	public:

		TEST_METHOD(CommandBasedBattleShouldCallTheCommand)
		{
			bool wasCalled = false;
			BattleCommand command = [&wasCalled]() {wasCalled = true; };

			Mock<IBattleCommandInvoker> mock;
			When(Method(mock, invoke)).Return(command);
			
			CommandBasedBattle battle(mock.get());
			
			battle.process();

			Verify(Method(mock, invoke)).Once();
			Assert::IsTrue(wasCalled);
		}

		TEST_METHOD(CommandBasedBattleShouldThrowBattleExceptionIfBattleCommandInvokerThrowsException)
		{
			Mock<IBattleCommandInvoker> mock;
			When(Method(mock, invoke)).Throw(BattleCommandInvokerException());

			CommandBasedBattle battle(mock.get());
			
			Assert::ExpectException<BattleException>([&battle]() { battle.process(); });

			Verify(Method(mock, invoke)).Once();
		}

		TEST_METHOD(CommandBasedBattleShouldThrowBattleExceptionIfBattleCommandThrowsException)
		{
			bool wasCalled = false;
			BattleCommand command = [&wasCalled]() 
			{
				wasCalled = true; 
				throw BattleCommandException();
			};

			Mock<IBattleCommandInvoker> mock;
			When(Method(mock, invoke)).Return(command);

			CommandBasedBattle battle(mock.get());

			Assert::ExpectException<BattleException>([&battle]() {battle.process(); });

			Verify(Method(mock, invoke)).Once();
			Assert::IsTrue(wasCalled);
		}

	};
}