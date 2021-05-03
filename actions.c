#include "actions.h"

// Funçoes do header
int treatClientActionRequest(char* request) {
	if ((strncmp(request, "exit", 4)) == 0) {
        return -2;
    } else {
        int action = atoi(request);

        switch (action) {
            case 1:
                createProfileAction();
                break;
            case 2:
                addProfessionalExperienceAction();
                break;
            case 3:
                listGraduatedOnCourseAction();
                break;
            case 4:
                listHasSkillAction();
                break;
            case 5:
                listGraduatedOnYearAction();
                break;
            case 6:
                listAllProfilesAction();
                break;
            case 7:
                getProfileInfoAction();
                break;
            case 8:
                removeProfileAction();
                break;
            default: 
                printf("Açao invalida!\n");
                return -1;	

            return 0;
        }
    }
}

int createProfileAction() {
    
}
int addProfessionalExperienceAction(){

}
int listGraduatedOnCourseAction(){

}
int listHasSkillAction(){

}
int listGraduatedOnYearAction(){

}
int listAllProfilesAction(){

}
int getProfileInfoAction(){

}
int removeProfileAction(){

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
int getProfileInfo() {

}
int removeProfile() {

}