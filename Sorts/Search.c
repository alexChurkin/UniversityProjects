
int find_insert_position_linearly(int arr[], int right, int* comp_count)
{
    int j, pos = right;
    for (j = 0; j < right; j++)
    {
        (*comp_count)++;
        if (arr[right] <= arr[j])
        {
            pos = j;
            break;
        }
    }
    return pos;
}

int find_insert_position_binary(int arr[], int right, int* comp_count)
{
    int l = 0, r = right - 1, c;
    while (l <= r)
    {
        c = (l + r) / 2;
        (*comp_count)++;
        if (arr[right] < arr[c])
            r = c - 1;
        else
            l = c + 1;
    }
    return r + 1;
}