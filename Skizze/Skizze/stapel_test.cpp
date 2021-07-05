#include "stapel_test.h"
#include "gtest/gtest.h"

TEST_F(stapel_test, testisempty1)
{
	EXPECT_TRUE(object_under_test.is_empty());
}

TEST_F(stapel_test, testisempty2)
{
	object_under_test.push(1);
	EXPECT_FALSE(object_under_test.is_empty());
}
