#include <iostream>
#include <cstring>

class Car {
public:
    char* model;
    int year;

    Car(const char* carModel, int carYear) {
        model = new char[strlen(carModel) + 1];
        strcpy(model, carModel);
        year = carYear;
    }

    ~Car() {
        delete[] model;
    }

    void display() const {
        std::cout << "Car Model: " << model << ", Year: " << year << std::endl;
    }
};

class Person {
public:
    char* name;
    Car* car;  // Association with Car class

    Person(const char* personName) {
        name = new char[strlen(personName) + 1];
        strcpy(name, personName);
        car = nullptr;  // Initially no car associated
    }

    ~Person() {
        delete[] name;
    }

    void setCar(Car* personCar) {
        car = personCar;
    }

    void display() const {
        std::cout << "Person Name: " << name << std::endl;
        if (car) {
            car->display();
        } else {
            std::cout << "No car associated" << std::endl;
        }
    }
};

int main() {
    // Create a Car object
    Car myCar("Toyota Corolla", 2020);

    // Create a Person object
    Person person("John Doe");

    // Associate the Car with the Person
    person.setCar(&myCar);

    // Display information about the Person and their Car
    person.display();

    return 0;
}
