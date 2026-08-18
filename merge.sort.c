#include <stdio.h>
#include <limits.h>

void merge(int a[], int p, int mid, int q)
{
    int l[100], r[100];
    int n1, n2, i, j, k;

    n1 = mid - p + 1;
    n2 = q - mid;

    for (i = 0; i < n1; i++)
        l[i] = a[p + i];

    for (j = 0; j < n2; j++)
        r[j] = a[mid + 1 + j];

    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = l[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = r[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int p, int q)
{
    int mid;

    if (p < q)
    {
        mid = (p + q) / 2;

        mergeSort(a, p, mid);
        mergeSort(a, mid + 1, q);

        merge(a, p, mid, q);
    }
}

int main()
{
    int a[100], m, i;

    printf("Enter number of elements: ");
    scanf("%d", &m);

    printf("Enter elements:\n");

    for (i = 0; i < m; i++)
        scanf("%d", &a[i]);

    mergeSort(a, 0, m - 1);

    printf("Sorted array:\n");

    for (i = 0; i < m; i++)
        printf("%d ", a[i]);

    return 0;
}