#pragma warning(disable:4996)
#include<stdio.h>
int main() {
	int n;
	printf("Please enter a integer:");
	scanf("%d",&n);

	printf("%d\n", (1 + n) * n / 2);

	return 0;
}
