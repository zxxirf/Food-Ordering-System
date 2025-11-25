#include <stdio.h>
#include <string.h>

void wallet(int *money) {
    printf("How much money do you have: ");
    scanf("%d", money);
}

void showMenu(int burger, int pizza, int cola) {
    printf("\n===== FOOD MENU =====\n");
    printf("Burger : %d\nPizza  : %d\nCola   : %d\n", burger, pizza, cola);
    printf("=====================\n");
}

int addToBasket(int burger, int pizza, int cola, char item[]) {
    if (strcmp(item, "Burger") == 0) return burger;
    if (strcmp(item, "Pizza") == 0)  return pizza;
    if (strcmp(item, "Cola") == 0)   return cola;
    return -1; // Item not found
}

void checkout(int *money, int basketTotal) {
    printf("\n===== CHECKOUT =====\n");
    printf("Total price: %d\n", basketTotal);

    if (*money >= basketTotal) {
        *money -= basketTotal;
        printf("Purchase successful!\n");
    } else {
        printf("Not enough money to buy all items.\n");
    }

    printf("Remaining balance: %d\n", *money);
}

int main() {
    int burger = 50, pizza = 80, cola = 20;
    int money, basket = 0;
    char choice[20];

    wallet(&money);
    showMenu(burger, pizza, cola);

    while (1) {
        printf("What do you want to buy (type 'checkout' to finish): ");
        scanf("%s", choice);

        if (strcmp(choice, "checkout") == 0) break;

        int price = addToBasket(burger, pizza, cola, choice);
        if (price == -1) {
            printf("Item not found.\n");
        } else {
            basket += price;
            printf("%s added to basket. Basket total = %d\n\n", choice, basket);
        }
    }

    checkout(&money, basket);
    return 0;
}
