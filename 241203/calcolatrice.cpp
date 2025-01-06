#include <iostream>
#include <cstring>
using namespace std;

typedef struct Stack {
    double data;
    struct Stack * next;
} Stack;

struct Stack * initStack() {
    return nullptr;
}

bool isEmpty(struct Stack * s) {
    return (s == nullptr);
}

void push(struct Stack * &s, int value) {
    struct Stack * newElement = new Stack;
    newElement->data = value;
    newElement->next = s;
    s = newElement;
}

int top(struct Stack * s) {
    if (isEmpty(s)) {
        std::cerr << "top Error: stack is empty" << std::endl;
        exit(1);
    }
    return s->data;
}

int pop(struct Stack * &s) {
    if (isEmpty(s)) {
        std::cerr << "pop Error: stack is empty" << std::endl;
        exit(1);
    }
    int value = s->data;
    struct Stack * temp = s;
    s = s->next;
    delete temp;
    return value;
}

int lenght(struct Stack * s) {
    int count = 0;
    struct Stack * temp = s;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteStack(struct Stack * &s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

void printStack(struct Stack * s, const char * message = "Stack: ") {
    if (isEmpty(s)) {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << message;
        struct Stack * temp = s;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}

double performOperation(double a, double b, const char * op) {
    if (op[0] == '+') return a + b;
    if (op[0] == '-') return a - b;
    if (op[0] == '*') return a * b;
    if (op[0] == '/') {
        if (b == 0) {
            cout << "Errore: divisione per zero" << endl;
            return -1;
        } 
        return a / b;
    }
    return -1;
}

void processRPN(const char * expression) {
    struct Stack * stack = initStack();

    for(int i = 0; expression[i]!='\0'; i++) {
        if (expression[i] == ' ') {
            continue;
        }
        char token[256];
        int j = 0;
        while (expression[i] != ' ' && expression[i] != '\0') {
            token[j++] = expression[i++];
        }
        token[j] = '\0';
        
        int tokenLength = strlen(token);
        // numero con più di un carattere
        if (std::isdigit(token[0]) || (token[0] == '-' && tokenLength > 1)) {
            // Il token è un numero
            push(stack, std::stod(token));
        } else {
            double b = top(stack); pop(stack);
            double a = top(stack); pop(stack);
            push(stack, performOperation(a, b, token));
        }
    }

    cout << "Risultato: " << top(stack) << endl;
}

int main() {

    cout << "Benvenuto nella calcolatrice RPN!" << endl;
    cout << "Inserisci un'espressione in notazione polacca inversa (es. '3 4 + 2 *') o 'exit' per uscire:" << endl;
    char input[256];
    while (true) {
        cout << "> ";
        cin.getline(input, 256);
        if (strcmp(input,"exit")==0) {
            break;
        }
        processRPN(input);
    }

    return 0;
}
