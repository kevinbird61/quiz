#include <stdio.h>
#include <string.h>
char smallest_character(char str[],char c);
int main()
{
	/* setting variable */
	int i = 0;
	char c,judge_c,result_c;
	char array[10];
	memset(array,'\0',sizeof(array));
	/* Input array */
	printf("Input the sorted character (input \"!\" will end the input array):\n");
	while(i<10){
		scanf("%c",&c);
		if(c=='!'){
			printf("End the Input!\n");
			scanf("%c",&c); // For '\n'
			break;
		}
		else if(c!='\n'){
			array[i] = c;
			i++;
		}
	}
	i=0;
	printf("Ok the array is full or you enter !\n");
	printf("length is :%d\n",sizeof(array));
	/* Get judgement character */
	printf("Please input the judgement character:\n");
	scanf("%c",&judge_c);
	/* Implement smallest_character */
	result_c = smallest_character(array,judge_c);
	printf("Output: [%c]\n",result_c);
    return 0;
}

char smallest_character(char str[],char c)
{
	int i = 0,len = sizeof(str);
	while(i<=len){
		if(str[i]>c){
			return str[i];
		}
		i++;
	}
	return str[0];
}
