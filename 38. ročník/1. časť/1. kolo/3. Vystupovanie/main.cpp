#include <iostream>
#include <algorithm>
#include <vector>

struct Zastavka {
	Zastavka(uint32_t vzdialenost, uint32_t index) {
		this->vzdialenost = vzdialenost;
		this->index = index;
	}

	uint32_t vzdialenost;
	uint32_t index;
};

bool operator> (const Zastavka &l, const Zastavka &r) {
	return l.vzdialenost > r.vzdialenost ||
		(l.vzdialenost == r.vzdialenost ? l.index > r.index : false);
}
bool operator< (const Zastavka &l, const Zastavka &r) {
	return l.vzdialenost < r.vzdialenost ||
		(l.vzdialenost == r.vzdialenost ? l.index < r.index : false);
}
bool operator== (const Zastavka &l, const Zastavka &r) {
	return l.vzdialenost == r.vzdialenost && l.index == r.index;
}
bool operator!= (const Zastavka &l, const Zastavka &r) {
	return l.vzdialenost != r.vzdialenost || l.index != r.index;
}

uint32_t pocetZastavok, pocetOtazok;
std::vector<Zastavka> zastavky;

int32_t binarne_vyhladavanie(uint32_t vzdialenost, uint32_t minimalnyIndex, uint32_t maximalnyIndex) {
	int32_t mid, low = 0;
	int32_t high = zastavky.size();
	while (true) {
		mid = low + (high - low) / 2;
		if (low >= high && (zastavky[mid] < Zastavka(vzdialenost, minimalnyIndex)
			|| zastavky[mid] > Zastavka(vzdialenost, maximalnyIndex))) break;

		if (zastavky[mid] < Zastavka(vzdialenost, minimalnyIndex))
			low = mid + 1;
		else if (zastavky[mid] > Zastavka(vzdialenost, maximalnyIndex))
			high = mid - 1;
		else if (low != mid)
			high = mid;
		else
			return mid;
	}

	return -1;
}

void otazka() {
	uint32_t zaciatocnaZastavka, koncovaZastavka,
		vyzadovanaVzdialenost, vyzadovanePoradie;

	std::cin >> zaciatocnaZastavka;
	std::cin >> koncovaZastavka;
	std::cin >> vyzadovanaVzdialenost;
	std::cin >> vyzadovanePoradie;

	int32_t result = binarne_vyhladavanie(vyzadovanaVzdialenost, zaciatocnaZastavka, koncovaZastavka);
	if (result == -1) {
		std::cout << -1 << std::endl;
		return;
	}

	if (result + vyzadovanePoradie > zastavky.size()) {
		std::cout << -1 << std::endl;
		return;
	}
	Zastavka zastavka = zastavky[result + vyzadovanePoradie - 1];

	if (zastavka.vzdialenost != vyzadovanaVzdialenost || zastavka.index < zaciatocnaZastavka || zastavka.index > koncovaZastavka) {
		std::cout << -1 << std::endl;
		return;
	}

	std::cout << zastavka.index << std::endl;
}

int main() {
	std::cin >> pocetZastavok;
	std::cin >> pocetOtazok;

	zastavky.reserve(pocetZastavok);

	for (uint32_t i = 0; i < pocetZastavok; ++i) {
		uint32_t vzdialenost;
		std::cin >> vzdialenost;
		zastavky.push_back(Zastavka(vzdialenost, i + 1));
	}

	std::sort(zastavky.begin(), zastavky.end(), [](const Zastavka& l, const Zastavka& r) {
		return l < r;
	});


		

	for (uint32_t i = 0; i < pocetOtazok; ++i)
		otazka();

	return 0;
}