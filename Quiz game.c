#include <stdio.h>

int main()
{
    int answer;
    int score = 0;
    int question = 1;

    printf("===== C QUIZ GAME =====\n");

    while(question <= 5)
    {
        if(question == 1)
        {
            printf("\nQ1. How many bits are there in 1 byte?\n");
            printf("1. 4\n2. 8\n3. 16\n4. 32\n");
            scanf("%d",&answer);

            if(answer == 2)
                score++;
        }

        else if(question == 2)
        {
            printf("\nQ2. Which symbol is used for AND?\n");
            printf("1. &&\n2. ||\n3. !\n4. %%\n");
            scanf("%d",&answer);

            if(answer == 1)
                score++;
        }

        else if(question == 3)
        {
            printf("\nQ3. C language was developed by?\n");
            printf("1. Dennis Ritchie\n2. Bill Gates\n3. Elon Musk\n4. James Gosling\n");
            scanf("%d",&answer);

            if(answer == 1)
                score++;
        }

        else if(question == 4)
        {
            printf("\nQ4. Which loop checks the condition first?\n");
            printf("1. while\n2. do while\n3. for\n4. switch\n");
            scanf("%d",&answer);

            if(answer == 1)
                score++;
        }

        else if(question == 5)
        {
            printf("\nQ5. Which operator is used for OR?\n");
            printf("1. &&\n2. ||\n3. !\n4. %%\n");
            scanf("%d",&answer);

            if(answer == 2)
                score++;
        }

        question++;
    }

    printf("\n=====================\n");
    printf("Quiz Finished!\n");
    printf("Your Score = %d/5\n", score);

    if(score == 5)
        printf("Excellent!\n");
    else if(score >= 3)
        printf("Good Job!\n");
    else
        printf("Keep Practicing!\n");

    return 0;
}