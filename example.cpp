#include <iostream>
#include "Compass.h"
#include "MockCompass.h"

int main() {
	std::cout << "Compass example" << std::endl;
	std::cout << "---------------" << std::endl;
    std::cout << "creating object" << std::endl;

	Compass compass;

	std::cout << "initialization: " << compass.init() << std::endl;

	while(true) {
		compass.readValues();
		std::cout << "heading\t: " << compass.getHeading() << std::endl;
		std::cout << "pitch\t: " << compass.getPitch() << std::endl;
		std::cout << "roll\t: " << compass.getRoll() << std::endl;
		std::cout << std::endl;
	}
}
