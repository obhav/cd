#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_KEY 1234
#define SHM_SIZE 1024

int main() {
    int shm_id;
    char *shm_addr;
    
    if ((shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666)) == -1) {
        perror("shmget");
        exit(1);
    }
    
    if ((shm_addr = shmat(shm_id, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    
    printf("Enter a message to share: ");
    fgets(shm_addr, SHM_SIZE, stdin);
    
    shmdt(shm_addr); //detatch
    
    return 0;
}

