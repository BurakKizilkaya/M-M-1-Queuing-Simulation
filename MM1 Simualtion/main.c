#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int main(){
	double meanmu, meanlambda;
	
	//getting meanlambda and meanmu from user to create random variables
	printf("enter lambda: "),
	scanf("%lf", &meanlambda);
	printf("enter mu: ");
	scanf("%lf", &meanmu);
	
	//writing created random variables which are iat and service times to txt file 
	exp_write(meanmu,meanlambda);
	
	//running simulation
	simulation();

	return 0;
}
