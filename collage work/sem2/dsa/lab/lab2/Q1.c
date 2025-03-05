#include <stdio.h>

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n%d\n", size);
}

void insertAtBeginning(int arr[], int *size, int capacity, int val)
{
    if (*size == capacity)
    {
        printf("Array is Full.\n");
        return;
    }
    for (int i = *size; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = val;
    (*size)++;
}

void insertAtEnd(int arr[], int *size, int capacity, int val)
{
    if (*size == capacity)
    {
        printf("Array is Full.\n");
        return;
    }
    arr[*size] = val;
    (*size)++;
}

void insertAtPos(int arr[], int *size, int capacity, int pos, int val)
{
    if (*size == capacity)
    {
        printf("Array is Full.\n");
        return;
    }
    for (int i = *size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    (*size)++;
}

void modifyAtBeginning(int arr[], int *size, int val)
{
    if (*size == 0)
    {
        printf("Array is empty!\n");
        return;
    }
    arr[0] = val;
}

void modifyAtEnd(int arr[], int *size, int val)
{
    if (*size == 0)
    {
        printf("Array is empty!\n");
        return;
    }
    arr[*size - 1] = val;
}

void modifyAtPos(int arr[], int pos, int val)
{
    arr[pos] = val;
}

void deleteAtBeginning(int arr[], int *size)
{
    if (*size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void deleteAtEnd(int arr[], int *size)
{
    if (*size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    (*size)--;
}

void deleteAtPos(int arr[], int *size, int pos)
{
    if (*size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    for (int i = pos; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void reverse(int arr[], int size)
{
    if (size == 0)
    {
        printf("Array is empty.\n");
        return;
    }
    for (int i = 0; i < size / 2; i++)
    {
        int t = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = t;
    }
}

void Merge(int arr[], int n1, int brr[], int n2, int ans[], int *sizeM)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr[i] >= brr[j])
            ans[k++] = arr[i++];
        else
            ans[k++] = brr[j++];
    }
    while (i < n1)
        ans[k++] = arr[i++];
    while (j < n2)
        ans[k++] = brr[j++];
    *sizeM = k;
}

void copy(int a1[], int *size1, int a2[], int size2)
{
    for (int i = 0; i < size2; i++)
    {
        a1[i] = a2[i];
    }
    *size1 = size2;
}

void displaySum(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    printf("%d\n", sum);
}

int displaySumRec(int arr[], int size, int sum, int i)
{
    if (i == size)
        return sum;
    return displaySumRec(arr, size, sum + arr[i], i + 1);
}

void find(int arr[], int size, int val)
{
    int i;
    for (i = 0; i < size; i++)
        if (arr[i] == val)
            break;
    if (i == size)
        printf("Element not found.\n");
    else
        printf("Element found at index %d\n", i);
}

void displayOddEven(int arr[], int size)
{
    printf("Odd numbers are: ");
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 != 0)
            printf("%d ", arr[i]);
    printf("\nEven numbers are: ");
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 == 0)
            printf("%d ", arr[i]);
    printf("\n");
}

void displayPosNeg(int arr[], int size)
{
    printf("Positive numbers are: ");
    for (int i = 0; i < size; i++)
        if (arr[i] >= 0)
            printf("%d ", arr[i]);
    printf("\nNegative numbers are: ");
    for (int i = 0; i < size; i++)
        if (arr[i] < 0)
            printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int SubArray1[10], size1 = 0;
    int SubArray2[10], size2 = 0;
    int MainArray[20], sizeM = 0;

    while (1)
    {
        printf("Would you like to continue (Y/N)? ");
        char ch;
        scanf(" %c", &ch);
        if (ch != 'Y')
            break;

        printf("To insert, click 1\nTo modify, click 2\nTo delete, click 3\nTo reverse elements, click 4\nTo copy elements of SubArray to MainArray, click 5\nTo merge two arrays of same size sorted in descending order, click 6\nTo display sum of elements, click 7\nTo find element, click 8\nTo display odd and even elements of MainArray, click 9\nTo display positive and negative elements of MainArray, click 10\n");
        int root;
        scanf("%d", &root);
        switch (root)
        {
        // INSERT
        case 1:
        {
            printf("Enter value you want to insert: ");
            int val;
            scanf("%d", &val);
            printf("To insert at beginning: click 1\nTo insert at end, click 2\nTo insert at any index, click 3\n");
            int child;
            scanf("%d", &child);
            printf("To insert in SubArray1: click 1\nTo insert in SubArray2, click 2\nTo insert in MainArray, click 3\n");
            int grandchild;
            scanf("%d", &grandchild);
            // TYPE OF INSERT
            switch (child)
            {
            case 1:
            {
                // IN WHICH ARRAY
                switch (grandchild)
                {
                case 1:
                {
                    insertAtBeginning(SubArray1, &size1, 10, val);
                    display(SubArray1, size1);
                    break;
                }
                case 2:
                {
                    insertAtBeginning(SubArray2, &size2, 10, val);
                    display(SubArray2, size2);
                    break;
                }
                case 3:
                {
                    insertAtBeginning(MainArray, &sizeM, 20, val);
                    display(MainArray, sizeM);
                    break;
                }
                default:
                    printf("Invalid Input\n");
                }
                break;
            }
            case 2:
            {
                // IN WHICH ARRAY
                switch (grandchild)
                {
                case 1:
                {
                    insertAtEnd(SubArray1, &size1, 10, val);
                    display(SubArray1, size1);
                    break;
                }
                case 2:
                {
                    insertAtEnd(SubArray2, &size2, 10, val);
                    display(SubArray2, size2);
                    break;
                }
                case 3:
                {
                    insertAtEnd(MainArray, &sizeM, 20, val);
                    display(MainArray, sizeM);
                    break;
                }
                default:
                    printf("Invalid Input\n");
                }
                break;
            }
            case 3:
            {
                int pos;
                printf("Enter index at which you want to insert: ");
                scanf("%d", &pos);
                // IN WHICH ARRAY
                switch (grandchild)
                {
                case 1:
                {
                    if (pos >= 0 && pos <= size1)
                    {
                        insertAtPos(SubArray1, &size1, 10, pos, val);
                        display(SubArray1, size1);
                    }
                    else
                        printf("Invalid index!\n");
                    break;
                }
                case 2:
                {
                    if (pos >= 0 && pos <= size2)
                    {
                        insertAtPos(SubArray2, &size2, 10, pos, val);
                        display(SubArray2, size2);
                    }
                    else
                        printf("Invalid index!\n");
                    break;
                }
                case 3:
                {
                    if (pos >= 0 && pos <= sizeM)
                    {
                        insertAtPos(MainArray, &sizeM, 20, pos, val);
                        display(MainArray, sizeM);
                    }
                    else
                        printf("Invalid index!\n");
                    break;
                }
                default:
                    printf("Invalid Input\n");
                }
                break;
            }
            default:
                printf("Invalid input!\n");
            }
            break;
        }
        // MODIFY
        case 2:
        {
            printf("Enter updated value: ");
            int val;
            scanf("%d", &val);
            printf("To modify at beginning, click 1\nTo modify at end, click 2\nTo modify at any index, click 3\n");
            int child;
            scanf("%d", &child);
            printf("To modify in SubArray1: click 1\nTo modify in SubArray2, click 2\nTo modify in MainArray, click 3\n");
            int grandchild;
            scanf("%d", &grandchild);
            // TYPE OF MODIFY
            switch (child)
            {
            case 1:
            {
                // IN WHICH ARRAY
                switch (grandchild)
                {
                case 1:
                {
                    modifyAtBeginning(SubArray1, &size1, val);
                    display(SubArray1, size1);
                    break;
                }
                case 2:
                {
                    modifyAtBeginning(SubArray2, &size2, val);
                    display(SubArray2, size2);
                    break;
                }
                case 3:
                {
                    modifyAtBeginning(MainArray, &sizeM, val);
                    display(MainArray, sizeM);
                    break;
                }
                default:
                    printf("Invalid Input\n");
                }
                break;
            }
            case 2:
            {
                // IN WHICH ARRAY
                switch (grandchild)
                {
                case 1:
                {
                    modifyAtEnd(SubArray1, &size1, val);
                    display(SubArray1, size1);
                    break;
                }
                case 2:
                {
                    modifyAtEnd(SubArray2, &size2, val);
                    display(SubArray2, size2);
                    break;
                }
                case 3:
                {
                    modifyAtEnd(MainArray, &sizeM, val);
                    display(MainArray, sizeM);
                    break;
                }
                default:
                    printf("Invalid Input\n");
                }
                break;
            }
            case 3:
            {
                int pos;
                printf("Enter index at which you want to modify: ");
                scanf("%d", &pos);
                // IN WHICH ARRAY
                switch (grandchild)
                {
                case 1:
                {
                    if (pos >= 0 && pos < size1)
                    {
                        modifyAtPos(SubArray1, pos, val);
                        display(SubArray1, size1);
                    }
                    else
                        printf("Invalid index!\n");
                    break;
                }
                case 2:
                {
                    if (pos >= 0 && pos < size2)
                    {
                        modifyAtPos(SubArray2, pos, val);
                        display(SubArray2, size2);
                    }
                    else
                        printf("Invalid index!\n");
                    break;
                }
                case 3:
                {
                    if (pos >= 0 && pos < sizeM)
                    {
                        modifyAtPos(MainArray, pos, val);
                        display(MainArray, sizeM);
                    }
                    else
                        printf("Invalid index!\n");
                    break;
                }
                default:
                    printf("Invalid Input\n");
                }
                break;
            }
            default:
                printf("Invalid input!\n");
            }
            break;
        }
        // DELETE
        case 3:
        {
            printf("To delete at beginning, click 1\nTo delete at end, click 2\nTo delete at any index, click 3\n");
            int child;
            scanf("%d", &child);
            printf("To delete in SubArray1, click 1\nTo delete in SubArray2, click 2\nTo delete in MainArray, click 3\n");
            int grandchild;
            scanf("%d", &grandchild);
            // TYPE OF DELETE
            switch (child)
            {
            case 1:
            {
                // IN WHICH ARRAY
                switch (grandchild)
                {
                case 1:
                {
                    deleteAtBeginning(SubArray1, &size1);
                    display(SubArray1, size1);
                    break;
                }
                case 2:
                {
                    deleteAtBeginning(SubArray2, &size2);
                    display(SubArray2, size2);
                    break;
                }
                case 3:
                {
                    deleteAtBeginning(MainArray, &sizeM);
                    display(MainArray, sizeM);
                    break;
                }
                default:
                    printf("Invalid Input\n");
                }
                break;
            }
            case 2:
            {
                // IN WHICH ARRAY
                switch (grandchild)
                {
                case 1:
                {
                    deleteAtEnd(SubArray1, &size1);
                    display(SubArray1, size1);
                    break;
                }
                case 2:
                {
                    deleteAtEnd(SubArray2, &size2);
                    display(SubArray2, size2);
                    break;
                }
                case 3:
                {
                    deleteAtEnd(MainArray, &sizeM);
                    display(MainArray, sizeM);
                    break;
                }
                default:
                    printf("Invalid Input\n");
                }
                break;
            }
            case 3:
            {
                int pos;
                printf("Enter index at which you want to delete: ");
                scanf("%d", &pos);
                // IN WHICH ARRAY
                switch (grandchild)
                {
                case 1:
                {
                    if (pos >= 0 && pos < size1)
                    {
                        deleteAtPos(SubArray1, &size1, pos);
                        display(SubArray1, size1);
                    }
                    else
                        printf("Invalid index!\n");
                    break;
                }
                case 2:
                {
                    if (pos >= 0 && pos < size2)
                    {
                        deleteAtPos(SubArray2, &size2, pos);
                        display(SubArray2, size2);
                    }
                    else
                        printf("Invalid index!\n");
                    break;
                }
                case 3:
                {
                    if (pos >= 0 && pos < sizeM)
                    {
                        deleteAtPos(MainArray, &sizeM, pos);
                        display(MainArray, sizeM);
                    }
                    else
                        printf("Invalid index!\n");
                    break;
                }
                default:
                    printf("Invalid Input\n");
                }
                break;
            }
            default:
                printf("Invalid input!\n");
            }
            break;
        }
        // REVERSE
        case 4:
        {
            // IN WHICH ARRAY
            printf("To reverse in SubArray1, click 1\nTo reverse in SubArray2, click 2\nTo reverse in MainArray, click 3\n");
            int child;
            scanf("%d", &child);
            switch (child)
            {
            case 1:
            {
                reverse(SubArray1, size1);
                display(SubArray1, size1);
                break;
            }
            case 2:
            {
                reverse(SubArray2, size2);
                display(SubArray2, size2);
                break;
            }
            case 3:
            {
                reverse(MainArray, sizeM);
                display(MainArray, sizeM);
                break;
            }
            default:
                printf("Invalid Input\n");
            }
            break;
        }
        // COPY
        case 5:
        {
            printf("To copy SubArray1, click 1\nTo copy SubArray2, click 2\n");
            int child;
            scanf("%d", &child);
            switch (child)
            {
            case 1:
            {
                copy(MainArray, &sizeM, SubArray1, size1);
                display(MainArray, sizeM);
                break;
            }
            case 2:
            {
                copy(MainArray, &sizeM, SubArray2, size2);
                display(MainArray, sizeM);
                break;
            }
            default:
                printf("Invalid input!\n");
            }
            break;
        }
        // MERGE
        case 6:
        {
            if (size1 == size2)
            {
                Merge(SubArray1, size1, SubArray2, size2, MainArray, &sizeM);
                display(MainArray, sizeM);
            }
            else
            {
                printf("Sizes of two arrays to be merged are unequal\n");
            }
            break;
        }
        // DISPLAY SUM
        case 7:
        {
            printf("To display sum using recursion, click 1\nTo display sum without using recursion, click 2\n");
            int child;
            scanf("%d", &child);
            switch (child)
            {
            case 1:
            {
                printf("To display sum of SubArray1, click 1\nTo display sum of SubArray2, click 2\nTo display sum of MainArray, click 3\n");
                int grandchild;
                scanf("%d", &grandchild);
                int sum;
                switch (grandchild)
                {
                case 1:
                {
                    sum = displaySumRec(SubArray1, size1, 0, 0);
                    break;
                }
                case 2:
                {
                    sum = displaySumRec(SubArray2, size2, 0, 0);
                    break;
                }
                case 3:
                {
                    sum = displaySumRec(MainArray, sizeM, 0, 0);
                    break;
                }
                default:
                    printf("Wrong input!\n");
                }
                printf("%d\n", sum);
                break;
            }
            case 2:
            {
                printf("To display sum of SubArray1, click 1\nTo display sum of SubArray2, click 2\nTo display sum of MainArray, click 3\n");
                int grandchild;
                scanf("%d", &grandchild);
                switch (grandchild)
                {
                case 1:
                {
                    displaySum(SubArray1, size1);
                    break;
                }
                case 2:
                {
                    displaySum(SubArray2, size2);
                    break;
                }
                case 3:
                {
                    displaySum(MainArray, sizeM);
                    break;
                }
                default:
                    printf("Wrong input!\n");
                }
                break;
            }
            default:
                printf("Invalid input!\n");
            }
            break;
        }
        // FIND
        case 8:
        {
            printf("Enter the value you want to find: ");
            int val;
            scanf("%d", &val);
            printf("To find element in SubArray1, click 1\nTo find element in SubArray2, click 2\nTo find element in MainArray, click 3\n");
            int child;
            scanf("%d", &child);
            switch (child)
            {
            case 1:
            {
                find(SubArray1, size1, val);
                break;
            }
            case 2:
            {
                find(SubArray2, size2, val);
                break;
            }
            case 3:
            {
                find(MainArray, sizeM, val);
                break;
            }
            default:
                printf("Wrong input!\n");
            }
            break;
        }
        // DISPLAY ODD AND EVEN
        case 9:
        {
            displayOddEven(MainArray, sizeM);
            break;
        }
        // DISPLAY POSITIVE AND NEGATIVE
        case 10:
        {
            displayPosNeg(MainArray, sizeM);
            break;
        }
        default:
            printf("Wrong input!\n");
        }
        fflush(stdin);
    }
    return 0;
}