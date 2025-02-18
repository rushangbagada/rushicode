#include <stdio.h>
#include <math.h>

void towerOfHanoiIterative(int n, char source, char target, char auxiliary)
{
    int totalMoves = (1 << n) - 1; 

    
    if (n % 2 == 0)
    {
        char temp = target;
        target = auxiliary;
        auxiliary = temp;
    }

    for (int i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 1)
        {
            printf("Move disk from %c to %c\n", source, target);
        }
        else if (i % 3 == 2)
        {
            printf("Move disk from %c to %c\n", source, auxiliary);
        }
        else
        {
            printf("Move disk from %c to %c\n", auxiliary, target);
        }
    }
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("The sequence of moves involved in the Tower of Hanoi are:\n");
    towerOfHanoiIterative(n, 'A', 'C', 'B'); 

    return 0;
}