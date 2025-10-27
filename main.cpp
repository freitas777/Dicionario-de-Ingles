#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream arq("words.txt");
    string word;
    char delimiter = ',';

    if (arq.is_open()) {
        while (getline(arq, word, delimiter)) {
            cout << word << "\n";
        }
    } else {
        cout << "Não foi possível abrir o arquivo";
    }
}
