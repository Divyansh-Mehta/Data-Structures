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
void display(array);         // Display
void append(array *, int);   // Append ie add at last
int delete (array *, int);   // Deletion
int l_search(array, int);    // Linear search
int b_search(array, int);    // Binary search
int get(array, int);         // Get element at particular index
void set(array *, int, int); // Replace element at particular index
int max(array);              // Return max element
int min(array);              // Return min element
int sum(array);              // Return sum of all elements of array
int avg(array);              // Return average of all elements of array
void reverse_v1(array *);    // Reverse array using another array
void reverse_v2(array *);    // Reverse array with using another array
void swap(int *, int *);     // Function to swap
void left_shift(array *);    // Shifts elements left and terminates 1st element
void left_rotate(array *);   // shifts elements left and 1st element to last
void right_shift(array *);   // Shifts elements right and terminates last element
void right_rotate(array *);  // shifts elements left and last element to 1st

// main
int main()
{
    array arr;
    int ch;
    do
    {
        printf("\n*****MENU*****");
        printf("\n1.Create\n2.Display\n3.append\n4.delete\n5.search\n6.Get and Set\n7.Some common operation");
        printf("\n8.Reverse\n9.Shift and Rotate\n10.Exit\nEnter your choice:");
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
            break;
        default:
            printf("Enter correct choice");
        }

    } while (ch != 10);

    return 0;
}

//Defination

void display(array arr)
{
    int i;
    printf("Elements are- ");
    for (i = 0; i < arr.length; i++)
    {
        printf("%d ", arr.A[i]);
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