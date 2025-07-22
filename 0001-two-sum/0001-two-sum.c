/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* arr = (int*)malloc(2 * sizeof(int)); // Dynamically allocate memory for the result array

    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2; // Set the return size
                return arr;
            }
        }
    }

    free(arr); // Free the memory allocated for arr
    return NULL; // Return NULL if no solution is found
}