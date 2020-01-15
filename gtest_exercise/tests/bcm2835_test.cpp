/// MOCKING C-Functions with GMOCK :)
#include <memory>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
extern "C" {
#include <bcm2835.h>
}
using namespace ::testing;
using ::testing::Return;

/*
 * Mock BCM2835Lib functions
 */

class BCM2835Lib_MOCK{
public:
    virtual ~BCM2835Lib_MOCK(){}

    // mock methods
    MOCK_METHOD0(bcm2835_init,int());
    MOCK_METHOD2(bcm2835_gpio_fsel,void(uint8_t,uint8_t));
};


/* Create a TestFixture */

class TestFixture: public ::testing::Test{
public:
    TestFixture(){
        _bcm2835libMock.reset(new ::testing::NiceMock<BCM2835Lib_MOCK>());
    }
    ~TestFixture(){
        _bcm2835libMock.reset();
    }
    virtual void SetUp(){}
    virtual void TearDown(){}

    // pointer for accessing mocked library
    static std::unique_ptr<BCM2835Lib_MOCK> _bcm2835libMock;
};

// instantiate mocked lib
std::unique_ptr<BCM2835Lib_MOCK> TestFixture::_bcm2835libMock;

// fake lib functions
int  bcm2835_init()
{
	return TestFixture::_bcm2835libMock->bcm2835_init();
}

void bcm2835_gpio_fsel(uint8_t pin, uint8_t mode)
{
	TestFixture::_bcm2835libMock->bcm2835_gpio_fsel(pin,mode);
}

// create unit testing class for BCM2835 from TestFixture
class BCM2835LibUnitTest : public TestFixture{
public:
    BCM2835LibUnitTest(){
        // here you can put some initializations
    }
};


TEST_F(BCM2835LibUnitTest,inits){
    EXPECT_CALL(*_bcm2835libMock,bcm2835_init()).Times(1).WillOnce(Return(1));
    inits();
    //EXPECT_EQ(1,inits()) << "init must return 1";
}

//TEST_F(BCM2835LibUnitTest,pinModeTest){
//
//    EXPECT_CALL(*_bcm2835libMock,bcm2835_gpio_fsel( (uint8_t)RPI_V2_GPIO_P1_18
//                                                   ,(uint8_t)BCM2835_GPIO_FSEL_OUTP
//                                                  )
//               )
//               .Times(1)
//               ;
//
//    pinMode((uint8_t)RPI_V2_GPIO_P1_18,(uint8_t)BCM2835_GPIO_FSEL_OUTP);
//}
