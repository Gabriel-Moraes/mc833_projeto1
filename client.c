#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Bibliotecas para o socket
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 8080
#define MAX 200
#define SockAddr struct sockaddr

/** Realiza a troca de mensagens entre o cliente e o servidor */
void exchangeMessages(int sock) {
	char buff[MAX];
	int n;
	while(1) {
		bzero(buff, sizeof(buff));
		printf("Digite a mensagem a ser enviada: ");
		n = 0;
		while ((buff[n++] = getchar()) != '\n') {
			// Espera ate a mensagem ser transferida completamente
		}
		write(sock, buff, sizeof(buff));
		bzero(buff, sizeof(buff));
		read(sock, buff, sizeof(buff));
		printf("Resposta do servidor: %s", buff);
		if ((strncmp(buff, "exit", 4)) == 0) {
			printf("Saindo do servidor %d...\n", sock);
			break;
		}
	}
}

int main() {
	int sock;
	struct sockaddr_in serverAddress;

	// Cria o socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		printf("Falha ao criar o socket... Erro: %d\n", errno);
		exit(0);
	} else {
		printf("Socker criado com sucesso!\n");
	}
	bzero(&serverAddress, sizeof(serverAddress));

	// Atribui valores da porta, do tipo de IP e do endereço do servidor
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	serverAddress.sin_port = htons(PORT);

	// Conecta o socket do cliente com o socket do servidor
	if (connect(sock, (SockAddr*)&serverAddress, sizeof(serverAddress)) != 0) {
		printf("Falha na conexao com o servidor... Erro: %d\n", errno);
		exit(0);
	} else {
		printf("Conectado ao servidor...\n");
	}

	exchangeMessages(sock);

	// Fecha o socket
	close(sock);
}
