#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BASE_16 16
#define DEFAULT_SIZE 5
#define nl "\n"


int main(void)
{
    int decimal;
    int remainder;
    
    int hexa_arr[DEFAULT_SIZE] = {}; //this is a wrong assumption and must be corrected with better allocation
    int hexa_arr_tmp[DEFAULT_SIZE] = {};

    int iteraction = 0; 
    
    printf("Enter the hexadecimal value (exit with 0):");
    scanf("%d", &decimal);

    while(decimal/BASE_16 > 0)
    {
        remainder = decimal % BASE_16;
        //printf("iteraction: %d , Remainder is %d" nl ,iteraction, remainder);
        decimal = decimal / BASE_16;

        hexa_arr_tmp[iteraction] = remainder;
        iteraction++;
    }
    //When the program is here, it means that decimal/16 < 0
    remainder = decimal % BASE_16;
    printf("iteraction: %d Remainder is %d" nl, iteraction, remainder);
    //iteraction++;
    hexa_arr_tmp[iteraction] = remainder;
    //iteraction++;
    //debug purpose: print hexa_arr_tmp
    for(int i = 0; i <= iteraction; i ++)
        printf("hexa_arr_tmp[%d] = %d" nl, i, hexa_arr_tmp[i]); 
    
    //flip array
    int flipped_hexa_arr[DEFAULT_SIZE];
    for(int i = iteraction; i >= 0; i --)
        printf("flipped_hexa_arr[%d] = %d" nl, iteraction, hexa_arr_tmp[i]);
    
    /*
    //10 -> A 11 -> B 12 -> C 13 -> D 14 -> E 15 F -> 16
    char hexa_code[iteraction];
    for(int i = 0; i < iteraction; i ++)
    {
        if(flipped_hexa_arr[i] == 10)
            hexa_code[i] = 'A';
        else if(flipped_hexa_arr[i] == 11)
            hexa_code[i] = 'B';
        else if(flipped_hexa_arr[i] == 12)
            hexa_code[i] = 'C';
        else if(flipped_hexa_arr[i] == 13)
            hexa_code[i] = 'D';
        else if(flipped_hexa_arr[i] == 14)
            hexa_code[i] = 'E';
        else if(flipped_hexa_arr[i] == 15)
            hexa_code[i] = 'F';
        else 
            hexa_code[i] = flipped_hexa_arr[i];
    }
   

    //output
    for(int i = 0; i < iteraction; i ++)
        printf("hexa_code[%d] = %c" nl, i, hexa_code[i]);
     */
    return 0;
}
