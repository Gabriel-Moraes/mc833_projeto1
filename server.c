#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Bibliotecas para o socket
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/time.h>
#include "actions.h"
#include <arpa/inet.h>
#define PORT 8080
#define MAX 200
#define SockAddr struct sockaddr

typedef struct profile {
	char email[30];
	char firstName[20];
	char lastName[20];
	char residence[30];
	char academicBackground[50];
	char graduationYear[4];
	char skills[300];
	char professionalExperience[300];
} profile;

void exchangeMessages(int sock) {
    char buff[MAX];
    // int n;
    // Loop infinito para manter a troca de mensagens
    while (1) {
		//zero o meu buffer onde conterá as informações
        bzero(buff, MAX);

        // Le a mensagem recebida e copia para o buffer
        read(sock, buff, sizeof(buff));

		// Printa a mensagem recebida
        printf("Mensagem recebida do cliente %d: %s", sock, buff);
		//vai entender qual é a solicitação pelo cliente
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
	// int bytesSent;
	struct sockaddr_in serverAddress, client;
	int master_socket, client_socket[30], activity, i, sd;
	int max_sd;
	fd_set readfds;
	int opt = 1;
	// char *message = "ECHO Daemon v1.0 \r\n";

	// inicializo o vetor de sockets 
	for(i=0; i < 30; i++) {
		client_socket[i] = 0;
	}
	master_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (master_socket == 0) {
		printf("Falha ao criar o socket... Erro: %d\n", errno);
		exit(-1);
	} else {
		printf("Socket criado com sucesso!\n");
	}

	if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) <0 ){
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
	int listenReturn = listen (master_socket, 5);
	if (listenReturn != 0) {
		printf("Falha ao escutar mensagem... Erro: %d\n", errno);
		exit(-1);
	} else {
		printf("Servidor escutando...\n");
	}
	len = sizeof(client);
	// addrlen = sizeof(serverAddress);
	puts("Servidor esperando por conexões ...");
	while (1) {
		FD_ZERO(&readfds);

		FD_SET(master_socket, &readfds);
		max_sd = master_socket;

		for( i = 0; i < 30 ; i++) {
			sd = client_socket[i];

			if(sd > 0 ) {
				FD_SET(sd, &readfds);
			}

			if(sd > max_sd) {
				max_sd = sd;
			}
		}

		activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);  
       
        if ((activity < 0) && (errno!=EINTR))  
        {  
            printf("select error");  
        }  
             
        //If something happened on the master socket , 
        //then its an incoming connection 
        if (FD_ISSET(master_socket, &readfds))  
        {  
           
		// Recebe e aceita as conexões vindas de clientes
			connection = accept(master_socket, (SockAddr*)&client, (socklen_t*)&len);
			if (connection < 0) {
				printf("Falha ao aceitar conexão... Erro: %d\n", errno);
				exit(-1);
			} else {
				printf("Conexão aceita com sucesso!\n");
		}
			
                 
            //add new socket to array of sockets 
            for (i = 0; i < 30; i++)  
            {  
                //if position is empty 
                if( client_socket[i] == 0 )  
                {  
                    client_socket[i] = connection;  
                    printf("Adicionando o socket como %d\n" , i);  
                         
                    break;  
                }  
            }  
        }  
		for (i = 0; i < 30; i++)  
        {  
            sd = client_socket[i];  
                 
            if (FD_ISSET( sd , &readfds))  
            {  
				printf("entrou aqui");

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