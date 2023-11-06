#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
# define BUFFER_SIZE 5
# define n 2
int buffer[BUFFER_SIZE];
int count=0;
pthread_mutex_t mutex;
sem_t full,empty,wrt;
void *writer(void *arg){
  int item;
  for(int i=0;i<n;i++){
    item = rand()%100;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    buffer[count]=item;
    printf("Writer %ld wrote %d item:\n",(long)arg,item);
    count++;
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
  }
  return NULL;
}
void *reader(void *arg){
  int item;
  for(int i=0;i<n;i++){
    sem_wait(&full);
    sem_wait(&wrt);
    pthread_mutex_lock(&mutex);
    item = buffer[count-1];
    printf("reader %ld read %d item:\n",(long)arg,item);
    count--;
    pthread_mutex_unlock(&mutex);
    sem_post(&wrt);
    sem_post(&empty);
    
  }
  return NULL;
}
int main(){
  int num_readers,num_writers;
  printf("enter the number of writers: \n");
  scanf("%d",&num_writers);
  printf("enter the number of readers: \n");
  scanf("%d",&num_readers);
  pthread_t writers[num_writers];
  pthread_t readers[num_readers];
  
  
  pthread_mutex_init(&mutex,NULL);
  sem_init(&empty,0,BUFFER_SIZE);
  sem_init(&full,0,0);
  sem_init(&wrt,0,1);
  
  for(long i=0;i<num_writers;i++){
    pthread_create(&writers[i],NULL,writer,(void*)i);
  }
  for(long i=0;i<num_readers;i++){
    pthread_create(&readers[i],NULL,reader,(void*)i);
  }
  for(int i=0;i<num_writers;i++){
    pthread_join(writers[i],NULL);
  }
  for(int i=0;i<num_readers;i++){
    pthread_join(readers[i],NULL);
  }
  pthread_mutex_destroy(&mutex);
  sem_destroy(&empty);
  sem_destroy(&full);
  sem_destroy(&wrt);
  return 0;
}