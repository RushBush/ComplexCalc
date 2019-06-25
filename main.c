#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

#include "menu.h"

int main()
{
	void *ptr=dlopen("libmenu.so",RTLD_NOW);

	if (!ptr)
	{
		printf("Can't open 'libmenu.so'\n");
		return -1;
	}

	void (*Menu)()=dlsym(ptr,"Menu");

	if (!Menu)
	{
		printf("Can't find function 'Menu' in 'libmenu.so'\n");
		return -2;
	}

	Menu();

	dlclose(ptr);

	return 0;
}
