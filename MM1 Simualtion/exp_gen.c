#include<stdlib.h>
#include<stdio.h>
#include <math.h>
#define e 2.71828
#define job_size 100000


//generating random number between 0.0 and 1.0
double my_rand()
{
    return((rand() % 32767) / 32767.0);
}

//generating exp dist random numbers for service times using number generated by my_rand function
//and meanmu which is taken from user
double exp_mu(double meanmu)
{

	double numb=my_rand();

    while(numb<(1.e-6)){//(pow(e,-6))
        numb =my_rand();
    }

	return ((-1/meanmu)*log(numb));            
}


//generating exp dist random numbers for interarrival times using number generated by my_rand function
//and meanlambda which is taken from user
double exp_lambda(double meanlambda)
{

	double numb=my_rand();

    while(numb<(1.e-6)){//(pow(e,-6))
        numb =my_rand();
    }
	return ((-1/meanlambda)*log(numb));            
}


//writing iats an service times to txt files
void exp_write(double meanmu, double meanlambda){
    int i;
    double a=0,b;
    FILE *iat =fopen("exp_iat.txt","w");
    FILE *Ts =fopen("exp_Ts.txt","w");
	if(iat==NULL || Ts ==NULL)
	{
		printf("error!!!!");

	}
    fprintf(iat,"%lf\n",a);
    for(i = 0; i<job_size-1; i++){
        a = (double)exp_lambda(meanlambda);
        b = (double)exp_mu(meanmu);
        fprintf(iat,"%lf\n",a);
        fprintf(Ts,"%lf\n",b);
    }
    
    b = (double)exp_mu(meanmu);
    fprintf(Ts,"%lf\n",b);
    rewind(iat);
    rewind(Ts);
    fclose(iat);
    fclose(Ts);
    
}



