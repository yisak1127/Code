#include "string.h"
#include <stdio.h>
#include <ctype.h>

int main()
{
    int f = 0;
    scanf("%i\n", &f);

    if (f == 1)
    {
        char firstName[21] = "";
        char middleName[21] = "";
        char lastName[21] = "";
        char fourthName[64] = "";

        /* copy str1 into str3 */
        scanf("%s %s %s", firstName, middleName, lastName);
        strcat(fourthName, lastName);
        strcat(fourthName, ", ");
        strcat(fourthName, firstName);
        strcat(fourthName, " ");
        strcat(fourthName, middleName);

        printf("%s\n", fourthName);
    }

    else if (f == 2)
    {
        char password[21] = "";
        char passwordVaildCheck[21] = "";
        int len = 0;

        scanf("%s", password);
        len = strlen(password);

        if (len < 6)
        {
            print("Password too short\n");
        }
        
        else if (len > 14)
        {
            printf("Password too long\n");
        }
        

         for (size_t i = 0; i < 20; i++)
    {
        if (islower(password[i]))
        {
            strcat(passwordVaildCheck, "y");
        }

        else
        {
            strcat(passwordVaildCheck, "n");
        }
    }
        if (strcmp(passwordVaildCheck, "nnnnnnnnnnnnnnnnnnnn") == 0)
        {
            printf("Password missing lowercase letter\n");
        }
        
        strcpy(passwordVaildCheck, "");

             for (size_t i = 0; i < 20; i++)
    {
        if (isupper(password[i]))
        {
            strcat(passwordVaildCheck, "y");
        }

        else
        {
            strcat(passwordVaildCheck, "n");
        }
    }
        if (strcmp(passwordVaildCheck, "nnnnnnnnnnnnnnnnnnnn") == 0)
        {
            printf("Password missing uppercase letter\n");
        }
    strcpy(passwordVaildCheck, "");

             for (size_t i = 0; i < 20; i++)
    {
        if (isdigit(password[i]))
        {
            strcat(passwordVaildCheck, "y");
        }

        else
        {
            strcat(passwordVaildCheck, "n");
        }
    }
        if (strcmp(passwordVaildCheck, "nnnnnnnnnnnnnnnnnnnn") == 0)
        {
            printf("Password missing digit\n");
        }
    strcpy(passwordVaildCheck, "");

             for (size_t i = 0; i < 20; i++)
    {
        if (ispunct(password[i]))
        {
            strcat(passwordVaildCheck, "y");
        }

        else
        {
            strcat(passwordVaildCheck, "n");
        }
    }
        if (strcmp(passwordVaildCheck, "nnnnnnnnnnnnnnnnnnnn") == 0)
        {
            printf("Password missing punctuation\n");
        }
    strcpy(passwordVaildCheck, "");
    }        
    printf("Valid password\n");
    return 0;
}