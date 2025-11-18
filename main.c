#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int server_fd;
    int client_fd;
    struct sockaddr_in addr;
    char buffer[1024];
    char *ip = "127.0.0.1";
    int port = atoi(argv[1]);
    int chat = 1;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); exit(1); }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &addr.sin_addr);

    if (bind(server_fd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind"); exit(1);
    }

    if (listen(server_fd, 1) < 0) {
        perror("listen"); exit(1);
    }

    while (chat == 1) {
        client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) { perror("accept"); exit(1); }
        while(1) {
            int n = read(client_fd, buffer, sizeof(buffer)-1);
            if (n > 0) {
                buffer[n] = '\0';
                printf("%s\n", buffer);
                if (strstr(buffer, "end") != NULL) {
                    printf("Ending chat.\n");
                    close(client_fd);
                    close(server_fd);
                    exit(0);
                }

            }
        }
    }
    close(client_fd);
    close(server_fd);
    return 0;
}