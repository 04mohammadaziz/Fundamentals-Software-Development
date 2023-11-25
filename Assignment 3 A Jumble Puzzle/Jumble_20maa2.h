//
// Created by 04Moh on 2022-11-08.
//

#ifndef CMPE320_A3_JUMBLE_20MAA2_H
#define CMPE320_A3_JUMBLE_20MAA2_H

#include <string>

using namespace std;

typedef char* charArrayPtr;

//JumblePuzzle class to generate a puzzle depending on hidden word and difficulty level
class JumblePuzzle {
public:
    //Main Constructor
    JumblePuzzle(const string& hiddenWord, const string& difficulty);
    //Copy Constructor
    JumblePuzzle(const JumblePuzzle&);
    //Destructor
    ~JumblePuzzle();
    //Overloading Assignment Operator
    JumblePuzzle& operator = (const JumblePuzzle&);

    //Accessors
    charArrayPtr* getJumble() const; //Get the matrix
    int getSize() const; //Gets the size for the matrix
    int getRowPos() const; //Gets the position of the rows
    int getColPos() const; //Gets the position of the columns
    char getDirection() const; // Direction of the rest of the word to be found by the user

private:
    //Initialize Variables
    charArrayPtr* jumble;
    string difficulty;
    int size;
    int row;
    int column;
    char direction;
};

//Exception class to throw an exception on non-legal arguments
class BadJumbleException {
public:
    BadJumbleException(string ); //constructor method to display error
    string& what(); //method called when thrown
private:
    string message; //message displayed
};

#endif //CMPE320_A3_JUMBLE_20MAA2_H
