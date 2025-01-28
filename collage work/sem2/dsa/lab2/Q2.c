#include <stdio.h>

void day(int n)
{
    n = n % 7;
    switch (n)
    {
    case 1:
    {
        printf("Wednesday\n");
        break;
    }
    case 2:
    {
        printf("Thursday\n");
        break;
    }
    case 3:
    {
        printf("Friday\n");
        break;
    }
    case 4:
    {
        printf("Saturday\n");
        break;
    }
    case 5:
    {
        printf("Sunday\n");
        break;
    }
    case 6:
    {
        printf("Monday\n");
        break;
    }
    case 0:
    {
        printf("Tuesday\n");
        break;
    }
    }
}

int main()
{
    printf("Input month number: ");
    int m;
    scanf("%d", &m);

    if (m < 1 || m > 12)
    {
        printf("Invalid month!\n");
    }
    else
    {
        int sum = 0;
        switch (m - 1)
        {
        case 12:
            sum += 31; 
        case 11:
            sum += 30; 
        case 10:
            sum += 31; 
        case 9:
            sum += 30;
        case 8:
            sum += 31; 
        case 7:
            sum += 31; 
        case 6:
            sum += 30; 
        case 5:
            sum += 31; 
        case 4:
            sum += 30; 
        case 3:
            sum += 31; 
        case 2:
            sum += 28; 
        case 1:
            sum += 31; 
        }

        int size;
        switch (m)
        {
        case 1:
        {
            size = 31;
            break;
        }
        case 2:
        {
            size = 28;
            break;
        }
        case 3:
        {
            size = 31;
            break;
        }
        case 4:
        {
            size = 30;
            break;
        }
        case 5:
        {
            size = 31;
            break;
        }
        case 6:
        {
            size = 30;
            break;
        }
        case 7:
        {
            size = 31;
            break;
        }
        case 8:
        {
            size = 31;
            break;
        }
        case 9:
        {
            size = 30;
            break;
        }
        case 10:
        {
            size = 31;
            break;
        }
        case 11:
        {
            size = 30;
            break;
        }
        case 12:
        {
            size = 31;
            break;
        }
        }

        for (int i = 1; i <= size; i++)
        {
            printf("%d\t", i);
            day(sum + i);
        }
    }
    return 0;
}