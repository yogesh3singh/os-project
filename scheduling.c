 // C programe to implement Scheduling using FCFS algorithm
 
 #include<stdio.h>
 #include<conio.h>
 
 // Here we are assuming that all the process arrived at time 0 (same time).
 
 // Function to find the waiting time for all the process
 
 void findwaitingtime(int process[],int n,int bt[],int wt[])
 {
 	
	 //waiting time for first process is 0.
 	  wt[0]=0;
 	  
 	  // calculating waiting time
 	  int i;
 	  for (i=1;i<n;i++)
	   wt[i]=bt[i-1]+wt[i-1]; 
      	
 }
 
 // Function to calculate the turn around time
 
 void findturnaroundtime(int process[],int n,int bt[],int wt[],int tat[])
 {
 	  
 	  // calculating turn around time by adding bt[i]+wt[i]
 	  int i;
 	  for (i=0;i<n;i++)
	   tat[i]=bt[i]+wt[i];     	
 }
 
// Function to calculate the average time 
 
 void findaveragetime(int process[],int n,int bt[])
 {
 	int wt[n],tat[n],total_wt=0,total_tat=0,i;
 	
	// Function Call
 	
	findwaitingtime(process,n,bt,wt);
 	findturnaroundtime(process,n,bt,wt,tat);
 	  
 	// Display the process along with details
 	  
 	printf("Processes  Burst_Time  Waiting_Time  Turn_Around_Time\n");
	 
	// Calculate total wating time and total turn around time  
 	  
 	for (i=0;i<n;i++)
	 {
	 	total_wt=total_wt+wt[i];
	 	total_tat=total_tat+tat[i];
	 	printf("    P%d",i);
	 	printf("       %d",bt[i]);
	 	printf("           %d",wt[i]);
	 	printf("               %d\n",tat[i]);
	 }
	 int s=(float)total_wt/(float)n;
	 int t=(float)total_tat/(float)n;  
	 printf("Average waiting time= %d",s);
	 printf("\n");
	 printf("Average turn around time= %d\n",t); 	
 }
 
 int main(int argc, char *argv[])
 {
 	int p0,p1,p2,p3,p4;
 	
 	// checking if number of arguments is equal to 6 or not
 	
 	if(argc<6 || argc>7)
 	{
 		printf("Enter Six arguments only eg. \"filename arg1 arg2 arg3 arg4 arg5v!!\"");
 		return 0;
	}
	
	//  Converting string type to integer type
	
	p0=atoi(argv[1]);
	p1=atoi(argv[2]);
	p2=atoi(argv[3]);
	p3=atoi(argv[4]);
	p4=atoi(argv[5]);
	
	// Process id's
	
	int process[]={1,2,3,4,5};
	int n=sizeof process/sizeof process[0];
	
	//checking if all the arguments passed are positive or not
	
	if(p0<0 || p1<0 || p2<0 || p3<0 || p4<0)
	{
		printf("The Burst time should be positive ");
		return 1;
	} 
	
	// Burst time for all process passed as command line argument
	
	int burst_time={p0,p1,p2,p3,p4};
	findaveragetime(process,n,burst_time);
	return 0;
 }
