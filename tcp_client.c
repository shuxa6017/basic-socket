#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {
	//CREATION
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	//ADDRESS
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9009);
	server_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	//print error
	if (connection_status == -1){
		printf("error connection  to remote socket \n\n");
	}

	//receive data
	char server_response[256];
	recv(network_socket, &server_response, sizeof(server_response), 0);

	//print data
	printf("server: %s\n", server_response);

	//close socket
	close(network_socket);

	return 0;
}
