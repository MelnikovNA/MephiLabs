/*Lab №1 Variant 18*/
#include <stdio.h>

int compare(int number);
int inv(int number);

int main(){
	int start, end;
	printf("Set Section\nSection Start: ");
	scanf("%d", &start);/*Section Start*/
	printf("Section End: ");
	scanf("%d", &end);/*Section End*/
	if (start>end){
		printf("Error Input Data");
		return 0;
	}
	printf("Result(s):");
	while (start!=end+1){
		compare(start);
		start+=1;
	};
	return 0;
};


int compare(int number){
	int sqnum=number*number; /*Squaring the number*/
	int num1 = inv(sqnum);/*The original number squared inverted*/
	int revnum = inv(number);/*Inverted original number*/
	int num2 = revnum*revnum;/*Squaring the new number*/

	if (num1 == num2){
		printf("%d, ", number);
		return 0;
	}
	else{
		return 0;
	};
};


int inv(int number){ /*Inverted Number*/
	int newnum = 0;
	while (number!=0){
		newnum+=number%10;
		newnum*=10;
		number/=10;
	}
	newnum/=10;
	return newnum;
};
