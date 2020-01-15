#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string.h>
extern "C" {
#include <myPrint.h>
}
#include "mock_myPrint.h"

using namespace std;

extern char buff[];
string input;
char *input_char;

PrintMock PrintMockObj;

class myPrint_copyTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		memset(buff,0, 100);
		input = "";
		input_char = static_cast<char*>(calloc(10, sizeof(char)));

	}

	virtual void TearDown()
	{
		free(input_char);

	}
};

class myPrint_sendTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		memset(buff,0, 100);


	}

	virtual void TearDown()
	{

	}
};


/*
 * verify if data are copy
 * how to compare with buffer?
 */
TEST_F(myPrint_copyTest, tests1){
	input = "test";
	int result = copyText(input.c_str());
	ASSERT_EQ(0, result);
	result = strcmp((const char*)buff, input.c_str());
	ASSERT_EQ(0, result);
}

TEST_F(myPrint_copyTest, tests2){
	strcpy(input_char, "abc");
	int result = copyText(input_char);
	ASSERT_EQ(0, result);
	result = strcmp((const char*)buff, input_char);
	ASSERT_EQ(0, result);
}

/*
 * verify if SendText call copyText
 */
TEST_F(myPrint_sendTest, tests1)
{
	EXPECT_CALL(PrintMockObj, copyText(testing::_))
			.Times(1);
	SendText("test"); //??? how does it work???
}
