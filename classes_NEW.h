#pragma once
#include <iostream>
#include <string>

using namespace std;

#define PLUS     0
#define MINUS    1
#define MULTIPLY 2
#define DIVIDE   3

class Coordinate {
private:
    int x;
    int y;

public:
    Coordinate() : x(0), y(0) {}
    Coordinate(int x, int y) : x(x), y(y) {}

    int getX() { 
        return x; 
    }
    int getY() { 
        return y; 
    }

    void setX(int value) { 
        x = value; 
    }
    void setY(int value) {
        y = value; 
    }
    void set(int X, int Y) {
        x = X;
        y = Y;
    }
};

class Objects {
protected:
    string x_type_of_object;
    Coordinate* coordinates;
    int c_length;

public:
    Objects();
    ~Objects();
    Objects(string type, int coordinate_length);

    int getCoordinatesLength() { 
        return c_length; 
    }

    string getType() { 
        return x_type_of_object; 
    }

    Coordinate getCoordinate(int index) { 
        return coordinates[index]; 
    }

    Coordinate* getAllCoordinates() { 
        return coordinates;
    }
    void setAllCoordinates(Coordinate* c, int length) {
        coordinates = c;
        c_length = length;
    }

    void setType(string type) { 
        x_type_of_object = type;
    }
    void setCoordinate(int index, int x, int y) {
        coordinates[index].setX(x);
        coordinates[index].setY(y);
    }

    void outObjects();
};

class Room
{
private:
    int length;
    Objects** house;

public:
    Room(int length_a) : length(length_a)
    {
        house = new Objects * [length] {0};
    }

    ~Room() {
        for (int i = 0; i < length; i++)
            delete house[i];
        delete[] house;
    }

    int getLength() {
        return length;
    }
    void addObject(int index, Objects* Object);
    void removeObject(int index);
    void resize(int new_size);
    void rearregement(int operation, int factor);
    Objects* getObject(int Objects_i);
};