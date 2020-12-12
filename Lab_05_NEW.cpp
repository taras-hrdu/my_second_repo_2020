#include "classes.h"

int main(int argc, const char* argv[]) {
    Room r(5);

    r.addObject(0, new Objects("table", 4));
    r.addObject(1, new Objects("Bed", 4));
    r.addObject(2, new Objects("Carpet", 4));
    r.addObject(3, new Objects("Sofa", 4));
    r.addObject(4, new Objects("Shafa", 4));

    r.getObject(0)->setCoordinate(0, 1, 2);
    r.getObject(1)->setCoordinate(0, 3, 4);
    r.getObject(2)->setCoordinate(0, 5, 6);
    r.getObject(3)->setCoordinate(0, 7, 8);

    r.removeObject(4);

    for (int i = 0; i < r.getLength(); i++)
        if (r.getObject(i) != 0)
            r.getObject(i)->outObjects();

    r.rearregement(PLUS, 2);
    r.rearregement(MULTIPLY, 3);
    r.rearregement(DIVIDE, 2);
    r.rearregement(MINUS, 3);
    cout << "\n";

    for (int i = 0; i < r.getLength(); i++)
        if (r.getObject(i) != 0)
            r.getObject(i)->outObjects();
}