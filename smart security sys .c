#include <stdio.h>
#include <string.h>

#define MAX_USERS 50
#define MAX_ATTEMPTS 3


struct User
{
    int id;
    char name[50];
    char role[30];
    int pin;
    int failedAttempts;
    int isLocked;
    int accessCount;
};


void addUser(struct User users[], int *count);
void displayUsers(struct User users[], int count);
void searchUser(struct User users[], int count);
void authenticate(struct User users[], int count);
void changePin(struct User *user);
void securityReport(struct User users[], int count);
int findUser(struct User users[], int count, int id);
void displayUser(struct User *user);


int main()
{
    struct User users[MAX_USERS];

    int userCount = 0;
    int choice;

    while (1)
    {
        printf("\n========================================\n");
        printf("       SMART SECURITY SYSTEM\n");
        printf("========================================\n");

        printf("1. Register User\n");
        printf("2. Display All Users\n");
        printf("3. Search User\n");
        printf("4. Authenticate Access\n");
        printf("5. Change PIN\n");
        printf("6. Security Report\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addUser(users, &userCount);
                break;

            case 2:
                displayUsers(users, userCount);
                break;

            case 3:
                searchUser(users, userCount);
                break;

            case 4:
                authenticate(users, userCount);
                break;

            case 5:
            {
                int id;
                int index;

                printf("Enter User ID: ");
                scanf("%d", &id);

                index = findUser(users, userCount, id);

                if (index == -1)
                {
                    printf("User not found!\n");
                }
                else
                {
                    changePin(&users[index]);
                }

                break;
            }

            case 6:
                securityReport(users, userCount);
                break;

            case 7:
                printf("\nSecurity System Closed.\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}


void addUser(struct User users[], int *count)
{
    if (*count >= MAX_USERS)
    {
        printf("\nUser database is full!\n");
        return;
    }

    printf("\nEnter User ID: ");
    scanf("%d", &users[*count].id);

    // Check duplicate ID
    for (int i = 0; i < *count; i++)
    {
        if (users[i].id == users[*count].id)
        {
            printf("ID already exists!\n");
            return;
        }
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", users[*count].name);

    printf("Enter Role: ");
    scanf(" %[^\n]", users[*count].role);

    printf("Create 4-digit PIN: ");
    scanf("%d", &users[*count].pin);

    users[*count].failedAttempts = 0;
    users[*count].isLocked = 0;
    users[*count].accessCount = 0;

    (*count)++;

    printf("\nUser registered successfully!\n");
}


void displayUsers(struct User users[], int count)
{
    if (count == 0)
    {
        printf("\nNo users registered.\n");
        return;
    }

    printf("\n========== USER DATABASE ==========\n");

    for (int i = 0; i < count; i++)
    {
        displayUser(&users[i]);
    }
}

void displayUser(struct User *user)
{
    printf("\nID              : %d", user->id);
    printf("\nName            : %s", user->name);
    printf("\nRole            : %s", user->role);
    printf("\nFailed Attempts : %d", user->failedAttempts);
    printf("\nAccess Count    : %d", user->accessCount);

    if (user->isLocked)
        printf("\nStatus          : LOCKED\n");
    else
        printf("\nStatus          : ACTIVE\n");
}


int findUser(struct User users[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (users[i].id == id)
        {
            return i;
        }
    }

    return -1;
}


void searchUser(struct User users[], int count)
{
    int id;
    int index;

    printf("\nEnter User ID to search: ");
    scanf("%d", &id);

    index = findUser(users, count, id);

    if (index == -1)
    {
        printf("\nUser not found!\n");
    }
    else
    {
        printf("\nUser Found!\n");
        displayUser(&users[index]);
    }
}


void authenticate(struct User users[], int count)
{
    int id;
    int enteredPin;
    int index;

    printf("\nEnter User ID: ");
    scanf("%d", &id);

    index = findUser(users, count, id);

    if (index == -1)
    {
        printf("\nACCESS DENIED: Unknown User!\n");
        return;
    }

    struct User *user = &users[index];

    if (user->isLocked)
    {
        printf("\n================================\n");
        printf("ACCESS DENIED\n");
        printf("ACCOUNT IS LOCKED!\n");
        printf("================================\n");

        return;
    }

    printf("Enter PIN: ");
    scanf("%d", &enteredPin);

    if (enteredPin == user->pin)
    {
        printf("\n================================\n");
        printf("       ACCESS GRANTED\n");
        printf("================================\n");

        printf("Welcome %s!\n", user->name);
        printf("Role: %s\n", user->role);

        user->failedAttempts = 0;
        user->accessCount++;
    }
    else
    {
        user->failedAttempts++;

        printf("\nACCESS DENIED!\n");
        printf("Wrong PIN.\n");

        printf("Failed attempts: %d/%d\n",
               user->failedAttempts,
               MAX_ATTEMPTS);

        if (user->failedAttempts >= MAX_ATTEMPTS)
        {
            user->isLocked = 1;

            printf("\n!!! SECURITY ALERT !!!\n");
            printf("Account has been LOCKED.\n");
        }
    }
}

void changePin(struct User *user)
{
    int oldPin;
    int newPin;

    if (user->isLocked)
    {
        printf("\nCannot change PIN.\n");
        printf("Account is locked!\n");
        return;
    }

    printf("\nEnter current PIN: ");
    scanf("%d", &oldPin);

    if (oldPin != user->pin)
    {
        printf("\nIncorrect PIN!\n");
        return;
    }

    printf("Enter new PIN: ");
    scanf("%d", &newPin);

    user->pin = newPin;

    printf("\nPIN changed successfully!\n");
}

void securityReport(struct User users[], int count)
{
    int locked = 0;
    int totalAccess = 0;
    int suspicious = 0;

    if (count == 0)
    {
        printf("\nNo security data available.\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        totalAccess += users[i].accessCount;

        if (users[i].isLocked)
        {
            locked++;
        }

        if (users[i].failedAttempts >= 2)
        {
            suspicious++;
        }
    }

    printf("\n====================================\n");
    printf("         SECURITY REPORT\n");
    printf("====================================\n");

    printf("Total Users          : %d\n", count);
    printf("Total Successful Accesses : %d\n", totalAccess);
    printf("Locked Accounts      : %d\n", locked);
    printf("Suspicious Accounts  : %d\n", suspicious);

    if (locked > 0)
    {
        printf("\nWARNING: Locked accounts detected!\n");
    }

    if (suspicious > 0)
    {
        printf("WARNING: Suspicious login activity detected!\n");
    }

    if (locked == 0 && suspicious == 0)
    {
        printf("\nSecurity Status: NORMAL\n");
    }
}