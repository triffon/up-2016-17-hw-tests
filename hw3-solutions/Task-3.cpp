#include <iostream>
using namespace std;

const int MaxTextLength = 10000;

bool isLetter(const char* symbol, bool detectDash = false)
{
    return *symbol >= 'A' && *symbol <= 'Z' ||
           *symbol >= 'a' && *symbol <= 'z' ||
           detectDash && *symbol == '-' && isLetter(symbol-1) && isLetter(symbol+1);
}

char* getWordEnd(char* word)
{
    while (*word && isLetter(word, true))
        ++word;
    return word;
}

char* getWordStart(char* text)
{
    while (*text && !isalpha(*text))
        ++text;
    return *text ? text : NULL;
}

void rotateWord(char* begin, char* end, unsigned n)
{
    int len = end - begin;
    n = n % len;
    for (int l = 0, r = len-1; l < r; ++l, --r)
        swap(begin[l], begin[r]);
    for (int l = 0, r = n-1; l < r; ++l, --r)
        swap(begin[l], begin[r]);
    for (int l = n, r = len-1; l < r; ++l, --r)
        swap(begin[l], begin[r]);
}

int main()
{
    char text[MaxTextLength];
    cin.getline(text, MaxTextLength);
    unsigned n;
    cin >> n;

    char *begin = text, *end = text;
    while (begin = getWordStart(end))
    {
        end = getWordEnd(begin+1);
        rotateWord(begin, end, n);
        begin = end;
    }

    cout << text << endl;
    return 0;
}
