#include <iostream>


int main() {
	uint16_t pocetVyplat;
	std::cin >> pocetVyplat;

	for (uint16_t i = 0; i < pocetVyplat; ++i) {
		uint16_t pocetMinci;
		std::cin >> pocetMinci;

		bool vypisatRiesenie;
		std::cin >> vypisatRiesenie;

		const uint16_t zvysok = pocetMinci % 4;
		std::cout << (zvysok == 0 || zvysok == 3 ? 0 : 1) << std::endl;

		

		if (vypisatRiesenie) {
			uint16_t poradie = 0;

			std::cout << (pocetMinci / 4) * 2 + (pocetMinci % 4 >= 1);
			for (uint16_t j = pocetMinci; j > 0; --j) {
				if(poradie % 4 == 0 || poradie % 4 == 3) std::cout << ' ' << j;
				++poradie;
			}
			std::cout << std::endl;
			poradie = 0;

			std::cout << (pocetMinci / 4) * 2 + (pocetMinci % 4 >= 2) + (pocetMinci % 4 >= 3);
			for (uint16_t j = pocetMinci; j > 0; --j) {
				if (poradie % 4 == 1 || poradie % 4 == 2) std::cout << ' ' << j;
				++poradie;
			}
			std::cout << std::endl;
		}
	}

	return 0;
}