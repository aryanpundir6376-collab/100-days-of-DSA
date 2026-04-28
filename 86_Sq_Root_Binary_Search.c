#include <stdio.h>

int integerSqrt(int n)
{
    int low = 0, high = n, mid;
    int ans = 0;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(mid * mid == n)
            return mid;
        else if(mid * mid < n)
        {
            ans = mid;      // store possible answer
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans;
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Integer square root: %d", integerSqrt(n));

    return 0;
}