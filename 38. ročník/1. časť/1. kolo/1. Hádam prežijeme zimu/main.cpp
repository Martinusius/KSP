#include <iostream>

int main() {
	uint32_t pocet;
	std::cin >> pocet;

	uint16_t cislo;

	bool timkaSpoluParne = true;
	bool maTimkaParne = false, maTimkaNeparne = false;
	for (uint32_t i = 0; i < pocet; ++i) {
		std::cin >> cislo;

		const bool parne = cislo % 2 == 0;
		timkaSpoluParne = timkaSpoluParne == parne;

		if (parne) maTimkaParne = true;
		else maTimkaNeparne = true;
	}

	bool gabikaSpoluParne = true;
	bool maGabikaParne = false, maGabikaNeparne = false;
	for (uint32_t i = 0; i < pocet; ++i) {
		std::cin >> cislo;

		const bool parne = cislo % 2 == 0;
		gabikaSpoluParne = gabikaSpoluParne == parne;

		if (parne) maGabikaParne = true;
		else maGabikaNeparne = true;
	}

	if (timkaSpoluParne != gabikaSpoluParne) {
		std::cout << "nie" << std::endl;
		return 0;
	}

	if (timkaSpoluParne) {
		if (maTimkaParne == maGabikaParne || maTimkaNeparne && maGabikaNeparne) {
			std::cout << "ano" << std::endl;
		}
		else {
			std::cout << "nie" << std::endl;
		}
	}
	else {
		if (maTimkaNeparne && maGabikaParne || maTimkaParne && maGabikaNeparne) {
			std::cout << "ano" << std::endl;
		}
		else {
			std::cout << "nie" << std::endl;
		}
	}

	return 0;
}