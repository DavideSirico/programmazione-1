#include <iostream>
#include <cstdlib>
using namespace std;


int str_len(char *str);
int occorrenze(char *str, char c);
void sort(int Array[], int From, int To);
void reverse(int *arr, int n);
void left_shift(int *a, int distance, int index, int dim);
void right_shift(int *arr, int distance, int index, int dim);
void merge(int *arr1, int n1, int *arr2, int n2);
int char_to_int(char *str, int n);
char* int_to_char(int n);
char* int_to_char(int n[], int dim);
char* str_cpy(char *dest, char *src);
// TODO: TESTARE
int bin_to_dec(int n);
int* bin_to_dec(int n[], int dim);
int dec_to_bin(int n);
int* dec_to_bin(int n[], int dim);
int main() {
    int arr1[] = {1, 3, 5, 7, 9};
    char *str = int_to_char(arr1,5);
    cout << str << endl;
    return 0;
}

int str_len(char *str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + str_len(str + 1);
}

int occorrenze(char *str, char c) {
    if (*str == '\0') {
        return 0;
    }
    if (*str == c) {
        return 1 + occorrenze(str + 1, c);
    }
    return occorrenze(str + 1, c);
}

int SmallestIndex(int Array[], int From, int To) {
  if (From == To-1)
    return From; // Single element left

  // Index of the smallest in the rest
  int Index= SmallestIndex(Array, From + 1, To);

  // Index of the smallest
  return Array[From] < Array[Index] ? From : Index;
}

void sort(int Array[], int From, int To) {
  if (From == To-1)
    return; // Single element left

  // Locate the smallest element
  int Index= SmallestIndex(Array, From, To);

  // Swap it to the first place
  int Swap= Array[Index]; Array[Index]= Array[From]; Array[From]= Swap;

  // Sort the rest
  sort(Array, From + 1, To);
}

void reverse(int *arr, int n) {
    if (n == 0) {
        return;
    }
    int temp = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = temp;
    reverse(arr + 1, n - 2);
}

void left_shift(int *a, int distance, int index, int dim) {
    if (index >= dim) {
        return;
    }
    int temp_index = (index + distance) % dim;
    int temp = a[temp_index];
    left_shift(a, distance, index + 1, dim);
    a[index] = temp;
}

void right_shift(int *arr, int distance, int index, int dim) {
    if (index >= dim) {
        return;
    }
    int temp_index = (index - distance + dim) % dim;
    int temp = arr[temp_index];
    right_shift(arr, distance, index + 1, dim);
    arr[index] = temp;
}

// recursive merge of 2 sorted arrays
void merge(int *arr1, int n1, int *arr2, int n2) {
    if (n1 == 0) {
        return;
    }
    if (n2 == 0) {
        return;
    }
    if (arr1[0] < arr2[0]) {
        cout << arr1[0] << " ";
        merge(arr1 + 1, n1 - 1, arr2, n2);
    } else {
        cout << arr2[0] << " ";
        merge(arr1, n1, arr2 + 1, n2 - 1);
    }
}

int char_to_int(char *str, int n) {
    if (n == 0) {
        return 0;
    }
    return (str[n - 1] - '0') + 10 * char_to_int(str, n - 1);
}

char* int_to_char(int n) {
    if (n == 0) {
        char *str = new char[1];
        str[0] = '\0';
        return str;
    }
    char *str = int_to_char(n / 10);
    int len = str_len(str);
    
    char *str2 = new char[len + 2];
    str2 = str_cpy(str2, str);
    delete[] str;
    str2[len] = (n % 10) + '0';
    str2[len + 1] = '\0';
    return str2;
}

char * int_to_char(int n[], int dim) {
    if (dim == 0) {
        char *str = new char[1];
        str[0] = '\0';
        return str;
    }
    char *str = int_to_char(n, dim - 1);
    int len = str_len(str);
    char *str2 = new char[len + 2];
    str2 = str_cpy(str2, str);
    delete[] str;
    str2[len] = n[dim - 1] + '0';
    str2[len + 1] = '\0';
    return str2;
}

char* str_cpy(char *dest, char *src) {
    *dest = *src; 
 
    if (*src == '\0')  
        return dest;
 
    str_cpy((dest+1), (src+1)); 
    return dest;
}

int bin_to_dec(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + 2 * bin_to_dec(n / 10);
}
int* bin_to_dec(int n[], int dim) {
    if (dim == 0) {
        int *arr = new int[1];
        arr[0] = 0;
        return arr;
    }
    int *arr = bin_to_dec(n, dim - 1);
    int *arr2 = new int[dim + 1];
    for (int i = 0; i < dim; i++) {
        arr2[i] = arr[i];
    }
    arr2[dim] = bin_to_dec(n[dim - 1]);
    delete[] arr;
    return arr2;
}

int dec_to_bin(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 2) + 10 * dec_to_bin(n / 2);
}
int* dec_to_bin(int n[], int dim) {
    if (dim == 0) {
        int *arr = new int[1];
        arr[0] = 0;
        return arr;
    }
    int *arr = dec_to_bin(n, dim - 1);
    int *arr2 = new int[dim + 1];
    for (int i = 0; i < dim; i++) {
        arr2[i] = arr[i];
    }
    arr2[dim] = dec_to_bin(n[dim - 1]);
    delete[] arr;
    return arr2;
}