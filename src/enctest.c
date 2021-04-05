#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"
#include "ptentry.h"
	
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
	char *ptr = sbrk(PGSIZE * 3); // Allocate one page
	// mencrypt(ptr, 1); // Encrypt 1 out of 3 pages
	mencrypt(ptr, 0); // Encrypt 2 out of 3 pages
	// mencrypt(ptr, 1); // Encrypt 3 out of 3 pages
	struct pt_entry pt_entries[3];

	getpgtable(pt_entries, 3);
	for (int i = 0; i < 3; i++) {
		printf(1, "XV6_TEST_OUTPUT Index %d: pdx: 0x%x, ptx: 0x%x, present bit: %d, writable bit: %d, encrypted: %d\n", 
			i,
			pt_entries[i].pdx,
			pt_entries[i].ptx,
			pt_entries[i].present,
			pt_entries[i].writable,
			pt_entries[i].encrypted
		);
	}

	printf(1, "decrypting...\n"); 

	// Trigger a decrypt
	for (int i = 0; i < 1; i++) 
    {
        ptr[(i + 1) * (4096) - 1] = 0xAA;
    }

	getpgtable(pt_entries, 3);
	for (int i = 0; i < 3; i++) {
		printf(1, "XV6_TEST_OUTPUT Index %d: pdx: 0x%x, ptx: 0x%x, present bit: %d, writable bit: %d, encrypted: %d\n", 
			i,
			pt_entries[i].pdx,
			pt_entries[i].ptx,
			pt_entries[i].present,
			pt_entries[i].writable,
			pt_entries[i].encrypted
		);
	}
    


	exit();
}


