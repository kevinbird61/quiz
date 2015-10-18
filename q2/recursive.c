#include <stdio.h>
#include <string.h>
#include <time.h>
char smallest_character_recursive(char str[],char c,int index);
int main(int argc,char *argv[])
{
	FILE *fp = fopen("analysis_time_recursive.txt","a");
    /* For time estimate */
    clock_t start,end;
    double result;
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
    result_c = smallest_character_recursive(array,judge_c,0);
    printf("Output: [%c]\n",result_c);
    end = clock();
    result = (end-start)/(double)(CLOCKS_PER_SEC);
    printf("%lf\n", result );
    if(argv[2][1]!='\0'&&argv[2][2]!='\0'&&argv[2][3]!='\0'){
    fprintf(fp,"%c%c%c%c		%-10lf\n",argv[2][0],argv[2][1],argv[2][2],argv[2][3],result);}
    else if(argv[2][1]!='\0'&&argv[2][2]!='\0'){
    fprintf(fp,"%c%c%c		%-10lf\n",argv[2][0],argv[2][1],argv[2][2],result);}
    else if(argv[2][1]!='\0'){
    fprintf(fp,"%c%c		%-10lf\n",argv[2][0],argv[2][1],result);}
    else{
    fprintf(fp,"%c		%-10lf\n",argv[2][0],result);
    }
    return 0;
}

char smallest_character_recursive(char str[],char c,int index)
{
    if(str[index]>c) {
        return str[index];
    } else if(str[index]!=NULL) {
        smallest_character_recursive(str,c,++index);
    } else {
        return str[0];
    }
}

