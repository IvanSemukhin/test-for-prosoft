#include <stdio.h>
#include <math.h>

#define TETR 4

typedef unsigned long int UINT;
typedef unsigned char BYTE;

void print_bin(UINT num);

int main()
{
	printf("sizeof(UINT) = [%ld]\n\n", sizeof(UINT));
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

void print_bin(UINT num)
{
	if(0 == num){
		puts("|0000|");
		return;
	}
		
	BYTE kol_bit = log2(num)+1;
	BYTE kol_iter = TETR*(kol_bit%TETR ? kol_bit/TETR+1 : kol_bit/TETR);

	UINT start = 1UL << (kol_iter-1);
	
	printf("|");
	for(UINT i=0; i < kol_iter; i++){
		if(!(i%TETR) && i!=0)
			printf("|");
		printf("%d", (num & (start>>i)) ? 1 : 0);
	}
	printf("|\n");
}
