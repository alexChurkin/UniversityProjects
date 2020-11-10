#include "sort.h"
#include "helpers.h"

void demonstrate_all(int* arr, int* tmp_arr, int size);

void print_menu()
{
    printf("Доступные команды:\n");
    printf("---------------------------\n");
    printf("1. Создать/пересоздать массив\n");
    printf("2. Отобразить текущий массив\n");
    printf("3. <Произвести шейкерную сортировку>\n");
    printf("4. <Произвести сортировку выбором>\n");
    printf("5. <Произвести сортировку вставками>\n");
    printf("6. <Произвести сортировку подсчётом>\n");
    printf("7. <Произвести быструю сортировку>\n");
    printf("8. <Произвести сортировку слиянием>\n");
    printf("9. <<<Сравнить скорость всех доступных сортировок>>>\n");
    printf("---------------------------\n");
    printf("10. Отобразить меню команд\n");
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
            print_array(arr, size, false);
            break;
        case 3:
            shaker_sort(arr, size, &comp_count, &swap_count);
            printf("Шейкерная сортировка:\n");
            print_array(arr, size, false);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 4:
            selection_sort(arr, size, &comp_count, &swap_count);
            printf("Сортировка выбором:\n");
            print_array(arr, size, false);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 5:
            insertion_sort(arr, size, &comp_count, &swap_count, 2);
            printf("Сортировка вставками (с бин. поиском):\n");
            print_array(arr, size, false);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 6:
            counting_sort(arr, size);
            printf("Сортировка подсчётом:\n");
            print_array(arr, size, false);
            printf("Корректность - %s\n", is_sorted(arr, size));
            recover_old_array(arr, tmp_arr, size);
            break;
        case 7:
            comp_count = 0;
            swap_count = 0;
            quick_sort(arr, 0, size - 1, &comp_count, &swap_count);
            printf("Быстрая сортировка:\n");
            print_array(arr, size, false);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 8:
            comp_count = 0;
            swap_count = 0;
            merge_sort(arr, 0, size - 1, &comp_count, &swap_count);
            printf("Сортировка слиянием:\n");
            print_array(arr, size, false);
            printf("Корректность - %s, сравнений - %i, замен - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 9:
            demonstrate_all(arr, tmp_arr, size);
            break;
        case 10:
            print_menu();
            break;
        }
    }
}

void demonstrate_all(int* arr, int* tmp_arr, int size)
{
    time_t begin, end;
    int comp_count, swap_count;

    //Шейкерная
    begin = clock();
    shaker_sort(arr, size, &comp_count, &swap_count);
    end = clock();
    printf("> Шейкерная:                     t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //Выбором
    begin = clock();
    selection_sort(arr, size, &comp_count, &swap_count);
    end = clock();
    printf("> Выбором:                       t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //Вставками с лин. поиском
    begin = clock();
    insertion_sort(arr, size, &comp_count, &swap_count, 1);
    end = clock();
    printf("> Вставками 1 (с лин. поиском):  t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //Вставками с бин. поиском
    begin = clock();
    insertion_sort(arr, size, &comp_count, &swap_count, 2);
    end = clock();
    printf("> Вставками 2 (с бин. поиском):  t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //Подсчётом
    begin = clock();
    counting_sort(arr, size);
    end = clock();
    printf("> Подсчётом:                     t = %f сек., корректность - %s, сравнений - (*), замен - (*)\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size));

    //Быстрая (Quick sort)
    begin = clock();
    comp_count = 0;
    swap_count = 0;
    quick_sort(arr, 0, size - 1, &comp_count, &swap_count);
    end = clock();
    printf("> Быстрая сортировка:            t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //Сортировка слиянием (Merge sort)
    begin = clock();
    comp_count = 0;
    swap_count = 0;
    merge_sort(arr, 0, size - 1, &comp_count, &swap_count);
    end = clock();
    printf("> Слиянием:                      t = %f сек., корректность - %s, сравнений - %i, замен - %i\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);
}