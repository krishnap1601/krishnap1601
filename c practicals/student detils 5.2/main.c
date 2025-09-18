#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[100], n, i, j, temp, choice;

    printf("enter number of elements: ");
    scanf("%d", &n);

    printf("enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("choose sorting order:\n1. ascending\n2. descending\nenter chooice: ");
    scanf("%d", &choice);

    for (i = 0; i < n - 1; i++){
        for (j = i + 1; j < n; j++){
            if ((choice == 1 && arr[i] > arr[j])  ||
            (choice == 2 && arr[i] < arr[j])) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            }
        }
    }

   printf("\nsorted array:\n");
   for (i = 0; i < n; i++)
        printf("%d", arr[i]);

    return 0;
}
