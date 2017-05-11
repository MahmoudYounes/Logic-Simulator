#pragma once
// including google test framework
#include "gtest\gtest.h"

#include "..\Logic-Simulator\Components\Component.h"
#include "..\Logic-Simulator\Components\Gate.h"
#include "..\Logic-Simulator\Pins\Pin.h"
#include "..\Logic-Simulator\Components\Connection.h"

#include <vector>

class ConnectionTest : public ::testing::Test, public Connection
{
protected:
	ConnectionTest();

};

TEST(ConnectionTest, )