#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bibliotecas para o socket
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>

#define PORT 8080
#define SockAddr struct sockaddr

int main()
{
	int sock, connection, len;
	int bytesSent;
	char* message = "Hello Client!\n";
	struct sockaddr_in serverAddress, client;

	// Cria o socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		printf("Falha ao criar o socket... Erro: %d\n", errno);
		exit(-1);
	} else {
		printf("Socket criado com sucesso!\n");
	}
	bzero(&serverAddress, sizeof(serverAddress));

	// Atribui valores da porta, do tipo de IP e dos endereços aceitos para o servidor
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(PORT);

	// Faz o bind do socket com o endereço
	int bindReturn = bind(sock, (SockAddr*)&serverAddress, sizeof(serverAddress));
	if (bindReturn != 0) {
		printf("Falha ao realizar o bind... Erro: %d\n", errno);
		exit(-1);
	} else {
		printf("Bind realizado com sucesso!\n");
	}

	// Inicia a escuta de mensagens pelo servidor
	int listenReturn = listen (sock, 5);
	if (listenReturn != 0) {
		printf("Falha ao escutar mensagem... Erro: %d\n", errno);
		exit(-1);
	} else {
		printf("Servidor escutando...\n");
	}
	len = sizeof(client);

	while (1) {
		// Recebe e aceita as conexões vindas de clientes
		connection = accept(sock, (SockAddr*)&client, &len);
		if (connection < 0) {
			printf("Falha ao aceitar conexão... Erro: %d\n", errno);
			exit(-1);
		} else {
			printf("Conexão aceita com sucesso!\n");
		}

		// Envio de mensagens do servidor para o cliente
		bytesSent = send(connection, message, strlen(message), 0);
		printf("%d bytes enviados para o cliente %d!\n", bytesSent, connection);

		close(client);
	}

	// Após todas as conexões, fecha o socket
	close(sock);

	return 0;
}
