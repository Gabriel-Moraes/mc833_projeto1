// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#define SockAddr struct sockaddr
#define PORT	 8080
#define MAXLINE 1024
char* removeNewLinesServer(char* data){
    int len = strlen(data);
    int i;
    for(i=0;i < len ; i++){
        if(data[i]=='\n' || data[i] == '\t'|| data[i] == '\r') {
            data[i] = 0;
        }
    }
    return data;
}

void exchangeMessages(int sock, struct sockaddr_in clientAdress) {
    char buff[MAX];
    int lenMessage;
    // Loop infinito para manter a troca de mensagens
    while (1) {
		// Zera o conteúdo do buffer
        bzero(buff, MAX);

        // Le a mensagem recebida e copia para o buffer
        read(sock, buff, sizeof(buff));

		// Printa a mensagem recebida
        printf("Mensagem recebida do cliente %d: %s\n", sock, buff);
		char* buff2 = removeNewLinesServer(buff);
		printf("esse e o buffer %s<\n", buff);
		printf("esse e o sock %d<\n", sock);
		
		int requestError = treatClientActionRequest(sock, buff2);
		if (requestError == -2) {
	        // Caso o retorno seja -2, fecha a conexao
			// write(sock, "5", 2);
			// write(sock, "exit\n", 5);
            sendto(sock, "5", strlen("5"),
		MSG_CONFIRM, (const struct sockaddr *) &clientAdress,
			lenMessage);
            sendto(sock, "exit\n", strlen("exit\n"),
		MSG_CONFIRM, (const struct sockaddr *) &clientAdress,
			lenMessage);
			printf("Cliente %d saiu do servidor...\n", sock);
            break;
		} else if (requestError < 0) {

            sendto(sock, "16", strlen("16"),
		MSG_CONFIRM, (const struct sockaddr *) &clientAdress,
			lenMessage);
            sendto(sock, "Açao invalida!\n", strlen("Açao invalida!\n"),
		MSG_CONFIRM, (const struct sockaddr *) &clientAdress,
			lenMessage);
			printf("requisicao: %d", requestError);
		}
    }
}
// Driver code
int main() {
	int sock;
	char buffer[MAXLINE];
	char *hello = "Hello from server";
	struct sockaddr_in servAddress, clientAdress;
	int client_socket[10];
    int i, master_socket;
    // Inicializa o vetor de sockets 
	for (i=0; i < 10; i++) {
		client_socket[i] = 0;
	}
    // Cria o socket mestre
	master_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (master_socket == 0) {
		printf("Falha ao criar o socket... Erro: %d\n", errno);
		exit(-1);
	} else {
		printf("Socket criado com sucesso!\n");
	}


	// Creating socket file descriptor
	// if ( (sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
	// 	perror("socket creation failed");
	// 	exit(EXIT_FAILURE);
	// }
	
	memset(&servAddress, 0, sizeof(servAddress));
	memset(&clientAdress, 0, sizeof(clientAdress));
	
	// Atribui valores da porta, do tipo de IP e dos endereços aceitos para o servidor
	servAddress.sin_family = AF_INET; // IPv4
	servAddress.sin_addr.s_addr = INADDR_ANY;
	servAddress.sin_port = htons(PORT);
	
	// Bind the socket with the server address
    int bindReturn = bind(master_socket, (SockAddr*)&serverAddress, sizeof(serverAddress));
	if ( bindReturn != 0 )
	{
		printf("Falha ao realizar o bind... Erro: %d\n", errno);
		exit(-1);
	} else {
		printf("Bind realizado com sucesso!\n");
	}
	
	int len, n;

	int lenMessage = sizeof(clientAdress); //len is value/resuslt
    //para ler o dado que está vindo do cliente
    printf("lendo mensagem do cliente...\n")
	n = recvfrom(sock, (char *)buffer, MAXLINE,
				MSG_WAITALL, ( struct sockaddr *) &clientAdress,
				&lenMessage);
	buffer[n] = '\0';
	printf("Mensagem recebida do Cliente : %s\n", buffer);
	
    exchangeMessages(sock, clientAdress)

    sendto(sock, (const char *)hello, strlen(hello),
		MSG_CONFIRM, (const struct sockaddr *) &clientAdress,
			len);
	printf("Hello message sent.\n");
	
	return 0;
}
