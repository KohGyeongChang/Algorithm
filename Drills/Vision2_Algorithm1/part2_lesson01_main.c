#include <stdio.h>

int NumOfCoin = 2;

void coin(int coinValue[], int n)
{
	if ( n == NumOfCoin ) {
		for ( int i = 0; i < NumOfCoin; ++i ) {
			if ( coinValue[i] == 1 ) {
				printf("Front ");
			}
			else {
				printf("Back ");
			}
		}
		printf("\n");

		return;
	}	

	for ( int i = 1; i <= 2; ++i) {
		coinValue[n] = i;

		coin(coinValue, n+1);
	}
}

int main()
{
	printf("Part2 Lesson1 DFS\n");

	int coinValue[2] = { 0 };
	coin(coinValue, 0);

	return 0;
}
