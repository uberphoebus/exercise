#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_size;

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("[-]Socket error");
        exit(1);
    }
    printf("[+]Client socket created successfully.\n");

    // Set server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    memset(serverAddr.sin_zero, '\0', sizeof(serverAddr.sin_zero));

    addr_size = sizeof(serverAddr);

    while (1) {
        printf("Client: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline

        // Send message
        sendto(sockfd, buffer, strlen(buffer) + 1, 0, (struct sockaddr*)&serverAddr, addr_size);

        // Receive message
        recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
        printf("Server: %s\n", buffer);
    }

    return 0;
}