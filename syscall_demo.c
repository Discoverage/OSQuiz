#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
    } else if (pid > 0) {
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        wait(NULL);  // Wait for child to finish
        printf("Child process has finished.\n");
    } else {
        // Fork failed
        perror("Fork failed");
        return 1;
    }

    return 0;
}