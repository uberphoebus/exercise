#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_LENGTH 20
#define SUBJECT_COUNT 3

typedef struct {
  int studentID;
  char studentName[MAX_CHAR_LENGTH];
  struct subject {
    int subjectCode;
    char subjectName[MAX_CHAR_LENGTH];
    int subjectScore;
  } subject[SUBJECT_COUNT];
  int totalScore;
  float averageScore;
} studentRecord;

// menu display functions
void title();
void menuDisplay();
void menuSelect(int choice);

// menu functions
void insert();
int displayCount();
void displayAll();
void search();
void update();
void delete ();

studentRecord *readAndSaveStudentRecord(int *iCount);
void writeStudentRecord(studentRecord *stStudent, int iCount);

void sortByScore();
void sortByID();
void sortByName();

int main() {
  int choice = 0;
  do {
    menuDisplay();
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    menuSelect(choice);
  } while (choice != 0);
}

void title() {
  printf("+");
  char *pcTitle = "Student Record System";
  __uint32_t iTitleLength = strlen(pcTitle) + 2;
  for (__uint32_t i = 0; i < iTitleLength; i++) {
    printf("-");
  }
  printf("+\n");
  printf("| %s |\n", pcTitle);
  printf("+");
  for (__uint32_t i = 0; i < iTitleLength; i++) {
    printf("-");
  }
  printf("+\n");
}

void menuDisplay() {
  title();
  printf("1. Add Student Record\t\t");
  printf("2. Display Record Count\n");
  printf("3. Display All Records\t\t");
  printf("4. Search Record\n");
  printf("5. Update Record\t\t");
  printf("6. Delete Record\n");
  printf("7. Sort by Score\t\t");
  printf("8. Sort by ID\n");
  printf("9. Sort by Name\t\t\t");
  printf("0. Exit\n");
}

void menuSelect(int choice) {
  switch (choice) {
  case 1:
    insert();
    break;
  case 2:
    displayCount();
    break;

  case 3:
    displayAll();
    break;

  case 4:
    search();
    break;

  case 5:
    update();
    break;

  case 6:
    delete ();
    break;

  case 7:
    sortByScore();
    break;

  case 8:
    sortByID();
    break;

  case 9:
    sortByName();
    break;
  }
}

void insert() {
  FILE *pFile;
  studentRecord stStudent;
  char buf[MAX_CHAR_LENGTH];
  pFile = fopen("studentRecord.txt", "a");

  // student ID
  printf("Enter Student ID: ");
  scanf("%s", buf);
  getchar();
  for (int i = 0; buf[i] != '\0'; i++) {
    if (!isdigit(buf[i])) {
      printf("Invalid Student ID\n");
      return;
    }
  }
  stStudent.studentID = atoi(buf);

  // student name
  printf("Enter Student Name: ");
  scanf("%[^\n]", stStudent.studentName);

  // score
  stStudent.totalScore = 0;
  for (int i = 0; i < SUBJECT_COUNT; i++) {
    printf("Enter score of subject %d: ", i + 1);
    scanf("%d", &stStudent.subject[i].subjectScore);
    stStudent.totalScore += stStudent.subject[i].subjectScore;
  }

  // average
  stStudent.averageScore = (float)stStudent.totalScore / (float)SUBJECT_COUNT;
  fwrite(&stStudent, sizeof(studentRecord), 1, pFile);
  fclose(pFile);
}

int displayCount() {
  FILE *pFile;
  pFile = fopen("studentRecord.txt", "r");

  if (pFile == NULL) {
    printf("File not found\n");
    return 0;
  }

  fseek(pFile, 0, SEEK_END);
  int iCount = ftell(pFile) / sizeof(studentRecord);
  fclose(pFile);

  printf("Total number of records: %d\n", iCount);

  return iCount;
}

void displayAll() {
  FILE *pFile;
  studentRecord stStudent;
  pFile = fopen("studentRecord.txt", "r");

  if (pFile == NULL) {
    printf("File not found\n");
    return;
  }

  int iCount = displayCount();
  if (iCount >= 1) {
    printf("%-10s%-10s", "ID", "Name");
    printf("%6s%6s%6s", "Sub1", "Sub2", "Sub3");
    printf("%8s%8s\n", "Total", "Avg");
    while (fread(&stStudent, sizeof(studentRecord), 1, pFile)) {
      printf("%-10d%-10s", stStudent.studentID, stStudent.studentName);
      for (int i = 0; i < SUBJECT_COUNT; i++) {
        printf("%6d", stStudent.subject[i].subjectScore);
      }
      printf("%8d%8.2f\n", stStudent.totalScore, stStudent.averageScore);
    }
  } else {
    printf("No record found\n");
  }

  fclose(pFile);
}

void search() {
  FILE *pFile;
  studentRecord stStudent;
  int iID = 0;
  int found = 0;
  pFile = fopen("studentRecord.txt", "r");

  if (pFile == NULL) {
    printf("File not found\n");
    return;
  }

  printf("Enter Student ID to search: ");
  scanf("%d", &iID);

  while (fread(&stStudent, sizeof(studentRecord), 1, pFile)) {
    if (stStudent.studentID == iID) {
      found = 1;
      printf("%-10s%-10s", "ID", "Name");
      printf("%6s%6s%6s", "Sub1", "Sub2", "Sub3");
      printf("%8s%8s\n", "Total", "Avg");
      printf("%-10d%-10s", stStudent.studentID, stStudent.studentName);
      for (int i = 0; i < SUBJECT_COUNT; i++) {
        printf("%6d", stStudent.subject[i].subjectScore);
      }
      printf("%8d%8.2f\n", stStudent.totalScore, stStudent.averageScore);
      fclose(pFile);
      return;
    }
  }

  if (found == 0) {
    printf("Record not found\n");
  }
  fclose(pFile);
}

void update() {
  FILE *pFile;
  FILE *pFileTmp;

  studentRecord stStudent;
  int iID = 0;
  int found = 0;

  pFile = fopen("studentRecord.txt", "r");
  pFileTmp = fopen("temp.txt", "w");

  printf("Enter Student ID to update: ");
  scanf("%d", &iID);
  while (fread(&stStudent, sizeof(studentRecord), 1, pFile)) {
    if (stStudent.studentID == iID) {
      found = 1;
      stStudent.totalScore = 0;
      getchar();
      printf("Enter Student New Name: ");
      scanf("%[^\n]", stStudent.studentName);
      for (int i = 0; i < SUBJECT_COUNT; i++) {
        printf("Enter new score of subject %d: ", i + 1);
        scanf("%d", &stStudent.subject[i].subjectScore);
        stStudent.totalScore += stStudent.subject[i].subjectScore;
      }
      stStudent.averageScore =
          (float)stStudent.totalScore / (float)SUBJECT_COUNT;
    }
    fwrite(&stStudent, sizeof(studentRecord), 1, pFileTmp);
  }

  fclose(pFile);
  fclose(pFileTmp);
  if (found == 1) {
    remove("studentRecord.txt");
    rename("temp.txt", "studentRecord.txt");
  } else {
    remove("temp.txt");
    printf("Record not found\n");
  }
}

void delete () {
  FILE *pFile;
  FILE *pFileTmp;

  studentRecord stStudent;
  int iID = 0;
  int found = 0;

  pFile = fopen("studentRecord.txt", "r");
  pFileTmp = fopen("temp.txt", "w");

  printf("Enter Student ID to delete: ");
  scanf("%d", &iID);
  while (fread(&stStudent, sizeof(studentRecord), 1, pFile)) {
    if (stStudent.studentID == iID) {
      found = 1;
    } else {
      fwrite(&stStudent, sizeof(studentRecord), 1, pFileTmp);
    }
  }

  fclose(pFile);
  fclose(pFileTmp);

  if (found == 1) {
    remove("studentRecord.txt");
    rename("temp.txt", "studentRecord.txt");
  } else {
    remove("temp.txt");
    printf("Record not found\n");
  }
}

studentRecord *readAndSaveStudentRecord(int *iCount) {
  FILE *pFile;
  studentRecord *stStudent;
  pFile = fopen("studentRecord.txt", "r");

  if (pFile == NULL) {
    printf("File not found\n");
    return NULL;
  }

  fseek(pFile, 0, SEEK_END);
  *iCount = ftell(pFile) / sizeof(studentRecord);
  rewind(pFile);

  stStudent = (studentRecord *)calloc(*iCount, sizeof(studentRecord));
  for (int i = 0; i < *iCount; i++) {
    fread(&stStudent[i], sizeof(studentRecord), 1, pFile);
  }
  fclose(pFile);

  return stStudent;
}

void writeStudentRecord(studentRecord *stStudent, int iCount) {
  FILE *pFile;
  pFile = fopen("studentRecord.txt", "w");

  for (int i = 0; i < iCount; i++) {
    fwrite(&stStudent[i], sizeof(studentRecord), 1, pFile);
  }
  fclose(pFile);
}

void sortByScore() {
  studentRecord *stStudent;
  studentRecord stStudentTmp;
  int iCount = 0;

  stStudent = readAndSaveStudentRecord(&iCount);

  for (int i = 0; i < iCount; i++) {
    for (int j = i + 1; j < iCount; j++) {
      if (stStudent[i].totalScore < stStudent[j].totalScore) {
        stStudentTmp = stStudent[i];
        stStudent[i] = stStudent[j];
        stStudent[j] = stStudentTmp;
      }
    }
  }

  writeStudentRecord(stStudent, iCount);
  displayAll();
}

void sortByID() {
  studentRecord *stStudent;
  studentRecord stStudentTmp;
  int iCount = 0;

  stStudent = readAndSaveStudentRecord(&iCount);

  for (int i = 0; i < iCount; i++) {
    for (int j = i + 1; j < iCount; j++) {
      if (stStudent[i].studentID > stStudent[j].studentID) {
        stStudentTmp = stStudent[i];
        stStudent[i] = stStudent[j];
        stStudent[j] = stStudentTmp;
      }
    }
  }

  writeStudentRecord(stStudent, iCount);
  displayAll();
}

void sortByName() {
  studentRecord *stStudent;
  studentRecord stStudentTmp;
  int iCount = 0;

  stStudent = readAndSaveStudentRecord(&iCount);

  for (int i = 0; i < iCount; i++) {
    for (int j = i + 1; j < iCount; j++) {
      if (strcmp(stStudent[i].studentName, stStudent[j].studentName) > 0) {
        stStudentTmp = stStudent[i];
        stStudent[i] = stStudent[j];
        stStudent[j] = stStudentTmp;
      }
    }
  }

  writeStudentRecord(stStudent, iCount);
  displayAll();
}
