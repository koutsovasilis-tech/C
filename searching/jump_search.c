/**
 * Jump search implementation 
 * author: George-Anastasios Koutsovasilis
 * github: https://github.com/koutsovasilis-tech
 * @param arr The sorted array 
 * @param size The size of the sorted array 
 * @param x The element we are trying to find 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>


int jump_search(int arr[], int size, int x)
{
    int step = sqrt(size);
    int prev = 0;
    int i = 0;
    while (i < size && arr[i] < x) // jumps till it finds the correct block or it exceeds it 
    {
        prev = i;
        i += step;
    }
    int limit = (i < size) ? i : size - 1; // limit because i might be larger than size 
    for (int m = prev; m <= limit; m++) // linear search 
    {
        if (arr[m] == x)
        {
            return m; 
        }
    }
    return -1; 
}
int main() 
{
    // Already sorted array for the tests 
    int arr[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Test Case 1: Element in the middle
    int target1 = 55;
    int result1 = jump_search(arr, size, target1);
    assert(arr[result1] == target1);
    printf("Test 1 Passed: Found %d at index %d\n", target1, result1);

    // Test Case 2: Element at the start 
    int target2 = 0;
    int result2 = jump_search(arr, size, target2);
    assert(result2 == 0);
    printf("Test 2 Passed: Found %d at index %d\n", target2, result2);

    // Test Case 3: Element at the end 
    int target3 = 610;
    int result3 = jump_search(arr, size, target3);
    assert(result3 == size - 1);
    printf("Test 3 Passed: Found %d at index %d\n", target3, result3);

    // Test Case 4: Element does not exist
    int target4 = 100;
    int result4 = jump_search(arr, size, target4);
    assert(result4 == -1);
    printf("Test 4 Passed: Element %d correctly not found\n", target4);
    printf("\n--- ALL TESTS PASSED SUCCESSFULLY ---\n");
    return 0;
}
 