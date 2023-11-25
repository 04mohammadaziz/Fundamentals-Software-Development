#include <time.h>

#include "Jumble_20maa2.h"


using namespace std;

// Exception to throw error message
BadJumbleException::BadJumbleException(string message) : message(std::move(message)) {}
    string &BadJumbleException::what() {
        return message;
    }

    //Constructor containing hidden word and difficulty of the puzzle
JumblePuzzle::JumblePuzzle(const string &hiddenWord, const string &difficulty) {
    //Throw exception if the correct word limit is not applied
    if (hiddenWord.length() > 10 || hiddenWord.length() < 3)
        throw BadJumbleException("Error, Length of word must be between 3 to 10 characters");
    if (difficulty != "easy" && difficulty != "medium" && difficulty != "hard")
        throw BadJumbleException("Error, Difficulty selection must be easy, medium or hard.");

    this->difficulty = difficulty;

    //Setting difficulty levels
    if (difficulty == "easy") {
        size = 2 * hiddenWord.length();
    } else if (difficulty == "medium") {
        size = 3 * hiddenWord.length();
    } else if (difficulty == "hard") {
        size = 4 * hiddenWord.length();
    }

    //Add random letters to each row and column
    jumble = new char *[size];

    for (int i = 0; i < size; i++) {
        jumble[i] = new char[size];

        //Seed random number generator
        srand(time(nullptr));

        for (int j = 0; j < size; j++) {
            jumble[i][j] = 'a' + rand() % 26;
        }
    }

    //Hide the word at the specific coordinates
    row = rand() % size;
    column = rand() % size;

    //Place the first letter in the randomized location
    jumble [row][column] = hiddenWord.at(0);
    //String directions
    const char* dir = "nesw";
    bool wordPlacement = 0;

    while (!wordPlacement){

        //Picking random direction
        direction = dir [rand() % 4];

        //Placing characters going upwards
        if (direction == 'n'){
            for (int i = 1; i < hiddenWord.length(); i++)
            {
                //Out of bounds
                if ((row-i) < 0)
                    break;
                    //Last letter
                else if (i == (hiddenWord.length() - 1)){

                    jumble[row-i][column] = hiddenWord.at(i);
                    wordPlacement = 1;
                }
                else
                    jumble[row-i][column] = hiddenWord.at(i);
            }
        }
        //Placing characters going right
        else if (direction == 'e'){
            for (int i = 1; i < hiddenWord.length(); i++){
                //Out of bounds
                if ((column+i) > (hiddenWord.length()-1))
                    break;
                //Last letter
                else if (i == (hiddenWord.length() - 1)){
                    jumble[row][column+i] = hiddenWord.at(i);
                    wordPlacement = 1;
                }
                else
                    jumble[row][column+i] = hiddenWord.at(i);
            }
        }
        //Placing characters going down
        else if (direction == 's'){
            for (int i = 1; i < hiddenWord.length(); i++){
                //Out of bounds
                if ((row+i) > (hiddenWord.length()-1))
                    break;
                //Last letter
                else if (i == (hiddenWord.length() - 1)){
                    jumble[row+i][column] = hiddenWord.at(i);
                    wordPlacement = 1;
                }
                else
                    jumble[row+i][column] = hiddenWord.at(i);
            }
        }
        //Placing characters going left
        else{
            for (int i = 1; i < hiddenWord.length(); i++){
                //Out of bonds
                if ( (column-i) < 0 )
                    break;
                //Last letter
                else if (i == (hiddenWord.length() - 1)){
                    jumble[row][column-i] = hiddenWord.at(i);
                    wordPlacement = 1;
                }
                else
                    jumble[row][column-i] = hiddenWord.at(i);
            }
        }
    }
}

//Copy Constructor
JumblePuzzle::JumblePuzzle(const JumblePuzzle & right) {
    //All accessors from other JumblePuzzle
    size = right.getSize();
    row = right.getRowPos();
    column = right.getColPos();
    direction = right.getDirection();

    //Copying values intro matrix from other JumblePuzzle and copying arrays in isolation on the heap
    jumble = new charArrayPtr [right.size];
    for (int i = 0; i < size; i++) {
        jumble[i] = new char[right.size];
    }

    for (int i = 0; i < right.size; i++){
        for (int j = 0; j < right.size; j++){
            jumble[i][j] = right.jumble[i][j];
        }
    }
}

int JumblePuzzle::getSize() const { //get size of puzzle
    return size;
}

int JumblePuzzle::getRowPos() const { //get row of jumble
    return row;
}

int JumblePuzzle::getColPos() const { //get column of jumble
    return column; }

char JumblePuzzle::getDirection() const { //get direction of jumble
    return direction; }

    //Destructor
JumblePuzzle::~JumblePuzzle() {
    //Delete everything in the jumble
    for (int i = 0; i < size; i++)
        delete jumble [i];
    delete [] jumble;
}

    //Comparison Operator
JumblePuzzle &JumblePuzzle::operator = (const JumblePuzzle & right) {
    if (this != &right) {
        size = right.getSize();
        row = right.getRowPos();
        column = right.getColPos();
        direction = right.getDirection();

        //Deleting the old jumble
        for (int i = 0; i < size; i++)
            delete[] jumble[i];
        delete[] jumble;

        //Copying the new jumble over
        for (int i = 0; i < right.size; i++)
            jumble[i] = new char[right.size];

        jumble = new charArrayPtr[right.size];

        for (int i = 0; i < right.size; i++) {
            for (int j = 0; j < right.size; j++) {
                jumble[i][j] = right.jumble[i][j];
            }
        }
    }
    return *this;
}

    //Accessor methods from playGame()
charArrayPtr* JumblePuzzle::getJumble() const {
    charArrayPtr* newJumble = new char*[size];

    //Create copy of jumble and return it
    for (int i = 0; i < size; i++)
        newJumble[i] = new char[size];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
            newJumble[i][j] = jumble[i][j];
    }

    return newJumble;
}








