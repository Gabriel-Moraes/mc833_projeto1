// Bibliotecas para o socket
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "actions.h"

#define PORT 8080
#define MAX 200
#define SockAddr struct sockaddr

void exchangeMessages(int sock) {
    char buff[MAX];
    // Loop infinito para manter a troca de mensagens
    while (1) {
		// Zera o conteúdo do buffer
        bzero(buff, MAX);

        // Le a mensagem recebida e copia para o buffer
        read(sock, buff, sizeof(buff));

		// Printa a mensagem recebida
        printf("Mensagem recebida do cliente %d: %s\n", sock, buff);
		int requestError = treatClientActionRequest(sock, buff);
		if (requestError == -2) {
	        // Caso o retorno seja -2, fecha a conexao
			write(sock, "5", 2);
			write(sock, "exit\n", 5);
			printf("Cliente %d saiu do servidor...\n", sock);
            break;
		} else if (requestError < 0) {
			write(sock, "16", 3);
			write(sock, "Açao invalida!\n", 16);
		}
    }
}

int main()
{
	int sock, connection, len;
	struct sockaddr_in serverAddress, client;
	int master_socket, client_socket[10], activity, i, sd;
	int max_sd;
	fd_set readfds;
	int opt = 1;

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

	if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0) {
		 perror("setsockopt");  
       	 exit(EXIT_FAILURE);  
	}
	bzero(&serverAddress, sizeof(serverAddress));

	// Atribui valores da porta, do tipo de IP e dos endereços aceitos para o servidor
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(PORT);

	// Faz o bind do socket com o endereço
	int bindReturn = bind(master_socket, (SockAddr*)&serverAddress, sizeof(serverAddress));
	if (bindReturn != 0) {
		printf("Falha ao realizar o bind... Erro: %d\n", errno);
		exit(-1);
	} else {
		printf("Bind realizado com sucesso!\n");
	}

	// Inicia a escuta de mensagens pelo servidor
	int listenReturn = listen(master_socket, 10);
	if (listenReturn != 0) {
		printf("Falha ao escutar mensagem... Erro: %d\n", errno);
		exit(-1);
	} else {
		printf("Servidor escutando...\n");
	}
	len = sizeof(client);
	puts("Servidor esperando por conexões ...");

	while (1) {
		FD_ZERO(&readfds);

		FD_SET(master_socket, &readfds);
		max_sd = master_socket;

		for (i = 0; i < 10 ; i++) {
			sd = client_socket[i];

			if (sd > 0) {
				FD_SET(sd, &readfds);
			}

			if (sd > max_sd) {
				max_sd = sd;
			}
		}

		activity = select(max_sd + 1 , &readfds , NULL , NULL , NULL);         
        if ((activity < 0) && (errno!=EINTR)) {  
            printf("Erro no select\n");  
        }  

		// Escuta as solicitações de conexões 
        if (FD_ISSET(master_socket, &readfds)) {  

			// Recebe e aceita as conexões vindas de clientes
			connection = accept(master_socket, (SockAddr*)&client, (socklen_t*)&len);
			if (connection < 0) {
				printf("Falha ao aceitar conexão... Erro: %d\n", errno);
				exit(-1);
			} else {
				printf("Conexão aceita com sucesso!\n");
			}

			 // Adiciona um novo socket no vetor de sockets
            for (i = 0; i < 10; i++) {  
                // Insere caso seja uma posiçao vazia
                if(client_socket[i] == 0) {  
                    client_socket[i] = connection;  
                    printf("Adicionando o socket como %d\n" , i);  
                         
                    break;  
                }  
            }  
        } 

		for (i = 0; i < 10; i++) {  
            sd = client_socket[i];  
                 
            if (FD_ISSET( sd , &readfds)) {  
				exchangeMessages(sd);
				close(sd);
				
				client_socket[i] = 0;
            } 
        }		
	}

	// Após todas as conexões, fecha o socket
	close(sock);
	close(master_socket);

	return 0;
}
