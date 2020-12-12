#include "classes.h"

Objects::Objects() {
    x_type_of_object = " ";
}

Objects::~Objects() {
    delete[] coordinates;
}

Objects::Objects(string type, int coordinate_length) {
    x_type_of_object = type;
    c_length = coordinate_length;
    coordinates = new Coordinate[c_length];
}

void Objects::outObjects() {
    cout << "Type: " << x_type_of_object << endl;
    for (int i = 0; i < c_length; i++) {
        cout << "x: " << coordinates[i].getX() << " y: " << coordinates[i].getY() << endl;
    }
}
void Room::addObject(int index, Objects* Object)
{
    if (index >= 0 && index < length)
        house[index] = Object;
    else
        cout << "Index not in bounds" << endl;
}

void Room::removeObject(int index) {
    if (index >= 0 && index < length) {
        if (house[index] != 0) {
            delete house[index];
            house[index] = nullptr;
        }
        else {
            cout << "Object at index " << index << " is not allocated!" << endl;
        }
    }
}

Objects* Room::getObject(int i) { return house[i]; }

void Room::resize(int new_size)
{
    Objects** tmp = new Objects * [new_size];
    for (int i = 0; i < length; i++)
        tmp[i] = house[i];
    delete[] house;
    house = tmp;
    length = new_size;
}

void Room::rearregement(int operation, int factor) {
    switch (operation) {
    case PLUS:
        for (int i = 0; i < length; i++) {
            if (house[i] != 0) {
                for (int j = 0; j < house[i]->getCoordinatesLength(); j++)
                    house[i]->setCoordinate(j,
                        house[i]->getCoordinate(j).getX() + factor,
                        house[i]->getCoordinate(j).getY() + factor
                    );
            }
        }
        break;
    case MINUS:
        for (int i = 0; i < length; i++) {
            if (house[i] != 0) {
                for (int j = 0; j < house[i]->getCoordinatesLength(); j++)
                    house[i]->setCoordinate(j,
                        house[i]->getCoordinate(j).getX() - factor,
                        house[i]->getCoordinate(j).getY() - factor
                    );
            }
        }
        break;
    case MULTIPLY:
        for (int i = 0; i < length; i++) {
            if (house[i] != 0) {
                for (int j = 0; j < house[i]->getCoordinatesLength(); j++)
                    house[i]->setCoordinate(j,
                        house[i]->getCoordinate(j).getX() * factor,
                        house[i]->getCoordinate(j).getY() * factor
                    );
            }
        }
        break;
    case DIVIDE:
        for (int i = 0; i < length; i++) {
            if (house[i] != 0) {
                for (int j = 0; j < house[i]->getCoordinatesLength(); j++)
                    house[i]->setCoordinate(j,
                        house[i]->getCoordinate(j).getX() / factor,
                        house[i]->getCoordinate(j).getY() / factor
                    );
            }
        }
        break;
    default:
        cout << "Undefined operation" << endl;
    }
}