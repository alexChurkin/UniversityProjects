#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

char* is_sorted(int arr[], int size)
{
    int i;
    for (i = 1; i < size; i++)
    {
        if (arr[i - 1] > arr[i])
            return "НЕТ!!!";
    }
    return "ДА";
}

int* create_empty_array(int size)
{
    return (int*)malloc(size * sizeof(int));
}

void print_array(int arr[], int size, bool not_big)
{
    //Не печатаем на экран массив слишком большого размера!
    if (not_big && size > 150)
        return;

    printf("[");
    for (int i = 0; i < size - 1; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("%i]\n", arr[size - 1]);
}

void populate_array(int arr[], int size)
{
    if (size <= 5)
    {
        printf("Введите %i чисел\n", size);
        for (int i = 0; i < size; i++)
            scanf("%i", &arr[i]);
    }
    else
    {
        int range_min, range_max;
        srand((unsigned int)time(NULL));
        printf("Введите минимальное значение: ");
        scanf("%i", &range_min);
        printf("Введите максимальное значение: ");
        scanf("%i", &range_max);
        for (int i = 0; i < size; i++)
        {
            arr[i] = (double)rand() /
                (RAND_MAX + 1) * (range_max + 1 - range_min) +
                range_min;
        }
        printf("Успешно сгенерирован новый массив.\n");
        print_array(arr, size, true);
    }
}

int* get_array(int* size)
{
    printf("Введите размер нового массива: ");
    scanf("%i", size);
    int* arr = create_empty_array(*size);
    populate_array(arr, *size);
    return arr;
}

int* array_copy(int arr[], int size)
{
    int* new_arr, i;
    new_arr = create_empty_array(size);
    for (i = 0; i < size; i++)
    {
        new_arr[i] = arr[i];
    }
    return new_arr;
}

void recover_old_array(int* arr, int* tmp_arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        arr[i] = tmp_arr[i];
}

void swap(int* a, int* b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

int get_min_index(int arr[], int size)
{
    int index = 0, i;
    for (int i = 0; i < size; i++)
        if (arr[i] < arr[index])
            index = i;
    return index;
}

int get_max_index(int arr[], int size)
{
    int index = 0, i;
    for (int i = 0; i < size; i++)
        if (arr[i] > arr[index])
            index = i;
    return index;
}

void merge_sorted_parts(
    int arr[], int l, int c, int r, int* comp_count, int* swap_count)
{
    int i = l,
        j = c + 1,
        t = 0;
    int* temp_arr;
    temp_arr = (int*)malloc((r - l + 1) * sizeof(int));

    while (i <= c && j <= r)
    {
        (*comp_count)++;
        if (arr[i] <= arr[j])
        {
            temp_arr[t] = arr[i], i++;
        }
        else
        {
            temp_arr[t] = arr[j], j++;
        }
        t++;
    }

    while (i <= c)
    {
        temp_arr[t] = arr[i];
        t++;
        i++;
    }
    while (j <= r)
    {
        temp_arr[t] = arr[j];
        t++;
        j++;
    }

    for (int i = l; i <= r; i++)
    {
        (*swap_count)++;
        arr[i] = temp_arr[i - l];
    }
    free(temp_arr);
}