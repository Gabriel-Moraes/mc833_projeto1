#include "actions.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
// Funçoes do header
typedef struct Profile {
	char email[30];
	char firstName[20];
	char lastName[20];
	char residence[30];
	char academicBackground[50];
	char graduationYear[4];
	char skills[300];
	char professionalExperience[300];
} Profile;
int treatClientActionRequest(int sock, char* request);

char* createProfile(char email[30],	char firstName[20],	char lastName[20],	char residence[30],	char academicBackground[50],	char graduationYear[4],	char skills[300],	char professionalExperience[300]) {
    FILE* file = NULL;
    file = fopen("files/users.csv", "a");

    if (file == NULL) {
        printf("Falha ao abrir o arquivo!\n");
        return NULL;
    }
    
    // Perfil newProfile = {email, firstName, lastName, residence, academicBackground, graduationYear, skills, profExp};
    Profile newProfile;
    strcpy(newProfile.email, email);
    printf("%s",newProfile.email);
    strcpy(newProfile.firstName, firstName);
    strcpy(newProfile.lastName, lastName);
    strcpy(newProfile.residence, residence);
    strcpy(newProfile.academicBackground, academicBackground);
    strcpy(newProfile.graduationYear, graduationYear);
    strcpy(newProfile.skills, skills);
    strcpy(newProfile.professionalExperience, professionalExperience);
    // size_t writeStruct = fwrite(&newProfile, sizeof(Perfil),1, file);
    fprintf(file, "%30s %20s %20s %30s %50s %4s %300s %300s\n",newProfile.email, newProfile.firstName,newProfile.lastName,newProfile.residence,newProfile.academicBackground,newProfile.graduationYear, newProfile.skills, newProfile.professionalExperience);
    printf("Perfil inserido com sucesso!\n");
    fclose(file);
    return "Perfil inserido com sucesso!\n";

    // if( writeStruct == 1) {
    //     
    //         // } else {
    //     printf("Erro ao escrever no arquivo\n");
    //     fclose(file);
    //     return "Erro ao escrever no arquivo\n";
    // }

    
    
}

int createProfileAction(int sock) {
    const char* getEmailMessage = "\nDigite o email para cadastro: \n";
    const char* getFirstNameMessage = "\nDigite o seu primeiro Nome para cadastro: \n";
    const char* getLastNameMessage = "\nDigite o seu último nome para cadastro: \n";
    const char* getResidenceMessage = "\nDigite o seu endereço de residencia para cadastro: \n";
    const char* getAcademicBackgroundMessage = "\nDigite o seu curso para cadastro: \n";
    const char* getGraduationYearMessage = "\nDigite o seu ano de formacao para cadastro: \n";
    const char* getSkillMessage = "\nDigite suas habilidades para cadastro: \n";
    const char* getProfExpMessage = "\nDigite suas experiencias profissionais para cadastro: \n";
    char* content;
    char email[30];
	char firstName[20];
	char lastName[20];
	char residence[30];
	char academicBackground[50];
	char graduationYear[4];
	char skills[300];
	char profExp[300], responseSize[80];
    bzero(responseSize, sizeof(responseSize));
    
    
    size_t sizeEmail = strlen(getEmailMessage);
    if ( sizeEmail > INT_MAX )
    {
       printf("Tamanho da mensagem excedeu o limite\n");
    } else {
        int size_message = (int)(sizeEmail);
        sprintf(responseSize, "%d", size_message);
    }
    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do email...\n");
    write(sock, responseSize, 100*sizeof(char));
    printf("Tamanho da resposta enviado...\n");
    write(sock, getEmailMessage, strlen(getEmailMessage)+1)*sizeof(char);
    printf("Mensagem enviada...\n");
    read(sock, email, sizeof(email));
    printf("%s",email);
    printf("Email lido...\n");
    
    
    size_t sizeFirstName = strlen(getFirstNameMessage);
    if ( sizeFirstName > INT_MAX )
    {
       printf("Tamanho da mensagem excedeu o limite\n");
    } else {
        int size_message = (int)(sizeFirstName);
        sprintf(responseSize, "%d", size_message);
    }
    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do firstName...\n");
    write(sock, responseSize, 100*sizeof(char));
    printf("Tamanho da resposta enviado...\n");
    write(sock, getFirstNameMessage, strlen(getFirstNameMessage)+1)*sizeof(char);
    printf("Mensagem enviada...\n");
    read(sock, firstName, sizeof(firstName));
    printf("firstName lido...\n");
    
    
    
    size_t sizeLastName = strlen(getLastNameMessage);
    if ( sizeLastName > INT_MAX )
    {
       printf("Tamanho da mensagem excedeu o limite\n");
    } else {
        int size_message = (int)(sizeLastName);
        sprintf(responseSize, "%d", size_message);
    }
    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do lastName...\n");
    write(sock, responseSize, 100*sizeof(char));
    printf("Tamanho da resposta enviado...\n");
    write(sock, getLastNameMessage, strlen(getLastNameMessage)+1)*sizeof(char);
    printf("Mensagem enviada...\n");
    read(sock, lastName, sizeof(lastName));
    printf("lastName lido...\n");

    size_t sizeResidence = strlen(getResidenceMessage);
    if ( sizeResidence > INT_MAX )
    {
       printf("Tamanho da mensagem excedeu o limite\n");
    } else {
        int size_message = (int)(sizeResidence);
        sprintf(responseSize, "%d", size_message);
    }
    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do residence...\n");
    write(sock, responseSize, 100*sizeof(char));
    printf("Tamanho da resposta enviado...\n");
    write(sock, getResidenceMessage, strlen(getResidenceMessage)+1)*sizeof(char);
    printf("Mensagem enviada...\n");
    read(sock, residence, sizeof(residence));
    printf("residence lido...\n");
    
    size_t sizeAcademic = strlen(getAcademicBackgroundMessage);
    if ( sizeAcademic > INT_MAX )
    {
       printf("Tamanho da mensagem excedeu o limite\n");
    } else {
        int size_message = (int)(sizeAcademic);
        sprintf(responseSize, "%d", size_message);
    }
    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do academicBackground...\n");
    write(sock, responseSize, 100*sizeof(char));
    printf("Tamanho da resposta enviado...\n");
    write(sock, getAcademicBackgroundMessage, strlen(getAcademicBackgroundMessage)+1)*sizeof(char);
    printf("Mensagem enviada...\n");
    read(sock, academicBackground, sizeof(academicBackground));
    printf("academicBackground lido...\n");
    

    size_t sizeYear = strlen(getGraduationYearMessage);
    if ( sizeYear > INT_MAX )
    {
       printf("Tamanho da mensagem excedeu o limite\n");
    } else {
        int size_message = (int)(sizeYear);
        sprintf(responseSize, "%d", size_message);
    }
    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do graduationYear...\n");
    write(sock, responseSize, 100*sizeof(char));
    printf("Tamanho da resposta enviado...\n");
    write(sock, getGraduationYearMessage, strlen(getGraduationYearMessage)+1)*sizeof(char);
    printf("Mensagem enviada...\n");
    read(sock, graduationYear, sizeof(graduationYear));
    printf("graduationYear lido...\n");


    size_t sizeSkill = strlen(getSkillMessage);
    if ( sizeSkill > INT_MAX )
    {
       printf("Tamanho da mensagem excedeu o limite\n");
    } else {
        int size_message = (int)(sizeSkill);
        sprintf(responseSize, "%d", size_message);
    }
    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao da habilidade...\n");
    write(sock, responseSize, 100*sizeof(char));
    printf("Tamanho da resposta enviado...\n");
    write(sock, getSkillMessage, strlen(getSkillMessage)+1)*sizeof(char);
    printf("Mensagem enviada...\n");
    read(sock, skills, sizeof(skills));
    printf("Habilidade lida...\n");

    size_t sizeProfExp = strlen(getProfExpMessage);
    if ( sizeProfExp > INT_MAX )
    {
       printf("Tamanho da mensagem excedeu o limite\n");
    } else {
        int size_message = (int)(sizeProfExp);
        sprintf(responseSize, "%d", size_message);
    }
    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao da experiencia profissional...\n");
    write(sock, responseSize, 100*sizeof(char));
    printf("Tamanho da resposta enviado...\n");
    write(sock, getProfExpMessage, strlen(getProfExpMessage)+1)*sizeof(char);
    printf("Mensagem enviada...\n");
    read(sock, profExp, sizeof(profExp));
    printf("experiencia profissional lida...\n");

    content = createProfile(email,firstName, lastName, residence, academicBackground, graduationYear, skills, profExp);

    write(sock, content, strlen(content)+1 * sizeof(char));
    printf("Conteudo enviado...\n");
    return 0;
}
int addProfessionalExperienceAction(){
    return 3;
}

int readFile(Profile people[], int n_p, FILE* fp){
 
   if(fp==NULL){
       printf("Error\n");
       return -1;
   }
    fscanf(fp,"%50s %20s %20s %30s\n", people[n_p].academicBackground, people[n_p].firstName,
      people[n_p].lastName, people[n_p].email);
    printf(">%s, %s, %s, %s<\n", people[n_p].academicBackground, people[n_p].firstName,
        people[n_p].lastName, people[n_p].email);
    return 0;
}
char* listGraduatedOnCourse(char* course) {
    FILE* file = NULL;
    file = fopen("files/users.csv", "r");

    if (file == NULL) {
        printf("Falha ao abrir o arquivo!\n");
        return NULL;
    }

    Profile searchedProfile[30];
    char* response = "";
    int i = 0;
    int size;
    printf("Lendo o arquivo...\n");
    while (!feof(file)) {
        readFile(searchedProfile, i, file);
        i++;
    }
    size = i;
 
    // for (i = 0; i < size; ++i)
    // printf("%s, %s, %s, %ld\n", people[i].code, people[i].first_name,
        // people[i].last_name, people[i].telephone);
   
 
    fclose(file);
    for(i = 0; i<size;i++) {
        if(!strcmp(searchedProfile[i].academicBackground, course)) {
            printf("Perfil encontrado! Enviando informaçoes...\n");
            sprintf(response, "%s\n%s\n%s\n", searchedProfile[i].email, searchedProfile[i].firstName, 
                        searchedProfile[i].lastName);
        }
    }
    // while(fread(&searchedProfile, sizeof(Perfil), 1, file)) {
    //     
    //     if(!strcmp(searchedProfile.academicBackground, course)) {
    //         printf("Perfil encontrado! Enviando informaçoes...\n");
    //         sprintf(response, "%s\n%s\n%s\n", searchedProfile.email, searchedProfile.firstName, 
    //                     searchedProfile.lastName);
    //     }
    // }
    if(strcmp("",response) == 0) {
        printf("Nao foi encontrado um perfil com este curso\n");
        response = "Nao foi encontrado um perfil com este curso\n";
    }else{
        printf("Retornando perfis com curso\n");
    }
                      
    return response;
}
int listGraduatedOnCourseAction(int sock){
    const char* getCourseMessage = "\nDigite o curso que gostaria de buscar: \n";
    char* content;
    char course[50], responseSize[100];
    bzero(responseSize, sizeof(responseSize));
    
    
    size_t size = strlen(getCourseMessage);
    if ( size > INT_MAX )
    {
       printf("Tamanho da mensagem excedeu o limite\n");
    } else {
        int size_message = (int)(size);
        sprintf(responseSize, "%d", size_message);
    }
    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do curso...\n");
    write(sock, responseSize, 100*sizeof(char));
    printf("Tamanho da resposta enviado...\n");
    write(sock, getCourseMessage, strlen(getCourseMessage)+1)*sizeof(char);
    printf("Mensagem enviada...\n");
    read(sock, course, sizeof(course));
    printf("Curso lido...\n");
    content = listGraduatedOnCourse(course);

    write(sock, content, strlen(content)+1 * sizeof(char));
    printf("Conteudo enviado...\n");
    return 0;
}
char* listHasSkill(char* skill) {
    FILE* file = NULL;
    file = fopen("files/users.dat", "r");

    if (file == NULL) {
        printf("Falha ao abrir o arquivo!\n");
        return NULL;
    }

    Profile searchedProfile;
    char* response = "";
    while(fread(&searchedProfile, sizeof(Profile), 1, file)) {
        printf("Lendo o arquivo...\n");
        if(!strcmp(searchedProfile.skills, skill)) {
            printf("Perfil encontrado! Enviando informaçoes...\n");
            sprintf(response, "%s\n%s\n%s\n", searchedProfile.email, searchedProfile.firstName, 
                        searchedProfile.lastName);
        }
    }
    if(strcmp("",response) == 0) {
        printf("Nao foi encontrado um perfil com este curso\n");
        response = "Nao foi encontrado um perfil com este curso\n";
    }else{
        printf("Retornando perfis com curso\n");
    }
                      
    return response;
}

int listHasSkillAction(int sock){
    const char* getSkillMessage = "\nDigite o curso que gostaria de buscar: \n";
    char* content;
    char skill[50], responseSize[100];
    bzero(responseSize, sizeof(responseSize));
    
    
    size_t size = strlen(getSkillMessage);
    if ( size > INT_MAX )
    {
       printf("Tamanho da mensagem excedeu o limite\n");
    } else {
        int size_message = (int)(size);
        sprintf(responseSize, "%d", size_message);
    }
    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao da habilidade...\n");
    write(sock, responseSize, 100*sizeof(char));
    printf("Tamanho da resposta enviado...\n");
    write(sock, getSkillMessage, strlen(getSkillMessage)+1)*sizeof(char);
    printf("Mensagem enviada...\n");
    read(sock, skill, sizeof(skill));
    printf("Habilidade lida...\n");

    content = listHasSkill(skill);

    write(sock, content, strlen(content)+1 * sizeof(char));
    printf("Conteudo enviado...\n");
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
int listAllProfilesAction(){
    return 3;
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
        }
        return 0;
    }
    return 0;
}



// Funçoes privadas


int addProfessionalExperience() {
    return 3;
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
int listAllProfiles() {
    return 3;
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
