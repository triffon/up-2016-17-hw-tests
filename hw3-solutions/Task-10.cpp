#include <iostream>
#include <cstring>

using std::cout;
using std::cin;

void init(int* letters)
{
  for (int i = 0; i < 26; i++) {
    letters[i] = -1;
  }
}

int letter_number(char letter)
{
  return letter - 'A';
}

bool read_table(int* letters)
{
  bool valid = true;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      char letter;
      cin>>letter;
      int number = letter_number(letter);
      if (number < 0 || number > 26 || letters[number] != -1) {
        valid = false;
      } else {
        letters[number] = i*5 + j;
      }
    }
  }
  return valid;
}

char find_sub(int* letters)
{
  if (letters[23] == -1) {
    return 'Z';
  }
  return 'X';
}

char find_not_in_table(int* letters)
{
  for (int i = 0; i < 26; i++) {
    if (letters[i] == -1) {
      return i + 'A';
    }
  }
}

void add_sub_at_the_end_if_needed(char* buffer, char sub)
{
  int len = strlen(buffer);
  if(len % 2 != 0){
    buffer[len] = sub;
    buffer[len + 1] = '\0';
  }
}

void capitalize(char* buffer)
{
  while (*buffer){
    if (*buffer >= 'a' && *buffer <= 'z') {
      *buffer += 'A' - 'a';
    }
    buffer++;
  }
}

void sub_chars(char* buffer, char sub, char not_in_table)
{
  while
 (*buffer){
    if (*buffer == not_in_table || *buffer < 'A' || *buffer > 'Z') {
      *buffer = sub;
    }
    buffer++;
  }
}

void transform(char* buffer, char sub, char not_in_table)
{
  add_sub_at_the_end_if_needed(buffer, sub);
  capitalize(buffer);
  sub_chars(buffer, sub, not_in_table);
}

char find_letter_in_table(int row_col, int* table)
{
  for (int i = 0; i < 26; i++) {
    if (table[i] == row_col) {
      return i + 'A';
    }
  }
}

void encode_two_letters(char &first, char &second, int* table, char sub)
{
  if (first == second) {
    if (first != sub) {
      second = sub;
    } else {
      return;
    }
  }
  int first_cr = table[letter_number(first)];
  int second_cr = table[letter_number(second)];
  int first_col = first_cr % 5;
  int first_row = first_cr / 5;
  int second_col = second_cr % 5;
  int second_row = second_cr / 5;
  if (first_col == second_col) {
    first_row += 1;
    second_row += 1;
    first_row %= 5;
    second_row %= 5;
  } else if (first_row == second_row) {
    first_col += 1;
    second_col += 1;
    first_col %= 5;
    second_col %= 5;
  } else {
    int temp = first_col;
    first_col = second_col;
    second_col = temp;
  }
  first = find_letter_in_table(first_row*5 + first_col, table);
  second = find_letter_in_table(second_row*5 + second_col, table);
}

void encode(char* buffer, int* table, char sub)
{
  while (*buffer) {
    encode_two_letters(buffer[0], buffer[1], table, sub);
    buffer += 2;
  }
}

int main()
{
  int letters[26];
  init(letters);
  bool valid = read_table(letters);
  if (!valid){
    cout<<"Bad table!\n";
  } else {
    char sub = find_sub(letters);
    char not_in_table = find_not_in_table(letters);
    char buffer[201];
    cin.get(buffer, 201);
    while (true){
      cin.getline(buffer, 201);
      int len = strlen(buffer);
      transform(buffer, sub, not_in_table);
      encode(buffer, letters, sub);
      cout<<buffer;
      if (len != 200) {
        break;
      }
    }
    cout<<"\n";
  }
  return 0;
}
