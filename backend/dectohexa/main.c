#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BASE 16
#define nl "\n"


int main(void)
{
    int decimal;
    int remainder;
    
    int hexa_arr[5] = {}; //this is a wrong assumption and must be corrected with better allocation
    int hexa_arr_tmp[5] = {};

    int iteraction = 0; 
    
    printf("Enter the hexadecimal value (exit with 0):");
    scanf("%d", decimal);
    
    while(decimal/16 > 0)
    {
        remainder = decimal % BASE;
        //printf("iteraction: %d , Remainder is %d" nl ,iteraction, remainder);
        decimal = decimal / BASE;

        hexa_arr_tmp[iteraction] = remainder;
        iteraction++;
    }
    //When the program is here, it means that decimal/16 < 0
    remainder = decimal % BASE;
    printf("iteraction: %d Remainder is %d" nl, iteraction, remainder);
    //iteraction++;
    hexa_arr_tmp[iteraction] = remainder;
    //iteraction++;
    //debug purpose: print hexa_arr_tmp
    for(int i = 0; i <= iteraction; i ++)
        printf("hexa_arr_tmp[%d] = %d" nl, i, hexa_arr_tmp[i]); 
    
    //flip array
    int flipped_hexa_arr[5];
    for(int i = iteraction; i >= 0; i --)
    {
        printf("flipped_hexa_arr[%d] = %d" nl, iteraction, hexa_arr_tmp[i]);
    }
    return 0;
}
