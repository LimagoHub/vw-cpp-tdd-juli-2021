#include "stapel_test.h"


#include "../Tag1_01stapel/stapel_exception.h"
#include "gtest/gtest.h"

const int validValue = 1;

//TEST_F(stapel_test, GivenAnEmptyStack_when_is_empty_called_then_returns_true) {
//
//
//	// Assertion	
//	ASSERT_EQ(1, 2);
//	EXPECT_TRUE(true);
//}

TEST_F(stapel_test, is_empty_empty_stack_returns_true) {

	// Arrange

	// Act

	bool result = object_under_test.is_empty();
	
	// Assertion	
	
	EXPECT_TRUE(result);
}

TEST_F(stapel_test, is_empty_not_empty_stack_returns_false) {

	// Arrange

	object_under_test.push(1);
	
	// Act

	bool result = object_under_test.is_empty();

	// Assertion	

	EXPECT_FALSE(result);
}

TEST_F(stapel_test, is_empty_stack_empty_again_returns_true) {

	// Arrange

	object_under_test.push(validValue);
	object_under_test.pop();

	// Act

	bool result = object_under_test.is_empty();

	// Assertion	

	EXPECT_TRUE(result);
}


TEST_F(stapel_test, push_fill_up_to_limit_no_exception_thrown) {

	for (int i = 0; i < 10; i++)
		EXPECT_NO_THROW(object_under_test.push(1));

	
}

TEST_F(stapel_test, push_overflow_throws_stapelexception) {

	for (int i = 0; i < 10; i++)
		object_under_test.push(i);

	EXPECT_THROW(object_under_test.push(1), stapel_exception);
}

TEST_F(stapel_test, push_overflow_throws_stapelexception_and_error_message_is_overflow) {
	try
	{
		// Arrange
		for (int i = 0; i < 10; i++)
			object_under_test.push(i);

		object_under_test.push(1);
		FAIL() << "expected exception is not thrown";
	}
	catch (stapel_exception & ex)
	{
		EXPECT_STREQ("Overflow", ex.what());
	}
	
}