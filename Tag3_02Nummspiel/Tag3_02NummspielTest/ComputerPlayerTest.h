#pragma once
#include <gtest/gtest.h>

#include "../Tag3_02Nummspiel/ComputerPlayer.h"

using namespace testing;



class ComputerPlayerTest :
    public Test
{
protected:
	ComputerPlayer object_under_test{"Fritz"};

};

class ComputerPlayerParamerTest :
	public ComputerPlayerTest,public  WithParamInterface<std::pair<int, int>>
{
protected:
	int param;
	int result;


	void SetUp() override
	{
		std::tie<int, int>(param, result) = GetParam();
	}
};









