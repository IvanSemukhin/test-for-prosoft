#include <stdio.h>
#include <math.h>

#define SIZE_TETR 4

typedef unsigned long int DWORD;
typedef unsigned char UBYTE;

void print_bin(DWORD num);

int main()
{
	printf("sizeof(unsigned long int) = [%ld]\n\n",
			sizeof(unsigned long int));
	print_bin(0);
	print_bin(1);
	print_bin(5);
	print_bin(7);
	print_bin(8);
	print_bin(15);
	print_bin(16);
	puts("");
	print_bin(67);
	print_bin(3735928559);
	print_bin(5678);
	puts("");
	print_bin(0xFFFFFF7F);
	print_bin(0xFFFFFF80);
	print_bin(0xFFFFFFFE);
	print_bin(0xFFFFFFFF);
	return 0;
}

void print_bin(DWORD num)
{
	if(0 == num){
		puts("|0000|");
		return;
	}
		
	UBYTE kol_bit = log2(num)+1;
	UBYTE kol_iter = SIZE_TETR *(kol_bit%SIZE_TETR ?
								 kol_bit/SIZE_TETR+1 :
								 kol_bit/SIZE_TETR);

	DWORD start = 1UL << (kol_iter-1);
	
	printf("|");
	for(DWORD i=0; i < kol_iter; i++){
		if(!(i%SIZE_TETR) && i!=0)
			printf("|");
		printf("%d", (num & (start>>i)) ? 1 : 0);
	}
	printf("|\n");
}
