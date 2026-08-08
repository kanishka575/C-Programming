#include <stdio.h>
#include <string.h>


struct Cricketer
{
    char name[30];
    char nickname[30];

    int matches;
    int innings;
    int runs;
    int highestScore;
    int sixes;
    int fours;
};


void displayStats(struct Cricketer *p)
{
    printf("\n====================================\n");
    printf("        CRICKETER STATISTICS\n");
    printf("====================================\n");

    printf("Name          : %s\n", p->name);
    printf("Nickname      : %s\n", p->nickname);
    printf("Matches       : %d\n", p->matches);
    printf("Innings       : %d\n", p->innings);
    printf("Runs          : %d\n", p->runs);
    printf("Highest Score : %d\n", p->highestScore);
    printf("Sixes         : %d\n", p->sixes);
    printf("Fours         : %d\n", p->fours);

    printf("====================================\n");
}

int main()
{
    
    struct Cricketer players[5] =
    {
        {
            "Virat Kohli",
            "King Kohli",
            292,
            280,
            13800,
            254,
            152,
            1290
        },

        {
            "Rohit Sharma",
            "Hitman",
            496,
            470,
            19000,
            264,
            620,
            1800
        },

        {
            "MS Dhoni",
            "Captain Cool",
            538,
            500,
            17266,
            224,
            359,
            1230
        },

        {
            "Sachin Tendulkar",
            "Master Blaster",
            664,
            782,
            34357,
            248,
            264,
            2016
        },

        {
            "AB de Villiers",
            "Mr. 360",
            420,
            484,
            20014,
            278,
            328,
            2004
        }
    };

    
    struct Cricketer *ptr;

    int choice;
    int i;

    ptr = players;

    do
    {
        printf("\n\n========================================\n");
        printf("       CRICKET STATISTICS SYSTEM\n");
        printf("========================================\n");

        printf("1. Display All Cricketers\n");
        printf("2. Search Cricketer\n");
        printf("3. Display Highest Run Scorer\n");
        printf("4. Display Cricketer with Most Sixes\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                
                for (i = 0; i < 5; i++)
                {
                    displayStats(ptr + i);
                }

                break;


            case 2:
            {
                char searchName[30];
                int found = 0;

                printf("\nEnter cricketer name: ");
                scanf(" %[^\n]", searchName);

                for (i = 0; i < 5; i++)
                {
                    if (strcmp((ptr + i)->name, searchName) == 0)
                    {
                        displayStats(ptr + i);
                        found = 1;
                        break;
                    }
                }

                if (found == 0)
                {
                    printf("\nCricketer not found!\n");
                }

                break;
            }


            case 3:
            {
                struct Cricketer *highestRuns;

                highestRuns = ptr;

                for (i = 1; i < 5; i++)
                {
                    if ((ptr + i)->runs > highestRuns->runs)
                    {
                        highestRuns = ptr + i;
                    }
                }

                printf("\n\n===== HIGHEST RUN SCORER =====\n");

                displayStats(highestRuns);

                break;
            }


            case 4:
            {
                struct Cricketer *mostSixes;

                mostSixes = ptr;

                for (i = 1; i < 5; i++)
                {
                    if ((ptr + i)->sixes > mostSixes->sixes)
                    {
                        mostSixes = ptr + i;
                    }
                }

                printf("\n\n===== MOST SIXES =====\n");

                displayStats(mostSixes);

                break;
            }


            case 5:

                printf("\nThank you for using Cricket Statistics System!\n");
                break;


            default:

                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}
