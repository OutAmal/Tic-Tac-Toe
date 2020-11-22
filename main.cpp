#include <iostream>
#include <time.h>
#include <list>

using namespace std;
char currentMarker;
int currentPlayer;


char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void drawBord (){
 cout << " " << board[0][0] << " " << "|" << " " << board[0][1] << " " << "|" << " " << board[0][2] << " " << endl;
 cout <<"----------\n" ;
 cout << " " << board[1][0] << " " << "|" << " " << board[1][1] << " " << "|" << " " << board[1][2] << " " << endl;
 cout <<"----------\n" ;
cout << " " << board[2][0] << " " << "|" << " " << board[2][1] << " " << "|" << " " << board[2][2] << " " << endl;
}
void swapePlayers(){
  if(currentMarker == 'X') currentMarker = 'O';
  else  currentMarker = 'X';

  if (currentPlayer == 1) currentPlayer = 2;
  else currentPlayer = 1;
}
bool placeMarker(int slot){
    int row = slot/3;
    int col;
    if (slot % 3 == 0) {col = 2; row = row - 1;}
    else col = (slot % 3)- 1;
    //cout << "(" << row << "," << col <<")";

    if ( board[row][col] != 'X' && board[row][col] != 'O' ) { board[row][col] = currentMarker; return true;}
    else  return false;

}
int Winner(){
    for (int i=0;i<3;i++){
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
};
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) return currentPlayer;
    return 0;
}
void deleteElement(int arr[], int n, int x)
{

   int i;
   for (i=0; i<n; i++)
      if (arr[i] == x)
         break;

   if (i < n)
   {
     n = n - 1;
     for (int j=i; j<n; j++)
        arr[j] = arr[j+1];
   };
}
int Generator(){

    int liste[9]= {1,2,3,4,5,6,7,8,9};
    int slot;
    if (currentPlayer == 2){ srand( time( NULL ) );
                             int index = rand() % 9;
                             slot = liste[index];
                             deleteElement(liste,  9, slot);
                             cout << slot << endl;
                             return slot ; }
    if (currentPlayer == 1){ cin >> slot ;
                             return slot ;} }




int Game(){
    int slot;
    char pMarker;
    cout << "First player,choose your marker: X or O " << endl;
    cin >> pMarker ;
    currentPlayer = 1;
    currentMarker = pMarker;
    drawBord();
    for (int i=1; i<=9 ; i++){

        cout << "player "<<currentPlayer<< " place your marker " << endl;
        slot = Generator();

        if (slot<1 || slot>9)
           {cout << "Choose another marker" << endl; i--; swapePlayers();};
        if (!placeMarker(slot))
           {cout << "Choose another marker" << endl; i--;swapePlayers(); };

        placeMarker(slot);
        drawBord();
        if (Winner() != 0){ cout << currentPlayer << " is the winner" << endl; break;}
        swapePlayers();
    }
cout << "Game over! ";
}

int main()

{

    Game();
    //return 0;
}
