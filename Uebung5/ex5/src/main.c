#include "../include/main.h"


int main(int argc, char *argv[])
{
    int socket_fd;
    int portno;
    socklen_t clilen;
    int new_socket_fd;
    int n;
    char buffer[250];
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;
    if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error regarding socket creation!");
        exit(EXIT_FAILURE);
    }
    
    if(argc < 2) {
        fprintf(stderr, "No port supplied!");
        exit(EXIT_FAILURE);
    }

    portno = atoi(argv[1]);
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if(bind(socket_fd, (struct sockaddr* ) &serv_addr,
                sizeof(struct sockaddr_in)) < 0) {
        perror("Error on binding!");
        exit(EXIT_FAILURE);
    }

    listen(socket_fd,5);
    clilen = sizeof(cli_addr);
    new_socket_fd = accept(socket_fd, (struct sockaddr*) &cli_addr,
            &clilen);
    if (new_socket_fd < 0) {
        perror("Error on accept!");
    }

    memset(buffer,0,250);
    n = read(new_socket_fd, buffer, 250);
    if(n < 0) {
        perror("Error reading from socket!");
    }
    fprintf(stderr, "Here is the message: %s\n", buffer);

    return EXIT_SUCCESS;
}
