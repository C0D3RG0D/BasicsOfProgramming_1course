#pragma once
#include <cstring>

namespace str {
	
	void to_lower(char& c) {
		if (c >= 65 && c <= 90)
			c += 32;
	}

	void to_upper(char& c) {
		if (c >= 97 && c <= 122)
			c -= 32;
	}

	bool is_letter(char c) {
		to_lower(c);
		if (c >= 97 && c <= 122)
			return true;
		return false;
	}

	void text_lower(char* string) {
		int len = strlen(string);
		for (int i = 0; i < len; ++i) {
			to_lower(string[i]);
		}
	}

	void text_upper(char* string) {
		int len = strlen(string);
		for (int i = 0; i < len; ++i) {
			to_upper(string[i]);
		}
	}

	bool is_vowel(char c) {
		char vowel_letters[] = "aeiouy";
		int n = 6;
		to_lower(c);

		for (int i = 0; i < n; ++i) {
			if (c == vowel_letters[i])
				return true;
		}
		return false;
	}

	bool is_consonant(char c) {
		char consonant_letters[] = "bcdfghjklmnpqrstvwxz";
		int n = 20;
		to_lower(c);

		for (int i = 0; i < n; ++i) {
			if (c == consonant_letters[i])
				return true;
		}
		return false;
	}

	bool is_consonantOrdered(char* string) {;
		for (int i = 0; string[i + 1] != '\0'; ++i) {
			if (string[i] > string[i + 1])
				return false;
		}

		return true;
	}


	int div_in_words(char words[100][100], char* string) {
		char word[100] = "";
		int i = 0;
		int size = 0;
		int k = 0;

		text_lower(string);

		while (i < strlen(string)) {
			if (is_letter(string[i])) {
				word[size] = string[i];
				size++;
			}
			else {
				word[size] = '\0';
				if (strlen(word) > 0) {
					strcpy_s(words[k], word);
					size = 0;
					k++;
				}
			}
			i++;
		}
		return k;
	}

	int alphabet_sort(char* lsh, char* rsh) {
		int n = strlen(lsh) < strlen(rsh) ? strlen(lsh) : strlen(rsh);

		for (int i = 0; i < n; ++i) {
			if (lsh[i] < rsh[i])
				return -1;
			if (lsh[i] > rsh[i])
				return 1;
		}
		return 0;
	}

	bool con_let_in_word(char* string) {
		int n = strlen(string);
		int k = 0;

		for (int i = 0; i < n; ++i) {
			if (is_consonant(string[i]))
				k++;
		}

		return k <= 3 ? true : false;
	}

	int consonant_word_sort(char temp[100][100], char words[100][100], int n) {
		int count = 0;
		for (int i = 0; i < n; ++i) {
			if (con_let_in_word(words[i])) {
				strcpy_s(temp[count], words[i]);
				count++;
			}
		}
		return count;
	}

	int other_word_sort(char other[100][100], char words[100][100], int n) {
		int k = 0;
		for(int i = 0; i < n; ++i) {
			if (!con_let_in_word(words[i])) {
				strcpy_s(other[k], words[i]);
				k++;
			}
		}
		return k;
	}

	bool dublicate_letter(char word[100]) {
		int len = strlen(word);
		char tmp[100];
		strcpy_s(tmp, word);
		text_lower(tmp);

		for (int i = 0; i < len - 1; ++i) {
			if (tmp[i] == tmp[i + 1])
				return true;
		}
		
		return false;
	}


}