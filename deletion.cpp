#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, index, arr[10];
    
    // Get array size
    printf("Enter the size of array: ");
    scanf("%d", &n);
    
    // Check if size is valid
    if (n > 10 || n <= 0) {
        printf("Invalid array size! Size should be between 1 and 10.\n");
        return 0;
    }
    
    // Get array elements
    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    // Get index of element to delete
    printf("Enter the index of the element to be deleted: ");
    scanf("%d", &index);
    
    // Check if the index is valid
    if(index < 0 || index >= n) {
        printf("\nDeletion is not possible. Invalid index.\n");
    } else {
        // Shift elements to the left from the index
        for(i = index; i < n-1; i++) {
            arr[i] = arr[i + 1];
        }
        
        // Decrease the size of the array
        n--;
        
        // Display the array after deletion
        printf("The array after deleting the element is:\n");
        for(i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

