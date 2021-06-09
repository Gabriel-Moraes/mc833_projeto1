#include "actions.h"

#define MAX 200

// Constantes 
const char* getEmailRegisterMessage = "Digite o email para cadastro: \n";
const char* getFirstNameRegisterMessage = "Digite o seu primeiro nome para cadastro: \n";
const char* getLastNameRegisterMessage = "Digite o seu último nome para cadastro: \n";
const char* getResidenceRegisterMessage = "Digite o seu endereço de residencia para cadastro: \n";
const char* getAcademicBackgroundRegisterMessage = "Digite o seu curso para cadastro: \n";
const char* getGraduationYearRegisterMessage = "Digite o seu ano de formacao para cadastro: \n";
const char* getSkillRegisterMessage = "Digite suas habilidades para cadastro: \n";
const char* getProfExpRegisterMessage = "Digite suas experiencias profissionais para cadastro: \n";
const char* getEmailMessage = "Digite o email do usuario que gostaria de buscar: ";
const char* getEmailRemoveMessage = "Digite o email do usuario que gostaria de remover: ";
const char* getCourseMessage = "Digite o curso que gostaria de buscar: \n";
const char* getSkillMessage = "Digite a habilidade que gostaria de buscar: \n";
const char* getYearMessage = "Digite o ano que gostaria de buscar: \n";
const char* successfullyRemovedMessage = "Usuario removido com sucesso\n";

// Funçoes privadas

// TODO atribuir corretamente os campos do arquivo para os atributos da struct
//  Verificar se o segmentation fault é aqui ou no listGraduatedOnCourseAction
int readFile(Profile profile[], int n_p, FILE* fp, char course[50]){

   if(fp==NULL){
       printf("Error\n");
       return -1;
   } else {
       char buffer[955];
  
        int row = 0;
        int column = 0;
  
        while (fgets(buffer,
                     955, fp)) {
            column = 0;
            row++;
  
  
            // Splitting the data
            char* value = strtok(buffer, ", ");
  
            while (value) {
                // Column 1
                if(column == 0) {
                    char email[]
                }
                if (column == 4 && strcmp(value,course) {
                    printf("Name :");
                    fscanf(fp,"%50s %20s %20s %30s\n", profile[n_p].academicBackground, profile[n_p].firstName,
                //   profile[n_p].lastName, profile[n_p].email);
                // printf(">>%s, %s, %s, %s<<\n", profile[n_p].academicBackground, profile[n_p].firstName,
                //     profile[n_p].lastName, profile[n_p].email);
                // return 0;
                }
  
                printf("%s", value);
                value = strtok(NULL, ", ");
                column++;
            }
  
            printf("\n");
        }
  
        // Close the file
        fclose(fp);
    }
    return 0;
   }
    // 

}

char* removeNewLinesEmail(char email[30]  ) {
//     char* temp = strstr(email, "\r");
// // Remove \n.
    int i;
    int len = strlen(email);
    for(i=0;i < len ; i++){
        if(email[i]=='\n' || email[i] == '\t'|| email[i] == '\r') {
            email[i] = 0;
        }
    
    }
    return email;
}

char* removeNewLinesFN(char firstName[20]){   
    int len = strlen(firstName);
    int i;
    for(i=0;i < len ; i++){
        if(firstName[i]=='\n' || firstName[i] == '\t'|| firstName[i] == '\r') {
            firstName[i] = 0;
        }
    
    }
    return firstName;
}
char* removeNewLinesLN(char lastName[20]){
    int len = strlen(lastName);
    int i;
    for(i=0;i < len ; i++){
        if(lastName[i]=='\n' || lastName[i] == '\t'|| lastName[i] == '\r') {
            lastName[i] = 0;
        }
    }
    return lastName;
}
char* removeNewlinesRes(char residence[30]){
    int len = strlen(residence);
    int i;
    for(i=0;i < len ; i++){
        if(residence[i]=='\n' || residence[i] == '\t'|| residence[i] == '\r') {
            residence[i] = 0;
        }
    
    }
    return residence;
}

char* removeNewLinesAB(char academicBackground[50]) {
    int len = strlen(academicBackground);
    int i;
    for(i=0;i < len ; i++){
        if(academicBackground[i]=='\n' || academicBackground[i] == '\t'|| academicBackground[i] == '\r') {
            academicBackground[i] = 0;
        }
    }
    return academicBackground;
}
char* removeNewLinesGradY(char graduationYear[4]) {
    int len = strlen(graduationYear);
    int i;
    for(i=0;i < len ; i++){
        if(graduationYear[i]=='\n' || graduationYear[i] == '\t'|| graduationYear[i] == '\r') {
            graduationYear[i] = 0;
        }
    }
    return graduationYear;
}
char* removeNewLinesSkill(char skills[300]){
    int len = strlen(skills);
    int i;
    for(i=0;i < len ; i++){
        if(skills[i]=='\n' || skills[i] == '\t'|| skills[i] == '\r') {
            skills[i] = 0;
        }
    }
    return skills;
}
char* removeNewLinesProfExp(char professionalExperience[300]){
    int len = strlen(professionalExperience);
    int i;
    for(i=0;i < len ; i++){
        if(professionalExperience[i]=='\n' || professionalExperience[i] == '\t'|| professionalExperience[i] == '\r') {
            professionalExperience[i] = 0;
        }
    }
    return professionalExperience;
}
//     while ((temp = strstr(email, "\r")) != NULL) {
// // Len is the length of the string, from the ampersand \n, including the \n.
//         int len = strlen(email);
//         memmove(temp, temp + 1, len); 
//     }  

char* createProfile(char email[30],	char firstName[20],	char lastName[20], char residence[30], char academicBackground[50], char graduationYear[4], char skills[300], char professionalExperience[300]) {
    FILE* file = NULL;
    file = fopen("files/users.csv", "a");

    if (file == NULL) {
        printf("Falha ao abrir o arquivo!\n");
        return NULL;
    }
    // int len = strlen(email);
    // if(email[len-1]=='\n' || email[len-1] == '\t'|| email[len-1] == '\r') {
    //     email[len-1] = 0;
    //     printf("entrou aqui \n");
    // }
    email = removeNewLinesEmail(email);
    firstName = removeNewLinesFN(firstName);
    lastName = removeNewLinesLN(lastName);
    residence = removeNewlinesRes(residence);
    academicBackground = removeNewLinesAB(academicBackground);
    graduationYear = removeNewLinesGradY(graduationYear);
    skills = removeNewLinesSkill(skills);
    professionalExperience = removeNewLinesProfExp(professionalExperience);
    // fprintf(file,"Email, First Name, Last Name, Residence, Academic Background, graduation Year, skills, Professional Experience\n");
    int returnCode = fprintf(file, "%30s, %20s, %20s, %30s, %50s, %4s, %300s, %300s\n",email, firstName,lastName,residence,academicBackground,
        graduationYear, skills, professionalExperience);

    // Cria um novo perfil com base nas informaçoes recebidas
    // Profile newProfile;
    // strcpy(newProfile.email, email);
    // strcpy(newProfile.firstName, firstName);
    // strcpy(newProfile.lastName, lastName);
    // strcpy(newProfile.residence, residence);
    // strcpy(newProfile.academicBackground, academicBackground);
    // strcpy(newProfile.graduationYear, graduationYear);
    // strcpy(newProfile.skills, skills);
    // strcpy(newProfile.professionalExperience, professionalExperience);
    
    if (returnCode) {
        printf("Perfil inserido com sucesso!\n");    
        fclose(file);
        return "Perfil inserido com sucesso!\n";
    } else {
        printf("Falha ao inserir perfil!\n");
        fclose(file);
        return "Falha ao inserir perfil!\n";
    }

}

int addProfessionalExperience() {
        return 0;
}

// TODO Verificar se o segmentation fault é aqui ou no readFile
char* listGraduatedOnCourse(char* course) {
    FILE* file = NULL;
    file = fopen("files/users.dat", "r");

    if (file == NULL) {
        printf("Falha ao abrir o arquivo!\n");
        return NULL;
    }

    Profile searchedProfile[10];
    char* response = "";
    int i = 0, size;

    printf("Lendo o arquivo...\n");
    while (!feof(file)) {
        readFile(searchedProfile, i, file);
        i++;
    }
    size = i;

    fclose(file);

    for(i = 0; i<size; i++) {
        if(!strcmp(searchedProfile[i].academicBackground, course)) {
            printf("Perfil encontrado! Enviando informaçoes...\n");
            sprintf(response, "%s\n%s\n%s\n", searchedProfile[i].email, searchedProfile[i].firstName, 
                        searchedProfile[i].lastName);
        }
    }

    if(strcmp("",response) == 0) {
        printf("Nao foi encontrado um perfil com este curso\n");
        response = "Nao foi encontrado um perfil com este curso\n";
    } else{
        printf("Retornando perfis com curso\n");
    }

    return response;
}

// TODO ler corretamente os perfis do arquivo e comparar a skill recebida
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

    if (strcmp("",response) == 0) {
        printf("Nao foi encontrado um perfil com esta habilidade\n");
        response = "Nao foi encontrado um perfil com esta habilidade\n";
    } else {
        printf("Retornando perfis com curso\n");
    }

    return response;
}

// TODO após enviar corretamente o ano como parametro, verificar
// se o codigo está funcionando corretamente
char* listGraduatedOnYear(char* year) {
    FILE* file = NULL;
    file = fopen("files/users.dat", "r");

    if (file == NULL) {
        printf("\tFalha ao abrir o arquivo!\n");
        return NULL;
    }

    Profile searchedProfile;
    char* response = "";
    while(fread(&searchedProfile, sizeof(Profile), 1, file)) {
        printf("\tLendo o arquivo...\n");
        if(!strcmp(searchedProfile.graduationYear, year)) {
            printf("\tPerfil encontrado! Enviando informaçoes...\n");
            sprintf(response, "%s\n%s\n%s\n%s\n", searchedProfile.email, searchedProfile.firstName, 
                        searchedProfile.lastName, searchedProfile.academicBackground);
        }
    }
    strcmp("",response) == 0 ? printf("\tNao foi encontrado um perfil com este ano de formatura\n") : 
                      printf("\tRetornando perfis com este ano de formatura\n");
    return response;

}

// TODO Corrigir segmantation fault
char* getProfileInfo(char* email) {  
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

    return NULL;
 }

char* removeProfile(char* email) {
    FILE* file = NULL;
    file = fopen("files/users.dat", "r+");

    if (file == NULL) {
        printf("Falha ao abrir o arquivo!\n");
        return NULL;
    }

    Profile profileToRemove;
    while(fread(&profileToRemove, sizeof(Profile), 1, file)) {
        printf("Lendo o arquivo...\n");
        if(!strcmp(profileToRemove.email, email)) {
            printf("Perfil encontrado! Removendo perfil...\n");
            // TODO implementar funçao para remover as linhas referentes ao perfil a ser removido
            //removeLinesFromFile();
            return "Perfil removido!";
        }
    }
        return "Nao foi encontrado um perfil com este email!";
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
        }
        return 0;
    }
    return -1;
}

// TODO Acertar tamanho das mensagens de solicitaçao para escrever corretamente ao servidor
int createProfileAction(int sock) {
    char* content;
    char email[30], firstName[20], lastName[20], residence[30], academicBackground[50], graduationYear[4], skills[300],
	    profExp[300], responseSize[MAX];
    int size_message = 0;
    int size_message_teste = 0;
    bzero(responseSize, sizeof(responseSize));

    size_t sizeEmail = strlen(getEmailRegisterMessage);
    size_message = (int)(sizeEmail);
    sprintf(responseSize, "%d", size_message);

    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do email...\n");
    write(sock, responseSize, strlen(responseSize));
    printf("Tamanho da resposta enviado...\n");
    write(sock, getEmailRegisterMessage, strlen(getEmailRegisterMessage));
    printf("Mensagem enviada...\n");
    read(sock, email, sizeof(email));
    printf("Email lido...(%s)\n", email);

    size_t sizeFirstName = strlen(getFirstNameRegisterMessage);
    size_message = (int)(sizeFirstName);
    sprintf(responseSize, "%d", size_message);

    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do firstName...\n");
    write(sock, responseSize, strlen(responseSize)+1);
    printf("Tamanho da resposta enviado...\n");
    write(sock, getFirstNameRegisterMessage, strlen(getFirstNameRegisterMessage)+1);
    printf("Mensagem enviada...\n");
    read(sock, firstName, sizeof(firstName));
    printf("firstName lido...(%s)\n", firstName);

    size_t sizeLastName = strlen(getLastNameRegisterMessage);

    size_message = (int)(sizeLastName);
    sprintf(responseSize, "%d", size_message);

    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do lastName...\n");
    write(sock, responseSize, strlen(responseSize)+1);
    printf("Tamanho da resposta enviado...\n");
    write(sock, getLastNameRegisterMessage, strlen(getLastNameRegisterMessage)+1);
    printf("Mensagem enviada...\n");
    read(sock, lastName, sizeof(lastName));
    printf("lastName lido...(%s)\n", lastName);

    size_t sizeResidence = strlen(getResidenceRegisterMessage);
    size_message = (int)(sizeResidence);
    sprintf(responseSize, "%d", size_message);
    

    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do residence...\n");
    write(sock, responseSize, strlen(responseSize)+1);
    printf("Tamanho da resposta enviado...\n");
    write(sock, getResidenceRegisterMessage, strlen(getResidenceRegisterMessage)+1);
    printf("Mensagem enviada...\n");
    read(sock, residence, sizeof(residence));
    printf("Residence lido...(%s)\n", residence);

    size_t sizeAcademic = strlen(getAcademicBackgroundRegisterMessage);
    size_message = (int)(sizeAcademic);
    sprintf(responseSize, "%d", size_message);

    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do academicBackground...\n");
    write(sock, responseSize, strlen(responseSize)+1);
    printf("Tamanho da resposta enviado...\n");
    write(sock, getAcademicBackgroundRegisterMessage, strlen(getAcademicBackgroundRegisterMessage)+1);
    printf("Mensagem enviada...\n");
    read(sock, academicBackground, sizeof(academicBackground));
    printf("AcademicBackground lido...(%s)\n", academicBackground);


    size_t sizeYear = strlen(getGraduationYearRegisterMessage);
    size_message = (int)(sizeYear);
    sprintf(responseSize, "%d", size_message);

    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do graduationYear...\n");
    write(sock, responseSize, strlen(responseSize)+1);
    printf("Tamanho da resposta enviado...\n");
    write(sock, getGraduationYearRegisterMessage, strlen(getGraduationYearRegisterMessage)+1);
    printf("Mensagem enviada...\n");
    read(sock, graduationYear, sizeof(graduationYear));
    printf("GraduationYear lido...(%s)\n", graduationYear);


    size_t sizeSkill = strlen(getSkillRegisterMessage);
    size_message_teste = (int)(sizeSkill);
    sprintf(responseSize, "%d", size_message_teste);    

    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao da habilidade...\n");
    write(sock, responseSize, strlen(responseSize)+1);
    printf("Tamanho da resposta enviado...\n");
    write(sock, getSkillRegisterMessage, strlen(getSkillRegisterMessage)+1);
    printf("Mensagem enviada...\n");
    read(sock, skills, sizeof(skills));
    printf("Habilidade lida...\n");

    size_t sizeProfExp = strlen(getProfExpRegisterMessage);
    size_message = (int)(sizeProfExp);
    sprintf(responseSize, "%d", size_message);

    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao da experiencia profissional...\n");
    write(sock, responseSize, strlen(responseSize)+1);
    printf("Tamanho da resposta enviado...\n");
    write(sock, getProfExpRegisterMessage, strlen(getProfExpRegisterMessage)+1);
    printf("Mensagem enviada...\n");
    read(sock, profExp, sizeof(profExp));
    printf("Experiencia profissional lida...\n");

    content = createProfile(email,firstName, lastName, residence, academicBackground, graduationYear, skills, profExp);
    
    size_t sizeFinalMessage = strlen(content);
    size_message = (int)(sizeFinalMessage);
    sprintf(responseSize, "%d", size_message);

    write(sock, responseSize, strlen(responseSize)+1);
    write(sock, content, strlen(content)+1);
    printf("Conteudo enviado...\n");

    return 0;
}

int addProfessionalExperienceAction(int sock){
        return 0;
}

int listGraduatedOnCourseAction(int sock) {
    char* content;
    char course[50], responseSize[MAX];
    bzero(responseSize, sizeof(responseSize));

    size_t size = strlen(getCourseMessage);
    int size_message = (int)(size);
    sprintf(responseSize, "%d", size_message);
    
    printf("Tamanho da resposta: %s\n", responseSize);
    write(sock, responseSize, strlen(responseSize)+1);
    printf("Tamanho da resposta enviado...\n");
    printf("Enviando solicitaçao do curso...\n");
    write(sock, getCourseMessage, strlen(getCourseMessage)+1);
    printf("Mensagem enviada...\n");
    read(sock, course, sizeof(course));
    printf("Curso lido...(%s)\n", course);
    content = listGraduatedOnCourse(course);

    size_t sizeFinalMessage = strlen(content);
    size_message = (int)(sizeFinalMessage);
    sprintf(responseSize, "%d", size_message);

    write(sock, responseSize, strlen(responseSize)+1);
    write(sock, content, strlen(content)+1);
    printf("Conteudo enviado...\n");
    return 0;
}

int listHasSkillAction(int sock){
    char* content;
    char skill[50], responseSize[MAX];
    bzero(responseSize, sizeof(responseSize));


    size_t size = strlen(getSkillMessage); 
    int size_message = (int)(size);
    sprintf(responseSize, "%d", size_message);

    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao da habilidade...\n");
    write(sock, responseSize, strlen(responseSize)+1);
    printf("Tamanho da resposta enviado...\n");
    write(sock, getSkillMessage, strlen(getSkillMessage)+1);
    printf("Mensagem enviada...\n");
    read(sock, skill, sizeof(skill));
    printf("Habilidade lida...(%s)\n", skill);

    content = listHasSkill(skill);

    size_t sizeFinalMessage = strlen(content);
    size_message = (int)(sizeFinalMessage);
    sprintf(responseSize, "%d", size_message);

    write(sock, responseSize, strlen(responseSize)+1);
    write(sock, content, strlen(content)+1);
    printf("Conteudo enviado...\n");
    return 0;
}

// TODO corrigir recebimento do ano (ultimo caractere esta bugado)
int listGraduatedOnYearAction(int sock) {
    char* content;
    char year[4], responseSize[MAX];
    bzero(responseSize, sizeof(responseSize));

    sprintf(responseSize, "%ld", strlen(getYearMessage)+1);
    printf("Tamanho da resposta: %s\n", responseSize);
    printf("Enviando solicitaçao do ano...\n");
    write(sock, responseSize, strlen(responseSize)+1);
    printf("\tTamanho da resposta enviado...\n");
    write(sock, getYearMessage, strlen(getYearMessage)+1);
    printf("\tSolicitaçao do ano enviada...\n");
    read(sock, year, sizeof(year));
    printf("\tAno lido...(%s)\n", year);
    content = listGraduatedOnYear(year);

    size_t sizeFinalMessage = strlen(content);
    sprintf(responseSize, "%d", (int) sizeFinalMessage);

    write(sock, responseSize, strlen(responseSize)+1);
    write(sock, content, strlen(content)+1);
    printf("Conteudo enviado...\n");
    return 0;
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

// TODO resolver erro devido ao malloc que quebra o servidor
// free(): double free detected in tcache 2
// char* getAllCharsOnFile(FILE* file, int size) {
//     char* c;
//     char* returnMessage = malloc(size);

//     // Conta a quantidade de caracteres no arquivo
//     while ((c = fgetc(file)) != EOF) {
//         strncpy(returnMessage, c, 1);
//     }
    
//     fclose(file);
//     return returnMessage;
// }

int listAllProfilesAction(int sock) {
    // Abre o arquivo dos usuarios
    FILE* file = NULL;
    file = fopen("files/users.dat", "r");

    if (file == NULL) {
        printf("Falha ao abrir arquivo!\n");
        return -1;
    }

    int fileSize = countCharsOnFile(file);
    char responseSize[MAX];
    // char* fullMessage;
    // fullMessage = getAllCharsOnFile(file, fileSize);

    // Converte o tamanho do arquivo de int para char
    sprintf(responseSize, "%d", fileSize);

    // printf("Mensagem enviada:\n%s", fullMessage);
    write(sock, responseSize, strlen(responseSize)+1);
    // write(sock, fullMessage, strlen(fullMessage)+1);

    // free(fullMessage);
    fclose(file);
    return 0;
}

int getProfileInfoAction(int sock) {
    char* content;
    char email[30], responseSize[MAX];
    bzero(responseSize, sizeof(responseSize));

    sprintf(responseSize, "%ld", strlen(getEmailMessage)+1); 
    printf("Enviando solicitaçao do email...\n");
    write(sock, responseSize, strlen(responseSize)+1);
    write(sock, getEmailMessage, strlen(getEmailMessage)+1);
    read(sock, email, sizeof(email));
    content = getProfileInfo(email);
    
    size_t sizeFinalMessage = strlen(content);
    sprintf(responseSize, "%d", (int) sizeFinalMessage);

    write(sock, responseSize, strlen(responseSize)+1);
    write(sock, content, strlen(content)+1);
    printf("Conteudo enviado...\n");
    return 0;
}

int removeProfileAction(int sock){
    char email[30], responseSize[MAX];
    bzero(responseSize, sizeof(responseSize));

    sprintf(responseSize, "%ld", strlen(getEmailRemoveMessage)); 
    printf("Enviando solicitaçao do email...\n");
    write(sock, responseSize, strlen(responseSize)+1);
    write(sock, getEmailRemoveMessage, strlen(getEmailRemoveMessage)+1);
    read(sock, email, sizeof(email));

    char* content = removeProfile(email);

    size_t sizeFinalMessage = strlen(content);
    sprintf(responseSize, "%d", (int) sizeFinalMessage);

    write(sock, responseSize, strlen(responseSize)+1);
    write(sock, content, strlen(content)+1);
    printf("%s\n", content);
    return 0;
}