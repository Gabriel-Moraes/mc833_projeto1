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
const char* getProfExpUpdateMessage = "Digite suas experiencias profissionais para Atualizarmos: \n";
const char* getEmailMessage = "Digite o email do usuario que gostaria de buscar: ";
const char* getEmailRemoveMessage = "Digite o email do usuario que gostaria de remover: ";
const char* getCourseMessage = "Digite o curso que gostaria de buscar: \n";
const char* getSkillMessage = "Digite a habilidade que gostaria de buscar: \n";
const char* getYearMessage = "Digite o ano que gostaria de buscar: \n";
const char* successfullyRemovedMessage = "Usuario removido com sucesso\n";

// Funçoes privadas

// TODO atribuir corretamente os campos do arquivo para os atributos da struct
//  Verificar se o segmentation fault é aqui ou no listGraduatedOnCourseAction
char* removeBlanks(char* text, char* blank) {
    // char blank[300];
    int c = 0, d = 0;
 
   while (text[c] != '\0')
   {
      if (!(text[c] == ' ' && text[c+1] == ' ')) {
        blank[d] = text[c];
        d++;
      }
      c++;
   }
 
   blank[d] = '\0';
 
   printf("Text after removing blanks\n%s\n", blank);
 
   return blank;
}
//Funções para remover quebras de linha dos campos

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

char* removeNewLines(char* data){
    int len = strlen(data);
    int i;
    for(i=0;i < len ; i++){
        if(data[i]=='\n' || data[i] == '\t'|| data[i] == '\r') {
            data[i] = 0;
        }
    }
    return data;
}

char* createProfile(char email[30],	char firstName[20],	char lastName[20], char residence[30], char academicBackground[50], char graduationYear[4], char skills[300], char professionalExperience[300]) {
    char email2[30];
    char professionalExperience2[300];
    char firstName2[20];
    char lastName2[20];
    char residence2[30];
    char academicBackground2[50];
    char graduationYear2[4];
    char skills2[300];
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
    strcpy(email2 , removeBlanks(email, email2));
    strcpy(professionalExperience2 , removeBlanks(professionalExperience, professionalExperience2));
    strcpy(firstName2 , removeBlanks(firstName, firstName2));
    strcpy(lastName2 , removeBlanks(lastName, lastName2));
    strcpy(residence2 , removeBlanks(residence, residence2));
    strcpy(academicBackground2 , removeBlanks(academicBackground, academicBackground2));
    strcpy(graduationYear2 , removeBlanks(graduationYear, graduationYear2));
    strcpy(skills2 , removeBlanks(skills, skills2));
    // fprintf(file,"Email, First Name, Last Name, Residence, Academic Background, graduation Year, skills, Professional Experience\n");
    

    // Cria um novo perfil com base nas informaçoes recebidas

    Profile newProfile;
    strcpy(newProfile.email, email2);
    strcpy(newProfile.firstName, firstName2);
    strcpy(newProfile.lastName, lastName2);
    strcpy(newProfile.residence, residence2);
    strcpy(newProfile.academicBackground, academicBackground2);
    strcpy(newProfile.graduationYear, graduationYear2);
    strcpy(newProfile.skills, skills2);
    strcpy(newProfile.professionalExperience, professionalExperience2);
    // int returnCode = fprintf(file, "%30s, %20s, %20s, %30s, %50s, %4s, %300s, %300s\n",newProfile.email, newProfile.firstName,newProfile.lastName,newProfile.residence,newProfile.academicBackground,
        // newProfile.graduationYear, newProfile.skills, newProfile.professionalExperience);
    int returnCode = fwrite (&newProfile, sizeof(Profile), 1,file);
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

char* addProfessionalExperience(char email[30], int sock) {
    FILE* file = NULL;
    file = fopen("files/users.csv", "r");

    if (file == NULL) {
        printf("Falha ao abrir o arquivo!\n");
        return NULL;
    }

    Profile searchedProfile;
    // char* response = malloc(1000);
    char* emailNoNewLine = removeNewLines(email);
    char responseSize[MAX];
    char profExp[300];
    while(fread(&searchedProfile, sizeof(Profile), 1, file)) {
        printf("Lendo o arquivo...\n");
        if(!strcmp(searchedProfile.email, emailNoNewLine)) {
            printf("Perfil encontrado! Solicitando informaçoes...\n");
            size_t sizeProfExp = strlen(getProfExpUpdateMessage);
            int size_message = (int)(sizeProfExp);
            sprintf(responseSize, "%d", size_message);

            printf("Tamanho da resposta: %s\n", responseSize);
            printf("Enviando solicitaçao do experiencia...\n");
            write(sock, responseSize, strlen(responseSize)+1);
            printf("Tamanho da resposta enviado...\n");
            write(sock, getProfExpUpdateMessage, strlen(getProfExpUpdateMessage)+1);
            printf("Mensagem enviada...\n");
            read(sock, profExp, sizeof(profExp));
            printf("experiencia lida...(%s)\n", profExp);
            char* profExpNoNewLine = removeNewLinesProfExp(profExp);
            // sprintf (response, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", searchedProfile.email, searchedProfile.firstName, searchedProfile.lastName, 
            //             searchedProfile.residence, searchedProfile.academicBackground, searchedProfile.graduationYear, searchedProfile.skills,
            //                 searchedProfile.professionalExperience);
            strcpy(searchedProfile.professionalExperience,profExpNoNewLine);
            fwrite (&searchedProfile, sizeof(Profile), 1,file);
            return "Perfil Atualizado com Sucesso!\n";
        }

        printf("Nao foi encontrado um perfil com este email");
        return NULL;        
    }

    return NULL;
}
char* listGraduatedOnCourse(char* course) {
    FILE* file = NULL;
    file = fopen("files/users.csv", "r");

    if (file == NULL) {
        printf("Falha ao abrir o arquivo!\n");
        return NULL;
    }

    Profile searchedProfile[100];
    char* response =malloc (90);
    int i = 0;
    // int size;
    printf("Lendo o arquivo...\n");

    // int count = readFile(searchedProfile, file);
     if(file==NULL){
       printf("Error\n");
       return "";
    }else{
        char* courseNoNewLine = removeNewLines(course);
        // printf("o valor de count é %d", count);
        while(fread(&searchedProfile[i], sizeof(Profile), 1, file) ) {
            printf("%s\n", searchedProfile[i].academicBackground); 
            if(!strcmp(searchedProfile[i].academicBackground, courseNoNewLine)) {
                printf("Perfil encontrado! Enviando informaçoes...\n");
                sprintf(response, "%s\n%s\n%s\n", searchedProfile[i].email, searchedProfile[i].firstName, 
                            searchedProfile[i].lastName);
                
            }
            i++;
        }
    }
    fclose(file);
    
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
        strcpy(response , "Nao foi encontrado um perfil com este curso\n");
    }else{
        printf("Retornando perfis com curso\n");
    }
                      
    return response;
}
char* listHasSkill(char* skill) {
    FILE* file = NULL;
    file = fopen("files/users.csv", "r");

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
    file = fopen("files/users.csv", "r");

    if (file == NULL) {
        printf("\tFalha ao abrir o arquivo!\n");
        return NULL;
    }

    Profile searchedProfile;
    char* response = malloc(90);
    char* yearNoNewLine = removeNewLines(year);
    while(fread(&searchedProfile, sizeof(Profile), 1, file)) {
        printf("\tLendo o arquivo...\n");
        printf("%s\n", searchedProfile.graduationYear);
        if(!strcmp(searchedProfile.graduationYear, yearNoNewLine)) {
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
    file = fopen("files/users.csv", "r");

    if (file == NULL) {
        printf("Falha ao abrir o arquivo!\n");
        return NULL;
    }

    Profile searchedProfile;
    char* response = malloc(1000);
    char* emailNoNewLine = removeNewLines(email);
    while(fread(&searchedProfile, sizeof(Profile), 1, file)) {
        printf("Lendo o arquivo...\n");
        if(!strcmp(searchedProfile.email, emailNoNewLine)) {
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

char* removeProfile(char* email)
{
    FILE* file = NULL;
    file = fopen("files/users.csv", "r+");
    FILE* newfile = fopen("temp.csv", "w");
    if (file == NULL) {
        printf("Falha ao abrir o arquivo!\n");
        return NULL;
    }
    int success = 0;
    Profile tempProfile;
    while(!feof(file)){
        printf("Lendo o arquivo...\n");
        fread(&tempProfile, sizeof(tempProfile), 1, file);
        if(strcmp(email, tempProfile.email)){
            fwrite(&tempProfile, sizeof(tempProfile), 1, newfile);
        } 
        else{
            printf("Perfil encontrado! Removendo perfil...\n");
            success = 1;
        }
    }
    
    fclose(newfile);
    fclose(file);
    remove("users.csv");
    rename("temp.csv", "users.csv");
    if(success) {
        return "Perfil removido!";
    } else{
        return "Nao foi encontrado um perfil com este email!";
    }
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
                printf("Açao invalida!>%d<\n",sock);
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
    char* content;
    char email[30], responseSize[MAX];
    bzero(responseSize, sizeof(responseSize));

    size_t size = strlen(getEmailMessage);
    int size_message = (int)(size);
    sprintf(responseSize, "%d", size_message);
    
    printf("Tamanho da resposta: %s\n", responseSize);
    write(sock, responseSize, strlen(responseSize)+1);
    printf("Tamanho da resposta enviado...\n");
    printf("Enviando solicitaçao do email...\n");
    write(sock, getEmailMessage, strlen(getEmailMessage)+1);
    printf("Mensagem enviada...\n");
    read(sock, email, sizeof(email));
    printf("Curso lido...(%s)\n", email);
    content = addProfessionalExperience(email,sock);
    size_t sizeFinalMessage = strlen(content);
    size_message = (int)(sizeFinalMessage);
    sprintf(responseSize, "%d", size_message);

    write(sock, responseSize, strlen(responseSize)+1);
    write(sock, content, strlen(content)+1);
    printf("Conteudo enviado...\n");
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
// int countCharsOnFile(FILE* file) {
//     int count = 0;
//     char c;

//     // Conta a quantidade de caracteres no arquivo
//     while ((c = fgetc(file)) != EOF) {
//         count++;
//     }

//     fclose(file);
//     return count;
// }



int listAllProfilesAction(int sock) {
    // Abre o arquivo dos usuarios
    FILE* file = NULL;
    file = fopen("files/users.csv", "r");

    if (file == NULL) {
        printf("Falha ao abrir arquivo!\n");
        return -1;
    }


    char responseSize[MAX];
    Profile searchedProfile;
    // Converte o tamanho do arquivo de int para char
    while(fread(&searchedProfile, sizeof(Profile), 1, file)) {
        printf("\tLendo o arquivo...\n");
            sprintf(responseSize, "%s\n%s\n%s\n%s\n", searchedProfile.email, searchedProfile.firstName, 
                        searchedProfile.lastName, searchedProfile.academicBackground);
    }
   


    write(sock, responseSize, strlen(responseSize)+1);
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
    char* email2 = removeNewLinesEmail(email);
    char* content = removeProfile(email2);

    size_t sizeFinalMessage = strlen(content);
    sprintf(responseSize, "%d", (int) sizeFinalMessage);

    write(sock, responseSize, strlen(responseSize)+1);
    write(sock, content, strlen(content)+1);
    printf("%s\n", content);
    return 0;
}