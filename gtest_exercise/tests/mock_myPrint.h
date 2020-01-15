#include <gmock/gmock.h>

class PrintInterface {
public:
	virtual ~PrintInterface() {}
//	virtual int strcmp(char* str1, char* str2) = 0;
	virtual int copyText(const char *input) = 0;
};

class PrintMock : public PrintInterface {
public:
	virtual ~PrintMock() {};
//	MOCK_METHOD2(strcmp, int(char* str1, char* str2)); //method0 because 0 arguments
	MOCK_METHOD1(copyText, int(const char *input));
};

//int	 MyMock::strcmp (const char *, const char *)
//{
//	return 0;
//}
