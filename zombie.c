#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void bubbleSort(int arr[],int n){
  for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
      if(arr[j]>arr[j+1]){
         int temp=arr[j];
         arr[j]=arr[j+1];
         arr[j+1]=temp;

      }
    }
  }
 printf("\n Sorted Array by bubble sort in child process : ");

  for(int i=0;i<n;i++){
    printf("%d " ,arr[i]);
  }
printf("\n");
}

int main() {
  int n;
  pid_t pid;

  printf("Enter the number of elements : ");
  scanf("%d" ,&n);
  int arr[n];
  printf("Enter the array : ");
  for(int i=0;i<n;i++){
    scanf("%d" ,&arr[i]);
  }
  pid=fork();
  if(pid==0){
  
    printf("\n****** CHILD PROCESS ********\n");
    printf("\nIt is child process with pid = %d and ppid = %d \n",getpid(),getppid());
    bubbleSort(arr,n);
    printf("\n ***** CHILD PROCESS TERMINATED *****\n\n\n");
  }
  else{
  system("\nps -el | grep Z\n");
  wait(NULL);
    printf("\n\n\n****** Parent PROCESS ********\n");
    printf("\nIt is parent process with pid = %d  \n",getpid());
    bubbleSort(arr,n);
    printf("\n ***** PARENT PROCESS TERMINATED *****\n\n");
  }
  

return 0;
}