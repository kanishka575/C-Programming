#include <stdio.h>

int main()
{
    int pin;
    int balance = 10000;
    int amount;

    printf("================================\n");
    printf("          ATM MACHINE\n");
    printf("================================\n");

    printf("Enter your PIN: ");
    scanf("%d", &pin);

    if (pin == 4518)
    {
        printf("\nLogin Successful!\n");

        printf("\nEnter withdrawal amount: ");
        scanf("%d", &amount);

        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;

            printf("\nTransaction Successful!\n");
            printf("Withdrawn Amount : Rs. %d\n", amount);
            printf("Remaining Balance: Rs. %d\n", balance);
        }
        else if (amount > balance)
        {
            printf("\nInsufficient Balance!\n");
            printf("Available Balance: Rs. %d\n", balance);
        }
        else
        {
            printf("\nInvalid Amount!\n");
        }
    }
    else
    {
        printf("\nIncorrect PIN!\n");
        printf("Transaction Cancelled.\n");
    }

    printf("\n================================\n");
    printf("       Thank You!\n");
    printf("================================\n");

    return 0;
}