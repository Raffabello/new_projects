#include <stdio.h>
#include <Windows.h>

//file settings

#define QUIT_STR "\nPress any key to quit..."
#define ROWS 3
#define SETTING_STR_LEN 256

int toAscii(char c);
char *toHexa(int ascii_code);

int main(void)
{
    char tmpString[SETTING_STR_LEN];
    char testString[SETTING_STR_LEN]; //Var used without reading from settings file.
    int confirmedCursorPos[2]; //(x,y)
    char tmpChar;

    POINT cursor_coords;

    /*
    FILE *setting_file = fopen("settings.txt", "r");
    //Bob does not find the settings file.
    if(setting_file == NULL)
    {
        printf("Bob could not locate the file.Program will be closed.");
        printf(QUIT_STR);
        scanf("%c", &tmpChar);
        return 1;
    }
    */

    //--- CLI bob - comment this
    int delay = 1000; //char/s
    printf("Enter the string you want Bob to type:\n");
    scanf("%[^\n]",testString);
    printf("String recorded! You entered \"%s\"\nPlease, move the mouse onto the place you want Bob to write the message.\nPress any key to view the cursor coordinates.Press \"y\" to confirm the coordinates.\n", testString);
    do
    {
        GetCursorPos(&cursor_coords);
        printf("-----\n>>Cursor at X=%d and Y=%d<<\nDo you want to confirm? y/any key.\n-----\n", cursor_coords.x, cursor_coords.y);   
        scanf(" %c", &tmpChar);
    }while(tmpChar != 'y');
    confirmedCursorPos[0] = cursor_coords.x;
    confirmedCursorPos[1] = cursor_coords.y;


    
    //Bob moves the cursor to the confirmedCursorPos
    SetCursorPos(confirmedCursorPos[0], confirmedCursorPos[1]);
    //Bob left clicks the previous mouse position
    mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
    //Bob types the message
    for(int i = 0; testString[i] != '\0'; i++)
    {
        printf("Bob is typing .. %c", testString[i]);
        keybd_event(0x45,0,0,0);
        keybd_event(0x68,0,KEYEVENTF_KEYUP,0);
        //only hexadecimal works
        Sleep(delay);
    }

    //--- CLI bob - comment this
    return 0;
}


int toAscii(char c)
{
    return (int) c;
}

/*
char *toHexa(int ascii_code)
{
    char hexaRow[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int remainder;
    while(ascii_code/16 == 0)
    {
        remainder = ascii_code % 16;
        printf("%d",remainder);
    }
}
*/
