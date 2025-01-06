#include <iostream>
#include "list.cpp"

using namespace std;

void test_length() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  insert_first(L, 3);
  cout << "Test length: " << (length(L) == 3 ? "Passed" : "Failed") << endl;
  delete_list(L);
}

void test_insert_first() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  insert_first(L, 3);
  cout << "Test insert_first: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

void test_insert_last() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_last(L, 2);
  insert_last(L, 3);
  cout << "Test insert_last: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

void test_insert_order() {
  nodo *L = NULL;
  insert_order(L, 3);
  insert_order(L, 1);
  insert_order(L, 2);
  cout << "Test insert_order: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

void test_remove_first() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  remove_first(L);
  cout << "Test remove_first: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

void test_remove_last() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  remove_last(L);
  cout << "Test remove_last: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

void test_remove_element_index() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  insert_first(L, 3);
  remove_element_index(L, 1);
  cout << "Test remove_element_index: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

void test_remove_element() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  insert_first(L, 1);
  remove_element(L, 1);
  cout << "Test remove_element: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

void test_reverse() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  insert_first(L, 3);
  reverse(L);
  cout << "Test reverse: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

void test_get_n() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  insert_first(L, 3);
  cout << "Test get_n: " << (get_n(L, 1) == 2 ? "Passed" : "Failed") << endl;
  delete_list(L);
}

void test_left_shift() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  insert_first(L, 3);
  left_shift(L);
  cout << "Test left_shift: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

void test_right_shift() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  insert_first(L, 3);
  right_shift(L);
  cout << "Test right_shift: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

void test_prec() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  insert_first(L, 3);
  nodo *x = L->next;
  cout << "Test prec: " << (prec(L, x) == L ? "Passed" : "Failed") << endl;
  delete_list(L);
}

void test_concat_se_ricorsiva() {
  nodo *L1 = NULL;
  insert_first(L1, 1);
  insert_first(L1, 2);
  nodo *L2 = NULL;
  insert_first(L2, 3);
  insert_first(L2, 4);
  nodo *L3 = concat_se_ricorsiva(L1, L2);
  cout << "Test concat_se_ricorsiva: ";
  stampa(L3);
  cout << endl;
  delete_list(L3);
}

void test_copy_seq() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  nodo *L_copy = copy_seq(L);
  cout << "Test copy_seq: ";
  stampa(L_copy);
  cout << endl;
  delete_list(L);
  delete_list(L_copy);
}

void test_occorrenze() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  insert_first(L, 1);
  cout << "Test occorrenze: " << (occorrenze(L, 1) == 2 ? "Passed" : "Failed") << endl;
  delete_list(L);
}

void test_remove_duplicates() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 1);
  insert_first(L, 2);
  remove_duplicates(L);
  cout << "Test remove_duplicates: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

void test_remove_at() {
  nodo *L = NULL;
  insert_first(L, 1);
  insert_first(L, 2);
  insert_first(L, 3);
  remove_at(L, 1);
  cout << "Test remove_at: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

void test_insert_at() {
  nodo *L = nullptr;
  insert_first(L, 1);
  insert_first(L, 2);
  insert_at(L, 3, 1);
  cout << "Test insert_at: ";
  stampa(L);
  cout << endl;
  delete_list(L);
}

int main() {
  test_length();
  test_insert_first();
  test_insert_last();
  test_insert_order();
  test_remove_first();
  test_remove_last();
  test_remove_element_index();
  test_remove_element();
  test_reverse();
  test_get_n();
  test_left_shift();
  test_right_shift();
  test_prec();
  test_concat_se_ricorsiva();
  test_copy_seq();
  test_occorrenze();
  test_remove_duplicates();
  test_remove_at();
  test_insert_at();
  return 0;
}