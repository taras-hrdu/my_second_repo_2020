#pragma once
#include <iostream>
#include <string>

using namespace std;

#define PLUS     0
#define MINUS    1
#define MULTIPLY 2
#define DIVIDE   3

class coordinate {
private:
    int x;
    int y;

public:
    coordinate() : x(0), y(0) {}
    coordinate(int x, int y) : x(x), y(y) {}

    int getX() { return x; }
    int getY() { return y; }

    void setX(int value) { x = value; }
    void setY(int value) { y = value; }
    void set(int X, int Y) {
        x = X;
        y = Y;
    }
};

class objects {
protected:
    string x_typeOfObject;
    coordinate* coordinates;
    int c_length;

public:
    objects();
    ~objects();
    objects(string type, int coordinate_length);

    int getCoordinatesLength() { return c_length; }

    string getType() { return x_typeOfObject; }

    coordinate getCoordinate(int index) { return coordinates[index]; }

    coordinate* getAllCoordinates() { return coordinates; }
    void setAllCoordinates(coordinate* c, int l) {
        coordinates = c;
        c_length = l;
    }

    void setType(string type) { x_typeOfObject = type; }
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
    objects** House;

public:
    Room(int a) : length(a)
    {
        House = new objects * [length] {0};
    }

    ~Room() {
        for (int i = 0; i < length; i++)
            delete House[i];
        delete[] House;
    }

    int getLength() {
        return length;
    }
    void addObject(int index, objects* Object);
    void removeObject(int index);
    void resize(int new_size);
    void Rearregement(int operation, int factor);
    objects* getObject(int i);


    // objects* tmp = House[idx1];
    // House[idx1] = House[idx2];
    // House[idx2] = tmp;

/*void Rearregement() {
    coordinate* c;
    int l;
    coordinate* first;
    int first_len;
    int idx = -1, last_idx = -1;
    for (int i = 0; i < length; i++) {
        if (House[i] != 0) {
            c = House[i]->getAllCoordinates();
            l = House[i]->getCoordinatesLength();
            if (idx != -1) {
                House[idx]->setAllCoordinates(c, l);
                last_idx = i;
            } else {
                first = c;
                first_len = l;
            }
        } else {
            while (House[i] == 0) {
                i++;
            }
        }
        idx = i;
    }
    House[last_idx]->setAllCoordinates(first, first_len);
}*/
};