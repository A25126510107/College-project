#include <stdio.h>

int insertion_sort(int arr[], int n)
{
    int i, j, key;
    int shifts = 0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
            shifts++;
        }
        arr[j + 1] = key;
        printf("Pass %d: ", i);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
    }
    return shifts;
}
int main()
{
    int arr[100];
    int n, shifts;
    printf("Enter number of marks: ");
    scanf("%d", &n);
    printf("Enter the marks:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    shifts = insertion_sort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("Total number of shifts: %d", shifts);
}