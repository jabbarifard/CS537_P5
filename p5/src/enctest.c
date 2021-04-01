#include "types.h"
#include "stat.h"
#include "user.h"
	
int
main(int argc, char *argv[])
{
	//char* a = malloc(4096);
	//*a = 0xAA // set some value here
	//mencrypt(a,1);

	//stat
	//getpgtable(&stat);

	// see what's inside stat, is it encrypted?
	// try to access value at a
	// you should have *a == 0xAA
	char *ptr = sbrk(4096); // Allocate one page
	mencrypt(ptr, 1); // Encrypt the pages
	struct pt_entry pt_entry; 
	getpgtable(&pt_entry, 1); // Get the page table information for newly allocated page
	exit();
}


