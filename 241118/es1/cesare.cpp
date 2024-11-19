void decrypt(char parola [], int chiave) {
    for(int i = 0; parola[i] != '\0'; i++) {
        char lettera = parola[i];
        if(lettera != ' ') {
            int pos_lettera = lettera - 'a';
            if (pos_lettera-chiave<0) {
                pos_lettera = pos_lettera - chiave + 26; 
            } else {
                pos_lettera = (pos_lettera-chiave)%26;
            }
            lettera = (char)pos_lettera + 'a';        }
        parola[i] = lettera;
    }
}
void crypt(char parola [], int chiave) {
    for(int i = 0; parola[i] != '\0'; i++) {
        char lettera = parola[i];
        if(lettera != ' ') {
            int pos_lettera = lettera - 'a';
            pos_lettera = (pos_lettera+chiave)%26;
            lettera = (char)pos_lettera + 'a';
        }
        parola[i] = lettera;

    }
}