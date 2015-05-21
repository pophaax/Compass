#include <iostream>
#include <unistd.h>
#include "HMC6343.h"
#include "Compass.h"
#include "MockCompass.h"
#include <math.h>

int main() {
	std::cout << "Compass example" << std::endl;
	std::cout << "---------------" << std::endl;
    std::cout << "creating object" << std::endl;
    HMC6343 c;
//    MockCompass c;
	Compass* compass = &c;
	std::cout << "object created" << std::endl;

	std::cout << "initialization: " << compass->init() << std::endl;
	double compHeading = 0;
	while(true) {
		compass->readValues();
		std::cout << "heading : " << compass->getHeading() << "\t"
				<< "pitch : " << compass->getPitch() << "\t"
				<< "roll : " << compass->getRoll() << std::endl;
		compHeading =  cos(a/2) +( 0 * sin(compass->getRoll()/2)) + 0 ( sin(compass->getRoll()/2)) + ( 1 * sin(compass->getRoll()/2))
				* cos(a/2) +( 1 * sin(compass->getPitch()/2)) + 0 ( sin(compass->getPitch()/2)) + ( 0 * sin(compass->getPitch()/2))
				* cos(a/2) +( 0 * sin(compass->getHeading()/2)) + 1 ( sin(compass->getHeading()/2)) + ( 0 * sin(compass->getHeading()/2));
		std::cout << "compensated heading : "<<compHeading<< std::endl;
		usleep(2000);
	}
}
