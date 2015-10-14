#include <stdio.h>
#include <string.h>
#include <time.h>
char smallest_character(char str[],char c);
int main(int argc,char *argv[])
{
	/* For time estimate */	
	clock_t start,end;
	start = clock();
    /* setting variable */
    char judge_c,result_c;
    /* Sorted array */
    char array[15];
    /* Set a static array for multiply input */
    array[0] = 'a';
    array[5] = 'i';
    array[10] = 'q';
    array[1] = 'c';
    array[6] = 'k';
    array[11] = 's';
    array[2] = 'd';
    array[7] = 'l';
    array[12] = 't';
    array[3] = 'f';
    array[8] = 'n';
    array[13] = 'v';
    array[4] = 'h';
    array[9] = 'o';
    array[14] = 'z';
    /* Get judgement character */
    judge_c = *argv[1];
    printf("%c\n",judge_c);
    /* Implement smallest_character */
    result_c = smallest_character(array,judge_c);
    printf("Output: [%c]\n",result_c);
   	end = clock();
   	printf("%lf\n", (end-start)/(double)(CLOCKS_PER_SEC));
    return 0;
}

char smallest_character(char str[],char c)
{
    int i = 0;
    while(str[i]!=NULL) {
        if(str[i]>c) {
            return str[i];
        }
        i++;
    }
    return str[0];
}
