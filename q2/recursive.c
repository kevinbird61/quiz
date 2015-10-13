#include <stdio.h>
#include <string.h>
char smallest_character_recursive(char str[],char c,int index);
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
	result_c = smallest_character_recursive(array,judge_c,0);
	printf("Output: [%c]\n",result_c);
    return 0;
}

char smallest_character_recursive(char str[],char c,int index)
{
	if(str[index]>c){return str[index];}
	else if(str[index]!='\0'){
		smallest_character_recursive(str,c,++index);
	}
	else{
		return str[0];
	}
}

