#include "lib_a.h"
#include "lib_x.h"

int lib_a_function()
{
	int retval = -1;
   retval = lib_x_function();
   return retval;
}
