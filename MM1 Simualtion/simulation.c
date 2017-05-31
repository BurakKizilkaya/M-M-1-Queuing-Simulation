#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define job_size 100000

void simulation(){

	double mean_iat, mean_service_time,lambda,mu,rho,util,avg_wait_time,avg_wait_for_who_wait;
	double iat,service_time,total_service_time=0.0,total_iat=0.0,time_in_sys=0.0,service_end = 0.0,mql,wait_time = 0.0,curr_wait;

	int i,wait_cnt=0;
	
	FILE *iat_file =fopen("exp_iat.txt","r");
    FILE *Ts_file =fopen("exp_Ts.txt","r");
	if(iat_file==NULL || Ts_file ==NULL)
	{
		printf("error!!!!");

	}
	
    //reading exp dist random variables for iat and service time from txt file and simulation
	fscanf(iat_file,"%lf",&iat);
	fscanf(Ts_file,"%lf",&service_time);
	
	total_iat += iat;  // total_iat = arrival time
	service_end = total_iat + service_time;
	time_in_sys += service_end - total_iat;
	total_service_time += service_time;
	
	while(!feof(Ts_file)  && !feof(iat_file)){
		fscanf(iat_file,"%lf",&iat);
		fscanf(Ts_file,"%lf",&service_time);
		total_iat += iat;  // total_iat = arrival time
		total_service_time += service_time;

		if(service_end > total_iat){
			
			curr_wait = service_end - total_iat;
			wait_time += curr_wait;
			wait_cnt++;
			service_end = total_iat + curr_wait + service_time;
			time_in_sys += service_end - total_iat; 
		}
		else{
			service_end = total_iat + service_time;
			time_in_sys += service_end - total_iat; 
		}
		
	}
	
	//calculations after simulation
	mean_iat = total_iat / (job_size-1);
	
	mean_service_time = total_service_time / job_size; 

	lambda = 1 / mean_iat;
	mu = 1 / mean_service_time;
	rho = lambda / mu;
	util = rho;
	mql = time_in_sys / service_end;
	avg_wait_time = wait_time / job_size;
	avg_wait_for_who_wait = wait_time / wait_cnt;
	
	
	//printing results
	printf("=============SIMULATION RESULTS FOR M/M/1 QUEUE==============\n");
	printf("Lambda is : %lf\n", lambda);
	printf("Mu is : %lf\n", mu);
	printf("Rho is : %lf\n", rho);
	printf("Utilisation is : %lf\n", util);
	printf("MQL is : %lf\n",mql );
	printf("avg_wait_time is : %lf\n",avg_wait_time );
	printf("avg_wait_for_who_wait is : %lf\n",avg_wait_for_who_wait );
	printf("total time in sys : %lf\n",time_in_sys);
	printf("total sim time : %lf\n",time_in_sys);
}
