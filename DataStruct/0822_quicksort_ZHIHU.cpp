#include<stdio.h>

void QuickSort(int arr[], int left, int right)
{
    int i    = left;
    int j    = right;
    int temp = 0;
    int mid  = arr[(i + j) / 2];  //取数组中间的值作为“基准值”

    while (i <= j)
    {
        while (arr[i] < mid)
        {
            i++;
        }
        while (arr[j] > mid)
        {
            j--;
        }

        //小于基准值移至左边，大于基准值的移至右边
        if (i <= j)
        {
            temp   = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (j > left)
    {
        QuickSort(arr, left, j);  //递归左半数组
    }
    if (i < right)
    {
        QuickSort(arr, i, right); //递归右半数组
    }
}

#define LEN 10

//测试程序
int main(void)
{
    int arr[LEN] = {0};

    printf("Input %d integers:", LEN);
    for (int i = 0; i < LEN; i++)
    {
        scanf("%d", &arr[i]);
    }

    QuickSort(arr, 0, LEN - 1);

    for (int i = 0; i < LEN; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}
