#ifndef TESTS_MOCK_A_H_
#define TESTS_MOCK_A_H_

//#include "a.h"

class AFileMock {
  public:
    //AFileMock();
    virtual ~AFileMock() {};
    MOCK_METHOD3(getValue, int(int, int *, int *));
};


#endif /* TESTS_MOCK_A_H_ */
