#include "../include/main.h"

orderNode *orderList = NULL;
static int orderNo = 0;

void printOrder(orderNode *thisOrder) {
  orderNode *tmp = NULL;
  int totalPrice = 0;

  if (thisOrder != NULL) {
    printf("\n\n\t\t\t=== Your Order ===\n");
    printf("\n\t\t");
    printf("-----------------------------------------------");
    printf("\n\t\t%-8s%-23s%-8s%8s", "No", "Menu", "Quantity", "Price");
    printf("\n\t\t");
    printf("-----------------------------------------------");
    for (tmp = thisOrder; tmp; tmp = tmp->next) {
      printf("\n\t\t%-8d%-23s%-8d%8d", tmp->menuId, tmp->menuName, tmp->sales,
             tmp->price);
      totalPrice += tmp->price;
    }
    printf("\n\t\t-----------------------------------------------");
    printf("\n\t\tTotal Price%36d", totalPrice);
    printf("\n\t\t-----------------------------------------------");
  }
}

bool isInMenu(int menuId) {
  menuItem *ptr;
  for (ptr = g_menuItemList; ptr; ptr = ptr->next) {
    if (ptr->id == menuId) {
      return true;
    }
  }
  return false;
}

int getPrice(int menuId) {
  menuItem *ptr;
  for (ptr = g_menuItemList; ptr; ptr = ptr->next) {
    if (ptr->id == menuId) {
      return ptr->price;
    }
  }
  printf("\n\t\t\tInvalid menu ID. Please try again.\n");
  return 0;
}

char *getMenuName(int menuId) {
  menuItem *ptr;
  for (ptr = g_menuItemList; ptr; ptr = ptr->next) {
    if (ptr->id == menuId) {
      return ptr->menuName;
    }
  }
  printf("\n\t\t\tInvalid menu ID. Please try again.\n");
  return NULL;
}

orderNode *insertOrderList(int menuId, int quantity, int price) {
  orderNode *tmp = (orderNode *)malloc(sizeof(orderNode));
  orderNode *ptr;

  tmp->orderId = ++orderNo;
  tmp->menuId = menuId;
  tmp->price = price;
  tmp->sales = quantity;
  strcpy(tmp->menuName, getMenuName(menuId));
  tmp->next = NULL;

  if (orderList == NULL) {
    orderList = tmp;
  } else {
    for (ptr = orderList; ptr->next; ptr = ptr->next) {
      ;
    }
    ptr->next = tmp;
  }
  return orderList;
}

int addOrder(int menuId, int quantity) {
  int price = getPrice(menuId);
  orderList = insertOrderList(menuId, quantity, price);
  return price * quantity;
}

orderNode *addThisOrder(orderNode *thisOrder, int menuId, int quantity,
                        int price) {
  orderNode *tmp = NULL;
  orderNode *ptr;

  tmp = malloc(sizeof(orderNode));
  tmp->menuId = menuId;
  strcpy(tmp->menuName, getMenuName(menuId));
  tmp->sales = quantity;
  tmp->price = price;
  tmp->next = NULL;

  if (thisOrder == NULL) {
    return tmp;
  } else {
    for (ptr = thisOrder; ptr->next; ptr = ptr->next) {
      ;
    }
    ptr->next = tmp;
    return thisOrder;
  }
}

void order() {
  menuItem *tmp = g_menuItemList;
  orderNode *thisOrder = NULL;

  int menuId;
  int quantity;
  int price;

  system("clear");
  printf("\n\t\t\t=== (2) Order Coffee ===\n");
  showCoffeeMenu();
  while (1) {
    printOrder(thisOrder);
    printf("\n\n\t\t\tEnter the menu ID to order (0 to exit): ");
    scanf("%d", &menuId);

    if (menuId == 0) {
      return;
    }

    if (isInMenu(menuId) == false) {
      printf("\n\t\t\tInvalid menu ID. Please try again.\n");
      sleep(1);
      continue;
    }

    printf("\n\t\t\tEnter the quantity: ");
    scanf("%d", &quantity);
    price = addOrder(menuId, quantity);
    thisOrder = addThisOrder(thisOrder, menuId, quantity, price);
  }
}

void showOrders() {
  orderNode *tmp = NULL;
  int totalPrice = 0;

  printf("\n\t\t");
  printf("-----------------------------------------------");
  printf("\n\t\t%-8s%-23s%-8s%8s", "No", "Menu", "Quantity", "Price");
  printf("\n\t\t");
  printf("-----------------------------------------------");
  for (tmp = orderList; tmp; tmp = tmp->next) {
    printf("\n\t\t%-8d%-23s%-8d%8d", tmp->orderId, tmp->menuName, tmp->sales,
           tmp->price);
    totalPrice += tmp->price;
  }
  printf("\n\t\t-----------------------------------------------");
  printf("\n\t\tTotal Price%36d", totalPrice);
  printf("\n\t\t-----------------------------------------------");
}

void deleteOrder() {
  orderNode *tmp = orderList;
  int id;

  while (1) {
    system("clear");
    printf("\n\t\t\t=== (3) Delete Order ===\n");
    showOrders();
    printf("\n\n\t\t");
    printf("Enter the order ID to delete (0 to exit): ");
    scanf("%d", &id);

    if (id == 0 || orderList == NULL) {
      return;
    }

    if (orderList->orderId == id) {
      orderList = orderList->next;
      printf("\n\t\t\tOrder deleted successfully. %d\n", id);
      sleep(2);
    } else {
      while (tmp->next) {
        if (tmp->next->orderId == id) {
          tmp->next = tmp->next->next;
          printf("\n\t\t\tOrder deleted successfully. %d\n", id);
          sleep(2);
          break;
        }
        tmp = tmp->next;
      }
    }
  }
}

void showOrderList() {
  system("clear");
  printf("\n\t\t\t=== (4) Show Order List ===\n");
  showOrders();
  waitZeroInput();
}