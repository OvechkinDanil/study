#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <vector>
#include <sstream>
#include <sstream>
using namespace std;
std::vector<string> StringParcing(std::string str)
{
  std::istringstream iss(str);
  std::vector<std::string> tokens;
  std::copy(std::istream_iterator<std::string>(iss),
    std::istream_iterator<std::string>(),
    std::back_inserter<std::vector<std::string> >(tokens));
  return tokens;
}
std::vector<string> TextParcing(string filename)
{
  std::string str;
  std::vector<string> s, words;
  ifstream input(filename);
  while (!input.eof())
  {
    std::getline(input, str);
    s = StringParcing(str);
    for (i = 0; i < s.size(); i++)
    {
      words.push_back(s[i]);
    }
  }
  return words;
}
void PrintSpaces(int num)
{
  int i;
  for (i = 0; i < num; i++)
  {
    cout << " ";
  }
}
int WordDivision(std::vector<string> words, int &i, int size, int rest)
{
  int curSize = 0, WordInd = 0, j = 0, WordSize = 0;
  const char* CharWord;

  WordSize = (int)words[i].size();
  CharWord = words[i].c_str();
  while (rest != 0)
  {
    cout << CharWord[WordInd];
    WordInd += 1;
    WordSize -= 1;
    rest -= 1;
  }
  if (WordInd != 0)
    cout << endl;
  while (WordSize >= size)
  {
    for (j = k;j < WordInd + size; j++)
      cout << CharWord[j];
    cout << endl;
    WordInd += size;
    WordSize -= size;
  }
  curSize = WordSize;
  while (WordSize > 0)
  {
    cout << CharWord[WordInd];
    WordInd += 1;
    WordSize -= 1;
  }
  if (curSize != 0)
  {
    cout << " ";
    return curSize + 1;
  }
  else
    return curSize;
}
void PrintString(std::vector<string> words,int curSize, int i, int count, int size)
{
  int spaces = 0, SpaceBetweenWords = 0, j;
  spaces = size - curSize;
  SpaceBetweenWords = spaces / (count - 1);
  if (SpaceBetweenWords < 0)
    return;
  for (j = i - count; j < i; j++)
    {
      cout << words[j];
      if (spaces < SpaceBetweenWords)
        PrintSpaces(spaces);
      else
        PrintSpaces(SpaceBetweenWords);
      spaces -= SpaceBetweenWords;
    }
    cout << endl;
}
void JustifyText(std::vector<string> words, int size)
{
  int curSize = 0, i = 0, NumWords = 0, count = 0, j = 0, k = 0;
  NumWords = words.size();
  while (i < NumWords)
  {
    if (words[i].size() > size - curSize)
    {
      curSize = WordDivision(words, i, size, size - curSize);
      i += 1;
      if (curSize == size)
        cout << endl;
      continue;
    }
    while (curSize < size)
    {
      if (curSize + (int)words[i].size() + count > size)
      {
        break;
      }
      curSize += words[i].size();
      i += 1;
      count += 1;
      if (i >= NumWords)
        break;
    }
    if (count == 1)
    {
      cout << words[i - 1] << endl;
      count = 0;
      curSize = 0;
      continue;
    }
    PrintString(words, curSize, i, count, size);
    count = 0;
    curSize = 0;
  }
}
int main(int argc, char *argv[])
{
  int size = 0;
  std:stringstream convert(argv[2]);
  std::vector<string> words;

  convert >> size;
  words = TextParcing(argv[1]);
  JustifyText(words, size);

  return 0;
}
