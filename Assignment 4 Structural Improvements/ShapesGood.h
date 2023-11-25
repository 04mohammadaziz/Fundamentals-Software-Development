//
// Created by 04Moh on 2022-11-21.
//

#ifndef CMPE_320_A4_SHAPESGOOD_H
#define CMPE_320_A4_SHAPESGOOD_H

#include <iostream>
#include <string>

using namespace std;

//Base class that is inherited from the rest of the shapes
class Shape {
public:
    Shape();
    Shape(int len, int wid);
    virtual ~Shape();
    int getLength();
    int getWidth();
    virtual void draw();

private:
    int length;
    int width;
};


//Sub Class Square that is inherited from the Shape class
class Square: public Shape {
public:
    Square(int len, int wid, string BC);
    ~Square();
    void draw();
    string getBC();
private:
    string borderColour;
};

//Sub Class FilledSquare inherited from the Square class, and extending parent class Fillable to indicate a filled shape
class FilledSquare : public Square {
public:
    FilledSquare(int len, int wid, string BC, string FC);
    ~FilledSquare();
    void draw();
    string getFC();
private:
    string fillColour;
};

//Sub Class FilledTextSquare inherited from the FilledSquare class, and extending parent class Labeled to get the text label
class FilledTextSquare : public FilledSquare {
public:
    FilledTextSquare(int len, int wid, string BC, string FC, string text);
    ~FilledTextSquare();
    void draw();
    string getText();
private:
    string text;
};

//Sub Class Circle inherited from base class Shape
class Circle : public Square {
public:
    Circle(int len, int wid, string BC);
    ~Circle();
    void draw();
};

//Sub Class FilledCircle inherited from base class Circle, and extended parent class Fillable
class FilledCircle : public FilledSquare {
public:
    FilledCircle(int len, int wid, string BC, string FC);
    ~FilledCircle();
    void draw();
};

//Sub Class Arc inherited from base class Shape
class Arc : public Square {
public:
    Arc(int len, int wid, string BC);
    ~Arc();
    void draw();
};

#endif //CMPE_320_A4_SHAPESGOOD_H
