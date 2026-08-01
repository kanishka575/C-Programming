#include <stdio.h>
int main(){
    
    char name[30];
    int age,tickets;
    float ticketprice = 200;
    float total, discount = 0, finalAmount;
    
    printf("=====================================\n");
    printf("      MOVIE TICKET BOOKING SYSTEM\n");
    printf("=====================================\n");
    
    printf("Enter Customer Name: ");
    scanf("%s",&name);
    
    printf("Enter your Age: ");
    scanf("%d",&name);
    
    printf("Enter number of Tickets: ");
    scanf("%d",&tickets);
     
    if (age < 5){
        printf("\nsorry! Entry is not allowed for children below 5 years.\n");
    } 
    else{
        
        total = tickets * ticketprice;
        
        if (age >= 60){
            
            discount = total * 0.20;
        }
        
        finalAmount = total - discount;
        
        printf("\n========== BOOKING DETAILS ==========\n");
        printf("Customer Name : %s\n", name);
        printf("Age           : %d\n", age);
        printf("Tickets       : %d\n", tickets);
        printf("Ticket Price  : Rs. %.2f\n", ticketprice);
        printf("Total Amount  : Rs. %.2f\n", total);
        printf("Discount      : Rs. %.2f\n", discount);
        printf("Final Amount  : Rs. %.2f\n", finalAmount);
        printf("Booking Successful!\n");
    }
    
    return 0;
    
}