#include <stdio.h>

int maxSubArray(int A[],int n);

int main()
{
    /* Variable & Given Array */
    int array[9] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("The max sum of array : %d\n",maxSubArray(array,9));
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
