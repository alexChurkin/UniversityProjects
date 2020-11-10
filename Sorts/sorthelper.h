#pragma once

//��������������� ������� ��� ���������� ���������
//(2 ���� ������ ����� �������)
int find_insert_position_linearly(int arr[], int right, int* comp_count);
int find_insert_position_binary(int arr[], int right, int* comp_count);

//������� ��� ������ ������������ � ������������� ���������
//(��� ���������� ���������, ����� ����� ��������� ������ ������� "���������")
int get_min_index(int arr[], int size);
int get_max_index(int arr[], int size);

//��������������� ������� ��� ���������� ��������
//(������� 2-� ��������������� ������ �������)
void merge_sorted_parts(
	int arr[], int l, int c, int r,
	int* comp_count, int* swap_count);