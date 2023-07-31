#include<stdio.h>

void QuickSort(int arr[], int left, int right)
{
    int i    = left;
    int j    = right;
    int temp = 0;
    int mid  = arr[(i + j) / 2];  //ȡ�����м��ֵ��Ϊ����׼ֵ��

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

        //С�ڻ�׼ֵ������ߣ����ڻ�׼ֵ�������ұ�
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
        QuickSort(arr, left, j);  //�ݹ��������
    }
    if (i < right)
    {
        QuickSort(arr, i, right); //�ݹ��Ұ�����
    }
}

#define LEN 10

//���Գ���
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
