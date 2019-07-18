#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

// int open (const char *name, int flags);
// int open (const char *name, int flags, mode_t mode);

int main (void) {
    int fd, r_fd;
    const char *filename = "/Users/dawn/Documents/study/TIL/LSP/test";

    fd = open(filename, O_RDWR);
    if (fd == -1) {
        // if there's no file located in filename(file not found)
        printf("err\n");
    }

//    fd = open (filename, O_WRONLY | O_TRUNC);

    fd = open (filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        fprintf(stderr, "creating file\n");
    } else {
        printf("file created via open\n");
    }

    fd = creat (filename, 0644);
    if (fd == -1) {
        fprintf(stderr, "creating file by creat()\n");
    } else {
        printf("file created via creat\n");
    }

// ssize_t read (int fd, void *buf, size_t len);
    unsigned long word;
    ssize_t nr;

    // read bytes from `fd` and store to `word`
    nr = read (fd, &word, sizeof(unsigned long));
    if (nr == -1) {
        fprintf(stderr, "reading file\n");
    } else {
        printf("%lu\n", word);
    }

    return 0;
}