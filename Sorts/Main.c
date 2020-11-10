#include "sort.h"
#include "search.h"
#include "helpers.h"

void demonstrate_search(int* arr, int* tmp_arr, int size);
void demonstrate_sorts(int* arr, int* tmp_arr, int size);

void print_menu()
{
    printf("Доступные команды:\n");
    printf("---------------------------\n");
    printf("1.  Создать/пересоздать массив\n");
    printf("2.  Отобразить текущий массив\n");
    printf("3.  <Произвести шейкерную сортировку>\n");
    printf("4.  <Произвести сортировку выбором>\n");
    printf("5.  <Произвести сортировку вставками>\n");
    printf("6.  <Произвести сортировку подсчётом>\n");
    printf("7.  <Произвести быструю сортировку>\n");
    printf("8.  <Произвести сортировку слиянием>\n");
    printf("9.  <<<Сравнить скорость всех доступных сортировок>>>\n");
    printf("10. <<Найти элемент в отсортированном массиве>>\n");
    printf("---------------------------\n");
    printf("11. Отобразить меню команд\n");
    printf("0. Завершить программу\n");
    printf("---------------------------\n\n");
}

void main()
{
    setlocale(LC_CTYPE, "rus");

    int menu_number;
    int* arr = NULL;
    int* tmp_arr = NULL;
    int size;
    int comp_count, swap_count;

    print_menu();
    arr = get_array(&size);
    tmp_arr = array_copy(arr, size);

    while (1)
    {
        scanf("%i", &menu_number);
        switch (menu_number)
        {
        case 0:
            printf("\nЗавершение программы.");
            return;
        case 1:
            free(arr);
            free(tmp_arr);
            arr = get_array(&size);
            tmp_arr = array_copy(arr, size);
            break;
        case 2:
            print_array(arr, size);
            break;
        case 3:
            shaker_sort(arr, size, &comp_count, &swap_count);
            printf("Шейкерная сортировка:\n");
            print_array(arr, size);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 4:
            selection_sort(arr, size, &comp_count, &swap_count);
            printf("Сортировка выбором:\n");
            print_array(arr, size);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 5:
            insertion_sort(arr, size, &comp_count, &swap_count, 2);
            printf("Сортировка вставками (с бин. поиском):\n");
            print_array(arr, size);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 6:
            counting_sort(arr, size);
            printf("Сортировка подсчётом:\n");
            print_array(arr, size);
            printf("Корректность - %s\n", is_sorted(arr, size));
            recover_old_array(arr, tmp_arr, size);
            break;
        case 7:
            comp_count = 0;
            swap_count = 0;
            quick_sort(arr, 0, size - 1, &comp_count, &swap_count);
            printf("Быстрая сортировка:\n");
            print_array(arr, size);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 8:
            comp_count = 0;
            swap_count = 0;
            merge_sort(arr, 0, size - 1, &comp_count, &swap_count);
            printf("Сортировка слиянием:\n");
            print_array(arr, size);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 9:
            demonstrate_sorts(arr, tmp_arr, size);
            break;
        case 10:
            demonstrate_search(arr, tmp_arr, size);
            break;
        case 11:
            print_menu();
            break;
        }
    }
}

void demonstrate_search(int* arr, int* tmp_arr, int size) {
    int comp_count = 0;
    int swap_count = 0;
    int element;
    printf("Введите элемент для поиска: ");
    scanf("%i", &element);

    quick_sort(arr, 0, size - 1, &comp_count, &swap_count);
    printf("Отсортированный массив:\n");
    print_array(arr, size);

    int lin = linear_search(arr, size, element);
    int bin = binary_search(arr, size, element);

    printf("Результат линейного поиска: ");
    if (lin != -1) printf("элемент найден на позиции %i\n", lin);
    else printf("элемент не найден!\n");

    printf("Результат бинарного поиска: ");
    if (bin != -1) printf("элемент найден на позиции %i\n", bin);
    else printf("элемент не найден!\n");

    recover_old_array(arr, tmp_arr, size);
}

void demonstrate_sorts(int* arr, int* tmp_arr, int size)
{
    time_t begin, end;
    int comp_count, swap_count;

    //Шейкерная
    begin = clock();
    shaker_sort(arr, size, &comp_count, &swap_count);
    end = clock();
    printf("> Шейкерная:                     t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
        t_diff(begin, end), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //Выбором
    begin = clock();
    selection_sort(arr, size, &comp_count, &swap_count);
    end = clock();
    printf("> Выбором:                       t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
        t_diff(begin, end), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //Вставками (с линейным поиском места вставки)
    begin = clock();
    insertion_sort(arr, size, &comp_count, &swap_count, 1);
    end = clock();
    printf("> Вставками 1 (с лин. поиском):  t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
        t_diff(begin, end), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //Вставками (с бинарным поиском места вставки)
    begin = clock();
    insertion_sort(arr, size, &comp_count, &swap_count, 2);
    end = clock();
    printf("> Вставками 2 (с бин. поиском):  t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
        t_diff(begin, end), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //Подсчётом
    begin = clock();
    counting_sort(arr, size);
    end = clock();
    printf("> Подсчётом:                     t = %f сек., корректность - %s\n",
        t_diff(begin, end), is_sorted(arr, size));

    //Быстрая
    begin = clock();
    comp_count = 0;
    swap_count = 0;
    quick_sort(arr, 0, size - 1, &comp_count, &swap_count);
    end = clock();
    printf("> Быстрая сортировка:            t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
        t_diff(begin, end), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //Cлиянием
    begin = clock();
    comp_count = 0;
    swap_count = 0;
    merge_sort(arr, 0, size - 1, &comp_count, &swap_count);
    end = clock();
    printf("> Слиянием:                      t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
        t_diff(begin, end), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);
}