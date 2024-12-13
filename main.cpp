#include <iostream>
#include "BoardGame_Classes.h"
#include "allgames.h"
using namespace std;

void game6_menu() {
    char choice;
    Player<char>* players[2];
    game6_board<char>* B = new game6_board<char>();
    string playerXName, player2Name;
    cout << "Welcome to 3x3 misere tic tac toe :)\n";
    cout << "Try to avoid normal win " << endl; 
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while(true){
        cin >> choice;
        if(choice == '1'){
            players[0] = new game6_player<char>(playerXName, 'X');
            break;
        }    
        else if(choice == '2'){
            players[0] = new game6_random_player<char>('X');
            break;
        }
        else {
            cout << "Invalid choice for Player 1.\n";
        }
    }
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while(true){
        cin >> choice;
        if(choice == '1'){
            players[1] = new game6_player<char>(player2Name, 'O');
            break;
        }    
        else if(choice == '2'){
            players[1] = new game6_random_player<char>('O');
            break;
        }
        else {
            cout << "Invalid choice for Player 2.\n";
        }
    }
    GameManager<char> game6_mang(B, players);
    game6_mang.run();
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}

void game7_menu(){
    char choice;
    Player<char>* players[2];
    game7_board<char>* B = new game7_board<char>();
    string playerXName, player2Name;
    cout << "Welcome to 4x4 tic tac toe :)\n";
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while(true){
        cin >> choice;
        if(choice == '1'){
            players[0] = new game7_player<char>(playerXName, 'X');
            break;
        }    
        else if(choice == '2'){
            players[0] = new game7_random_player<char>('X');
            break;
        }
        else {
            cout << "Invalid choice for Player 1.\n";
        }
    }
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while(true){
        cin >> choice;
        if(choice == '1'){
            players[1] = new game7_player<char>(player2Name, 'O');
            break;
        }    
        else if(choice == '2'){
            players[1] = new game7_random_player<char>('O');
            break;
        }
        else {
            cout << "Invalid choice for Player 2.\n";
        }
    }
    GameManager<char> game7_mang(B, players);
    game7_mang.run();
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
void game3_menu(){
    char choice;
    Player<char>* players[2];
    game3_board<char>* B = new game3_board<char>();
    string playerXName, player2Name;
    cout << "Welcome to 5x5 tic tac toe :)\n";
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while(true){
        cin >> choice;
        if(choice == '1'){
            players[0] = new game3_player<char>(playerXName, 'X');
            break;
        }    
        else if(choice == '2'){
            players[0] = new game3_random_player<char>('X');
            break;
        }
        else {
            cout << "Invalid choice for Player 1.\n";
        }
    }
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while(true){
        cin >> choice;
        if(choice == '1'){
            players[1] = new game3_player<char>(player2Name, 'O');
            break;
        }    
        else if(choice == '2'){
            players[1] = new game3_random_player<char>('O');
            break;
        }
        else {
            cout << "Invalid choice for Player 2.\n";
        }
    }
    GameManager<char> game3_mang(B, players);
    game3_mang.run();
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }

}
void game1_menu(){
    char choice;
    Player<char>* players[2];
    game1_board<char>* B = new game1_board<char>();
    string playerXName, player2Name;
    cout << "Welcome to triangle tic tac toe :)\n";
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while(true){
        cin >> choice;
        if(choice == '1'){
            players[0] = new game1_player<char>(playerXName, 'X');
            break;
        }    
        else if(choice == '2'){
            players[0] = new game1_random_player<char>('X');
            break;
        }
        else {
            cout << "Invalid choice for Player 1.\n";
        }
    }
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while(true){
        cin >> choice;
        if(choice == '1'){
            players[1] = new game1_player<char>(player2Name, 'O');
            break;
        }    
        else if(choice == '2'){
            players[1] = new game1_random_player<char>('O');
            break;
        }
        else {
            cout << "Invalid choice for Player 2.\n";
        }
    }
    GameManager<char> game1_mang(B, players);
    game1_mang.run();
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
void game4_menu(){
    char choice;
    Player<char>* players[2];
    game4_board<char>* B = new game4_board<char>();
    string playerXName, player2Name;
    cout << "Welcome to word tic tac toe :)\n";
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while(true){
        cin >> choice;
        if(choice == '1'){
            players[0] = new game4_player<char>(playerXName, 'X');
            break;
        }    
        else if(choice == '2'){
            players[0] = new game4_random_player<char>('X');
            break;
        }
        else {
            cout << "Invalid choice for Player 1.\n";
        }
    }
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while(true){
        cin >> choice;
        if(choice == '1'){
            players[1] = new game4_player<char>(player2Name, 'O');
            break;
        }    
        else if(choice == '2'){
            players[1] = new game4_random_player<char>('O');
            break;
        }
        else {
            cout << "Invalid choice for Player 2.\n";
        }
    }
    GameManager<char> game4_mang(B, players);
    game4_mang.run();
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
void game8_menu(){
    char choice;
    Player<char>* players[2];
    game8_board<char>* B = new game8_board<char>();
    string playerXName, player2Name;
    cout << "Welcome to ultimate tic tac toe :)\n";
    cout << "Enter Player X name: ";
    cin >> playerXName;
    cout << "Choose Player X type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while(true){
        cin >> choice;
        if(choice == '1'){
            players[0] = new game8_player<char>(playerXName, 'X');
            break;
        }    
        else if(choice == '2'){
            players[0] = new game8_random_player<char>('X');
            break;
        }
        else {
            cout << "Invalid choice for Player 1.\n";
        }
    }
    cout << "Enter Player 2 name: ";
    cin >> player2Name;
    cout << "Choose Player 2 type:\n";
    cout << "1. Human\n";
    cout << "2. Random Computer\n";
    while(true){
        cin >> choice;
        if(choice == '1'){
            players[1] = new game8_player<char>(player2Name, 'O');
            break;
        }    
        else if(choice == '2'){
            players[1] = new game8_random_player<char>('O');
            break;
        }
        else {
            cout << "Invalid choice for Player 2.\n";
        }
    }
    GameManager<char> game8_mang(B, players);
    game8_mang.run();
    delete B;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
}
void Larg_menu(){
    char choice ;
    cout << "\nWellcome to game club :) " <<endl; 
    while (true) {
        cout << "\nChoose the game U want to play :) " << endl; 
        cout << "1- Game 1 triangle X-O tic tac toe " << endl; 
        cout << "2- Game 3 5x5 tic tac toe " << endl; 
        cout << "3- Game 4 word tic tac toe " << endl; 
        cout << "4- Game 6 misere 3x3 tic tac toe " << endl; 
        cout << "5- Game 7 4x4 tic tac toe " << endl; 
        cout << "6- Game 8 ultimate tic tac toe " << endl; 
        cout << "else- Exit program " << endl;  
        cout << "-> " ;
        cin >> choice ;
        if (choice == '1') {
            game1_menu() ;
        }
        else if(choice == '2'){
            game3_menu();
        }
        else if (choice == '3'){
            game4_menu() ;
        }
        else if(choice == '4'){
            game6_menu();
        }
        else if(choice == '5'){
            game7_menu();
        }
        else if(choice == '6'){
            game8_menu();
        }
        else {
        cout << "Exit program !" << endl; 
        break ;
        }
    }
}
int main() {
    Larg_menu() ;
    return 0;
}
