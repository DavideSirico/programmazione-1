#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
/*
1) Aggiungere al programma persona/persona2/persona3 una funzionalita'
   che legga la lista iniziale di persone da file, e che poi salvi su
   file.
*/

const int NmaxPers = 1000;
const int NmaxNome = 30;
const int NmaxCognome = 30;

struct address {
  char via[NmaxNome];
  int civico;
  char comune[NmaxNome];
  int cap;
  char prov[3];
};

struct persona {
  char nome[NmaxNome];
  char cognome[NmaxCognome];
  address indirizzo;
};

struct gruppo {
  int npers;
  persona persone [NmaxPers];
};

// elementi base
void leggi_indirizzo (address &a);
void stampa_indirizzo (const address & a);
void leggi_nome (char s[]);
void stampa_nome (const char s[]);
void leggi_cognome (char s[]);
void stampa_cognome (const char s[]);

// persona
void stampa_persona(const persona & p);
void leggi_persona(persona & p);

// gruppo di persone
void salva(gruppo &g, fstream &out);
void inizializza_gruppo(gruppo &g, fstream &in);
bool inserisci_persona(const persona & p, gruppo & g);
bool leggieinserisci_persona(gruppo & g);
void stampa_gruppo(const gruppo & g);

void swap (persona &p1, persona &p2);
void ordina_per_cognome(gruppo & g);
int cerca_per_cognome(char cognome[],gruppo & g);
int cerca_per_cognome1(char cognome[],persona *p,int inizio,int fine);


int main ()
{
  int pos;
  char cognome[NmaxCognome];
  gruppo comune;
  char s[2];

  fstream in;
  fstream out;
  in.open("data.txt", ios::in);
  
  inizializza_gruppo(comune, in);
  in.close();
  out.open("data.txt", ios::out);
  do {
    cout << endl;
    cout << " i: inserisci\n";
    cout << " s: stampa\n";
    cout << " c: cerca per cognome\n";
    cout << " e: esci\n";
    cout << "\nLeggi Scelta: ";
    cin >> s;

    switch (s[0]) {
    case 'i': if (! leggieinserisci_persona(comune))
	cout << "Gruppo pieno\n";
      break;
    case 's': stampa_gruppo(comune); break;
    case 'c': leggi_cognome(cognome);
      pos=cerca_per_cognome(cognome,comune);
      if (pos==-1)
        cout << "Non trovato\n";
      else {
        cout << "Trovato in posizione " << pos+1 << endl;
        stampa_persona(comune.persone[pos]);
      }
      break;
    case 'e':
      salva(comune, out);
      break;
    default: cout << "scelta non capita\n";
    }
  }
  while ((s[0]=='i' || s[0]=='s' || s[0]=='o' || s[0]=='c'));
  out.close();
}


//  FUNZIONI
void salva(gruppo &g, fstream &out) {
  out << g.npers << endl;
  for(int i = 0; i < g.npers; i++) {
    persona p = g.persone[i];
    out << p.nome << " " << p.cognome << " ";
    address indirizzo = p.indirizzo;
    out << " " << indirizzo.via << " " << indirizzo.civico << " " << indirizzo.comune << " " << indirizzo.cap << " " << indirizzo.prov << endl;
  }
}
void leggi_indirizzo (address &a)
{
  cout << "\n Inserisci via: ";
  cin >> a.via;
  cout << "\n Inserisci civico: ";
  cin >> a.civico;
  cout << "\n Inserisci comune: ";
  cin >> a.comune;
  cout << "\n Inserisci cap: ";
  cin >> a.cap;
  cout << "\n Inserisci prov: ";
  cin >> a.prov;
}

void stampa_indirizzo (const address & a)
{
  cout << "Via: " << a.via << endl;
  cout << "Civico: " << a.civico << endl;
  cout << "Comune: " << a.comune << endl;
  cout << "cap: " << a.cap << endl;
  cout << "prov: " << a.prov << endl;
  cout << endl;
}

void leggi_nome (char s[])
{
  cout << "\n Inserisci nome: ";
  cin >> s;
}

void stampa_nome (const char s[])
{
  cout << "nome: " << s << endl;
}

void leggi_cognome (char s[])
{
  cout << "\n Inserisci cognome: ";
  cin >> s;
}

void stampa_cognome (const char s[])
{
  cout << "cognome: " << s << endl;
}

//-------------------------------------------

void leggi_persona(persona & p)
{
  leggi_nome(p.nome);
  leggi_cognome(p.cognome);
  leggi_indirizzo(p.indirizzo);
}

void stampa_persona(const persona & p)
{
  stampa_nome(p.nome);
  stampa_cognome(p.cognome);
  stampa_indirizzo(p.indirizzo);
}

//--------------------- gruppo

void inizializza_gruppo(gruppo &g, fstream &in)
{
  int n_persone;
  in >> n_persone;
  g.npers = 0;
  for(int i = 0; i < n_persone; i++) {
    persona *p = new persona;
    in >> p->nome >> p->cognome;
    address *indirizzo = new address;
    in >> indirizzo->via >> indirizzo->civico >> indirizzo->comune >> indirizzo->cap >> indirizzo->prov;
    p->indirizzo = *indirizzo;
    inserisci_persona(*p,g);
  }
}

bool inserisci_persona(const persona & p, gruppo & g)
{
  bool res = true;
  if (g.npers==NmaxPers)
    res = false;
  else {
    g.persone[g.npers]=p;
    g.npers++;
    ordina_per_cognome(g);
  }
  return res;
}

bool leggieinserisci_persona(gruppo & g)
{
  persona p;
  leggi_persona(p);
  return inserisci_persona(p,g);
}

void stampa_gruppo(const gruppo & g)
{
  for   (int i=0; i < g.npers; i++) {
    cout << "\n\nDati della persona num. " << i+1 << endl;
    stampa_persona(g.persone[i]);
  }
}

void swap (persona &p1, persona &p2)
{
  persona temp;
  temp=p1; p1=p2; p2=temp;
}

//procedura di bubble sort, per cognome
void ordina_per_cognome(gruppo & g)
{
  int i, j;

  for (i=g.npers-1; i > 0; i--)
    for (j=0; j< i; j++)
      if (strcmp(g.persone[j].cognome,g.persone[j+1].cognome)> 0)
        swap(g.persone[j],g.persone[j+1]);
}

//procedura di ricerca dicotomica, per cognome
int cerca_per_cognome(char cognome[],gruppo & g)
{
  return cerca_per_cognome1(cognome,g.persone,0,g.npers-1);
}

int cerca_per_cognome1(char cognome[],persona *p,int inizio,int fine)
{
  int pivot,cmp,res;
  if (inizio > fine)
    res = -1;
  else {
    pivot = (inizio+fine)/2;
    cmp =  strcmp(p[pivot].cognome,cognome);
    if (cmp==0)
      res = pivot;
    else if (cmp>0)
      res = cerca_per_cognome1(cognome,p,inizio,pivot-1);
    else
      res = cerca_per_cognome1(cognome,p,pivot+1,fine);
  }
  return res;
}
