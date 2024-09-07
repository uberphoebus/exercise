#include "main.h"

int main() {

  if (passwordCheck() == 0) {
    return 0;
  }

  loadCoffeeMenu();
  // loadTodaySales();
  // mainMenu();

  return 0;
}

int passwordCheck() {
  int password;
  printf("\n\t\t\t Coffee Management System\n");
  printf("\n\t\t\t\t Enter Password: ");
  scanf("%d", &password);

  if (password == 1234) {
    return 1;
  } else {
    printf("\n\t\t\t\t Wrong password. System exit.\n");
    sleep(1);
    return 0;
  }
}

void loadCoffeeMenu() {
  FILE *pFile;
  menuItem *tmp = menuItemList;
  char line[80];
  char menuName[30];
  int id;
  int price;

  pFile = fopen("menu.txt", "r");
  if (pFile == NULL) {
    printf("File not found.\n");
    return;
  }

  while (fgets(line, 80, pFile) != NULL) {
    sscanf(line, "%d %s %d", &id, menuName, &price);
    // insertCoffeeMenu(id, menuName, price);
  }
}

void insertCoffeeMenu(int id, char *menuName, int price) {
  menuItem *head;
  menuItem *tmp = (menuItem *)malloc(sizeof(menuItem));

  if (tmp != NULL) {
    tmp->id = id;
    strcpy(tmp->menuName, menuName);
    tmp->price = price;
    tmp->next = NULL;
  } else {
    printf("Memory allocation failed.\n");
    return;
  }

  if (menuItemList == NULL) {
    menuItemList = tmp;
  } else {
    head = menuItemList;
    while (head->next != NULL) {
      head = head->next;
    }
    head->next = tmp;
  }
}