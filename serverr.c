#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1024

void bit_stuffing(char *data, char *stuffed_data) {
    int count = 0, j = 0;
    for (int i = 0; i < strlen(data); i++) {
        stuffed_data[j++] = data[i];
        if (data[i] == '1') count++;
        else count = 0;
        if (count == 5) {
            stuffed_data[j++] = '0';
            count = 0;
        }
    }
    stuffed_data[j] = '\0';
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[MAX] = {0};
    char stuffed_data[MAX] = {0};

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);
    read(new_socket, buffer, MAX);

    bit_stuffing(buffer, stuffed_data);
    send(new_socket, stuffed_data, strlen(stuffed_data), 0);

    close(new_socket);
    close(server_fd);
    return 0;
}