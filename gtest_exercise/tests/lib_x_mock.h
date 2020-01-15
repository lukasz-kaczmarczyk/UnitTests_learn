#ifndef TESTS_LIB_X_MOCK_H_
#define TESTS_LIB_X_MOCK_H_
#include <gmock/gmock.h>

class LibXInterface {
public:
   virtual ~LibXInterface() {}
   virtual int lib_x_function() = 0;
};

class LibXMock : public LibXInterface {
public:
   virtual ~LibXMock() {}
   MOCK_METHOD0(lib_x_function, int());
};

#endif /* TESTS_LIB_X_MOCK_H_ */
