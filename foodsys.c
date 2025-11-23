#include <stdio.h>
#include <string.h>

struct Food {
    int Burger;
    int Pizza;
    int Cola;
};

void wallet(int *money) {
    printf("How much money do you have: ");
    scanf("%d", money);
}

void showMenu(struct Food menu) {
    printf("\n===== FOOD MENU =====\n");
    printf("Burger : %d\n", menu.Burger);
    printf("Pizza  : %d\n", menu.Pizza);
    printf("Cola  : %d\n", menu.Cola);
    printf("=====================\n");
}

int addToBasket(struct Food menu, char item[]) {
    if (strcmp(item, "Burger") == 0)
        return menu.Burger;

    else if (strcmp(item, "Pizza") == 0)
        return menu.Pizza;

    else if (strcmp(item, "Cola") == 0)
        return menu.Cola;

    else
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
    struct Food menu = {50, 80, 20};
    int money;
    int basket = 0;

    wallet(&money);
    showMenu(menu);

    char choice[20];

    while (1) {
        printf("What do you want to buy (type 'checkout' to finish): ");
        scanf("%s", choice);

        if (strcmp(choice, "checkout") == 0) {
            break;
        }

        int price = addToBasket(menu, choice);

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
