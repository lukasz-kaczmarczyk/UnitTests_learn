#include "lib_x_mock.h"

extern LibXMock LibXMockObj;    /* This is just a declaration! The actual
                                   mock obj must be defined globally in your
                                   test file. */

int lib_x_function()
{
    return LibXMockObj.lib_x_function();
}
