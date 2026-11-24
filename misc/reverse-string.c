#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


void reverse(char* input)
{
	int length = strlen(input);
	int i = 0;
	int j = 0;
	for (i = 0, j = length - 1;i < j;i++, j--)
	{
		char temp = input[i];
		input[i] = input[j];
		input[j] = temp;
	}
}
int main()
{
	char input[] = {0};
	scanf("%s", &input);
	reverse(input);
	printf("%s\n",input);
	return 0;
}
