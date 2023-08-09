#include<stdio.h>
int main(){
	try{
	int n,rev=0;
	printf("ENTER A 32 BIT INTEGER:- ");
	scanf("%d",&n);
	if(n>0){
	while(n!=0){
		rev=rev*10+n%10;
		n=n/10;
	}
	printf("Reverse of the bit is %d",rev);
	}
	else if(n<=0){
		printf("INVALID");
	}
	
}
	catch(int){
		printf("INVALID");
	}
}
