#include <stdlib.h>
#include "actions.h"

#define MAX 200

// Funçoes do header
int treatClientActionRequest(int sock, char* request) {
	if ((strncmp(request, "exit", 4)) == 0) {
        return -2;
    } else {
        int action = atoi(request);

        switch (action) {
            case 1:
                createProfileAction(sock);
                break;
            case 2:
                addProfessionalExperienceAction(sock);
                break;
            case 3:
                listGraduatedOnCourseAction(sock);
                break;
            case 4:
                listHasSkillAction(sock);
                break;
            case 5:
                listGraduatedOnYearAction(sock);
                break;
            case 6:
                listAllProfilesAction(sock);
                break;
            case 7:
                getProfileInfoAction(sock);
                break;
            case 8:
                removeProfileAction(sock);
                break;
            default: 
                printf("Açao invalida!\n");
                return -1;	

            return 0;
        }
    }
}

int createProfileAction(int sock) {
    
    
}
int addProfessionalExperienceAction(int sock){

}
int listGraduatedOnCourseAction(int sock){

}
int listHasSkillAction(int sock){

}
int listGraduatedOnYearAction(int sock){

}

/** Pega o numero de caracteres do arquivo 
 * 
 * Codigo com base na seguinte pagina do geeks4geeks
 * https://www.geeksforgeeks.org/c-program-to-count-the-number-of-characters-in-a-file/
*/
int countCharsOnFile(FILE* file) {
    int count = 0;
    char c;

    // Conta a quantidade de caracteres no arquivo
    while ((c = fgetc(file)) != EOF) {
        count++;
    }
  
    fclose(file);
    return count;
}

int listAllProfilesAction(int sock) {
    // Abre o arquivo dos usuarios
    FILE* file = NULL;
    file = fopen("files/users.txt", "r");

    if (file == NULL) {
        printf("Falha ao abrir arquivo!");
        return -1;
    }

    int fileSize = countCharsOnFile(file);
    char responseSize[10], content[MAX], fullMessage[fileSize];

    // Converte o tamanho do arquivo de int para char
    sprintf(responseSize, "%d", fileSize);
    bzero(fullMessage, sizeof(fullMessage));
    while (fgets(content, MAX, file) != NULL) {
        printf("%s",content);
        strcat(fullMessage, content);
    }
    printf("%s", fullMessage);
    write(sock, responseSize, sizeof(responseSize));
    write(sock, fullMessage, sizeof(fullMessage));
    fclose(file);
    return 0;
}

int getProfileInfoAction(int sock) {
    const char* getEmailMessage = "Digite o email do usuario que gostaria de buscar: ";
    char email[30];

    write(sock, getEmailMessage, sizeof(getEmailMessage));
    read(sock, email, sizeof(email));
    getProfileInfo(email);
}

int removeProfileAction(int sock){

}

// Funçoes privadas

int createProfile() {

}
int addProfessionalExperience() {

}
int listGraduatedOnCourse() {

}
int listHasSkill() {

}
int listGraduatedOnYear() {

}
int listAllProfiles() {

}
char* getProfileInfo(char* email) {  

    FILE* file = NULL;    
    file = fopen("files/users.txt", "r");

    char* content, fullMessage, profile;
    bzero(fullMessage, sizeof(fullMessage));

    if (file == NULL) {
        printf("Falha ao abrir arquivo!");
        return NULL;
    }
}
int removeProfile() {

}