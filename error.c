#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/socket.h>
int main(void) {
    int sockfd = socket(0, 0, 0);
    printf("Last error was: %d\n", errno);
    printf("Error Message: %s\n", strerror(errno));
}
