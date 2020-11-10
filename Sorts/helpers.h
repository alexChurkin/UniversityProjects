#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

char* is_sorted(int arr[], int size);

void print_menu();
int* get_array(int* newsize);
int* create_empty_array(int size);
int* array_copy(int arr[], int size);
void populate_array(int arr[], int size);
void print_array(int arr[], int size, bool not_big);
void recover_old_array(int* arr, int* tmp_arr, int size);
void swap(int* a, int* b);
int get_min_index(int arr[], int size);
int get_max_index(int arr[], int size);
void merge_sorted_parts(int arr[], int l, int c, int r, int* comp_count, int* swap_count);
float t_diff(time_t begin, time_t end);