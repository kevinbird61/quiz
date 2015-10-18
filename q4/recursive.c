#include <stdio.h>
#include <time.h>

int maxSubArray_re(int A[],int n);

int sum = 0;
int ind,standard;

int main(int argc,char *argv[])
{
    FILE *fp = fopen("analysis_time_recursive.txt","a");
    clock_t start,end;
    double result;
    start = clock();
    /* Variable & Given Array */
    int array[9] = {-2,1,-3,4,-1,2,1,-5,4};
    standard = array[0];
    ind = 0;
    maxSubArray_re(array,8);
    printf("The max sum of array : %d\n",standard);
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

int maxSubArray_re(int A[],int n)
{
    if(n!=0) {
        maxSubArray_re(A,n-1);
    }
    sum+=A[n];
    if(sum<=standard) {
        sum-=A[n];
        if(sum>standard) {
            standard = sum;
        }
        sum = 0;
    }
    return standard;

}
