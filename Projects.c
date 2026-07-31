#include <stdio.h>

int main()
{
    char item1[20], item2[20], item3[20];

    int qty1, qty2, qty3;

    float price1, price2, price3;
    float total1, total2, total3;
    float grandTotal;

    printf("====================================\n");
    printf("        🛒 SHOPPING BILL\n");
    printf("====================================\n");

    // Item 1
    printf("\nEnter first item name: ");
    scanf("%s", item1);

    printf("Enter quantity: ");
    scanf("%d", &qty1);

    printf("Enter price: ");
    scanf("%f", &price1);

    printf("Price = %.2f", price1);

    total1 = qty1 * price1;


    // Item 2
    printf("\nEnter second item name: ");
    scanf("%s", item2);

    printf("Enter quantity: ");
    scanf("%d", &qty2);

    printf("Enter price: ");
    scanf("%f", &price2);

    printf("Price = %.2f", price2);

    total2 = qty2 * price2;


    // Item 3
    printf("\nEnter third item name: ");
    scanf("%s", item3);

    printf("Enter quantity: ");
    scanf("%d", &qty3);

    printf("Enter price: ");
    scanf("%f", &price3);

    printf("Price = %.2f", price3);

    total3 = qty3 * price3;


    // Calculate grand total
    grandTotal = total1 + total2 + total3;


    // Print Bill
    printf("\n\n====================================\n");
    printf("             FINAL BILL\n");
    printf("====================================\n");

    printf("%-10s %5s %10s\n", "Item", "Qty", "Total");
    printf("------------------------------------\n");

    printf("%-10s %5d %10.2f\n", item1, qty1, total1);
    printf("%-10s %5d %10.2f\n", item2, qty2, total2);
    printf("%-10s %5d %10.2f\n", item3, qty3, total3);

    printf("------------------------------------\n");
    printf("Grand Total = ₹%.2f\n", grandTotal);

    printf("====================================\n");

    return 0;
}