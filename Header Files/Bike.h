#pragma once

#include "Vehicle.h"

class Bike : public Vehicle {

private:
    int engine_size, number_of_wheels;

public:
    Bike(Vehicle *vehicle);

    Bike();

    Bike(int engineSize, int numberOfWheels);

    int getCostPerDay() override;

    ~Bike();

    int numberOfWheels(int no_of_wheels);

    inline int getEngineSize() const;

    inline void setEngineSize(int engineSize);

    inline int getNumberOfWheels() const;

    inline void setNumberOfWheels(int numberOfWheels);

    Bike *createBike();

    static void searchForBike(vector<Vehicle *> &vec);

    static void searchByEngineSize(vector<Vehicle *> &vec);

    static void searchByTwoOrThreeWheeler(vector<Vehicle *> &vector);

    static void searchByRegNumber(vector<Vehicle *> &vec);
};

int Bike::getEngineSize() const {
    return engine_size;
}

void Bike::setEngineSize(int engineSize) {
    engine_size = engineSize;
}

int Bike::getNumberOfWheels() const {
    return number_of_wheels;
}

void Bike::setNumberOfWheels(int numberOfWheels) {
    number_of_wheels = numberOfWheels;
}