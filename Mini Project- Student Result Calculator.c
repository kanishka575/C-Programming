#include <stdio.h>

int main()
{
    char name[30];

    int maths, physics, chemistry;
    int total;

    float percentage;

    printf("=================================\n");
    printf("       STUDENT RESULT SYSTEM\n");
    printf("=================================\n");

    printf("Enter student name: ");
    scanf("%s", name);

    printf("Enter Maths marks: ");
    scanf("%d", &maths);

    printf("Enter Physics marks: ");
    scanf("%d", &physics);

    printf("Enter Chemistry marks: ");
    scanf("%d", &chemistry);


    total = maths + physics + chemistry;


    percentage = total / 3.0;

    printf("\n=================================\n");
    printf("           RESULT\n");
    printf("=================================\n");

    printf("Name       : %s\n", name);
    printf("Total      : %d / 300\n", total);
    printf("Percentage : %.2f%%\n", percentage);


    if (maths >= 35 && physics >= 35 && chemistry >= 35)
    {
        printf("Result     : PASS\n");

        if (percentage >= 90)
        {
            printf("Grade      : A+\n");
        }
        else if (percentage >= 75)
        {
            printf("Grade      : A\n");
        }
        else if (percentage >= 60)
        {
            printf("Grade      : B\n");
        }
        else
        {
            printf("Grade      : C\n");
        }
    }
    else
    {
        printf("Result     : FAIL\n");
        printf("Grade      : F\n");
    }

    printf("=================================\n");

    return 0;
}