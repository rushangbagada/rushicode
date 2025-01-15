#include <stdio.h>

int main()
{
    int k, n = 3;
    int a[] = {2,3,1};
    for (int i = 0; i < 1; i++)
    {
        int b = 1;
        for (k = n - 2; k >= 0; k--)
        {
            for (int j = n - 1; j > k; j--)
            {
                if (a[k] < a[j])
                {
                    int temp = a[k];
                    a[k] = a[j];
                    a[j] = temp;
                    b = 2;
                    break;
                }
            }
            if (b == 2)
            {
                break;
            }
        }
        for (int i = k + 1; i < n - 1; i++)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                if (a[i] > a[j])
                {
                    int temp1 = a[i];
                    a[i] = a[j];
                    a[j] = temp1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d", a[i]);
        }
        printf(" \n");
    }

    return 0;
}