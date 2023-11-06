#include<stdio.h>
#include<stdlib.h>

int main(){
	int RQ[100], i, n, count=0, HM=0, initial;
	int s[100];
	printf("\nEnter the number of request : ");
	scanf("%d",&n);
	printf("\nEnter the request sequence  : ");
	for(i=0;i<n;i++){
		scanf("%d" ,&RQ[i]);
	}
	printf("\nEnter the initial head position : ");
	scanf("%d" ,&initial);

	while ( count != n ){
		int min=1000,d,index;
		for(i=0;i<n;i++){
			d=abs(RQ[i]-initial);
			if(min>d){
				min=d;
				index=i;
			}

		}
		HM +=min;
		initial=RQ[index];
		s[count]=initial;
		RQ[index]=1000;
		count++;
	}
	
	
	printf("Arm sequence : %d",s[0]);
	for(i=1;i<n;i++){
	printf(" ->  %d", s[i]);
	}
	
	printf("\nTotal Seektime %d \n",HM);


	return 0 ;
}