#include <iostream>
#include <cassert>
#include <cstring>
#include "recursive.cpp"
using namespace std;
void test_str_len() {
    char str1[] = "hello";
    char str2[] = "";
    assert(str_len(str1) == 5);
    assert(str_len(str2) == 0);
}

void test_occorrenze() {
    char str1[] = "hello";
    assert(occorrenze(str1, 'l') == 2);
    assert(occorrenze(str1, 'z') == 0);
}

void test_sort() {
    int arr[] = {5, 3, 8, 1, 2};
    sort(arr, 0, 5);
    int sorted_arr[] = {1, 2, 3, 5, 8};
    for (int i = 0; i < 5; i++) {
        assert(arr[i] == sorted_arr[i]);
    }
}

void test_reverse() {
    int arr[] = {1, 2, 3, 4, 5};
    reverse(arr, 5);
    int reversed_arr[] = {5, 4, 3, 2, 1};
    for (int i = 0; i < 5; i++) {
        assert(arr[i] == reversed_arr[i]);
    }
}

void test_left_shift() {
    int arr[] = {1, 2, 3, 4, 5};
    left_shift(arr, 2, 0, 5);
    int shifted_arr[] = {3, 4, 5, 1, 2};
    for (int i = 0; i < 5; i++) {
        assert(arr[i] == shifted_arr[i]);
    }
}

void test_right_shift() {
    int arr[] = {1, 2, 3, 4, 5};
    right_shift(arr, 2, 0, 5);
    int shifted_arr[] = {4, 5, 1, 2, 3};
    for (int i = 0; i < 5; i++) {
        assert(arr[i] == shifted_arr[i]);
    }
}

void test_merge() {
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    merge(arr1, 3, arr2, 3);
    // Expected output: 1 2 3 4 5 6
}

void test_char_to_int() {
    char str[] = "12345";
    assert(char_to_int(str, 5) == 12345);
}

void test_int_to_char() {
    int n = 12345;
    char *str = int_to_char(n);
    assert(strcmp(str, "12345") == 0);
    delete[] str;
}

void test_int_to_char_array() {
    int arr[] = {1, 2, 3, 4, 5};
    char *str = int_to_char(arr, 5);
    assert(strcmp(str, "12345") == 0);
    delete[] str;
}

void test_str_cpy() {
    char src[] = "hello";
    char dest[6];
    str_cpy(dest, src);
    assert(strcmp(dest, "hello") == 0);
}

void test_bin_to_dec() {
    assert(bin_to_dec(101) == 5);
}

void test_bin_to_dec_array() {
    int arr[] = {1, 0, 1};
    int dec_arr = bin_to_dec(arr, 3);
    int expected = 5;
    assert(dec_arr == expected);
}

void test_dec_to_bin() {
    assert(dec_to_bin(5) == 101);
}

int main() {
    test_str_len();
    test_occorrenze();
    test_sort();
    test_reverse();
    test_left_shift();
    test_right_shift();
    test_merge();
    test_char_to_int();
    test_int_to_char();
    test_int_to_char_array();
    test_str_cpy();
    test_bin_to_dec();
    test_bin_to_dec_array();
    test_dec_to_bin();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}