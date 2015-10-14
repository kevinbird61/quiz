#include <stdio.h>

int maxSubArray_re(int A[],int n);

int sum = 0;
int ind,standard;

int main()
{
    /* Variable & Given Array */
    int array[9] = {-2,1,-3,4,-1,2,1,-5,4};

    standard = array[0];
    ind = 0;
    maxSubArray_re(array,8);
    printf("The max sum of array : %d\n",standard);
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
