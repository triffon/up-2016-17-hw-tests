#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

const char LOWERCASE_VOWELS[6] = {'a', 'e', 'i', 'u', 'o', 'y'};
const char* CONSONANT_ENDING = "ay";
const char* VOWEL_ENDING = "way";

bool isUppercaseLetter(char symbol)
{
	return symbol >= 'A' && symbol <= 'Z';
}

bool isLowercaseLetter(char symbol)
{
	return symbol >= 'a' && symbol <= 'z';
}

bool isLetter(char symbol)
{
	return isUppercaseLetter(symbol) || isLowercaseLetter(symbol);
}

char toLowercase(char letter)
{
	if (isUppercaseLetter(letter))
		return letter + 'a' - 'A';
	else
		return letter;
}

char toUppercase(char letter)
{
	if (isLowercaseLetter(letter))
		return letter + 'A' - 'a';
	else
		return letter;
}

bool isVowel(char letter)
{
	for (int i = 0; i < 6; ++i)
		if (toLowercase(letter) == LOWERCASE_VOWELS[i])
			return true;
	return false;
}

bool isConsonant(char letter)
{
	return isLetter(letter) && !isVowel(letter);
}

unsigned int countLeadingLetters(char* word)
{
	unsigned int length = 0;
	while (isLetter(word[length]))
	{
		length += 1;
	}
	return length;
}

unsigned int countLeadingConsonants(char* word, unsigned int wordLength)
{
	unsigned int leadingConsonants = 0;
	while (isConsonant(word[leadingConsonants]) && leadingConsonants <= wordLength)
	{
		leadingConsonants += 1;
	}
	return leadingConsonants;
}

bool isWordUppercased(char* word, unsigned int wordLength)
{
	if (wordLength == 1)
		return false;
	return isUppercaseLetter(word[0]) && isUppercaseLetter(word[1]);
}

bool isWordLowercased(char* word, unsigned int wordLength)
{
	if (wordLength == 1)
		return isLowercaseLetter(word[0]);
	return isLowercaseLetter(word[0]) && isLowercaseLetter(word[1]);
}

bool isWordTitlecase(char* word, unsigned int wordLength)
{
	if (wordLength == 1)
		isUppercaseLetter(word[0]);
	return isUppercaseLetter(word[0]) && isLowercaseLetter(word[1]);
}

void wordToUppercase(char* word, unsigned int wordLength)
{
	for (int i = 0; i < wordLength; ++i)
	{
		word[i] = toUppercase(word[i]);
	}
}

void wordToLowercase(char* word, unsigned int wordLength)
{
	for (int i = 0; i < wordLength; ++i)
	{
		word[i] = toLowercase(word[i]);
	}
}

void wordToTitlecase(char* word, unsigned int wordLength)
{
	wordToLowercase(word, wordLength);
	word[0] = toUppercase(word[0]);
}

void fixCase(char* word, unsigned int wordLength,
			char* pigLatinWord, unsigned int pigLatinWordLength)
{
	if (isWordUppercased(word, wordLength))
		wordToUppercase(pigLatinWord, pigLatinWordLength);
	else if (isWordLowercased(word, wordLength))
		wordToLowercase(pigLatinWord, wordLength);
	else if (isWordTitlecase(word, wordLength))
		wordToTitlecase(pigLatinWord, wordLength);
}

// returns the pig latin word length
unsigned int wordToPigLatin(char* word, unsigned int wordLength, char* pigLatinBuffer)
{
	unsigned int leadingConsonants = countLeadingConsonants(word, wordLength);
	unsigned int write = 0;

	for (int i = leadingConsonants; i < wordLength; ++i, ++write)
	{
		pigLatinBuffer[write] = word[i];
	}

	for (int i = 0; i < leadingConsonants; ++i, ++write)
	{
		pigLatinBuffer[write] = word[i];
	}

	const char* ending = (leadingConsonants == 0) ? VOWEL_ENDING : CONSONANT_ENDING;
	unsigned int endingLength = strlen(ending);

	for (int i = 0; i < endingLength; ++i, ++write)
	{
		pigLatinBuffer[write] = ending[i];
	}

	fixCase(word, wordLength, pigLatinBuffer, write);

	return write;
}

int main()
{
	const unsigned int MAX_CHARACTERS = 10000;
	char text[MAX_CHARACTERS];
	char pigLatinText[MAX_CHARACTERS * 3];
	cin.getline(text, MAX_CHARACTERS);

	unsigned int wordLength = 0, written = 0;

	unsigned int read = 0;
	char* startOfWord;
	unsigned int write = 0;
	char* pigLatinWrite;

	unsigned int textLength = strlen(text);
	while (read < textLength)
	{
		if (isLetter(text[read]))
		{
			startOfWord = text + read;
			wordLength = countLeadingLetters(startOfWord);
			pigLatinWrite = pigLatinText + write;
			written = wordToPigLatin(startOfWord, wordLength, pigLatinWrite);
			write += written;
			read += wordLength;
		}
		else
		{
			pigLatinText[write] = text[read];
			read += 1;
			write += 1;
		}
	}
	pigLatinText[write] = '\0';

	cout << pigLatinText << endl;

	return 0;
}
