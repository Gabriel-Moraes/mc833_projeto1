#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int treatClientActionRequest(int sock, char* request); 
int createProfileAction(int sock);
int addProfessionalExperienceAction(int sock);
int listGraduatedOnCourseAction(int sock);
int listHasSkillAction(int sock);
int listGraduatedOnYearAction(int sock);
int listAllProfilesAction(int sock);
int getProfileInfoAction(int sock);
int removeProfileAction(int sock);