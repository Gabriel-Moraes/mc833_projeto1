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

// TODO implementar essa mensagem como retorno do servidor, nao como parte do cliente
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

/** Realiza a troca de mensagens entre o cliente e o servidor */
void exchangeMessages(int sock) {
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
		write(sock, buff, strlen(buff)-1);
		bzero(buff, sizeof(buff));

		// Le o tamanho do retorno
		responseSize = 0;
		read(sock, buff, 10);
		responseSize = atoi(buff);
	    printf("Tamanho da resposta: %d\n", responseSize);

		bzero(buff, sizeof(buff));
		printf("Resposta do servidor:\n");	
		// Imprime a resposta completa do servidor, mesmo que envolva mais de uma operaçao no buffer
		while(responseSize > 0) {
			read(sock, buff, sizeof(buff));
			printf("%s", buff);
			responseSize-= (int) sizeof(buff);
		}
		
		// TODO Fazer funcionar corretamente para qualquer fluxo
		if ((strncmp(buff, "exit", 4)) == 0) {
			printf("Saindo do servidor %d...\n", sock);
			break;
		}

		printf("\n");
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
		printf("Socket criado com sucesso!\n");
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

	printInitialMessage();
	exchangeMessages(sock);

	// Fecha o socket
	close(sock);
}
