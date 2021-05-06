#include "actions.h"

#define MAX 200
// Funçoes privadas

int createProfile() {
        return 0;
}
int addProfessionalExperience() {
        return 0;
}
int listGraduatedOnCourse() {
    return 0;
}

int listHasSkill() {
        return 0;
}

char* listGraduatedOnYear(char* year) {
    FILE* file = NULL;
    file = fopen("files/users.dat", "r");

    if (file == NULL) {
        printf("Falha ao abrir o arquivo!");
        return NULL;
    }

    Profile searchedProfile;
    char* response = "";
    while(fread(&searchedProfile, sizeof(Profile), 1, file)) {
        printf("Lendo o arquivo...\n");
        if(!strcmp(searchedProfile.graduationYear, year)) {
            printf("Perfil encontrado! Enviando informaçoes...\n");
            sprintf(response, "%s\n%s\n%s\n%s\n", searchedProfile.email, searchedProfile.firstName, 
                        searchedProfile.lastName, searchedProfile.academicBackground);
        }
    }
    strcmp("",response) == 0 ? printf("Nao foi encontrado um perfil com este ano de formatura\n") : 
                      printf("Retornando perfis com este ano de formatura\n");
    return response;

}

char* getProfileInfo(char* email) {  
    FILE* file = NULL;
    file = fopen("files/users.txt", "r");

    if (file == NULL) {
        printf("Falha ao abrir o arquivo!");
        return NULL;
    }

    Profile searchedProfile;
    char* response;
    while(fread(&searchedProfile, sizeof(Profile), 1, file)) {
        printf("Lendo o arquivo...\n");
        if(!strcmp(searchedProfile.email, email)) {
            printf("Perfil encontrado! Enviando informaçoes...\n");
            sprintf (response, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", searchedProfile.email, searchedProfile.firstName, searchedProfile.lastName, 
                        searchedProfile.residence, searchedProfile.academicBackground, searchedProfile.graduationYear, searchedProfile.skills,
                            searchedProfile.professionalExperience);
            return response;
        }

        printf("Nao foi encontrado um perfil com este email");
        return NULL;        
    }
 }

int removeProfile(char* email) {
    FILE* file = NULL;
    file = fopen("files/users.txt", "r+");

    if (file == NULL) {
        printf("Falha ao abrir o arquivo!");
        return NULL;
    }

    Profile profileToRemove;
    char* response;
    while(fread(&profileToRemove, sizeof(Profile), 1, file)) {
        printf("Lendo o arquivo...\n");
        if(!strcmp(profileToRemove.email, email)) {
            printf("Perfil encontrado! Removendo perfil...\n");
            //TODO implementar funçao para remover as linhas referentes ao perfil a ser removido
            //removeLinesFromFile();
            return 0;
        }
    }

        printf("Nao foi encontrado um perfil com este email");
        return -1;
}

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
        return 0;  
}
int addProfessionalExperienceAction(int sock){
        return 0;
}
int listGraduatedOnCourseAction(int sock){

    return 0;

}
int listHasSkillAction(int sock){
    return 0;

}
int listGraduatedOnYearAction(int sock) {
    const char* getYearMessage = "Digite o ano que gostaria de buscar: \n";
    char* content;
    char year[4], responseSize[10];
    bzero(responseSize, sizeof(responseSize));

    sprintf(responseSize, "%d", strlen(getYearMessage));
    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do ano...\n");
    write(sock, responseSize, 10*sizeof(char));
    printf("Tamanho da resposta enviado...\n");
    write(sock, getYearMessage, strlen(getYearMessage)+1)*sizeof(char);
    printf("Mensagem enviada...\n");
    read(sock, year, sizeof(year));
    printf("Ano lido...\n");
    content = listGraduatedOnYear(year);

    write(sock, content, strlen(content)+1 * sizeof(char));
    printf("Conteudo enviado...\n");


    return 0;
}
int listAllProfilesAction(int sock){

}

int getProfileInfoAction(int sock) {
    const char* getEmailMessage = "Digite o email do usuario que gostaria de buscar: ";
    char* content;
    char email[30], responseSize[10];
    bzero(responseSize, sizeof(responseSize));

    sprintf(responseSize, "%d", strlen(getEmailMessage)); 
    printf("Enviando solicitaçao do email...\n");
    write(sock, responseSize, sizeof(responseSize));
    write(sock, getEmailMessage, responseSize);
    read(sock, email, sizeof(email));
    content = getProfileInfo(email);
    printf("%s\n", content);
    write(sock, content, sizeof(content));

    return 0;
}

int removeProfileAction(int sock){
    const char* getEmailMessage = "Digite o email do usuario que gostaria de remover: ";
    char* content;
    char email[30], responseSize[10];
    bzero(responseSize, sizeof(responseSize));

    sprintf(responseSize, "%d", strlen(getEmailMessage)); 
    printf("Enviando solicitaçao do email...\n");
    write(sock, responseSize, sizeof(responseSize));
    write(sock, getEmailMessage, responseSize);
    read(sock, email, sizeof(email));

    removeProfile(email);
    char* successfullyRemovedMessage = "Usuario removido com sucesso\n";
    write(sock,successfullyRemovedMessage, strlen(successfullyRemovedMessage));

    return 0;
}