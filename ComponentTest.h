#pragma once
#include "gtest\gtest.h"
#include "..\Logic-Simulator\Components\Component.h"
#include "..\Logic-Simulator\Components\"
using namespace std;

/* Fixture class for Component Class */
class ComponentTest : public ::testing::Test, public Component {
protected:
	
	// ComponentTest Constructor
	ComponentTest();

	
};

// all tests go here
TEST(ComponentTest, TestConstructor){
	Component *p = new ;
	ASSERT_TRUE()
}

TEST(ComponentTest, TestSecondConstructor){

}

TEST(ComponentTest, TestSetSelectedF){

}

TEST(ComponentTest, TestIsSelectedF){

}

//TEST(ComponentTest, )