// CS19 Final Exam: Othello Spring 2011
// as per academic integrity policy
// for your individual use only this semester
// DO NOT DUPLICATE, DO NOT DISTRIBUTE, DO NOT TRANSCRIBE

// John Carlyle jcarlyle

// you may #include additional standard libraries if necessary
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <vector>
using namespace std;

/* Othello Game Board Array Representation & Structure
board[10][10] 10x10 array
8x8 from (1,1) to (8,8) is the playing board
   0 = empty square   1,2 = occupied by player 1 or 2
   (4,4), (4,5), (5,4) and (5,5) are initally occupied
row and columns 0 and 9 are unused (a gutter) and should always be 0
  
   1  2  3  4  5  6  7  8
1  .  .  .  .  .  .  .  .
2  .  .  .  .  .  .  .  .
3  .  .  .  .  .  .  .  .
4  .  .  . (1)(2) .  .  .
5  .  .  . (2)(1) .  .  .
6  .  .  .  .  .  .  .  .
7  .  .  .  .  .  .  .  .
8  .  .  .  .  .  .  .  .

Directions:
When you need to explore in one direction the following code (0-7) is used
   5   6   7
   4   *   0    
   3   2   1     (0=left, 2=down etc...)
*/

class Othello{
public:
  Othello(){initGame();}
  void playGame();
private:
  void initGame();
  void inputMove(int p, int &r, int &c);
  bool hasMove(int p); 
  bool isGameOver();
  int countPieces(int p);
  int checkAt(int p, int r, int c); 
  int playAt(int p, int r, int c); 
  int exploreFrom(int p, int r, int c, bool flip);
  int exploreOneDir(int p, int r, int c, bool flip, int dir);
  void readLogo();
  void drawLogo();
  void color(int); // change the display color
  void offerInstructions();
  void printClosing();
  void drawBoard();
  int board[10][10]; // who owns board[r][c] (0=open 1=p1 2=p2)
  int logo[60][15]; // array of ints zero-two 
  static const int xoffset[8];
  static const int yoffset[8];
  static const string square[3];
};

// xoffset and yoffset useful for calculation adjacent board
//   positions in one of 8 (horizontal, vertical, diagonal) directions
// (same ordering as "direction" code elsewhere in the program)
const int Othello::xoffset[8] = {1,1,0,-1,-1,-1,0,1};
const int Othello::yoffset[8] = {0,1,1,1,0,-1,-1,-1};
// square used by the drawBoard() function
const string Othello::square[3] = {" . ", "(1)", "(2)"};


// main game loop
void Othello::playGame(){
  int player = 1; 
  int r, c; // row and column of a move
  initGame();readLogo();drawLogo();
  offerInstructions();
  while( !isGameOver() ){
    if (hasMove(player)){
      drawBoard();
      inputMove(player,r,c);
      playAt(player,r,c);
    }
    player = 3 - player; // alternate between p1 and p2
  }
 drawBoard();
 printClosing();
}


// Clear board (including gutter, place inital four pieces
void Othello::initGame(){
  for(int i=0; i<10; i++)
    for(int j=0; j<10; j++)
      board[i][j] = 0;
  board[4][4]=board[5][5]=2;
  board[4][5]=board[5][4]=1;
}


// input p's legal/valid move into params r&c 
void Othello::inputMove(int p, int &r, int &c){
  char buffer[128];
  char *tok1=0, *tok2=0; 
  bool goodInput = false;
  while(!goodInput){
    color(3+p); cout << "Player " << p << ":";
    color(0); cout << " your move (x, y)? ";
    cin.getline(buffer, 128);
    tok1 = strtok(buffer," ,");
    tok2 = strtok(0, " ,");
    if (tok1 !=0 && tok2 !=0){
      c = atoi(tok1);
      r = atoi(tok2);
      if (r >0 && c>0 && r<=8 && c<=8)
	if (board[c][r]==0)
	  goodInput = checkAt(p,r,c);
    }
  }
}


// is there any legal move for p?
bool Othello::hasMove(int p){
  for(int r=1; r<=8; r++)
    for(int c=1; c<=8; c++){
      if( board[c][r]==0 && exploreFrom(p,r,c,false) > 0)
	return true;
    }
  return false;
}

// Is the game over?
bool Othello::isGameOver(){
  if (hasMove(1)) return false;
  if (hasMove(2)) return false;
  return true;
}


// count how many pieces on the board belong to p
int Othello::countPieces(int p){
  int count=0;
  for(int r=1; r<=8; r++)
    for(int c=1; c<=8; c++)
      if( board[c][r]==p) count++;
  return count;
}

// check to see how many pieces would be flipped
// if p moved to position (r,c)
int Othello::checkAt(int p, int r, int c){
  return exploreFrom(p,r,c,false);
}


// player p moves to (r,c) (& flip pieces)
int Othello::playAt(int p, int r, int c){
  board[c][r]=p;
  return exploreFrom(p,r,c,true);
}


// explores board to check for (or make) flips
// for p at position (r,c)
// capture determines actual move (flip=true) or testing for a move
int Othello::exploreFrom(int p, int r, int c, bool flip){
  int flips = 0;
  for(int i=0; i<8; i++)
    flips +=exploreOneDir(p,r,c,flip,i);
  return flips;
} 





void Othello::drawLogo(){
  for (int j=0; j<15; j++){
    for (int i=0; i<60; i++){
      color(logo[i][j]+3);
      cout << " ";
      color(0);
    }
    cout << endl;
  }
  color(5); cout << "O";  color(4); cout << "t";
  color(5); cout << "h";  color(4); cout << "e";
  color(5); cout << "l";  color(4); cout << "l";
  color(5); cout << "o";  color(0); cout << endl;
}


// change the ANSI terminal color using CSI escape sequences
void Othello::color(int n){
  switch(n){
  case 1:    cout << '\x1B' << "[0;30;1;42m"; break;  // black bold on green
  case 2:    cout << '\x1B' << "[0;37;1;42m"; break;  // white bold on green
  case 3:    cout << '\x1B' << "[0;33;42m"; break;  // yellow on green
  case 4:    cout << '\x1B' << "[0;32;1;40m"; break;  // bold green on black
  case 5:    cout << '\x1B' << "[0;32;1;47m"; break;  // bold green on white
  default:
  case 0:    cout << '\x1B' << "[0;30m"; break;  // black on white (default)
  }
}


void Othello::offerInstructions(){
  char buf[128];

  cout << "Instructions (Y/N)? ";
  cin.getline(buf, 128);
  if (buf[0] != 'y' && buf[0] != 'Y')
    return;

  color(0); cout << endl << endl;
  color(5); cout << "O";  color(4); cout << "t";
  color(5); cout << "h";  color(4); cout << "e";
  color(5); cout << "l";  color(4); cout << "l";
  color(5); cout << "o";  color(0); cout << endl;
  cout << "The game of reversi was invented in the late 1800s in England, and quickly became popular. A variation of the game, named Othello, originated in Japan in the 1970s." << endl << endl;
  color(2); cout << "Getting Started";
  color(0); cout << endl;
  cout << "Four pieces are initally placed in the center of the board."<<endl<<endl;

  color(2); cout << "Gameplay";
  color(0); cout << endl;
  cout << "When a player places a piece, all opposing contiguous pieces lying in a straight line (horizontally, vertically, or diagonally) between the new piece and any anchoring piece (another piece of the same player) are flipped in color. A player may only place a piece on the board if that move results in at least one flip. If a player has no move, they loose their turn." << endl << endl;
  color(2); cout << "Winning";
  color(0); cout << endl;
  cout << "The game ends when neither player can move. The player with the most pieces on the board wins." << endl << endl;

  cout << "Ready to Play (Y/N)? ";
  cin.getline(buf, 128);
  if ( buf[0] == 'N' || buf[0] =='n'){
    cout << "Bye!" << endl;
    exit(0);
  }
  cout << endl;
}


// print game results
void Othello::printClosing(){
  int p1 = countPieces(1); int p2=countPieces(2);
  if (p1 > p2){
    color(1+3); cout << "Player 1 wins!";
  }
  if (p1 < p2){
    color(2+3); cout << "Player 2 wins!";
  }
  if (p1 == p2){
    color(3+3); cout << "Tie game.";
  }
  color(0);
  cout << endl << "The final score was "<<p1<< " to "<<p2<<"."<<endl;
  cout << endl << "Thanks for playing." << endl;
}


void Othello::drawBoard(){
  cout << endl << "   1  2  3  4  5  6  7  8"<<endl;
  for(int r=1; r<=8; r++){
    cout << r << " ";
    for(int c=1; c<=8; c++){
      color( board[c][r]+3);
      cout << square[ board[c][r]];
    }
    color(0);
    cout << " " << r << endl;
  }
  cout << "   1  2  3  4  5  6  7  8"<<endl;
}



// explores board from position (r,c) to check for/make flips
// for player p (1 or 2) in one direction (0-7) (0=to the right etc...)
// directions are not guaranteed to be "legal" -- check for boundaries!
// if flip==true, the function should flip any "captured" pieces
// if flip==false, just count the number of pieces that would be flipped
// returns the count of pieces that were/would be flipped
// ***** YOUR CODE IN THIS FUNCTION
int Othello::exploreOneDir(int p, int r, int c, bool flip, int dir){

  //poor hacked together algorithm that seems to missing a few cases

  //just read the instructiosn which differ slgihtly from wikipedia and would have made it easier.
  //I was making it so that all pieces between your anchor and your new piece would be flipped.
  //Continuous would be much easier unfortunatly it is 2:13
  //Edit: Nope I just misread wikipedia. Great.

  //player row column flip direction
  int x = c, y = r;
  int dx = 0;
  int dy = 0;

  //giant unnessisary if tree
 //E
  if (dir == 0) {
    dx = 1;
  }
  //SE
  else if (dir == 1) {
    dx = 1;
    dy = 1;
  }
  //S
  else if (dir == 2) {
    dy = 1;
  }
  //SW
  else if (dir == 3) {
    dx = -1;
    dy = 1;
  }
  //W
  else if (dir == 4) {
    dx = -1;
  }
  //NW
  else if (dir == 5) {
    dx = -1;
    dy = -1;
  }
  //N
  else if (dir == 6) {
    dy = -1;
  }
  //NE
  else if (dir == 7) {
    dx = 1;
    dy = -1;
  }

  //vector to store line im going to check
  vector<int> line;
  int countToFlip = 0;
  int sx = x; //starting x and y position
  int sy = y;
  //go through the line and add each value to it
  do {
    //update x y position
    line.push_back(board[x][y]);
    x += dx;
    y += dy;
  } while (x > 0 && x < 9 && y > 0 && y < 9);

  //search the row
  bool searching = true;
  int anchor = -1; //anchor piece to flip things between
  for (unsigned int i = 0; searching && i < line.size(); i++) {
    //if we find a piece of the same color that is our anchor
    if (line[i] == p)
      anchor = i;
    if (line[i] == 0) { // if I find an open position I stop searching the line
      searching = false;
    }
  }
  //temporary x and y position to help convert back from 1D array to 2D coord
  int tx, ty;
  for (unsigned int i = 0; i < anchor && i < line.size();i++) {
    //if I find a piece that isnt blank and isnt the same color as the player it can be flipped
    if (line[i] != 0 && line[i] != p) {
      countToFlip++;
      if (flip) {
	//kludgy way that doesn't appear to work to get a 2D coord back from a 1D array index
	for (int j = 0 ; j < i ; j++) {
	  //start at my starting spot and move along until we find i to flip
	  tx = sx;
	  ty = sy;
	  tx += dx;
	  ty += dy;
	}
	//ty tx is now the 2D coord of i so swap that to p
	board[tx][ty] = p;
      }
    }
  }

  return countToFlip;
}

// read logo from the 60 by 15 ASCII file (values 0-2)
// '0' = 0, '1' = 1, '2' = 2
// named "othello-logo.txt"
// and store into the 60 by 15 integer array logo.
void Othello::readLogo(){
  // ***** YOUR CODE IN THIS FUNCTION
  ifstream fin("othello-logo.txt");
  if (!fin.good()) {
    exit(-1);
  }
  char t;
  for (int j=0; j<15; j++){
    for (int i=0; i<60; i++){
      fin >> t;
      logo[i][j] = t - '0';
    }  
  }
  fin.close();
}


// =======================================


main(){
  Othello g;
  g.playGame();
}
