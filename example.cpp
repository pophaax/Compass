#include <iostream>
#include <unistd.h>
#include "HMC6343.h"
#include "Compass.h"
#include "MockCompass.h"

int main() {
	std::cout << "Compass example" << std::endl;
	std::cout << "---------------" << std::endl;
    std::cout << "creating object" << std::endl;
    HMC6343 c;
//    MockCompass c;
	Compass* compass = &c;
	std::cout << "object created" << std::endl;

	std::cout << "initialization: " << compass->init() << std::endl;
	while(true) {
		compass->readValues();
		std::cout << "heading : " << compass->getHeading() << "\t"
				<< "pitch : " << compass->getPitch() << "\t"
				<< "roll : " << compass->getRoll() << std::endl;
		usleep(2000);
	}
}
