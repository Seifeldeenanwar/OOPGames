#ifndef _ALLGAMES_H
#define _ALLGAMES_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include"bits/stdc++.h"
#include <fstream>
using namespace std;

template <typename T>
class game8_board:public Board<T> {
public:
    game8_board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class game8_player : public Player<T> {
public:
    game8_player(string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class game8_random_player : public RandomPlayer<T>{
public:
    game8_random_player (T symbol);
    void getmove(int &x, int &y) ;
};

ifstream file1("dic.txt");
vector<string>words;
string word;

template <typename T>
class game4_board:public Board<T> {
public:
    game4_board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};

template <typename T>
class game4_player : public Player<T> {
public:
    game4_player(string name, T symbol);
    void getmove(int& x, int& y) ;

};

template <typename T>
class game4_random_player: public RandomPlayer<T>{
public:
    game4_random_player(T symbol);
    void getmove(int &x, int &y) ;
};

template <typename T>
class game1_board:public Board<T> {
public:
    game1_board ();
    bool update_board (int x , int y , T symbol);
    void display_board () ;
    bool is_win() ;
    bool is_draw();
    bool game_is_over();

};
template <typename T>
class game1_player : public Player<T> {
public:
    game1_player (string name, T symbol);
    void getmove(int& x, int& y) ;

};
template <typename T>
class game1_random_player : public RandomPlayer<T>{
public:
    game1_random_player (T symbol);
    void getmove(int &x, int &y) ;
};

template<typename T>
class game7_board : public Board<T> {
public:
    game7_board();
    ~game7_board();  // Destructor to clean up memory
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
    int count_mark(T mark) ;
};

template<class T>
class game7_player : public Player<T> {
public:
    game7_player(string name, T symbol);
    virtual void getmove(int& x, int& y);  // Virtual function
};

template <class T>
class game7_random_player : public RandomPlayer<T> {
public:
    game7_random_player(T symbol);
    void getmove(int& x, int& y);
};

template<class T>
class game6_board : public Board<T> {
    static bool checkX ;
    static bool checkO ;
public:
    game6_board();  // Constructor for 3x3 grid
    ~game6_board(); // Destructor to clean up memory
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};
template<typename T>
bool game6_board<T>::checkX = true;

template<typename T>
bool game6_board<T>::checkO = true;


template<class T>
class game6_player : public Player<T> {
public:
    game6_player(string name, T symbol);
    void getmove(int& x, int& y) override;
};

template<class T>
class game6_random_player : public RandomPlayer<T> {
public:
    game6_random_player(T symbol);
    void getmove(int& x, int& y);
};
template<class T>
class game3_board: public Board<T>  {
    static int countplayer1 ;
    static int countplayer2 ;
public:
    game3_board();
    ~game3_board();  // Destructor to clean up memory
    bool update_board(int x, int y, T symbol);
    void display_board();
    bool is_win();
    bool is_draw();
    bool game_is_over();
};
template<typename T>
int game3_board<T>::countplayer1 = 0;

template<typename T>
int game3_board<T>::countplayer2 = 0;

template <class T>
class game3_player: public Player<T> {
public:
    game3_player(string name, T symbol);
    virtual void getmove(int& x, int& y);  
};
template<class T>
class game3_random_player : public RandomPlayer<T> {
public:
    game3_random_player(T symbol);
    void getmove(int& x, int& y);
};


//-----------------------------------------------------implmentation---------------------------------------------------------

template <typename T>
game1_board<T>::game1_board() {
    this->rows =3, this->columns=5  ;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
   this->board[0][0]=1;this->board[0][1]=1;this->board[0][3]=1;this->board[0][4]=1;
   this->board[1][0]=1;this->board[1][4]=1;
    this->n_moves = 0;
}

template <typename T>
bool game1_board<T>::update_board(int x, int y, T mark) {
    // Only update if move is valid
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }

        return true;
    }
    return false;
}

// Display the board and the pieces on it
template <typename T>
void game1_board<T>::display_board() {
      for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            if((i==0&&j==0)||(i==0&&j==1)||(i==0&&j==3)||(i==0&&j==4)||
            (i==1&&j==0)||(i==1&&j==4)
            )
            {
                cout<<"       ";
               if(j==4)
                cout<<"|";
                continue;
            }
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] ;
            if(!((i==0&&j==2)||(i==1&&j==3)))
            cout<<"|";
        }
        cout << "\n-------------------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool game1_board<T>::is_win() {
    // Check rows and columns
  if(((this->board[0][2]==this->board[1][2]&&this->board[1][2]==this->board[2][2])&&this->board[0][2])||//column win
  (this->board[0][2]==this->board[1][1]&&this->board[1][1]==this->board[2][0]&&this->board[0][2])|| //diagonal win
  (this->board[1][1]==this->board[1][2]&&this->board[1][2]==this->board[1][3]&&this->board[1][1])||//row 2 win
  (this->board[0][2]==this->board[1][3]&&this->board[1][3]==this->board[2][4]&&this->board[0][2])||//diagonal win
  (this->board[2][0]==this->board[2][1]&&this->board[2][1]==this->board[2][2]&&this->board[2][0])||
  (this->board[2][1]==this->board[2][2]&&this->board[2][2]==this->board[2][3]&&this->board[2][1])||
  (this->board[2][2]==this->board[2][3]&&this->board[2][3]==this->board[2][4]&&this->board[2][2])){

   return true;}
 return false; 
}

template <typename T>
bool game1_board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool game1_board<T>::game_is_over() {
    return is_win() || is_draw();
}
template <typename T>
game1_player<T>::game1_player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void game1_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin.clear();
    cin.ignore(10000,'\n') ;
    cin >> x >> y;
}

template <typename T>
game1_random_player<T>::game1_random_player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  
}

template <typename T>
void game1_random_player<T>::getmove(int& x, int& y) {

    x = rand() % (this->dimension+2);  
    y = rand() % 5;
}
//---------------------------------end game1 implementation-------------------------------------------

template <typename T>
game4_board<T>::game4_board() {
    this->rows = this->columns = 3;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;
        }
    }
    this->n_moves = 0;
}
template <typename T>
bool game4_board<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= this->rows || y < 0 || y >= this->columns) && (this->board[x][y] == 0)) {
         string mark1="0";  
            cout<<"enter valid character: ";
            cin>>mark1;
            mark=toupper(mark1[0]);

      while((!(mark>='A'&&mark<='Z')||mark1.size()!=1))
        {
            cout<<"not valid character, ";
            cout<<"enter valid character: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin>>mark1;
            mark=toupper(mark1[0]);
        }
        this->n_moves++;
        this->board[x][y] = mark;
        return true;
    }
    
}
template <typename T>
void game4_board<T>::display_board() {
     while(file1>>word){   
    words.push_back(word);
   }
    for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
template <typename T>
bool game4_board<T>::is_win() {
    // Check rows and columns
   static bool bo[8]{1,1,1,1,1,1,1,1};
   if(this->board[0][0]!=0&&this->board[0][1]!=0&&this->board[0][2]!=0&&bo[0])//for first row
    { 
        string word1({this->board[0][0],this->board[0][1],this->board[0][2]});
        string word2({this->board[0][2],this->board[0][1],this->board[0][0]});
        bo[0]=0;
       if((find(words.begin(),words.end(),word1)-words.end())||(find(words.begin(),words.end(),word2)-words.end()))
       return true;
   }
    if(this->board[1][0]!=0&&this->board[1][1]!=0&&this->board[1][2]!=0&&bo[1])//second row
    { 
        string word1({this->board[1][0],this->board[1][1],this->board[1][2]});
        string word2({this->board[1][2],this->board[1][1],this->board[1][0]});

    
       bo[1]=0;
       if((find(words.begin(),words.end(),word1)-words.end())||(find(words.begin(),words.end(),word2)-words.end()))
       return true;
   }
    if(this->board[2][0]!=0&&this->board[2][1]!=0&&this->board[2][2]!=0&&bo[2])//third row
    { 
        string word1({this->board[2][0],this->board[2][1],this->board[2][2]});
        string word2({this->board[2][2],this->board[2][1],this->board[2][0]});

       bo[2]=0;
       if((find(words.begin(),words.end(),word1)-words.end())||(find(words.begin(),words.end(),word2)-words.end()))
       return true;
   }
    if(this->board[0][0]!=0&&this->board[1][0]!=0&&this->board[2][0]!=0&&bo[3])//for first column
    { 
        string word1({this->board[0][0],this->board[1][0],this->board[2][0]});//done
        string word2({this->board[2][0],this->board[1][0],this->board[0][0]});//done

    
       bo[3]=0;
       if((find(words.begin(),words.end(),word1)-words.end())||(find(words.begin(),words.end(),word2)-words.end()))
       return true;
   }
    if(this->board[0][1]!=0&&this->board[1][1]!=0&&this->board[2][1]!=0&&bo[4])// second column
    { 
        string word1({this->board[0][1],this->board[1][1],this->board[2][1]});//done
        string word2({this->board[2][1],this->board[1][1],this->board[0][1]});//done

    
       bo[4]=0;
       if((find(words.begin(),words.end(),word1)-words.end())||(find(words.begin(),words.end(),word2)-words.end()))
       return true;
   }
    if(this->board[0][2]!=0&&this->board[1][2]!=0&&this->board[2][2]!=0&&bo[5])//third column
    { 
        string word1({this->board[0][2],this->board[1][2],this->board[2][2]});//done
        string word2({this->board[2][2],this->board[1][2],this->board[0][2]});//done

    
       bo[5]=0;
       if((find(words.begin(),words.end(),word1)-words.end())||(find(words.begin(),words.end(),word2)-words.end()))
       return true;
   }
    if(this->board[0][0]!=0&&this->board[1][1]!=0&&this->board[2][2]!=0&&bo[6])//for first diagonal
    { 
        string word1({this->board[0][0],this->board[1][1],this->board[2][2]});
        string word2({this->board[2][2],this->board[1][1],this->board[0][0]});

    
       bo[6]=0;
       if((find(words.begin(),words.end(),word1)-words.end())||(find(words.begin(),words.end(),word2)-words.end()))
       return true;
   }
    if(this->board[0][2]!=0&&this->board[1][1]!=0&&this->board[2][0]!=0&&bo[7])//for second diagonal
    { 
        string word1({this->board[0][2],this->board[1][1],this->board[2][0]});
        string word2({this->board[2][0],this->board[1][1],this->board[0][2]});

    
       bo[7]=0;
       if((find(words.begin(),words.end(),word1)-words.end())||(find(words.begin(),words.end(),word2)-words.end()))
       return true;
   }
return false;
}

template <typename T>
bool game4_board<T>::is_draw() {
    return (this->n_moves == 9 && !is_win());
}

template <typename T>
bool game4_board<T>::game_is_over() {
    return is_win() || is_draw();
}

template <typename T>
game4_player<T>::game4_player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void game4_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> x >> y;
}
template <typename T>
game4_random_player<T>::game4_random_player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));  
}
template <typename T>
void game4_random_player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;  
    y = rand() % this->dimension;
    char ch=rand() %('Z'-'A');
    ch=ch+'A';
    this->symbol = ch;

}

//-------------------------------------end game4 implementation ---------------------------------------
template<typename T>
game7_board<T>::game7_board() {
    this->rows = this->columns = 4; 
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 32; 
        }
    }
    this->board[0][0] = 'X' ;
    this->board[0][2] = 'X' ;
    this->board[3][1] = 'X' ;
    this->board[3][3] = 'X' ;
    this->board[0][1] = 'O' ;
    this->board[0][3] = 'O' ;
    this->board[3][2] = 'O' ;
    this->board[3][0] = 'O' ;

    this->n_moves = 0;
}
template<typename T>
game7_board<T>::~game7_board() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

template <typename T>
bool game7_board<T>::update_board(int x, int y, T mark) {
     int x1,y1;
    x1=x/10000;
    y1=y/10000;
    x%=10000;//3
    y%=10000;
    // cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    if (x > 0 || x < this->rows || y >= 0 || y < this->columns || this->board[x][y] == 32 ) {
      if(this->board[x][y]!=mark){
      
       return false;}
    }
    else {
        return false;}
    if(!(((x1>=0&&x1<3) &&  (x==x1&&(y==y1+1||y==y1-1))  ||  (y==y1&&(x==x1+1||x==x1-1)))&& this->board[x1][y1]==32  ))    return false;
=
    this->board[x][y] = toupper(mark);
   this->board[x1][y1]=mark;
    this->board[x][y]=32;
    this->n_moves++;
    return true;
}
template <class T>
int game7_board<T> :: count_mark(T mark){
    int counter = 0 ;
    for(int i = 0 ; i < this->rows ; i++){
        for(int j = 0 ; j < this->columns ; j++){
            if(this->board[i][j] == mark) {
                counter ++ ;
            }
        }
    }
    return counter ;
}
template <typename T>
void game7_board<T>::display_board() {
     for (int i = 0; i < this->rows; i++) {
        cout << "\n| ";
        for (int j = 0; j < this->columns; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
template<class T>
bool game7_board<T>::is_win() {
    // Check rows
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] == this->board[i][j + 1] && this->board[i][j] == this->board[i][j + 2] && this->board[i][j] != 32) {
                return true;  
            }
        }
    }
    // Check columns
    for (int i = 0; i < this->columns; i++) {
        for (int j = 0; j < this->rows - 2; j++) {
            if (this->board[j][i] == this->board[j + 1][i] && this->board[j][i] == this->board[j + 2][i] && this->board[j][i] != 32) {
                return true;  
            }
        }
    }
    // Check diagonal top-left to bottom-right
    for (int i = 0; i < this->rows - 2; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] == this->board[i + 1][j + 1] && this->board[i][j] == this->board[i + 2][j + 2] && this->board[i][j] != 32) {
                return true;  
            }
        }
    }
    // Check diagonal bottom-left to top-right
    for (int i = 2; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] == this->board[i - 1][j + 1] && this->board[i][j] == this->board[i - 2][j + 2] && this->board[i][j] != 32) {
                return true; 
            }
        }
    }
    return false;  
}

template<class T>
bool game7_board<T>::is_draw() {
    return (this->n_moves == this->rows * this->columns && !is_win()); 
}

template <typename T>
bool game7_board<T>::game_is_over() {
    return is_win() || is_draw(); 
}

template <typename T>
game7_player<T>::game7_player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void game7_player<T>::getmove(int& x, int& y) {  
    cout << "\nPlease enter your move x and y (0 to 3) ->(the character you want to move from) ";
    cin.clear();
    cin.ignore(10000,'\n');
    cin >> x >> y; 
    cout<<"enter postion you to move to ";
    int x1;
    int y1;
    cin>>x1>>y1;
    x1*=10000;
    y1*=10000;
    x=x+x1;
    y=y+y1;
    
}

template <typename T>
game7_random_player<T>::game7_random_player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 4; 
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0))); 
}

template <typename T>
void game7_random_player<T>::getmove(int& x, int& y) {
    int arr[]={0,1,2,3,10000,10001,10002,10003,20000,20001,20002,20003,30000,30001,30002,30003};
    x = rand() % 16; 
    y = rand() % 16;  
    x=arr[x]; 
    y=arr[y];
}
//--------------------------------------------------------------------------End game 7 implementation ----------------------------------------------------
// Misere Tic-Tac-Toe (game6_board) implementation

template <class T>
game6_board<T>::game6_board() {
    this->rows = this->columns = 3; 
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0; 
        }
    }
    this->n_moves = 0;
}

template <class T>
game6_board<T>::~game6_board() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

template<class T>
bool game6_board<T>::update_board(int x, int y, T symbol) {
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns || this->board[x][y] != 0) {
        return false;  
    }
    this->board[x][y] = toupper(symbol);
    this->n_moves++;
    return true;
}

template <typename T>
void game6_board<T>::display_board() {
    cout << "---------------------" << endl;  
    for (int i = 0; i < this->rows; i++) {
        cout << "| ";  // Start of each row
        for (int j = 0; j < this->columns; j++) {
            cout << this->board[i][j] << " | ";  
        }
        cout << endl;
        if (i < this->rows - 1) {
            cout << "---------------------" << endl;
        }
    }
    cout << "---------------------" << endl;  
}

template<class T>
bool game6_board<T>::is_win() {
    bool checkR = true ;
    bool checkC = true ;
    bool checkRD = true ;
    bool checkLD = true ;
    if(this-> n_moves == 7 || this->n_moves == 8 || this->n_moves== 9){
        if(this->n_moves  == 7) {
        for (int i = 0; i < this->rows; i++) {
            if (this->board[i][0] == 'X' && (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][2] != 0)) {
                checkR = false; 
            }
        }
        for (int j = 0; j < this->columns; j++) {
            if (this->board[0][j] == 'X' && (this->board[0][j] == this->board[1][j] && this->board[1][j] == this->board[2][j] && this->board[1][j] != 0)) {
                checkC = false ; 
            }
        }
        if (this->board[0][0] == 'X' && (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[1][1] != 0)) {
            checkRD = false ; 
        }
        if (this->board[0][2] == 'X' && (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[1][1] != 0 )) {
            checkLD = false ;
        }
    this->checkX = checkLD && checkRD && checkC && checkR ;
    }
    else if(this->n_moves == 8) {
        for (int i = 0; i < this->rows; i++) {
            if (this->board[i][0] == 'O' && (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][1] != 0)) {
                checkR = false; 
            }
        }
        for (int j = 0; j < this->columns; j++) {
            if (this->board[0][j] == 'O' && (this->board[0][j] == this->board[1][j] && this->board[1][j] == this->board[2][j] && this->board[1][j] != 0)) {
                checkC = false ; 
            }
        }
        if (this->board[0][0] == 'O' && (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[1][1] != 0)) {
            checkRD = false ; 
        }
        if (this->board[0][2] == 'O' && (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[1][1] != 0)) {
            checkLD = false ;
        }
    this->checkO = checkLD && checkRD && checkC && checkR ;
    return this->checkO && !(this->checkX) ;
    }
    else {
        for (int i = 0; i < this->rows; i++) {
            if (this->board[i][0] == 'X' && (this->board[i][0] == this->board[i][1] && this->board[i][1] == this->board[i][2] && this->board[i][2] != 0)) {
                checkR = false; 
            }
        }
        for (int j = 0; j < this->columns; j++) {
            if (this->board[0][j] == 'X' && (this->board[0][j] == this->board[1][j] && this->board[1][j] == this->board[2][j] && this->board[1][j] != 0)) {
                checkC = false ; 
            }
        }
        if (this->board[0][0] == 'X' && (this->board[0][0] == this->board[1][1] && this->board[1][1] == this->board[2][2] && this->board[1][1] != 0)) {
            checkRD = false ; 
        }
        if (this->board[0][2] == 'X' && (this->board[0][2] == this->board[1][1] && this->board[1][1] == this->board[2][0] && this->board[1][1] != 0 )) {
            checkLD = false ;
        }
    this->checkX = checkLD && checkRD && checkC && checkR ;
    return this->checkX && !(this->checkO) ;
    }
    }
    return false ;
}
template<class T>
bool game6_board<T>::is_draw() {
    return !is_win() && this-> n_moves == 9 ; 
}
template<class T>
bool game6_board<T>::game_is_over() {
    return is_win() || is_draw() ; 
}
template<class T>
game6_player<T>::game6_player(string name, T symbol) : Player<T>(name, symbol) {}
template<class T>
void game6_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) -> ";
    cin.clear();
    cin.ignore(10000,'\n');
    cin >> x >> y; 
    
}
template<class T>
game6_random_player<T>::game6_random_player(T symbol) : RandomPlayer<T>(symbol) {}

template<class T>
void game6_random_player<T>::getmove(int& x, int& y) {
    x = rand() % 3;
    y = rand() % 3;
}
//-------------------------------------------------------------end game 6 implementaion ---------------------------------------------------------------------------
template<typename T>
game3_board<T>::game3_board() {
    this->rows = this->columns = 5; 
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 0;  // Initialize the board 
        }
    }
    this->n_moves = 0;
}
template<typename T>
game3_board<T>::~game3_board() {
    for (int i = 0; i < this->rows; i++) {
        delete[] this->board[i];
    }
    delete[] this->board;
}

template <typename T>
bool game3_board<T>::update_board(int x, int y, T mark) {
    if (x < 0 || x >= this->rows || y < 0 || y >= this->columns || this->board[x][y] != 0) {
        return false;  
    }
    this->board[x][y] = toupper(mark);
    this->n_moves++;
    return true;
}

template <typename T>
void game3_board<T>::display_board() {
    cout << "---------------------" << endl;  
    for (int i = 0; i < this->rows; i++) {
        cout << "| ";  // Start of each row
        for (int j = 0; j < this->columns; j++) {
            cout << this->board[i][j] << " | ";  
        }
        cout << endl;
        if (i < this->rows - 1) {
            cout << "---------------------" << endl;
        }
    }
    cout << "---------------------" << endl;  
}

template <class T>
bool game3_board<T>::is_win() {
    int count = 0;
    if (this->n_moves == 23 || this->n_moves == 24 || this->n_moves == 25) {
        if(this->n_moves == 23){
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] == 'X' && this->board[i][j] == this->board[i][j + 1] && this->board[i][j] == this->board[i][j + 2]) {
                count++;
            }
        }
    }

    for (int i = 0; i < this->columns; i++) {
        for (int j = 0; j < this->rows - 2; j++) {
            if (this->board[j][i] == 'X' && this->board[j][i] == this->board[j + 1][i] && this->board[j][i] == this->board[j + 2][i]) {
                count++;
            }
        }
    }
    for (int i = 0; i < this->rows - 2; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] == 'X' && this->board[i][j] == this->board[i + 1][j + 1] && this->board[i][j] == this->board[i + 2][j + 2]) {
                count++;
            }
        }
    }
    for (int i = 2; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] == 'X' && this->board[i][j] == this->board[i - 1][j + 1] && this->board[i][j] == this->board[i - 2][j + 2]) {
                count++;
            }
        }
    }
    this->countplayer1 = count ;
    count = 0 ;
        }
        else if(this->n_moves == 24) {
                for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] == 'O' && this->board[i][j] == this->board[i][j + 1] && this->board[i][j] == this->board[i][j + 2]) {
                count++;
            }
        }
    }

    for (int i = 0; i < this->columns; i++) {
        for (int j = 0; j < this->rows - 2; j++) {
            if (this->board[j][i] == 'O' && this->board[j][i] == this->board[j + 1][i] && this->board[j][i] == this->board[j + 2][i]) {
                count++;
            }
        }
    }
    for (int i = 0; i < this->rows - 2; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] == 'O' && this->board[i][j] == this->board[i + 1][j + 1] && this->board[i][j] == this->board[i + 2][j + 2]) {
                count++;
            }
        }
    }
    for (int i = 2; i < this->rows; i++) {
        for (int j = 0; j < this->columns - 2; j++) {
            if (this->board[i][j] == 'O' && this->board[i][j] == this->board[i - 1][j + 1] && this->board[i][j] == this->board[i - 2][j + 2]) {
                count++;
            }
        }
    }
    this->countplayer2 = count ;
    count = 0 ;
    if(countplayer1 < countplayer2){
        cout << "wins of player X -> " << this->countplayer1 << " | wins of player O -> " << this->countplayer2 << endl;
        return true ;

     }
    }
    else if(this->n_moves == 25){
        if(this->countplayer2 < this->countplayer1){
            cout << "wins of player X -> " << this->countplayer1 << " | wins of player O -> " << this->countplayer2 << endl;
            return true ;
        }
    }   
    }
    return false;
}
template<class T>
bool game3_board<T>::is_draw() {
    return !is_win() && this-> n_moves == 25; 
}
template<class T>
bool game3_board<T>::game_is_over() {
    return is_win() || is_draw() ; 
}
template<class T>
game3_player<T>::game3_player(string name, T symbol) : Player<T>(name, symbol) {}
template<class T>
void game3_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 4) -> ";
    cin.clear();
    cin.ignore(10000,'\n');
    cin >> x >> y; 
    
}
template<class T>
game3_random_player<T>::game3_random_player(T symbol) : RandomPlayer<T>(symbol) {}

template<class T>
void game3_random_player<T>::getmove(int& x, int& y) {
    x = rand() % 5;
    y = rand() % 5;
}
//-----------------------------------------------------end game 3 implementaion -------------------------------------------------------------------------------
template <typename T>
game8_board<T>::game8_board() {
    this->rows = this->columns = 12;
    this->board = new char*[this->rows];
    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->columns];
        for (int j = 0; j < this->columns; j++) {
            this->board[i][j] = 32;
        }
    }
    this->n_moves = 0;
}
template <typename T>
bool game8_board<T>::update_board(int x, int y, T mark) {
    if (!(x < 0 || x >= 9 || y < 0 || y >= 9) && (this->board[x][y] == 32|| mark == 0)) {
        if (mark == 0){
            this->n_moves--;
            this->board[x][y] = 0;
        }
        else {
            this->n_moves++;
            this->board[x][y] = toupper(mark);
        }
 for (int j = 0; j < 3; j++) {
        for(int i = 0; i <9;i++){
                if((this->board[i][j*3]!=32 && this->board[i][j*3]==this->board[i][((j*3)+1)]) &&( this->board[i][(j*3)+1]==this->board[i][(j*3)+2] &&this->board[(i/3 +9)][j +9]==32)){
                    for(int i1=(i/3)*3; i1<((i/3)*3)+3;i1++){
                        for(int j1=j*3; j1<j*3+3;j1++){
                             if(this->board[i1][j1] ==32 )
                             this->n_moves++;
                            this->board[i1][j1] =mark; 
                            
                        }
                       this->board[((i/3)) +9][j +9]=mark;

                    }
                }
    
        }
       
    }
   // Check columns
      for (int j = 0; j < 9; j++) {
        for(int i = 0; i <3;i++){
                if(this->board[i*3][j]!=32 && this->board[i*3][j]==this->board[i*3+1][j] && this->board[i*3+1][j]==this->board[i*3+2][j]&& this->board[i +9][j/3 +9]==32){
                    for(int i1=i*3; i1<i*3+3 ;i1++){
                        for(int j1=(j/3)*3; j1<(j/3)*3+3;j1++){
                             if(this->board[i1][j1] ==32 )
                                  this->n_moves++;
                            this->board[i1][j1] =mark; 
                        }
                         this->board[i +9][j/3 +9]=mark;

                    }
                }
    
        }
       
    }
   //L ro R diagonal 
 
   for(int i=0;i<3;i++)     {
    for(int j=0;j<3;j++) {
        if(this->board[i*3][j*3]!=32 && this->board[i*3][j*3]==this->board[i*3+1][j*3+1] && this->board[i*3+1][j*3+1]==this->board[i*3+2][j*3+2] && this->board[i +9][j +9]==32){
          
           for(int i1=i*3; i1<i*3+3 ;i1++){
                        for(int j1=j*3; j1<j*3+3;j1++){
                            if(this->board[i1][j1] ==32 )
                             this->n_moves++;
                            this->board[i1][j1] =mark; 
                        }
                         this->board[i +9][j +9]=mark;

                    }
                }
    
   }
   }
     for(int i=0;i<3;i++)     {
    for(int j=0;j<3;j++) {
        if(this->board[i*3][j*3+2]!=32 && this->board[i*3][j*3+2]==this->board[i*3+1][j*3+1] && this->board[i*3+1][j*3+1]==this->board[i*3+2][j*3] && this->board[i +9][j +9]==32){
           //   cout<<"ssssssssssssssssssssssssssssssssssssssaaa"<<i<<j<<(this->board[i*3][j*3+2])<<" "<<(this->board[i*3][j*3+2]==this->board[i*3+1][j*3+1])<<(this->board[i*3+2][j*3]==this->board[i*3+1][j*3+1])<<endl;
           for(int i1=i*3; i1<i*3+3 ;i1++){
                        for(int j1=j*3; j1<j*3+3;j1++){
                             if(this->board[i1][j1] ==32 )
                              this->n_moves++;
                            this->board[i1][j1] =mark; 
                        }
                         this->board[i +9][j +9]=mark;

                    }
                }
    
   }
   
   
   }
   
   }
   else {

    return false;
   }
    return true;
    }
template <typename T>
void game8_board<T>::display_board() {
    for (int i = 0; i < 9; i++) {
        cout << "\n| ";
        for (int j = 0; j < 9; j++) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
        if((i+1)%3!=0)
        cout << "\n----------------------------|--------------------------|--------------------------|";
        else
        cout << "\n____________________________|__________________________|__________________________|"<<endl;

    }
    cout << endl;
    cout<< endl;
    for (int i = 9; i < 12; i++) {
        cout << "\n| ";
        for (int j = 9; j < 12; j++) {
            cout << "(" << i-9 << "," << j-9 << ")";
            cout << setw(2) << this->board[i][j] << " |";
        }
           cout << "\n--------------------------------";
}
cout<<endl;
}
template <typename T>
bool game8_board<T>::is_win() {
    for (int i = 9; i < this->rows; i++) {
        if ((this->board[i][9] == this->board[i][10] && this->board[i][10] == this->board[i][11] && this->board[i][10] != 32) ||
            (this->board[9][i] == this->board[10][i] && this->board[10][i] == this->board[11][i] && this->board[10][i] != 32)) {
            return true;
        }
    }

    // Check diagonals
    if ((this->board[9][9] == this->board[10][10] && this->board[10][10] == this->board[11][11] && this->board[9][9] != 32) ||
        (this->board[9][11] == this->board[10][10] && this->board[10][10] == this->board[11][9] && this->board[9][11] != 32)) {
        return true;
    }

    return false;
}
template <typename T>
bool game8_board<T>::is_draw() {
    return (this->n_moves == 81 && !is_win());
}

template <typename T>
bool game8_board<T>::game_is_over() {
    return is_win() || is_draw();
}
template <typename T>
game8_player<T>::game8_player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void game8_player<T>::getmove(int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 9) separated by spaces: ";
    cin.clear();
    cin.ignore(10000,'\n');
    cin >> x >> y;
}
template <typename T>
game8_random_player<T>::game8_random_player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 9;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}
template <typename T>
void game8_random_player<T>::getmove(int& x, int& y) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
}

#endif 
