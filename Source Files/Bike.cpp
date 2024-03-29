#include "../Header Files/Bike.h"

// Constructors for initialising different types of bike objects
Bike::Bike(Vehicle *vehicle) {

}

Bike::Bike() {
    this->number_of_wheels = 0;
    this->engine_size = 0;
}

Bike::Bike(int engineSize, int numberOfWheels) : engine_size(engineSize), number_of_wheels(numberOfWheels) {

}

// Destructor for deallocating memory
Bike::~Bike() {

}

// Creates a bike object and returns a pointer to it
Bike *Bike::createBike() {
    cout << "Please enter age: \n";
    age = Vehicle::userInput(age);
    cout << "Please enter registration number: \n";
    cin >> reg_number;
    cout << "Please enter make: \n";
    cin >> make;
    cout << "Please enter model: \n";
    cin >> model;
    cout << "Please enter engine size: \n";
    engine_size = Vehicle::userInput(engine_size);
    cout << "Please enter two or three wheeler: \n";
    number_of_wheels = numberOfWheels(number_of_wheels);

    Bike *b = new Bike(engine_size, number_of_wheels);
    b->setAge(age);
    b->setRegNumber(reg_number);
    b->setMake(make);
    b->setModel(model);
    b->setType("bike");
    return b;
}

// Checks the user enters two or three wheels
int Bike::numberOfWheels(int no_of_wheels) {
    no_of_wheels = 0;
    while(true){
        no_of_wheels = Vehicle::userInput(no_of_wheels);
        if (no_of_wheels == 2 || no_of_wheels == 3){
            break;
        } else {
            cout<<"Please enter two or three wheels: \n";
        }
    }
    return no_of_wheels;
}

// Menu for searching for a bike
void Bike::searchForBike(vector<Vehicle *> &vec) {
    int option = 0;
    do {
        cout << "Search for a bike by :\n";
        cout << "--------------------\n";
        cout << "1) Registration number\n";
        cout << "2) Max engine size\n";
        cout << "3) Two or Three-wheeler\n";
        cout << "9) Return to main menu\n";
        cout << "Please choose an option:\n";
        option = Vehicle::userInput(option);
        switch (option) {
            case 1:
                searchByRegNumber(vec);
                break;
            case 2:
                searchByEngineSize(vec);
                break;
            case 3:
                searchByTwoOrThreeWheeler(vec);
                break;
            default:
                cout << "Please enter option above\n";
                break;
        }

    } while (option != 9);
}

// Searches for bikes by registration number
void Bike::searchByRegNumber(vector<Vehicle *> &vec) {
    cout << "Please enter registration number: \n";
    string reg_number;
    cin >> reg_number;
    cout << "\n";
    cout << "   List of bikes matching that search: \n";
    cout << "   Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "   ------------------ - ------------      ----------\n";
    for (auto &i: vec) {
        int index = 1;
        if (i->getRegNumber() == reg_number && i->getType() == "bike") {
            cout << index << "  " << i->getRegNumber() << "\t\t\t\t\t" << typeid(i).name() << " \n";
        }
        ++index;
    }
    cout << "\n";
}

// Searches for bikes by engine size
void Bike::searchByEngineSize(vector<Vehicle *> &vec) {
    cout << "Please enter engine size\n";
    int engine_size = 0;
    engine_size = Vehicle::userInput(engine_size);
    cout << "   List of bikes matching that search: \n";
    cout << "   Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "   ------------------ - ------------      ----------\n";
    for (auto &item: vec) {
        int index = 1;
        if (item->getType() == "bike") {
            Bike *bike = dynamic_cast<Bike *>(item);
            if (bike->getEngineSize() == engine_size) {
                cout << index << "  " << bike->getRegNumber() << "\t\t\t\t\t" << bike->getType() << " \n";
            }
        }
        ++index;
    }
    cout << "\n";
}

// Searches for bikes by two or three wheels
void Bike::searchByTwoOrThreeWheeler(vector<Vehicle *> &vector) {
    cout << "Would you like to search by two or three wheeler: \n";
    int no_of_wheels = 0;
    no_of_wheels = Vehicle::userInput(no_of_wheels);
    cout << "   List of bikes matching that search: \n";
    cout << "   Registration Number  Cost Per Day	Vehicle Type\n";
    cout << "   ------------------ - ------------      ----------\n";
    for (auto &item: vector) {
        int index = 1;
        if (item->getType() == "bike") {
            Bike *bike = dynamic_cast<Bike *>(item);
            if (bike->getNumberOfWheels() == no_of_wheels) {
                cout << index << "  " << bike->getRegNumber() << "\t\t\t\t\t" << bike->getType() << " \n";
            }
        }
        ++index;
    }
}

// Returns the cost per day for each bike
int Bike::getCostPerDay() {
    int costPerDay = (1500 + getEngineSize());
    return costPerDay;
}

