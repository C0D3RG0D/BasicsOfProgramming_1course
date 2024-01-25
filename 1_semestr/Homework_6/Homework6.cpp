#include <iostream>
#include <algorithm>
#include <fstream>
#include "Homework6.hpp"

int main6() {
	setlocale(LC_ALL, "Rus");
	// Çàäàíèå 1
	/*Äàí ôàéë, ñîäåðæàùèé ðóññêèé òåêñò. Íàéòè â òåêñòå N<=2000 ñàìûõ äëèííûõ ñëîâ, â êîòîðûõ ñîãëàñíûå áóêâû óïîðÿäî÷åíû ïî àëôàâèòó. 
	Çàïèñàòü íàéäåííûå ñëîâà â òåêñòîâûé ôàéë â ïîðÿäêå íåâîçðàñòàíèÿ äëèíû. Âñå íàéäåííûå ñëîâà äîëæíû áûòü ðàçíûìè!*/

	/*const int MAX_LENGTH = 100;
	const int MAX_WORDS = 2000;

	std::fstream input("input.txt");
	std::fstream output("output.txt");

	char words[MAX_WORDS][MAX_LENGTH] = {0};
	char word[MAX_LENGTH + 1];
	char tmp[MAX_LENGTH + 1];
	int word_count = 0;

	while (input >> tmp) {
		int len = 0;
		for (int i = 0; i < strlen(tmp); ++i) {
			if (!str::is_letter(tmp[i]))
				tmp[i] = '\0';
			

			str::to_lower(tmp[i]);

			if (str::is_consonant(tmp[i]))
				word[len++] = tmp[i];
		}
		word[len] = '\0';

		bool consonantOrdered = str::is_consonantOrdered(word);
		bool uniq = true;

		for (int i = 0; i < word_count; ++i) {
			if (!strcmp(tmp, words[i])) {
				uniq = false;
				break;
			}
		}


		if ((consonantOrdered && uniq) && len > 0) {
			strcpy_s(words[word_count], tmp);
			word_count++;
		}
	}

	for (int i = 0; i < word_count - 1; ++i) {
		for (int j = 0; j < word_count - 1; ++j) {
			if (strlen(words[j]) < strlen(words[j + 1]))
				std::swap(words[j], words[j + 1]);
		}
	}
	
	for (int i = 0; i < word_count; ++i) {
		output << words[i] << std::endl;
	}*/


	//Çàäàíèå 2

	/*Äàíà ñòðîêà, ñîäåðæàùàÿ ðóññêèé òåêñò. Âûâåñòè â àëôàâèòíîì ïîðÿäêå ñëîâà òåêñòà, ñîäåðæàùèå íå áîëåå 3-õ ñîãëàñíûõ, 
	â îñòàëüíûõ ñëîâàõ óäàëèòü ãëàñíûå è ïðîäóáëèðîâàòü ñîãëàñíûå áóêâû.*/

	/*char string[200] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
	char words[100][100];
	char consonant_words[100][100];
	char other[100][100];

	int len = strlen(string);
	string[len] = '.';
	string[len + 1] = '\0';

	int count_words = str::div_in_words(words, string);

	int n = str::consonant_word_sort(consonant_words, words, count_words);
	int m = str::other_word_sort(other, words, count_words);

	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - 1; ++j) {
			if (str::alphabet_sort(consonant_words[j], consonant_words[j + 1]) == 1)
				std::swap(consonant_words[j], consonant_words[j + 1]);
		}
	}

	int i = 0;
	while (i < m) {
		char word[100];
		int len = 0;

		for (int j = 0; j < strlen(other[i]); ++j) {
			if (str::is_consonant(other[i][j])) {
				word[len++] = other[i][j];
				word[len++] = other[i][j];
			}
		}
		word[len] = '\0';
		strcpy_s(other[i], word);
		i++;
	}


	for (int i = 0; i < n; ++i)
		std::cout << consonant_words[i] << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < m; ++i)
		std::cout << other[i] << std::endl << std::endl;*/


	//Çàäàíèå 3
	/*Â òåêñòîâîì ôàéëå input.txt çàïèñàí ðóññêèé òåêñò. Íàéòè â òåêñòå ñëîâà, ñîäåðæàùèå äâå îäèíàêîâûå áóêâû ïîäðÿä, 
	çàïèñàòü èõ çàãëàâíûìè áóêâàìè è óêàçàòü ïîñëå êàæäîãî òàêîãî ñëîâà â ñêîáêàõ íàéäåííûå áóêâû. 
	Ïîëó÷åííûé òåêñò çàïèñàòü â ôàéë output.txt. Âåñü òåêñò, êðîìå íàéäåííûõ ñëîâ, äîëæåí îñòàòüñÿ íåèçìåííûì, âêëþ÷àÿ è çíàêè ïðåïèíàíèÿ.*/

	const int MAX_LENGTH = 100;
	const int MAX_WORDS = 2000;

	std::fstream input("input.txt");
	std::fstream output("output.txt");

	char words[MAX_WORDS][MAX_LENGTH] = { 0 };
	char word[MAX_LENGTH + 1];
	char tmp[MAX_LENGTH + 1];

	int word_count = 0;

	while (input >> tmp) {
		if (str::dublicate_letter(tmp))
			str::text_upper(tmp);

		strcpy_s(words[word_count], tmp);
		word_count++;
	}

	for (int i = 0; i < word_count; ++i) {
		output << words[i] << ' ';
	}


	return 0;
}