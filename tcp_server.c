#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <netinet/in.h>

int main() {
	char server_message[256] = "you reached server";
	
	//create server
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	
	//define server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9009);
	server_address.sin_addr.s_addr = INADDR_ANY;

	//bind specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

	//listening
	listen(server_socket, 5);
	
	//accept socket
	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);
	
	//send message
	send(client_socket, server_message, sizeof(server_message), 0);

	//close socket
	close(server_socket);			
	return 0;
}
