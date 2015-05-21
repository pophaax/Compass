#include <iostream>
#include <unistd.h>
#include "HMC6343.h"
#include "Compass.h"
#include "MockCompass.h"
#include <vectormath_aos.h>

int main() {
	std::cout << "Compass example" << std::endl;
	std::cout << "---------------" << std::endl;
    std::cout << "creating object" << std::endl;
    HMC6343 c;
//    MockCompass c;
	Compass* compass = &c;
	std::cout << "object created" << std::endl;

	std::cout << "initialization: " << compass->init() << std::endl;
	int compHeading = 0;
	while(true) {
		compass->readValues();
		std::cout << "heading : " << compass->getHeading() << "\t"
				<< "pitch : " << compass->getPitch() << "\t"
				<< "roll : " << compass->getRoll() << std::endl;
		compHeading = Vectormath::Aos::Quat::Quat(0,0,1, compass->getRoll()) *
				Vectormath::Aos::Quat::Quat(1,0,0, compass->getPitch()) *
				Vectormath::Aos::Quat::Quat(0,1,0, compass->getRoll());
		std::cout << "compensated heading : "<<compHeading<< std::endl;
		usleep(2000);
	}
}
