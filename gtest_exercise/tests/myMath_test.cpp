#include <gtest/gtest.h>
extern "C" {
#include <myMath.h>
}

int *num1_p, *num2_p;
int num1, num2;

class myMath_copyTest : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		num1_p = static_cast<int*>(calloc(1, sizeof(int)));
		num2_p = static_cast<int*>(calloc(1, sizeof(int)));
	}

	virtual void TearDown()
	{
		free(num1_p);
		free(num2_p);

	}
};


TEST_F(myMath_copyTest, tests1){
	*num1_p = 11;
	*num2_p = 22;
	swapNum(num1_p, num2_p);
	ASSERT_EQ(22, *num1_p);
	ASSERT_EQ(11, *num2_p);
}

TEST_F(myMath_copyTest, tests2){
	num1 = 45;
	num2 = 100;
	swapNum(&num1, &num2);
	ASSERT_EQ(100, num1);
	ASSERT_EQ(45, num2);
}
