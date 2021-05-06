#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Bibliotecas para o socket
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>

#include "actions.h"

#define PORT 8080
#define MAX 200
#define SockAddr struct sockaddr

void exchangeMessages(int sock) {
    char buff[MAX];
    // Loop infinito para manter a troca de mensagens
    while (1) {
        bzero(buff, MAX);

        // Le a mensagem recebida e copia para o buffer
        read(sock, buff, sizeof(buff));

		// Printa a mensagem recebida
        printf("Mensagem recebida do cliente %d: %s", sock, buff);
		int requestError = treatClientActionRequest(sock, buff);
		if (requestError == -2) {
	        // Caso o retorno seja -2, fecha a conexao
			write(sock, "exit\n", 5*sizeof(char));
			printf("Cliente %d saiu do servidor...\n", sock);
            break;
		} else if (requestError < 0) {
			write(sock, "Açao invalida!\n", 16*sizeof(char));
		} else {
			// Responde o cliente com a mensagem recebida
			write(sock, buff, sizeof(buff));
		}
    }
}

int main()
{
	int sock, connection, len;
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

		// Troca de mensagens entre o servidor e o cliente
		exchangeMessages(connection);
		close(connection);
	}

	// Após todas as conexões, fecha o socket
	close(sock);

	return 0;
}
