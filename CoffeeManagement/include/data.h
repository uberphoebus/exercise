
// coffeeMenu
typedef struct menuItem {
  int id;
  char menuName[50];
  int price;
  struct menuItem *next;
} menuItem;

// order
typedef struct orderNode {
  int orderId;
  int menuId;
  char menuName[50];
  int price;
  int sales;
  struct orderNode *next;
} orderNode;

// sales
typedef struct salesNode {
  int menuId;
  char menuName[50];
  int price;
  int sales;
  struct salesNode *next;
} salesNode;