#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BASE_16 16
#define DEFAULT_SIZE 5
#define nl "\n"



int main(void)
{
    #if BASE_16 < 2
        printf("The base cannot be less than 2!");
        return 1;
    #else
        unsigned int decimal;
        unsigned int remainder;
        
        unsigned int hexa_arr[DEFAULT_SIZE] = {}; //this is a wrong assumption and must be corrected with better allocation
        unsigned int hexa_arr_tmp[DEFAULT_SIZE] = {};

        unsigned int iteraction = 0; 
        
        printf("Enter the hexadecimal value (exit with 0):");
        scanf("%u", &decimal);

        while(decimal/BASE_16 > 0)
        {
            remainder = decimal % BASE_16;
            //printf("iteraction: %d , Remainder is %u" nl ,iteraction, remainder);
            decimal = decimal / BASE_16;

            hexa_arr_tmp[iteraction] = remainder;
            iteraction++;
        }
        //When the program is here, it means that decimal/16 < 0
        remainder = decimal % BASE_16;
        //printf("iteraction: %u Remainder is %u" nl, iteraction, remainder);
        //iteraction++;
        hexa_arr_tmp[iteraction] = remainder;
        //iteraction++;
        //debug purpose: print hexa_arr_tmp
        //for(int i = 0; i <= iteraction; i ++)
        //    printf("hexa_arr_tmp[%u] = %u" nl, i, hexa_arr_tmp[i]); 
        
        //flip array
        unsigned int flipped_hexa_arr[DEFAULT_SIZE];
        unsigned int j = 0;
        for(int i = iteraction; i >= 0; i --)
        {
            flipped_hexa_arr[j] = hexa_arr_tmp[i];
            //printf("flipped_hexa_arr[%u] = %u" nl, j, flipped_hexa_arr[j]);
            j++;
        }
        
        
        //10 -> A 11 -> B 12 -> C 13 -> D 14 -> E 15 F -> 16
        char hexa_code[iteraction];
        for(int i = 0; i <= iteraction; i ++)
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
                hexa_code[i] = flipped_hexa_arr[i] + '0';
        }
    

        //output
        printf("The converted number in base %d:" nl, BASE_16);
        //add hexadecimal prefix -- debug part
        #if BASE_16 == 16
            printf("0x");
        #endif
        for(int i = 0; i <= iteraction; i ++)
            printf("%c",hexa_code[i]);
        printf(nl);
        return 0;
    #endif
}
