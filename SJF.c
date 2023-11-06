#include<stdio.h>
int at[100],bt[100],ct[100],temp[100];

int main(){
int i,n,j,smallest,count=0;
double avg_tat=0,avg_wt=0;

printf("\nEnter the number of processes : ");
scanf("%d",&n);
printf("\nEnter the details of %d processes : ",n);
for(i=0;i<n;i++){
printf("\nEnter Arrival time for p%d ",i+1);
scanf("%d" ,&at[i]);
printf("\nEnter Burst time for p%d ",i+1);
scanf("%d" ,&bt[i]);
temp[i]=bt[i];
}

bt[99]=1000;
for(i=0;count!=n;i++){
smallest=99;
for(j=0;j<n;j++){
if(at[j]<=i && bt[j]<bt[smallest] && bt[j]>0){
smallest=j;
}
}
bt[smallest]--;
if(bt[smallest]==0){
count++;
ct[smallest]=i+1;
}
}

printf("\np\tAT\tBT\tTAT\tWT");
for(i=0;i<n;i++){
int TAT =ct[i]-at[i];
int WT =TAT -temp[i];
avg_tat +=TAT;
avg_wt +=WT;
printf("\np%d\t%d\t%d\t%d\t%d",i+1,at[i],bt[i],TAT,WT);
}

avg_tat /=n;
avg_wt /=n;

printf("\nAverage turnaround time is  : %lf",avg_tat);
printf("\nAverage Waiting time is  : %lf\n",avg_wt);


return 0;
}






//round robin

#include<stdio.h>

int main(){
	int n, i, j, sum=0, count=0, qt, tat=0, wt=0, at[10], bt[10], temp[10];
	double avg_tat=0, avg_wt=0;
	printf("\nEnter the number of processes in system : ");
	scanf("%d",&n);
	printf("\nEnter the quantum time for processes : ");
	scanf("%d", &qt);
	printf("\nEnter the details of %d prosesses",n);
	for(i=0;i<n;i++){
		printf("\nEnter the arrivel time for p%d : ",i+1);
		scanf("%d",&at[i]);
		printf("\nEnter the burst time for p%d : ",i+1);
		scanf("%d",&bt[i]);
		temp[i] = bt[i];
	}

	int y=n;

	printf("\nP\tAT\tBT\tTAT\tWT");

	for(sum=0 , i=0; y != 0;){
		if ( temp[i] <= qt && temp[i] > 0 ){
			sum=sum+temp[i];
			temp[i]=0;
			count=1;
		}
		else if ( temp[i] > 0 ) {
			temp[i]=temp[i]-qt;
			sum=sum+qt;
		}
		if( count==1 && temp[i]==0 ){
			y--;
			tat = sum-at[i];
			wt = tat-bt[i];
			avg_tat += tat;
			avg_wt += wt;
			printf("\np%d\t%d\t%d\t%d\t%d",i+1, at[i], bt[i], tat, wt);
			count = 0;
		}
		if ( i == n-1 ) {
			i=0;
		}
		else if ( at[i+1] <= sum ){
			i++;
		}
		else{
			i=0;
		}
	}

	avg_tat /=n;
	avg_wt /=n;

	printf("\nAverage turnaround time is %lf" ,avg_tat);
	printf("\nAverage waiting time is %lf" ,avg_wt);
	return 0;
}