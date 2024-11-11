#include "app.h"
#include <iostream>

// read number of results
// read all student data
// read grade and output grade statistics
// read letter and output letter statistics
int main()
{
	using namespace vsite::oop::v3;

	uint32_t broj_rezultata;
	std::cout << "unesi broj studenata: \n";
	std::cin >> broj_rezultata;

	results Rez(broj_rezultata);

	for (uint32_t i = 0; i < broj_rezultata; ++i)
	{
		std::string name;
		uint32_t grade;


		std::cout << "Unesi ime studenta {}:\n", i + 1;
		std::cin >> name;
		std::cout << "Unesi ocjenu studenta {}:\n", i + 1;
		std::cin >> grade;

		Rez.add(student(name, grade));
	}

	uint32_t statistika_ocjene;
	std::cout << "Unesi ocjenu za provjeru statistike: \n";
	std::cin >> statistika_ocjene;

	uint32_t broj_ocjene = Rez.has_grade(statistika_ocjene);
	std::cout << "Broj studenata sa ocjenom " << statistika_ocjene << ": " << broj_ocjene << "\n";

	char slovo;
	std::cout << "Unesi slovo za provjeru statistike imena: \n";
	std::cin >> slovo;

	uint32_t broj_slova = Rez.starts_with_letter(slovo);
	std::cout << "Broj studenata cije ime pocinje na slovo '" << slovo << "': " << broj_slova << "\n";

}
