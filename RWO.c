#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

int readcount=0,nw,nr;
sem_t mutex,wrt;
void *readert(int temp);
void *writert(int temp);

void *readert(int temp){
printf("\nReader %d is trying to read the database",temp);
sem_wait(&mutex);
readcount++;
if(readcount==1)
sem_wait(&wrt);
sem_post(&mutex);
printf("\nReader %d is reading the database",temp);
sem_wait(&mutex);
readcount--;
if(readcount == 0)
sem_post(&wrt);
sem_post(&mutex);
printf("\nReader %d is has left the database\n",temp);
}

void *writert(int temp){
printf("\nWriter %d is trying modify the database",temp);
sem_wait(&wrt);
printf("\nWriter %d is modifying the database",temp);
sleep(10);
printf("\nWriter %d is leaving the database\n",temp);
sem_post(&wrt);
}


int main(){
 long int i;
sem_init(&mutex,0,1);
sem_init(&wrt,0,1);
pthread_t writer[100],reader[100];
printf("Enter the numbers of readers : ");
scanf("%d", &nr);
printf("Enter the number of writer : ");
scanf("%d", &nw);
for(i=1;i<=nw;i++){
pthread_create(&writer[i], NULL, (void *)writert, (int *)i);
pthread_join(writer[i],NULL);
}
for(i=1;i<=nr;i++){
pthread_create(&reader[i], NULL, (void *)readert, (int *)i);
}
for(i=1;i<=nr;i++){
pthread_join(reader[i],NULL);
}
sem_destroy(&mutex);
sem_destroy(&wrt);

return 0;
}