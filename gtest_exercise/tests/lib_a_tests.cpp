#include <gtest/gtest.h>
#include "lib_x_mock.h"
extern "C" {
#include <lib_a.h>
}

LibXMock LibXMockObj;  /* This is now the actual definition of the mock obj */

class foo : public ::testing::Test
{
protected:
	virtual void SetUp()
	{
	}

	virtual void TearDown()
	{

	}
};

/*
 * verify if lib_a_function() call lib_x_function()
 */
TEST_F(foo, bar)
{
	lib_a_function();
   EXPECT_CALL(LibXMockObj, lib_x_function());

}
