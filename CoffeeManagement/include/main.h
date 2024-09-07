#ifndef MAIN_H
#define MAIN_H
#define _CRT_SECURE_NO_WARNINGS

#include "data.h"
#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern menuItem *menuItemList;
extern orderNode *orderList;

int passwordCheck();
void loadCoffeeMenu();
void insertCoffeeMenu(int id, char *menuName, int price);

int deleteCoffeeMenu();
void mainMenu();
void showMainMenu();

void showCoffeeMenuList();
void showCoffeeMenu();

int close();
void waitZeroInput();
void showSaleToday();
void showOrderList();
void showOrders();
void saveMenuFile();
salesNode *addSales(salesNode *saleToday, orderNode *orderList);

#endif // MAIN_H