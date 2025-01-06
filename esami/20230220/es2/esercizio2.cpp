#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAXVALUE 100
#define MAXSIZE 100

// NON MODIFICARE IL CODICE SOTTO FINO A "NON MODIFICARE IL CODICE SOPRA"
struct list {
  int info;
  list * next;
};

struct tree {
  int info;
  tree * left;
  tree * right;
};

void insert(tree * & result, const int num) {
		if (result == NULL) {
				result = new tree;
				*result = {num, NULL, NULL};
		} else if (result->info > num) {
				insert(result->left, num);
		} else {
				insert(result->right, num);
		}
}

tree * crea_tree(const int num) {
		tree * result = NULL;
		for(int i = 0; i < num; i++) {
				insert(result, rand()%MAXVALUE);
		}
		return result;
}

void print_tree(const tree * root){
		if (root != NULL) {
				print_tree(root->right);
				std::cout << " " << root->info;
				print_tree(root->left);
  }
}

void delete_tree(tree * & root) {
  if (root != NULL) {
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    root = NULL;
  }
}

void print_array(const int l[], const int l_size) {
  for(int i = 0; i < l_size; i++)
    std::cout << " " << l[i];
  std::cout << std::endl;
}

// NON MODIFICARE IL CODICE SOPRA

// Add hereafter the declaration of estrai
void estrai(const tree * t, int * & l1, int & l1_size, int * & l2, int & l2_size);
// Add here above the declaration of estrai

// NON MODIFICARE IL MAIN
int main(int argc, char ** argv) {
  srand(unsigned(time(0)));
		//
		// Commentare la linea seguente per avere comportamento
		// non-deterministico
		//
		srand(0);
		tree * root = crea_tree(rand()%MAXSIZE);
		std::cout << "Initial tree content: ";
		print_tree(root); std::cout << std::endl;
  int * l1;
  int l1_size;
  int * l2;
  int l2_size;
  estrai(root, l1, l1_size, l2, l2_size);
  delete_tree(root);
		std::cout << "L1 =";
  print_array(l1, l1_size);
		std::cout << "L2 =";
  print_array(l2, l2_size);
  delete [] l1;
  delete [] l2;
}
// NON MODIFICARE IL MAIN

// Add hereafter the definition of estrai
void n_dispari(const tree * t, int &size) {
	if(t == NULL) {
		return;
	}
	int v = t->info;
	if(v%2 != 0) {
		size++;
	}
	n_dispari(t->left, size);
	n_dispari(t->right, size);
}
void n_pari(const tree * t, int &size) {
	if(t == NULL) {
		return;
	}
	int v = t->info;
	if(v%2 == 0) {
		size++;
	}
	n_pari(t->left, size);
	n_pari(t->right, size);
}
void estrai_aux_1(const tree * t, int * & l1, int &index) {
	if(t == NULL) {
		return;
	}
	estrai_aux_1(t->left, l1, index);
	int v = t->info;
	if(v%2 == 0) {
		l1[index] = v;
		index++;
	}
	estrai_aux_1(t->right, l1, index);
}
void estrai_aux_2(const tree * t, int * & l2, int &index) {
	if(t == NULL) {
		return;
	}
	estrai_aux_2(t->left, l2, index);
	int v = t->info;
	if(v%2 != 0) {
		l2[index] = v;
		index++;
	}
	estrai_aux_2(t->right, l2, index);
}
void estrai(const tree * t, int * & l1, int & l1_size, int * & l2, int & l2_size) {
	l1_size = 0;
	l2_size = 0;
	n_pari(t, l1_size);
	n_dispari(t, l2_size);
	l1 = new int[l1_size];
	l2 = new int[l2_size];
	int index1 = 0;
	int index2 = 0;
	estrai_aux_1(t, l1, index1);
	estrai_aux_2(t, l2, index2);
}
// Add here above the definition of estrai
