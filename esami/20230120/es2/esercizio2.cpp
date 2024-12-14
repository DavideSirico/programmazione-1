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

void delete_list(list * &l) {
  if (l != NULL) {
    delete_list(l->next);
    delete l;
    l = NULL;
  }
}

void print_list(const list * l) {
  if (l != NULL) {
    std::cout << " " << l->info;
    print_list(l->next);
  }
  else
    std::cout << std::endl;
}

// NON MODIFICARE IL CODICE SOPRA


// Add hereafter the declaration of estrai
void estrai(const tree * t, list *&l1, list *&l2);
// Add here above the declaration of estrai

int main(int argc, char ** argv) {
  // NON MODIFICARE IL MAIN
  srand(unsigned(time(0)));
		//
		// Commentare la linea seguente per avere comportamento
		// non-deterministico
		//
		srand(0);
		tree * root = crea_tree(rand()%MAXSIZE);
		std::cout << "Initial tree content: ";
		print_tree(root); std::cout << std::endl;
  list * l1;
  list * l2;
  estrai(root, l1, l2);
  delete_tree(root);
		std::cout << "L1 =";
  print_list(l1);
		std::cout << "L2 =";
  print_list(l2);
  delete_list(l1);
  delete_list(l2);
  // NON MODIFICARE IL MAIN
}

// Add hereafter the definition of estrai
void insert_last(list * &head, int element) {
    list *temp = new list;
    temp->info = element;
    temp->next = nullptr;

    if(head == nullptr) {
        head = temp;
    } else {
        list * temp_head = head;
        while(temp_head->next!=nullptr) {
            temp_head = temp_head->next;
        }
        temp_head->next = temp;
    }
}

void estrai_aux(const tree * t, list *&l1, list *&l2) {
  if(t==NULL) {
    return;
  }
  estrai_aux(t->left, l1,l2);
  std::cout << t->info << std::endl;
  if(t->info%2 == 0) {
    insert_last(l1,t->info);
  } else {
    insert_last(l2,t->info);
  }
  estrai_aux(t->right, l1,l2);
}
void estrai(const tree * t, list *&l1, list *&l2) {
  l1 = nullptr;
  l2 = nullptr;
  estrai_aux(t,l1,l2);
}
// Add here above the definition of estrai
