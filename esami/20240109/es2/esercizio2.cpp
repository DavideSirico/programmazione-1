#include <iostream>
#include <cstdlib>

#define MAX_DIM 75

void fill_random_array(char * A, int N) {
  if (NULL != A) {
    for(int i = 0; i < N; i++) {
      A[i] = 'A' + rand()%(('A' - 'Z')+1);
    }
  }
}

void print_array(const char msg[], char * A, int N) {
  std::cout << msg;
  if (NULL != A) {
    for (int i = 0; i < N; i++) {
      std::cout << A[i];
    }
  }
  std::cout << std::endl;
}

/* Inserire qui sotto la dichiarazione della funzione conta */
void conta(char array[], int D, int i, int j, int *&res);
/* Inserire qui sopra la dichiarazione della funzione conta */

int main(int argc, char **argv) {
  unsigned int seed = (unsigned int)time(NULL);
  seed = 90000;
  // seed = 1697033220;
  if (argc > 1) {
    seed = atoi(argv[1]);
  }
  std::cout << "Seed = " << seed << std::endl;
  srand(seed);

  char A[MAX_DIM];

  fill_random_array(A, MAX_DIM);
  print_array("A[] = ", A, MAX_DIM);
  int i, j;
  i = 0; j = -1;
  while(i > j) {
    i = rand()%MAX_DIM;
    j = rand()%MAX_DIM;
  }
  int * res;
  conta(A, MAX_DIM, i, j, res);
  std::cout << "i = " << i << ", j = " << j << std::endl;
  std::cout << "A[" << i << "] = " << A[i];
  std::cout << "  A[" << j << "] = " << A[j] << std::endl;
  std::cout << "There are " << res[0] << " occurrences of the searched pattern";
  std::cout << " between indexes " << i << " and " << j
            << " (with A[" << i << "] included and A[" << j << "] excluded)" << std::endl;
  if (res[0] > 0) {
    std::cout << "They are at indexes: ";
    for(int l = 1; l < res[0]+1; l++) {
      std::cout << res[l] << " ";
    }
    std::cout << std::endl;
  }
  delete [] res;
}

/* Inserire qui sotto la definizione della funzione conta */
int lenght(char array[], int index, int dim, char pattern) {
  if(index == dim) {
    return 0;
  }
  if(array[index] == pattern) {
    return lenght(array,++index, dim, pattern)+1;
  } else {
    return lenght(array,++index, dim, pattern);
  }
}
void conta_aux(char array[], int D, int i, int j, int *&res, int index_res) {
  if(i>=j || i>=D) {
    return;
  }
  char pattern = array[j];
  if(array[i] == pattern) {
    std::cout << "sboora";
    res[index_res] = i;
    index_res++;
  }
  conta_aux(array,D,++i,j,res,index_res);
}

void conta(char array[], int D, int i, int j, int *&res) {
  int size = lenght(array,i,j,array[j]);
  *&res = new int[size+1];
  res[0] = size;
  conta_aux(array,D,i,j,res,1);
}
/* Inserire qui sotto la definizione della funzione conta */


