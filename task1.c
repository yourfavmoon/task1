#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct User
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};

void registration(void)
{
    FILE *reg;

    reg=fopen("reg.txt","w");
    if (reg == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }


    struct User u;

    printf("\nEnter First Name:\n");
    scanf("%s",u.fname);
    printf("\nEnter last name:\n");
    scanf("%s",u.lname);

    printf("\nEnter Username:\n");
    scanf("%s",u.username);
    printf("\nEnter Password:\n");
    scanf("%s",u.password);


    fwrite(&u,sizeof(u),1,reg);
    fclose(reg);

    printf("\nRegistration Successful!\n");
     getchar();
    login();
}
void login (void)
{    struct User u;
    char username[30],password[20];
    FILE *reg;

    reg = fopen("reg.txt","r");
    if (reg == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }

    

    printf("\n your credentials :\n\n");
    printf("Username:  ");
    fgets(username, 30, stdin);
    printf("\nPassword: ");
    printf("\n");
    fgets(password, 20, stdin);

    while(fread(&u,sizeof(u),1,reg))
        {
        if(strcmp(username,u.username)==1 && strcmp(password,u.password)==1)

            { 
                printf("\nSuccessful Login\n");
            }
        else
            {
                printf("\n wrong password or username\n");
            }
        }

    fclose(reg);

    return;
}
void registration (void);
void login (void);
int main (void)
{
    int num;

    printf("Press '1' to Register\nPress '2' to Login\n\n");
    scanf("%d",&num);

    getchar();           // catching newline.

    if(num == 1)
        {
            
            registration();
        }

    else if(num == 2)
        {
            
            login();
        }
}




