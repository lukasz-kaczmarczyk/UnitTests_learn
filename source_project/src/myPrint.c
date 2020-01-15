#include "myPrint.h"
#include "stdlib.h"
#include "string.h"

char buff[100];


int copyText(const char *input);
int sendData();


void SendText(const char *input)
{
	//copyText(input);
	sendData();

}

int copyText(const char *input)
{
	int result = 0;
	strcpy(buff, (const char*) input);
	if (strcmp((const char*)buff, (const char*)input))
		result = -1;

	return result;
}


int sendData()
{
	//send buff
	return 1;
}
