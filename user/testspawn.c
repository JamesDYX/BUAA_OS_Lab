#include "lib.h"

void umain(int argc, char **argv)
{
	char a[]={"testfdsharing.b"};
	char *s1[]={{"hello!"},{"world!"},{"haha"},{NULL}};
	
	spawn(a, s1);

}
