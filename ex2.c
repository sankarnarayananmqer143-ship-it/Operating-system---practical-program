#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char write_buf[] = "Hello, I/O System Call in C\n";
    char read_buf[50];

    // Open file (create if not exists)
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if (fd < 0) {
        printf("File open failed\n");
        return 1;
    }

    // Write to file
    write(fd, write_buf, sizeof(write_buf));

    // Move file pointer to beginning
    lseek(fd, 0, SEEK_SET);

    // Read from file
    read(fd, read_buf, sizeof(read_buf));

    // Display data
    printf("Data read from file:\n%s", read_buf);

    // Close file
    close(fd);

    return 0;
}