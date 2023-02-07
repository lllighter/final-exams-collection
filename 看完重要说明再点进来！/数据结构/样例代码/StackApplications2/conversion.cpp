#include "arrayStack.h"
#include <stdio.h>
void conversion(int decimal)
{
	//stackPointer top = Create();
	stack s = aCreate(100);
	element temp;
	while(decimal>0){
		int m = decimal % 2;
		decimal = decimal / 2;
		temp.key = m;
		//push(top, temp);
		apush(&s, temp);
	}
	printf("\nThe corresponding binary version is:");
	//while(!IsEmpty(top)){
	while(!aIsEmpty(s)){
		//temp = pop(top);
		temp = apop(&s);
		printf("%d",temp.key);
	}
}

void main()
{
	int decimal;
	printf("\nPlease input the decimal number:");
	scanf("%d", &decimal);
	while(decimal > -1){
		conversion(decimal);
		printf("\nPlease input the decimal number:");
		scanf("%d", &decimal);
	}
	printf("\nBye!");
}