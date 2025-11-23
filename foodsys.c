#include <stdio.h>
#include <string.h>

struct Food {
    int Burger;
    int Pizza;
    int Drink;
};

void wallet(int *money) {
    printf("How much money do you have: ");
    scanf("%d", money);
}

void order(struct Food menu, int *money) {
    char input[20];
    int found = 0;

    printf("What do you want to order: ");
    scanf("%s", input);

    if (strcmp(input, "Burger") == 0) {
        if (*money >= menu.Burger) {
            printf("You bought a Burger.\n");
            *money -= menu.Burger;
        } else {
            printf("Not enough money.\n");
        }
        found = 1;
    }

    else if (strcmp(input, "Pizza") == 0) {
        if (*money >= menu.Pizza) {
            printf("You bought a Pizza.\n");
            *money -= menu.Pizza;
        } else {
            printf("Not enough money.\n");
        }
        found = 1;
    }

    else if (strcmp(input, "Drink") == 0) {
        if (*money >= menu.Drink) {
            printf("You bought a Drink.\n");
            *money -= menu.Drink;
        } else {
            printf("Not enough money.\n");
        }
        found = 1;
    }

    if (!found) {
        printf("Item not found.\n");
    }
}

void final_balance(int money) {
    printf("Your final balance: %d\n", money);
}

int main() {
    struct Food menu;
    menu.Burger = 50;
    menu.Pizza = 80;
    menu.Drink = 20;

    int money;
    wallet(&money);
    order(menu, &money);
    final_balance(money);

    return 0;
}
