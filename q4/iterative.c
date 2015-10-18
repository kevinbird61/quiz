#include <stdio.h>
#include <time.h>
int maxSubArray(int A[],int n);

int main(int argc,char *argv[])
{
    FILE *fp = fopen("analysis_time_iterative.txt","a");
    clock_t start,end;
    double result;
    start = clock();
    /* Variable & Given Array */
    int array[9] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("The max sum of array : %d\n",maxSubArray(array,9));
    end = clock();
    result = (end-start)/(double)(CLOCKS_PER_SEC);
    printf("%lf\n", result);
    if(argv[1][1]!='\0') {
        fprintf(fp,"%c%c		%lf\n",argv[1][0],argv[1][1],result);
    } else {
        fprintf(fp,"%c		%lf\n",argv[1][0],result);
    }
    return 0;
}

int maxSubArray(int A[],int n)
{
    int i,sum=0,standard=A[0];
    for(i=0; i<n; i++) {
        sum+=A[i];
        if(sum<=standard) {
            sum-=A[i];
            if(sum>standard) {
                standard = sum;
            }
            sum = 0;
        }
    }
    return standard;
}
