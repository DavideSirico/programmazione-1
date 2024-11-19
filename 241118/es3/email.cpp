#include <iostream>
#include "email.h"
int my_strlen(char parola[255]) {
    int lenght;
    for(lenght = 0; parola[lenght] != '\0'; lenght++);
    return lenght;
}
void my_strncpy(char src[255], char dest[255], int start, int end) {
    int i;
    int index = 0;
    for(i = start; src[i] != '\0' && i < end; i++){ 
        dest[index] = src[i];
        index++;
    }
    dest[index] = '\0';
    // std::cout << dest;
}

bool is_letter(char let) {
    if((let >= 'A' && let <= 'Z') || (let >= 'a' && let <= 'z')) {
        return true;
    }
    return false;
}
bool is_number(char let) {
    if(let >= '0' && let <= '9') {
        return true;
    }
    return false;
}

bool is_only_letter_and_number(char str[255]) {
    for(int i = 0; str[i] != '\0'; i++) {
        if(!is_letter(str[i]) && !is_number(str[i]) && str[i]!='.' && str[i]!='_') {
            return false;
        }
    }
    return true;
}

bool is_email(char parola[255]) {
    int lenght = my_strlen(parola);
    int i;
    char utente[255];
    char dominio[255];
    for(i = 0; i < lenght; i++) {
        if(parola[i] == '@') {
            my_strncpy(parola, utente, 0, i);
            my_strncpy(parola, dominio, i+1, lenght);
            break;
        }
    }
    if(i == lenght) {
        return false;
    }
    if(my_strlen(utente) < 1) {
        return false;
    }
    if(my_strlen(dominio) < 1) {
        return false;
    }
    if(!is_only_letter_and_number(utente) || !is_only_letter_and_number(dominio)) {
        return false;
    }
    if(parola[0] == '.' || parola[lenght-1] =='.') {
        return false;
    }
    // std::cout << utente << "@" << dominio << std::endl;

    return true;
}