#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct Array_ADT
{
    int A[MAX];
    int size;
    int length;
} array;

// Function Declaration
void display(array);                            // Display
void append(array *, int);                      // Append ie add at last
int delete (array *, int);                      // Deletion
int l_search(array, int);                       // Linear search
int b_search(array, int);                       // Binary search
int get(array, int);                            // Get element at particular index
void set(array *, int, int);                    // Replace element at particular index
int max(array);                                 // Return max element
int min(array);                                 // Return min element
int sum(array);                                 // Return sum of all elements of array
int avg(array);                                 // Return average of all elements of array
void reverse_v1(array *);                       // Reverse array using another array
void reverse_v2(array *);                       // Reverse array with using another array
void swap(int *, int *);                        // Function to swap
void left_shift(array *);                       // Shifts elements left and terminates 1st element
void left_rotate(array *);                      // Shifts elements left and 1st element to last
void right_shift(array *);                      // Shifts elements right and terminates last element
void right_rotate(array *);                     // Shifts elements left and last element to 1st
void insert_sort(array *, int);                 // Insert in a shorted array
int check_sort(array);                          // Cheak if array is sorted
void negative_on_left(array *);                 // Put all negative element on left side of array
array *merge(array *, array *);                 // Merge sorted array
array *union_unsort(array *, array *);          // Union of unsorted arrays
array *union_sorted(array *, array *);          // Union of sorted arrays
array *intersection_unsorted(array *, array *); // Intersection of unsorted arrays
array *intersection_sorted(array *, array *);   // Intersection of sorted array
array *difference_unsorted(array *, array *);   // Difference of unsorted array first param - second param
array *difference_sorted(array *, array *);     // Difference of sorted array first param - second param

// main
int main() // Add in main merge, union_sorted, union_unsorted, intersection_sorted and unsorted, difference sorted and unsorted
{
    array arr;
    int ch;
    do
    {
        printf("\n*****MENU*****");
        printf("\n1.Create\n2.Display\n3.append\n4.delete\n5.search\n6.Get and Set\n7.Some common operation");
        printf("\n8.Reverse\n9.Shift and Rotate\n10.Misc\n11.Operation on two array\n12.Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {
            int n, i;
            printf("Enter no of elements[max size %d]- ", MAX);
            scanf("%d", &n);
            printf("Enter elements: ");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &arr.A[i]);
            }
            arr.length = n;
            arr.size = MAX;
        }
        break;
        case 2:
        {
            display(arr);
        }
        break;
        case 3:
        {
            int element;
            printf("\nEnter element to append- ");
            scanf("%d", &element);
            append(&arr, element);
        }
        break;
        case 4:
        {
            int index;
            printf("\nEnter index: ");
            scanf("%d", &index);
            delete (&arr, index);
        }
        break;
        case 5:
        {
            int n, key;
            int (*p[2])(array, int) = {l_search, b_search};
            printf("\n1.Linear search\n2.Binary search\nEnter your choice:");
            scanf("%d", &n);
            printf("Enter element: ");
            scanf("%d", &key);
            if (p[n - 1](arr, key) != -1)
                printf("Element found at %d", p[n - 1]);
            else
                printf("Element not found");
        }
        break;
        case 6:
        {
            int n, index, x;
            printf("1.Get an element\n2.Set an element\nEnter your choice: ");
            scanf("%d", &n);
            printf("Enter index: ");
            scanf("%d", &index);
            if (n == 1)
            {
                printf("Element at %d is %d", index, get(arr, index));
            }
            else
            {
                printf("Enter element to set: ");
                scanf("%d", &x);
                set(&arr, index, x);
            }
        }
        break;
        case 7:
        {
            int (*p[4])(array) = {max, min, sum, avg}, n;
            printf("1.Find max\n2.Find min\n3.Find sum\n4.Find average");
            printf("\nEnter your choice: ");
            scanf("%d", &n);
            printf("%d\n", p[n - 1](arr));
        }
        break;
        case 8:
        {
            reverse_v2(&arr);
        }
        break;
        case 9:
        {
            int n;
            void (*p[4])(array *) = {left_shift, left_rotate, right_shift, right_rotate};
            printf("\n1.Left shift\n2.Left rotate\n3.Right shift\n4.Right rotate");
            printf("\nEnter your choice: ");
            scanf("%d", &n);
            p[n - 1](&arr);
        }
        break;

        case 10:
        {
            int n;
            printf("1.Insert in sorted array\n2.Check if array is sorted\n3.Arrange negavite element on one side");
            printf("\nEnter your choice: ");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
            {
                int x;
                printf("Enter element to be inserted: ");
                scanf("%d", &x);
                insert_sort(&arr, x);
            }
            break;
            case 2:
            {
                if (check_sort(arr))
                    printf("\nArray is sorted");
                else
                    printf("\nArray is not sorted");
            }
            break;
            case 3:
            {
                negative_on_left(&arr);
            }
            break;
            default:
                printf("\nWrong choice");
            }
        }
        case 11:
        {
            int i, n;
            array arr2, *arr3;
            printf("\nEnter length another array: ");
            scanf("%d", &arr2.length);
            printf("Enter array elements: ");
            for (i = 0; i < arr2.length; i++)
            {
                scanf("%d",&arr2.A[i]);
            }
            arr2.size = MAX;
            printf("\n1.Merge\n2.Union\n3.Intersection\n4.Difference\nEnter your choice: ");
            scanf("%d", &n);
            switch (n)
            {
            case 1:
            {
                arr3 = merge(&arr, &arr2);
                printf("\nMerger array: ");
                for (i = 0; i < arr3->length; i++)
                    printf("%d ", arr3->A[i]);
            }
            break;
            case 2:
            {
                int i;
                arr3 = union_unsort(&arr, &arr2);
                printf("\nResultent array: ");
                for (i = 0; i < arr3->length; i++)
                    printf("%d ", arr3->A[i]);
            }
            break;
            case 3:
            {
                int i;
                arr3 = intersection_unsorted(&arr, &arr2);
                printf("\nResultant array: ");
                for (i = 0; i < arr3->length; i++)
                    printf("%d ", arr3->A[i]);
            }
            break;
            case 4:
            {
                int i;
                arr3 = difference_unsorted(&arr, &arr2);
                printf("\nMerger array: ");
                for (i = 0; i < arr3->length; i++)
                    printf("%d ", arr3->A[i]);
            }
            break;
            default:
                printf("\nWrong choice");
            }
        }
        break;

        case 12:
            break;
        default:
            printf("Enter correct choice");
        }

    } while (ch != 12);

    return 0;
}

//Defination

void display(array arr)
{
    int i;
    printf("Elements are- ");
    for (i = 0; i < arr.length; i++)
    {
        printf("[%d] ", arr.A[i]);
    }
}

void append(array *arr, int x)
{
    if (arr->length < arr->size)
    {
        arr->A[arr->length++] = x;
    }
}

int delete (array *arr, int index)
{
    int x = 0, i;

    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length - 1; i++)
        {
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        return x;
    }

    return x;
}

int l_search(array arr, int key)
{
    int i;
    for (i = 0; i < arr.length; i++)
    {
        if (arr.A[i] == key)
            return i;
    }

    return -1;
}

int b_search(array arr, int key)
{
    int l, h, mid;
    l = 0;
    h = arr.length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (arr.A[mid] == key)
            return mid;
        else if (arr.A[mid] > key)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int get(array arr, int index)
{
    if (index > 0 && index < arr.length)
        return arr.A[index];

    return -1;
}

void set(array *arr, int index, int x)
{
    if (index > 0 && index < arr->length)
        arr->A[index] = x;
}

int max(array arr)
{
    int max = arr.A[0], i;

    for (i = 0; i < arr.length; i++)
    {
        if (max < arr.A[i])
            max = arr.A[i];
    }
    return max;
}

int min(array arr)
{
    int min = arr.A[0], i;

    for (i = 0; i < arr.length; i++)
    {
        if (min > arr.A[i])
            min = arr.A[i];
    }
    return min;
}

int sum(array arr)
{
    int sum = 0, i;
    for (i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}

int avg(array arr)
{
    int sum = 0, i;
    for (i = 0; i < arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum / arr.length;
}

void reverse_v1(array *arr)
{
    int *b = (int *)malloc(arr->length * sizeof(int)), i, j;

    for (i = 0, j = arr->length - 1; i < arr->length; i++, j--)
    {
        b[i] = arr->A[j];
    }
    for (i = 0; i < arr->length; i++)
    {
        arr->A[i] = b[i];
    }
    free(b);
    b = NULL;
}

void reverse_v2(array *arr)
{
    int i, j;
    for (i = 0, j = arr->length - 1; i < j; i++, j--)
    {
        swap(&(arr->A[i]), &(arr->A[j]));
    }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void left_shift(array *arr)
{
    int i;
    for (i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = 0;
}

void left_rotate(array *arr)
{
    int i, temp = arr->A[0];
    for (i = 0; i < arr->length - 1; i++)
    {
        arr->A[i] = arr->A[i + 1];
    }
    arr->A[arr->length - 1] = temp;
}

void right_shift(array *arr)
{
    int i;
    for (i = arr->length - 1; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = 0;
}

void right_rotate(array *arr)
{
    int i, temp = arr->A[arr->length - 1];
    for (i = arr->length - 1; i > 0; i--)
    {
        arr->A[i] = arr->A[i - 1];
    }
    arr->A[0] = temp;
}

void insert_sort(array *arr, int x)
{
    int i = arr->length - 1;
    while (arr->A[i] > x && i >= 0)
    {
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    arr->A[i + 1] = x;
    arr->length++;
}

int check_sort(array arr)
{
    int i;

    for (i = 0; i < arr.length - 1; i++)
    {
        if (arr.A[i] > arr.A[i + 1])
        {
            return 0;
        }
    }

    return 1;
}

void negative_on_left(array *arr)
{
    int i = 0, j = arr->length - 1;
    while (i < j)
    {
        while (arr->A[i] < 0)
        {
            i++;
        }
        while (arr->A[j] >= 0)
        {
            j--;
        }
        if (i < j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

array *merge(array *arr1, array *arr2)
{
    array *arr3 = (array *)malloc(sizeof(array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];

        else
            arr3->A[k++] = arr2->A[j++];
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = arr1->length + arr2->length;
    arr3->size = MAX;

    return arr3;
}

array *union_unsort(array *arr1, array *arr2)
{
    array *arr3 = (array *)malloc(sizeof(array));
    int i, j, k;
    i = j = k = 0;
    for (i = 0; i < arr1->length; i++)
    {
        arr3->A[k++] = arr1->A[i];
    }
    for (i = 0; i < arr2->length; i++)
    {
        for (j = 0; j < arr1->length; j++)
        {
            if (arr2->A[i] == arr1->A[j])
            {
                break;
            }
        }
        if (j == arr1->length)
            arr3->A[k++] = arr2->A[i];
    }
    arr3->size = MAX;
    arr3->length = k;
    return arr3;
}

array *union_sorted(array *arr1, array *arr2)
{
    array *arr3 = (array *)malloc(sizeof(array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];

        else if (arr1->A[i] > arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr2->A[i++];
            j++;
        }
    }

    for (; i < arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    for (; j < arr2->length; j++)
        arr3->A[k++] = arr2->A[j];

    arr3->length = k;
    arr3->size = MAX;

    return arr3;
}

array *intersection_unsorted(array *arr1, array *arr2)
{
    array *arr3 = (array *)malloc(sizeof(array));
    int i, j, k;
    i = j = k = 0;
    for (i = 0; i < arr1->length; i++)
    {
        for (j = 0; j < arr2->length; j++)
        {
            if (arr2->A[j] == arr1->A[i])
            {
                break;
            }
        }
        if (j != arr2->length)
            arr3->A[k++] = arr1->A[i];
    }
    arr3->size = MAX;
    arr3->length = k;
    return arr3;
}

array *intersection_sorted(array *arr1, array *arr2)
{
    array *arr3 = (array *)malloc(sizeof(array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            i++;

        else if (arr1->A[i] > arr2->A[j])
            j++;
        else
        {
            arr3->A[k++] = arr2->A[i++];
            j++;
        }
    }

    arr3->length = k;
    arr3->size = MAX;

    return arr3;
}

array *difference_unsorted(array *arr1, array *arr2)
{
    array *arr3 = (array *)malloc(sizeof(array));
    int i, j, k;
    i = j = k = 0;
    for (i = 0; i < arr2->length; i++)
    {
        for (j = 0; j < arr1->length; j++)
        {
            if (arr2->A[j] == arr1->A[i])
            {
                break;
            }
        }
        if (j == arr1->length)
            arr3->A[k++] = arr1->A[i];
    }
    arr3->size = MAX;
    arr3->length = k;
    return arr3;
}

array *difference_sorted(array *arr1, array *arr2)
{
    array *arr3 = (array *)malloc(sizeof(array));
    int i, j, k;
    i = j = k = 0;
    while (i < arr1->length && j < arr2->length)
    {
        if (arr1->A[i] < arr2->A[j])
            arr3->A[k++] = arr1->A[i++];

        else if (arr1->A[i] > arr2->A[j])
            j++;
        else
        {
            i++;
            j++;
        }
    }

    arr3->length = k;
    arr3->size = MAX;

    return arr3;
}