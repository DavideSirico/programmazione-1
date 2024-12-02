#include <iostream>
using namespace std;

void esagonale(int *array, int dim);
void esagonale_ric(int *array, int dim, int index);
void visualizza(int *array, int dim);
void visualizza_ric(int *array, int dim, int index);
int get_input();
int main() {

    int N = get_input();
    int *array = new int[N];

    esagonale(array, N);
    visualizza(array, N);
    cout << endl;
    delete array;
    return 0;
}

int get_input() {
    int n;
    cin >> n;
    if(n<0) {
        return get_input();
    }
    return n;
}

void esagonale(int *array, int dim) {
    esagonale_ric(array, dim, 0);
}
void esagonale_ric(int *array, int dim, int index) {
    if(index<dim) {
        array[index] = (index)*((index*2)-1);
        esagonale_ric(array, dim, index+1);
    }
}


void visualizza(int *array, int dim) {
    visualizza_ric(array,dim,0);
}
void visualizza_ric(int *array, int dim, int index) {
    if(index<dim) {
        cout << array[index] << " ";
        visualizza_ric(array,dim,index+1);
    }
}
