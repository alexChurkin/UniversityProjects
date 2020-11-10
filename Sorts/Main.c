#include "sort.h"
#include "helpers.h"

void demonstrate_all(int* arr, int* tmp_arr, int size);

void print_menu()
{
    printf("��������� �������:\n");
    printf("---------------------------\n");
    printf("1. �������/����������� ������\n");
    printf("2. ���������� ������� ������\n");
    printf("3. <���������� ��������� ����������>\n");
    printf("4. <���������� ���������� �������>\n");
    printf("5. <���������� ���������� ���������>\n");
    printf("6. <���������� ���������� ���������>\n");
    printf("7. <���������� ������� ����������>\n");
    printf("8. <���������� ���������� ��������>\n");
    printf("9. <<<�������� �������� ���� ��������� ����������>>>\n");
    printf("---------------------------\n");
    printf("10. ���������� ���� ������\n");
    printf("0. ��������� ���������\n");
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
            printf("\n���������� ���������.");
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
            printf("��������� ����������:\n");
            print_array(arr, size, false);
            printf("������������ - %s, ��������� - %i, ����� - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 4:
            selection_sort(arr, size, &comp_count, &swap_count);
            printf("���������� �������:\n");
            print_array(arr, size, false);
            printf("������������ - %s, ��������� - %i, ����� - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 5:
            insertion_sort(arr, size, &comp_count, &swap_count, 2);
            printf("���������� ��������� (� ���. �������):\n");
            print_array(arr, size, false);
            printf("������������ - %s, ��������� - %i, ����� - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 6:
            counting_sort(arr, size);
            printf("���������� ���������:\n");
            print_array(arr, size, false);
            printf("������������ - %s\n", is_sorted(arr, size));
            recover_old_array(arr, tmp_arr, size);
            break;
        case 7:
            comp_count = 0;
            swap_count = 0;
            quick_sort(arr, 0, size - 1, &comp_count, &swap_count);
            printf("������� ����������:\n");
            print_array(arr, size, false);
            printf("������������ - %s, ��������� - %i, ����� - %i\n",
                is_sorted(arr, size), comp_count, swap_count);
            recover_old_array(arr, tmp_arr, size);
            break;
        case 8:
            comp_count = 0;
            swap_count = 0;
            merge_sort(arr, 0, size - 1, &comp_count, &swap_count);
            printf("���������� ��������:\n");
            print_array(arr, size, false);
            printf("������������ - %s, ��������� - %i, ����� - %i\n",
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

    //���������
    begin = clock();
    shaker_sort(arr, size, &comp_count, &swap_count);
    end = clock();
    printf("> ���������:                     t = %f ���., ������������ - %s, ��������� - %i, ����� - %i\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //�������
    begin = clock();
    selection_sort(arr, size, &comp_count, &swap_count);
    end = clock();
    printf("> �������:                       t = %f ���., ������������ - %s, ��������� - %i, ����� - %i\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //��������� � ���. �������
    begin = clock();
    insertion_sort(arr, size, &comp_count, &swap_count, 1);
    end = clock();
    printf("> ��������� 1 (� ���. �������):  t = %f ���., ������������ - %s, ��������� - %i, ����� - %i\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //��������� � ���. �������
    begin = clock();
    insertion_sort(arr, size, &comp_count, &swap_count, 2);
    end = clock();
    printf("> ��������� 2 (� ���. �������):  t = %f ���., ������������ - %s, ��������� - %i, ����� - %i\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //���������
    begin = clock();
    counting_sort(arr, size);
    end = clock();
    printf("> ���������:                     t = %f ���., ������������ - %s, ��������� - (*), ����� - (*)\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size));

    //������� (Quick sort)
    begin = clock();
    comp_count = 0;
    swap_count = 0;
    quick_sort(arr, 0, size - 1, &comp_count, &swap_count);
    end = clock();
    printf("> ������� ����������:            t = %f ���., ������������ - %s, ��������� - %i, ����� - %i\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);

    //���������� �������� (Merge sort)
    begin = clock();
    comp_count = 0;
    swap_count = 0;
    merge_sort(arr, 0, size - 1, &comp_count, &swap_count);
    end = clock();
    printf("> ��������:                      t = %f ���., ������������ - %s, ��������� - %i, ����� - %i\n",
        ((float)(end - begin) / CLOCKS_PER_SEC), is_sorted(arr, size), comp_count, swap_count);
    recover_old_array(arr, tmp_arr, size);
}