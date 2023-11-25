
#include "ShapesGood.h"
//default constructor
Shape::Shape():length(0), width(0){}
//constructor for parent class Shape
Shape::Shape(int len, int wid):length(len), width(wid){}
//destructor
Shape::~Shape(){}
//default draw() function for parent class
void Shape::draw() {}

//Getters for Length and Width
int Shape::getLength() {return length;}
int Shape::getWidth() {return width;}

//Base square function using polymorphism
Square::Square(int len, int wid, string BC): Shape(len, wid), borderColour(BC) {} //constructor
//Destructor
Square::~Square(){}
//Get borderColour
string Square::getBC() {return borderColour;}
//Drawing the square in the specified colour
void Square::draw() {cout<<"\nDrawing a "<<getBC()<<" square.";}

//Constructor
FilledSquare::FilledSquare(int len, int wid, string BC, string FC): Square(len, wid, BC), fillColour(FC) {}
//Destructor
FilledSquare::~FilledSquare(){}
//Get the colour we need to fill
string FilledSquare::getFC() {return fillColour;}
//Drawing to fill the square with colours
void FilledSquare::draw() {
    Square::draw();
    cout<<" With "<<getFC()<<" fill.";
}

//Constructor
FilledTextSquare::FilledTextSquare(int len, int wid, string BC, string FC, string text): FilledSquare(len, wid, BC, FC), text(text) {}
//Destructor
FilledTextSquare::~FilledTextSquare(){}
//Get the text
string FilledTextSquare::getText() {return text;}
//Drawing to fill the square with colours and text
void FilledTextSquare::draw() {
    FilledSquare::draw();
    cout<<" Containing the text: \""<<getText()<<"\".";
}

//Constructor
Circle::Circle(int len, int wid, string BC): Square(len, wid, BC) {}
//Destructor
Circle::~Circle(){}
//Drawing a circle with the base colour chosen
void Circle::draw(){
    cout<<"\nDrawing a "<<getBC()<<" circle.";
}

//Constructor
FilledCircle::FilledCircle(int len, int wid, string BC, string FC): FilledSquare(len, wid, BC, FC) {}
//Destructor
FilledCircle::~FilledCircle(){}
//Drawing to fill in the circle with colours
void FilledCircle::draw(){
    cout<<"\nDrawing a "<<getBC()<<" cricle.";
    cout<<" With "<<getFC()<<" fill.";
}

//Constructor
Arc::Arc(int len, int wid, string BC) : Square(len, wid, BC) {}
//Destructor
Arc::~Arc(){}
//Drawing a circle with the base colour chosen
void Arc::draw() {
    cout<<"\nDrawing a "<<getBC()<<" arc.";
}
