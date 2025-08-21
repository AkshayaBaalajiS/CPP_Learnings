#include <iostream>
#include <typeinfo>
using namespace std;

//--library--------
struct GameObject {
    virtual void collideswitch(GameObject &rhs) = 0;
    virtual void collided() = 0;
};

struct Asteroid : GameObject {
    void collided() {
        cout << "Asteroid Collided....\n";
    }
    void collideswitch(GameObject &rhs) {
        cout << "Asteroid Object got collided with.....\n";
        rhs.collided();
    }
};

struct Ship : GameObject {
    void collideswitch(GameObject &rhs) {
        cout << "Ship Object got collided with.....\n";
        rhs.collided();
    }
    void collided() {
        cout << "Ship Collided....\n";
    }
};

struct Satellite : GameObject {
    void collided() {
        cout << "Satellite Collided....\n";
    }
    void collideswitch(GameObject &rhs) {
        cout << "Satellite Object got collided with.....\n";
        rhs.collided();
    }
};

void collide(GameObject &lhs, GameObject &rhs) {
    if (typeid(lhs) != typeid(rhs)) {
        lhs.collideswitch(rhs);
    } else {
        cout << "typeid(lhs).name()   :" << typeid(lhs).name() << "   Same Object cannot be collided...    " << "typeid(rhs).name()  :" << typeid(rhs).name() << "\n";
    }
}

//---application-----
int main() {
    Asteroid aObj;
    Ship sObj;
    Satellite saObj;

    cout << "------------------------------------\n";
    collide(aObj, sObj);
    collide(aObj, saObj);
    collide(sObj, saObj);
    collide(sObj, sObj);

    cout << "------------------------------------\n";

    Asteroid aObj2;

    cout << "------------------------------------\n";
    collide(aObj, aObj2);

    cout << "------------------------------------\n";
}
