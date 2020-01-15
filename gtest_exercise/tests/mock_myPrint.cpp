#include "mock_myPrint.h"

extern PrintMock PrintMockObj;

int copyText(const char *input)
{
	return PrintMockObj.copyText(input);
}
