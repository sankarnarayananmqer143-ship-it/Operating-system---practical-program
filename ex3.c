#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pid_t pid;
    char write_msg[] = "Hello from Parent Process";
    char read_msg[50];

    // Create pipe
    if (pipe(fd) == -1) {
        printf("Pipe creation failed\n");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(fd[0]);  // Close read end
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);  // Close write end
    }
    else {
        // Child process
        close(fd[1]);  // Close write end
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received message: %s\n", read_msg);
        close(fd[0]);  // Close read end
    }

    return 0;
}
