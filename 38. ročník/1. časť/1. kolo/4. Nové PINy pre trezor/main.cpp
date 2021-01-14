#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, uint32_t> pins;

size_t pinLength;
uint32_t pinCount;

uint32_t pinConstruct(uint32_t* pinDistance, std::string value) {
	for (size_t i = 0; i < pinLength; ++i) {
		for (char j = 48; j < 68; ++j) {
			std::string key = value;
			if (key[i] == j) continue;
			key[i] = j;

			auto iterator = pins.find(key);
			if (iterator == pins.end()) continue;

			const uint32_t distance = iterator->second + abs(value[i] - j);
			if (*pinDistance < distance) *pinDistance = distance;
		}
	}

	return *pinDistance;
}


int main() {
	std::cin >> pinLength;
	std::cin >> pinCount;

	uint32_t total = 0;
	for (uint32_t i = 0; i < pinCount; ++i) {
		std::string value;
		std::cin >> value;

		const uint32_t distance = pinConstruct(&pins.emplace(value, uint32_t()).first->second, value);
		if (total < distance) total = distance;
	}
	std::cout << total << std::endl;

}*/

#include <iostream>
#include <string>

int32_t* pins;

size_t pinLength;
uint32_t pinCount;

uint32_t powers[] = {
	1,
	10,
	100,
	1000,
	10000,
	100000
};

uint32_t pinIndex(const std::string& key) {
	uint32_t total = 0;
	for (size_t i = 0; i < pinLength; ++i) {
		total += (key[pinLength - i - 1] - 48) * powers[i];
	}
	return total;
}

int32_t pinConstruct(int32_t* pinDistance, std::string value) {
	*pinDistance = 0;
	for (size_t i = 0; i < pinLength; ++i) {
		for (char j = 48; j < 58; ++j) {
			std::string key = value;
			if (key[i] == j) continue;
			key[i] = j;

			const int32_t pin = pins[pinIndex(key)];
			if (pin == -1) continue;

			const int32_t distance = pin + abs(value[i] - j);
			if (*pinDistance < distance) *pinDistance = distance;
		}
	}

	return *pinDistance;
}


int main() {
	std::cin >> pinLength;
	std::cin >> pinCount;

	pins = new int32_t[powers[pinLength]];
	for (uint32_t i = 0; i < powers[pinLength]; ++i) pins[i] = -1;

	

	int32_t total = 0;
	for (uint32_t i = 0; i < pinCount; ++i) {
		std::string value;
		std::cin >> value;

		const int32_t distance = pinConstruct(&pins[pinIndex(value)], value);
		if (total < distance) total = distance;
	}
	std::cout << total << std::endl;
}