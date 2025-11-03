#include <iostream>
#include <string>
#include "../include/FileReader.hpp"
#include "../include/Word.hpp"
#include "../include/WordList.hpp"
#include "../include/Dictionary.hpp"

using namespace std;

void displayMenu() {
    cout << "\n========== DICIONARIO DE INGLES ==========" << endl;
    cout << "1. Buscar palavra" << endl;
    cout << "2. Adicionar palavra" << endl;
    cout << "3. Remover palavra" << endl;
    cout << "4. Exibir percurso em ordem" << endl;
    cout << "5. Exibir percurso em largura" << endl;
    cout << "6. Mostrar quantidade de palavras" << endl;
    cout << "0. Sair" << endl;
    cout << "==========================================" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    FileReader fileReader;
    WordList wordList = fileReader.readWords("words.txt");
    
    Dictionary dictionary;
    dictionary.initializeFromWordList(wordList);
    
    int option;
    do {
        displayMenu();
        cin >> option;
        cin.ignore(); 
        
        switch(option) {
            case 1: { 
                string english;
                cout << "\nDigite a palavra em ingles: ";
                getline(cin, english);
                
                Word* result = dictionary.treeSearch(english);
                if (result != nullptr) {
                    cout << "\n--- Palavra Encontrada ---" << endl;
                    result->printWord();
                } else {
                    cout << "\nPalavra nao encontrada no dicionario." << endl;
                }
                break;
            }
            case 2: { 
                string english, portuguese, wordClass;
                
                cout << "\nDigite a palavra em ingles: ";
                getline(cin, english);
                
                cout << "Digite a traducao em portugues: ";
                getline(cin, portuguese);
                
                cout << "Digite a classe gramatical: ";
                getline(cin, wordClass);
                
                Word newWord(english, portuguese, wordClass);
                dictionary.treeInsert(newWord);
                
                cout << "\nPalavra adicionada com sucesso!" << endl;
                break;
            }
            case 3: { 
                string english;
                cout << "\nDigite a palavra em ingles a ser removida: ";
                getline(cin, english);
                
                if (dictionary.remove(english)) {
                    cout << "\nPalavra removida com sucesso!" << endl;
                } else {
                    cout << "\nPalavra não encontrada no dicionario." << endl;
                }
                break;
            }
            case 4: { 
                dictionary.printInOrder();
                break;
            }
            case 5: { 
                dictionary.printBreadthFirst();
                break;
            }
            case 6: { 
                cout << "\nO dicionario contem " << dictionary.size() 
                     << " palavras." << endl;
                break;
            }
            case 0: {
                cout << "\nEncerrando o programa..." << endl;
                break;
            }
            default:
                cout << "\nOpção invalida! Tente novamente." << endl;
        }

        if (option != 0) {
            cout << "\nPressione Enter para continuar...";
            cin.get();
        }
        
    } while (option != 0);
    
    return 0;
}

// g++ -o main.exe src/Main.cpp src/Word.cpp src/WordList.cpp src/FileReader.cpp src/Dictionary.cpp -Iinclude -std=c++11