#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdio.h>

#define KEY 1234

int main() {

    int shmid;
    int *num;
    void *shared_memory = NULL;

    shmid = shmget(KEY, sizeof(int), 0644 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return -1;
    }

    printf("Memory attached at %X\n", (int)shared_memory);

    char *data = shmat(shmid, (void *)0, 0);
    printf("Write data: ");
    gets(data);
    printf("Data written in memory: %s\n", data);
    shmdt(data);
}