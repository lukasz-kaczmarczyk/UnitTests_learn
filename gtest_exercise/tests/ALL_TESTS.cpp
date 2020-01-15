#include <gtest/gtest.h>

#define BTEST 0
#define GMOCKTEST 0
#define BCM2835 1

int main(int argc, char **argv)
{
#if BTEST
	::testing::GTEST_FLAG(filter) = "*BTest*";
#elif BCM2835
	::testing::GTEST_FLAG(filter) = "*BCM2835LibUnitTest*";
#elif GMOCKTEST
	::testing::GTEST_FLAG(filter) = "*GMockTests*";
#endif

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
