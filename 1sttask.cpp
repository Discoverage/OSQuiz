#include <iostream>
#include <unistd.h>     // fork(), getpid(), sleep()
#include <sys/wait.h>   // wait()
#include <sys/syscall.h> // syscall()
#include <vector>

int main() {
    const int NUM_PROCESSES = 3;
    std::vector<pid_t> child_pids;

    for (int i = 0; i < NUM_PROCESSES; i++) {
        pid_t pid = fork();  // Create child process

        if (pid < 0) {
            // Fork failed
            perror("fork failed");
            return 1;
        }
        else if (pid == 0) {
            // Child process
            pid_t child_pid = syscall(SYS_getpid); // Using syscall()
            pid_t parent_pid = syscall(SYS_getppid);

            std::cout << "Child " << i + 1
                      << " | PID: " << child_pid
                      << " | Parent PID: " << parent_pid
                      << std::endl;

            sleep(1); // Simulate work (like "sleep 1" in C#)
            return 0; // Child exits
        }
        else {
            // Parent process
            child_pids.push_back(pid);
        }
    }

    // Parent waits for all children
    for (pid_t pid : child_pids) {
        int status;
        wait(&status); // wait for child
        std::cout << "Child PID " << pid << " finished" << std::endl;
    }

    std::cout << "All children finished" << std::endl;
    return 0;
}
