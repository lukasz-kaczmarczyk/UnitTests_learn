#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "mock_A.h"
extern "C" {
#include <B.h>
}

using testing::_;
using testing::Return;
using testing::InSequence;

class BTest: public testing::Test {

protected:
   AFileMock aFile;

public:
   void SetUp() { }
   void TearDown() { }
};


TEST_F(BTest, test1)
{
   InSequence sequence;

   EXPECT_CALL(aFile, getValue(_, _, _)).
      Times(1);
   formValue();

}
