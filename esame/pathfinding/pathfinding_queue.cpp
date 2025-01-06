#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;
#define R 4
#define C 4

// Structure to define a vertex u=(i,j)
typedef struct Cell {
	int i;
	int j;
} Cell;

typedef struct List {
	Cell *data;
    struct List * next;
} List;

typedef struct Queue {
    List * head;
    List * tail;
} Queue;

Queue * initQueue() {
    return new Queue {nullptr, nullptr};
}

bool isEmpty(Queue * s) {
    return ((s != nullptr) && (s->head == s->tail) && (s->head == nullptr));
}

void enqueue(Queue * &s, Cell *value) {
    if (s == nullptr) {
        std::cerr << "enqueue Error: the queue is nullptr" << std::endl;
        assert(false);
        exit(1);
    }
    List * newElement = new List {value, nullptr};
    if (isEmpty(s)) {
        s->tail = s->head = newElement;
    } else {
      s->tail->next = newElement;
      s->tail = newElement;
    }
}

Cell* first(Queue * s) {
    if (isEmpty(s)) {
        std::cerr << "first Error: the queue is empty" << std::endl;
        assert(false);
        exit(1);
    }
    return s->head->data;
}

Cell* dequeue(Queue * &s) {
    if (isEmpty(s)) {
        std::cerr << "dequeue Error: queue is empty" << std::endl;
        assert(false);
        exit(1);
    }
    Cell *value = s->head->data;
    List * temp = s->head;
    if (s->head == s->tail) {
        s->head = s->tail = nullptr;
    } else {
        s->head = s->head->next;
    }
    delete temp;
    return value;
}

void deleteQueue(Queue * &s) {
    while (!isEmpty(s)) {
        Cell *cell = dequeue(s);
        delete cell;
    }
    delete s;
}


bool findPath(int M[R][C], int start_x, int start_y, int end_x, int end_y) {
	// 1) Create BFS queue q
	// queue<BFSElement> q;
	Queue *q = initQueue();

	Cell *c = new Cell;
	c->i = start_x;
	c->j = start_y;
	enqueue(q, c);
	delete c;

	// 3) run BFS algorithm with q.
	while (!isEmpty(q)) {
		Cell *x = new Cell;
		x->i = first(q)->i;
		x->j = first(q)->j;

		dequeue(q);
		int i = x->i;
		int j = x->j;
		delete x;

		// skipping cells which are not valid.
		// if outside the matrix bounds
		if (i >= 0 && i < R && j >= 0 && j < C) { 

			// if they are walls (value is 0).
			if (M[i][j] == -1)
				continue;

			// 3.1) if in the BFS algorithm process there was a
			// vertex x=(i,j) such that M[i][j] is 2 stop and
			// return true
			if (i == end_x && j == end_y)
				deleteQueue(q);
				delete q;
				return true;

			// marking as wall upon successful visitation
			M[i][j] = 0;

			// pushing to queue u=(i,j+1),u=(i,j-1)
			//				 u=(i+1,j),u=(i-1,j)
			for (int k = -1; k <= 1; k += 2) {
				Cell *t1 = new Cell;
				t1->i = i+k;
				t1->j = j;
				enqueue(q,t1);
				Cell *t2 = new Cell;
				t2->i = i;
				t2->j = j+k;
				enqueue(q,t2);
			}
		}
	}
	// BFS algorithm terminated without returning true
	// then there was no element M[i][j] which is 2, then
	// return false
	deleteQueue(q);
	delete q;
	return false;
}

// Main Driver code
int main() {

	int M[R][C] = { { -1, 0, 0, -1 },
					{ 0, -1, 0, 0 }, 
					{ 0, 0, -1, 0 }, 
					{ -1, 0, 0, 0 }}; 
    int start_x = 0;
    int start_y = 2;

    int end_x = 2;
    int end_y = 0;
    if(findPath(M, start_x, start_y, end_x, end_y)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
	return 0;
}
