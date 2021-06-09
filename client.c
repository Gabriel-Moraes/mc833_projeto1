// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include<errno.h>
#define PORT	 8080
#define MAXLINE 1024

void printInitialMessage() {
	printf("Bem vindo ao servidor! Para executar uma ação, insira uma das seguintes entradas:\n1: Criar um perfil\n"
	"2: Adicionar uma experiencia profissional\n"
	"3: Listar todos os graduados num determinado curso\n"
	"4: Listar todos os usuários com uma determinada habilidade\n"
	"5: Listar todos os graduados num determinado ano\n"
	"6: Listar todos os perfis\n"
	"7: Listar informaçoes sobre um perfil\n"
	"8: Remover um perfil\n"
	"exit: Sair\n\n");
}
void exchangeMessages(int sock, struct sockaddr * serverAddress) {
	char buff[MAX];
	int n, responseSize;
	while(1) {
		bzero(buff, sizeof(buff));
		printf("Digite a mensagem a ser enviada: ");
		n = 0;
		// Espera ate a mensagem ser digitada completamente
		while ((buff[n++] = getchar()) != '\n') {}
		printf("Enviando mensagem: %s\n", buff);
		// Escreve a mensagem excluindo o '\n'

        sendto(sock, buff, strlen(buff)-1,
		MSG_CONFIRM, (const struct sockaddr *) &serverAddress,
			sizeof(serverAddress));
		// write(sock, buff, strlen(buff)-1);
		bzero(buff, sizeof(buff));

		// Le o tamanho do retorno
        responseSize = recvfrom(sock, (char *)buff, MAXLINE,
				MSG_WAITALL, (struct sockaddr *) &serverAddress,
				&len);
	    buff[n] = '\0';
		// responseSize = 0;
		// read(sock, buff, 10);
		// responseSize = atoi(buff);
	    printf("Tamanho da resposta: %d\n", responseSize);

		// bzero(buff, sizeof(buff));
		printf("Resposta do servidor:\n");
        printf(" %s\n", buff);
		// Imprime a resposta completa do servidor, mesmo que envolva mais de uma operaçao no buff
		// while(responseSize > 0) {
		// 	read(sock, buff, sizeof(buff));
		// 	printf("%s", buff);
		// 	responseSize-= (int) sizeof(buff);
		// }

		
		// TODO Fazer funcionar corretamente para qualquer fluxo
		if ((strncmp(buff, "exit", 4)) == 0) {
			printf("Saindo do servidor %d...\n", sock);
			break;
		}

		printf("\n");
	}
}
// Driver code
int main() {
	int sockfd, sock;
	char buff[MAXLINE];
	char *hello = "Hello from client";
	struct sockaddr_in	 serverAddress;

    // Cria o socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if ( sock < 0 ) {
		printf("Falha ao criar o socket... Erro: %d\n", errno);
		exit(0);
	} else {
		printf("Socket criado com sucesso!\n");
	}

	bzero(&serverAddress, sizeof(serverAddress));
	// Atribui valores da porta, do tipo de IP e do endereço do servidor
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(PORT);
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	
	int n, len;
	
	sendto(sock, (const char *)hello, strlen(hello),
		MSG_CONFIRM, (const struct sockaddr *) &serverAddress,
			sizeof(serverAddress));
	printf("Hello message sent.\n");
		
	n = recvfrom(sock, (char *)buff, MAXLINE,
				MSG_WAITALL, (struct sockaddr *) &serverAddress,
				&len);
	buff[n] = '\0';
	printf("Server : %s\n", buff);


    printInitialMessage();
    exchangeMessages(sock, serverAddress);

	close(sock);
	return 0;
}
