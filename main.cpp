#include <iostream>
#include <string>

using namespace std;

//creazione struttura Contatto, variabile che contiene più variabili
struct Contatto {
    int numero = -1; //imposto -1 perché sennò non capisco quando contatto è presente oppure no
    string nome;
};


//dichiarazione metodi
void add(Contatto& contatto);
void del();
void edit();

int main() {
    int value, select;
    bool esec = true;
    cout << "Quante persone vuoi inserire? nella rubrica" << endl;
    cin >> value;
    Contatto* rubrica = new Contatto[value]; //creiamo un array gestendo la memoria noi

    while (esec) {
        cout << "Quale operazione vuoi eseguire?\n 0. Aggiungi contatto\n 1.Rimuovi Contatto\n 2.Modifica contatto\n 3.Ricerca numero" << endl;
        cin >> select;

        switch (select) {
        case 0:
            for (int i = 0; i < value; i++){
                if (rubrica[i].numero != -1) continue; //controllo se lo slot è occupato
                add(rubrica[i]);
                break;
            }
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        default:
            cout << "Operazione non trovata" << endl;
            esec = !esec;
            break;
        }
    }

    for (int i = 0; i < value; i++){
        if (rubrica[i].numero == -1) continue;
        cout << rubrica[i].nome << endl;
    }

    delete[] rubrica; //gestiamo noi la memoria, quindi lo eliminiamo perchè non ci serve più
    return 0;
}

void add(Contatto& contatto){
    string nome;
    int numero;

    cout << "Inserisci il numero" << endl;
    cin >> numero;

    while (cin.fail()){ //se l'utente non inserisce un intero allora do errore
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Inserisci il numero" << endl;
        cin >> numero;
    }
    
    cout << "Inserisci il nome" << endl;
    cin >> nome;

    contatto.nome = nome;
    contatto.numero = numero; //aggiorno contatto, non creo un copia con Contatto& :)
}

void del(){

}

void edit(){

}
