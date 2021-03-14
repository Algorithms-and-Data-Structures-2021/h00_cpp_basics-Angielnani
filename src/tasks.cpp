#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *a, int *b)
{
    if ((a != nullptr) && (b != nullptr))
    {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
}

// Задание 2
int **allocate_2d_array(int rows, int cols, int value)
{
    if ((rows >= 1) && (cols >= 1))
    {
        int **array_2d = new int *[rows];
        for (int row_num = 0; row_num < rows; row_num++)
        {
            array_2d[row_num] = new int[cols]{};
        }
        for (int row_num = 0; row_num < rows; row_num++)
        {
            for (int cols_num = 0; cols_num < cols; cols_num++ )
            {
                array_2d[row_num][cols_num] = value;
            }
        }
        return array_2d;
    }
    else
        {
            return nullptr;
        }
}

// Задание 3
bool copy_2d_array(int **src, int **dst, int rows, int cols)
{
    if ((src == nullptr) || (dst == nullptr) || (rows <= 0) || (cols <= 0))
    {
        return false;
    }
    else
        {
            for (int row_num = 0; row_num < rows; row_num++)
            {
                copy(src[row_num],src[row_num]+ cols, dst[row_num]);
            }
        }
    return true;
}

// Задание 4
void reverse_1d_array(vector<int> &arr)
{
    int size = arr.size();
    for (int elem = 0; elem < size; elem++)
    {
        if (elem >= size - elem - 1)
        {
            break;
        }
        arr[elem] = arr[elem] + arr[size - elem - 1];
        arr[size - elem - 1] = arr[elem] - arr[size - elem - 1];
        arr[elem] = arr[elem] - arr[size - elem - 1];
    }
}

// Задание 5
void reverse_1d_array(int *begin, int *end)
{
    if ((begin != nullptr) || (end != nullptr))
    {
        for (int *i = begin; i <= end; i++ )
        {
            int n = *i;
            int elem = (i - begin);
            if (i >= end - elem)
            {
                break;
            }
            *i = *(end - elem);
            *(end - elem) = n;
        }
    }
}

// Задание 6
int *find_max_element(int *arr, int size)
{
    if ((arr == nullptr) || (size <= 0))
    {
        return nullptr;
    }
    else
        {
        int *maxi = arr;
        for (int *elem = arr; elem < arr + size ; elem++)
        {
            if (*elem > *maxi)
            {
                maxi = elem;
            }
        }
        return maxi;
    }
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr)
{
    vector<int> odd_arr;
    for (int number:arr)
    {
        if ((number % 2) != 0)
        {
            odd_arr.push_back(number);
        }
    }
    return odd_arr;
}

// Задание 8
vector<int> find_common_elements(vector<int> &a, vector<int> &b)
{
    vector<int> comm_arr;
    vector<int> b_copy = b;
    for (int elem : a)
    {
        for (int i = 0; i < b_copy.size(); i++)
        {
            if (elem == b_copy[i])
            {
                comm_arr.push_back(elem);
                b_copy[i] = b_copy.back();
                b_copy.pop_back();
                break;
            }
        }
    }
    return comm_arr;
}