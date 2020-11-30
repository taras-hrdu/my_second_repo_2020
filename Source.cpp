#include "classes.h"

objects::objects() {
    x_typeOfObject = " ";
}

objects::~objects() {
    delete[] coordinates;
}

objects::objects(string type, int coordinate_length) {
    x_typeOfObject = type;
    c_length = coordinate_length;
    coordinates = new coordinate[c_length];
}

void objects::outObjects() {
    cout << "Type: " << x_typeOfObject << endl;
    for (int i = 0; i < c_length; i++) {
        cout << "x: " << coordinates[i].getX() << " y: " << coordinates[i].getY() << endl;
    }
}
void Room::addObject(int index, objects* Object)
{
    if (index >= 0 && index < length)
        House[index] = Object;
    else
        cout << "Index not in bounds" << endl;
}

void Room::removeObject(int index) {
    if (index >= 0 && index < length) {
        if (House[index] != 0) {
            delete House[index];
            House[index] = nullptr;
        }
        else {
            cout << "Object at index " << index << " is not allocated!" << endl;
        }
    }
}

objects* Room::getObject(int i) { return House[i]; }

void Room::resize(int new_size)
{
    objects** tmp = new objects * [new_size];
    for (int i = 0; i < length; i++)
        tmp[i] = House[i];
    delete[] House;
    House = tmp;
    length = new_size;
}

void Room::Rearregement(int operation, int factor) {
    switch (operation) {
    case PLUS:
        for (int i = 0; i < length; i++) {
            if (House[i] != 0) {
                for (int j = 0; j < House[i]->getCoordinatesLength(); j++)
                    House[i]->setCoordinate(j,
                        House[i]->getCoordinate(j).getX() + factor,
                        House[i]->getCoordinate(j).getY() + factor
                    );
            }
        }
        break;
    case MINUS:
        for (int i = 0; i < length; i++) {
            if (House[i] != 0) {
                for (int j = 0; j < House[i]->getCoordinatesLength(); j++)
                    House[i]->setCoordinate(j,
                        House[i]->getCoordinate(j).getX() - factor,
                        House[i]->getCoordinate(j).getY() - factor
                    );
            }
        }
        break;
    case MULTIPLY:
        for (int i = 0; i < length; i++) {
            if (House[i] != 0) {
                for (int j = 0; j < House[i]->getCoordinatesLength(); j++)
                    House[i]->setCoordinate(j,
                        House[i]->getCoordinate(j).getX() * factor,
                        House[i]->getCoordinate(j).getY() * factor
                    );
            }
        }
        break;
    case DIVIDE:
        for (int i = 0; i < length; i++) {
            if (House[i] != 0) {
                for (int j = 0; j < House[i]->getCoordinatesLength(); j++)
                    House[i]->setCoordinate(j,
                        House[i]->getCoordinate(j).getX() / factor,
                        House[i]->getCoordinate(j).getY() / factor
                    );
            }
        }
        break;
    default:
        cout << "Undefined operation" << endl;
    }
}