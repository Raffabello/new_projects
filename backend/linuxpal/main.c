#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./library/lib.h"

//Color table
#define HRED "\e[0;91m"
#define CRESET "\e[0m"
#define HCYN "\e[0;96m"
//

int main(void)
{
    //routine
    drawInterface();
    identifyOS();
    return 0;
}

void identifyOS()
{
    /*Most Unix distros recognize the command 'touch' therefore we can use it to check if we are in an Unix environment*/
    FILE *testfile;
    char testfile_name[] = "verifyOS_linuxpal";
    system("touch verifyOS_linuxpal");
    testfile = fopen(testfile_name,"r");
    if(testfile)
        printf("You are not in an UNIX distro.");
    else
    {
        fclose(testfile);
    }
}

void drawInterface(void)
{
    char github_link[] = {"https://github.com/Raffabello"};
    printf(HRED);
    for(int j = 0; j < 3; j++)
    {
        if(j == 1)
        {
            for(int i = 0; i < 12; i++)
            {
                if(i == 0)
                    printf("|");
                if(i == 11)
                    printf("|");
                if(i != 5)
                    printf(" ");
                if(i == 5)
                    printf("LINUXPAL");
            }
            printf("\n");
        }else
        {
            for(int i = 0; i < 20; i++)
                printf("*");
            printf("\n");            
        }
    }
    printf(CRESET);
    printf(HCYN);
    printf(">Developed by Raffabello (%s)\n\n", github_link); 
    printf(CRESET);   
}
