#include <stdio.h>


void displayHeader();
float calculateBill(int units);
float calculateDiscount(float totalBill, int units, int seniorCitizen);
void printBill(char name[], int id, int units, float rate, float electricityCharge, float meterCharge, float discount, float finalBill);

int main()
{
    char name[30];
    int customerID;
    int units;
    int seniorCitizen;

    float rate;
    float electricityCharge;
    float meterCharge = 150;
    float totalBill;
    float discount;
    float finalBill;

    displayHeader();

  
    printf("Enter Customer Name : ");
    scanf("%s", name);

    printf("Enter Customer ID : ");
    scanf("%d", &customerID);

    printf("Enter Units Consumed : ");
    scanf("%d", &units);

    printf("Senior Citizen? (1 = Yes, 0 = No): ");
    scanf("%d", &seniorCitizen);

    // Decide rate
    if (units <= 100)
    {
        rate = 5;
    }
    else if (units <= 300)
    {
        rate = 7;
    }
    else
    {
        rate = 10;
    }

    electricityCharge = calculateBill(units) * rate;

    totalBill = electricityCharge + meterCharge;

    discount = calculateDiscount(totalBill, units, seniorCitizen);

    finalBill = totalBill - discount;

    printBill(name, customerID, units, rate, electricityCharge, meterCharge, discount, finalBill);

    return 0;
}


void displayHeader()
{
    printf("=========================================\n");
    printf("      ELECTRICITY BILL GENERATOR\n");
    printf("=========================================\n\n");
}


float calculateBill(int units)
{
    return units;
}


float calculateDiscount(float totalBill, int units, int seniorCitizen)
{
    float discount = 0;

    if (units > 300 && seniorCitizen == 1)
    {
        discount = totalBill * 0.15;
    }
    else if (units > 500)
    {
        discount = totalBill * 0.10;
    }

    return discount;
}

void printBill(char name[], int id, int units, float rate, float electricityCharge, float meterCharge, float discount, float finalBill)
{
    printf("\n=========================================\n");
    printf("            ELECTRICITY BILL\n");
    printf("=========================================\n");

    printf("Customer Name      : %s\n", name);
    printf("Customer ID        : %d\n", id);
    printf("Units Consumed     : %d\n", units);
    printf("Rate Per Unit      : Rs. %.2f\n", rate);
    printf("Electricity Charge : Rs. %.2f\n", electricityCharge);
    printf("Meter Charge       : Rs. %.2f\n", meterCharge);
    printf("Discount           : Rs. %.2f\n", discount);
    printf("-----------------------------------------\n");
    printf("Final Bill         : Rs. %.2f\n", finalBill);

    printf("=========================================\n");
    printf("        THANK YOU! VISIT AGAIN\n");
    printf("=========================================\n");
}