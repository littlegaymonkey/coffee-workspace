#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int nums[1000];
    for (int i = 0; i < n; i++) 
        scanf("%d", &nums[i]);
    // Sort nums from largest to smallest without using qsort()
    for (int i = 0; i < n - 1; i++)
    {
        int index;
        int tmp;
        int max = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > max)
            {
                max = nums[j];
                index = j;
            }
        }
        if (index != i)
        {
            tmp = nums[i];
            nums[i] = max;
            nums[index] = tmp;
        }
    }
    for (int i = 0; i < n; i++) 
        printf("%d ", nums[i]);
    printf("\n");
    return 0;
}
