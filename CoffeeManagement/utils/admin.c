#include "../include/main.h"

int totalSales() {
  orderNode *ptr;
  int totalSales = 0;

  for (ptr = g_orderList; ptr; ptr = ptr->next) {
    totalSales += (int)(ptr->price * ptr->sales);
  }
  return totalSales;
}

void showSaleToday() {
  system("clear");
  printf("\n\t\t\t=== (5) Sale Today ===\n");
  printf("\n\t\tTotal Sales: %d\n", totalSales());
  waitZeroInput();
}

int addCoffeeMenu() {
  int id;
  int price;
  char menuName[30];

  system("clear");
  printf("\n\t\t\t=== (6) Add Coffee Menu ===\n");
  showCoffeeMenu();
  printf("\n\t\t\tEnter the menu ID: (enter 0 to exit): ");
  scanf("%d", &id);

  if (id == 0) {
    return 0;
  }

  printf("\n\t\t\tEnter the menu name: ");
  scanf("%[^\n]", menuName);

  printf("\n\t\t\tEnter the price: ");
  scanf("%d", &price);

  insertCoffeeMenu(id, menuName, price);
  return 1;
}

int deleteCoffeeMenu() { return 0; }

void saveMenuFile() {}