/**
 * rps.cpp
 * Project UID 24b93ce4a6274610f4c3f3e31fe17277c
 *
 * <#Name#>Clarke Norris
 * <#Uniqname#>clnorris
 *
 * EECS 183: Project 2
 * Winter 2025
 *
 * <#description#> This project is implementing a game of rock-paper-scissors, best out of 3 rounds.
 */

#include <iostream>
#include <string>

const int MAX_ROUNDS = 3;

using namespace std;

//************************************************************************
// The following four functions have already been implemented for you.
// You should use them when writing the other functions, but do not edit
// their implementations.
//************************************************************************

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints a pretty header to introduce the user to the game.
 */
void printInitialHeader();

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints the menu.
 * Prompts:  "1) Play rock, paper, scissors"
 *           "2) Play rock, paper, scissors, lizard, spock"
 *           "3) Quit"
 *           "Choice --> "
 */
void printMenu();

/**
 * Requires: errorNumber be either 1 or 2
 * Modifies: cout
 * Effects:  If errorNumber is 1, prints an error message indicating
 *           an illegal name was entered.
 *           If errorNumber is 2, prints an error message indicating
 *           an illegal move was entered.
 */
void printErrorMessage(int errorNumber);

/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  Prints out the final greeting for the program.
 */
void printCloser();

//************************************************************************
// You must implement all of the following functions. Add your 
// implementations below rps() as indicated.
//************************************************************************

/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Utilizes the other functions in this file to play 
 *           the game Rock Paper Scissors.
 *
 *           Starter algorithm pseudocode: 
 *           1. Print the header
 *           2. Get player 1 name
 *           3. Get player 2 name
 *           4. Repeat the following until the user quits the program:
 *              * Get the menu choice
 *              * Play the game and announce the winner, 
 *                or quit the program (according to user's menu choice)
 *           5. Print the closing message 
 */
void rps();

/**
 * Requires: playerNumber is either 1 or 2
 * Modifies: cout, cin
 * Effects:  Prompts the user to enter their name. Names entered may
 *           have spaces within them.
 *               Example: "Kermit the frog"
 *
 *           If an empty name is given, this is invalid input, so print
 *           error message 1, and return a default name.
 *           For player 1, the default name is: Rocky
 *           For player 2, the default name is: Creed
 *           Otherwise, return name entered by user.
 *              
 * Prompt:   Player [playerNumber], enter your name:
 */
string getName(int playerNumber);


/**
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  Prints the menu, and reads the input from the user.
 *           Checks to make sure the input is within range for the menu.
 *           If it is not, prints "Invalid menu choice". Continues to print 
 *           the menu and read in input until a valid choice is entered,
 *           then returns the user's choice of menu options. You can assume
 *           a user will enter an integer, and nothing else, as their choice.
 *
 * Prompt:   Invalid menu choice
 */
int getMenuChoice();


/**
 * Requires: nothing
 * Modifies: nothing
 * Effects:  Returns true if and only if move represents a valid move character
 *           one of 'R', 'r', 'P', 'p', 'S', 's'. Returns false otherwise.
 */
bool isMoveGood(char move);


/**
 * Requires: playerName is the name of the player being prompted for their
 *           move.
 * Modifies: cout, cin
 * Effects:  Prompts the player for their move and returns it.
 *           This function should accept the first non-whitespace character as
 *           the move. If an illegal character is entered for their move, print
 *           error message 2 and return rock as a default. 
 *           You can assume a user will enter a single character, 
 *           and nothing else, as their move.
 *
 * Prompt:   [playerName], enter your move:
 */
char getMove(string playerName);




/**
 * Requires: move is the move of the player being checked for a win.
 *           opponentMove is the move of the opponent.
 *           both move and opponentMove are valid moves.
 * Modifies: nothing
 * Effects:  Returns true if and only if the player who made move won
 *           according to the rules to rock-paper-scissors. Returns false
 *           otherwise.
 */
bool isRoundWinner(char move, char opponentMove);


/**
 * Requires: winnerName is the name of the player who won the round.
 * Modifies: cout
 * Effects:  If winnerName is the empty string, i.e., "",
 *           prints a message indicating the round is a draw. 
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   This round is a draw!
 *           ------------- OR -------------
 *           [winner_name] wins the round!
 */
void announceRoundWinner(string winnerName);


/**
 * Requires: p1Name and p2Name are the names of the respective players
 * Modifies: nothing
 * Effects:  Simulates a complete round of rock-paper-scissors, which
 *           consists of three steps:
 *             1. Get player1 move
 *             2. Get player2 move
 *             3. Return 0 if the round was a draw; 1 if player 1 won;
 *                2 if player 2 won.
 */
int doRound(string p1Name, string p2Name);


/**
 * Requires: winnerName is the name of the player who won the game.
 * Modifies: cout
 * Effects:  If winnerName is the empty string, i.e., "", 
 *           prints that the game was a draw.
 *           Otherwise, prints a congratulatory message to the winner.
 * Prompt:   No winner!
 *           ------------- OR -------------
 *           Congratulations [winnerName]!
 *           You won EECS 183 Rock-Paper-Scissors!
 */
void announceWinner(string winnerName);


/**
 * Requires: p1Name and p2Name are the names of the respective players,
 *           gameType can be 1 for regular rock-paper-scissors
 *           or 2 for rock-paper-scissors-lizard-spock
 * Modifies: cout
 *
 * Base Project:
 * Effects:  If gameType is 2, prints "Under Construction" to indicate that the
 *           s'more has not been implemented. Returns empty string.
 *           Otherwise, plays exactly three rounds of rock-paper-scissors while
 *           keeping track of the number of round wins for each player.
 *           When a round results in a draw, neither player is the winner,
 *           so neither player is awarded a point.
 *           After each round is played, the round winner (or draw) is
 *           announced. 
 *           Returns the name of the game winner, or "" in event of a draw.
 * Prompt:   Under Construction
 *
 * S'more Version:
 * Effects:  Has same functionality as base project, but also handles a
 *           gameType of 2. When game_type is 2, plays exactly three rounds of
 *           rock-paper-scissors-lizard-spock. Keeps track of round wins for
 *           each player and announces round winners in the same fashion as 
 *           described above.
 */
string doGame(string p1Name, string p2Name, int gameType);

//************************************************************************
// Implement the functions below this line.
//************************************************************************

void rps() {
    // TODO: implement
    printInitialHeader();
    
    string p1Name = getName(1);
    string p2Name = getName(2);
    int endgame = 3;
    int menu = 0;
    while (menu != endgame) {
        menu = getMenuChoice();
        
        if ((menu != endgame)) {
            string winner = doGame(p1Name, p2Name, menu);
            announceWinner(winner);
        }
    }
    
    printCloser();
}

string getName(int playerNumber) {
    // TODO: implement
    string name;
    cout << "Player" << playerNumber << ", enter your name: ";
    getline(cin, name);
    if(name== "" && playerNumber == 1) {
        name = "Rocky";
        printErrorMessage(1);
    } else if (name == "" && playerNumber ==2){
        name = "Creed";
        printErrorMessage(1);
    }
    //  string name;
   // NOTE: return "" to avoid compile error
    //       remove it after implementing
    return name;
}


int getMenuChoice() {
    // TODO: implement
    int choice;
    printMenu();  // Display the menu
    cin >> choice;
    cout << endl;  // Extra newline for autograder compatibility
    
    while (choice != 1 && choice != 2 && choice != 3) {
           cout << "Invalid menu choice" << endl;
           printMenu();
           cin >> choice;
           cout << endl;
       }
    // NOTE: return 0 to avoid compile error
    //remove it after implementing
    return choice;
}


bool isMoveGood(char move) {
    // TODO: implement
    if (move == 'r'|| move == 'R' || move =='p' || move== 'P' || move =='s' || move == 'S'){
        return true;
    } else
    // NOTE: return false to avoid compile error
    //       remove it after implementing
    return false;
}

char getMove(string playerName) {
    // TODO: implement
    char move;
    cout << playerName << ", enter your move: ";
    cin >> move;
    if (isMoveGood(move) == false){
        printErrorMessage(2);
        move = 'r';
    }
    // NOTE: return 'r' to avoid compile error
    //  remove it after implementing
    return move;
}


bool isRoundWinner(char move, char opponentMove) {
    // TODO: implement
    if ((move == 'p' || move == 'P') && (opponentMove == 'r' || opponentMove == 'R')){
        return true;
    }else if ((move == 'R' || move == 'r' ) && (opponentMove == 's' || opponentMove == 'S')){
        return true;
    } else if ((move == 'S' || move == 's') && (opponentMove == 'p' || opponentMove == 'P')) {
        return true;
    }
    // NOTE: return false to avoid compile er`ror
    //       remove it after implementing
    return false;
}


void announceRoundWinner(string winnerName) {
    // TODO: implement
    if (winnerName == "") {
        cout << "This round is a draw!" << endl;
    } else
        cout << winnerName << " wins the round!" << endl;
    return;
}


int doRound(string p1Name, string p2Name) {
    // TODO: implement
    char p1Move = getMove(p1Name);
    char p2Move = getMove(p2Name);
    if(isRoundWinner(p1Move, p2Move)) {
        return 1;
    } else if (isRoundWinner(p2Move, p1Move)) {
        return 2;
    } else
    // NOTE: return 0 to avoid compile error
    //       remove it after implementing
    return 0;
}


void announceWinner(string winnerName) {
    // TODO: implement
    if (winnerName == "") {
         cout << "No winner!" << endl;
     } else {
         cout << "Congratulations " << winnerName << "!" << endl;
         cout << "You won EECS 183 Rock-Paper-Scissors!" << endl;
     }
}


string doGame(string p1Name, string p2Name, int gameType) {
    // TODO: implement
    if (gameType == 2) {
        cout << "Under Construction";
        return "";
    }
    
    int p1wins = 0;
    int p2wins = 0;

for (int rounds = 0; rounds < MAX_ROUNDS; rounds++) {
    
int winner = doRound(p1Name, p2Name);
    
if (winner == 1) {
    p1wins++;
    announceRoundWinner(p1Name);  
    } else if (winner == 2) {
        p2wins++;
        announceRoundWinner(p2Name);
    } else {
        announceRoundWinner("");
        }
    }

if (p1wins > p2wins) {
    return p1Name;
    } else if (p2wins > p1wins) {
        return p2Name;
    } else {
        return "";
    }
// NOTE: return "" to avoid compile error
    // remove it after implementing
  
}




//***********************************************************************
// DO NOT modify the four functions below.
//***********************************************************************
void printInitialHeader() {
    cout << "----------------------------------------" << endl;
    cout << "               EECS 183                 " << endl;
    cout << "          Rock-Paper-Scissors           " << endl;
    cout << "----------------------------------------" << endl << endl;
    
    return;
}

void printMenu() {
    cout << endl << endl;
    cout << "Menu Options" << endl
        << "------------" << endl;
    cout << "1) Play rock, paper, scissors" << endl;
    cout << "2) Play rock, paper, scissors, lizard, spock" << endl;
    cout << "3) Quit" << endl << endl;
    
    cout << "Choice --> ";
    
    return;
}

void printErrorMessage(int errorNumber) {
    if (errorNumber == 1) {
        cout << endl << "ERROR: Illegal name given, using default" 
            << endl << endl;
    } else if (errorNumber == 2) {
        cout << endl << "ERROR: Illegal move given, using default" << endl;
    } else {
        cout << "This should never print!";
    }
    
    return;
}

void printCloser() {
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "           Thanks for playing           " << endl;
    cout << "          Rock-Paper-Scissors!          " << endl;
    cout << "----------------------------------------" << endl << endl;
    
    return;
}
