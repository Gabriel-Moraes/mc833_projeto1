#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct profile {
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
int createProfileAction(int sock);
int addProfessionalExperienceAction(int sock);
int listGraduatedOnCourseAction(int sock);
int listHasSkillAction(int sock);
int listGraduatedOnYearAction(int sock);
int listAllProfilesAction(int sock);
int getProfileInfoAction(int sock);
int removeProfileAction(int sock);
