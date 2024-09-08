#include "main.h"

menuItem *g_menuItemList;
orderNode *g_orderList;

int main() {

  system("clear");
  if (passwordCheck() == 0) {
    return 0;
  }

  loadCoffeeMenu();
  // loadTodaySales();
  mainMenu();

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
  menuItem *tmp = g_menuItemList;
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
    sscanf(line, "%d, %[^,], %d", &id, menuName, &price);
    insertCoffeeMenu(id, menuName, price);
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

  if (g_menuItemList == NULL) {
    g_menuItemList = tmp;
  } else {
    head = g_menuItemList;
    while (head->next != NULL) {
      head = head->next;
    }
    head->next = tmp;
  }
}

void mainMenu() {
  int choice;
  int s = 0;

  while (1) {
    showMainMenu();
    s = scanf("%d", &choice);

    switch (choice) {
    case 1:
      showCoffeeMenuList();
      break;
    case 2:
      order();
      break;
    case 3:
      deleteOrder();
      break;
    case 4:
      showOrderList();
      break;
    case 5:
      showSaleToday();
      break;
    case 6:
      if (addCoffeeMenu() == 1) {
        saveMenuFile();
      }
      break;
    case 7:
      if (deleteCoffeeMenu() == 1) {
        saveMenuFile();
      }
      break;
    case 0:
      if (close() == 1) {
        return;
      }
      break;
    default:
      break;
    }
  }
}

void showMainMenu() {
  system("clear");
  printf("\n\t\t\t\t=== Main Menu ===\n\n");
  printf("\t\t\t 1. Show Coffee Menu List\n");
  printf("\t\t\t 2. Order Coffee\n");
  printf("\t\t\t 3. Cancle Order\n");
  printf("\t\t\t 4. Show Order List\n");
  printf("\t\t\t 5. Show Sales Today\n");
  printf("\t\t\t 6. Add Coffee Menu\n");
  printf("\t\t\t 7. Delete Coffee Menu\n");
  printf("\t\t\t 8. Save Coffee Menu\n");
  printf("\t\t\t 0. Exit\n");
  printf("\t\t\t Enter your choice: ");
}

void showCoffeeMenuList() {
  system("clear");
  printf("\n\t\t\t=== (1) Coffee Menu List ===\n\n");
  showCoffeeMenu();
  waitZeroInput();
}

void showCoffeeMenu() {
  menuItem *tmp = g_menuItemList;
  printf("\n\t\t");
  printf("-----------------------------------------------");
  printf("\n\t\t");
  printf("%s\t%-25s\t%7s", "No", "Menu", "Price");
  printf("\n\t\t");
  printf("-----------------------------------------------");

  while (tmp != NULL) {
    printf("\n\t\t");
    printf("%d\t%-25s\t%7d", tmp->id, tmp->menuName, tmp->price);
    tmp = tmp->next;
    printf("\n\t\t");
    printf("-----------------------------------------------");
  }
}

int close() {
  char confirm[2];
  printf("\n\t\t\tSystem exit...");
  printf("\n\t\t\tPlease check data save before exit.\n");
  printf("\n\t\t\tDo you want to exit? (y/n): ");
  scanf("%s", confirm);

  if (!strcmp(confirm, "y")) {
    return 1;
  } else {
    return 0;
  }
}

void waitZeroInput() {
  int c = 1;

  printf("\n\t\t\tEnter 0 to return to the main menu: ");
  while (c != 0) {
    scanf("%d", &c);
  }
}