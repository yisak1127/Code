#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
   string fileName = "";
   string vowel = "vowels_";
   string outputFile = "";
   string str;
   long int pos;

   cin >> fileName;
   vowel += fileName;

   fstream in(fileName);

   while (getline(in, str))
   {
      string onlyVowels = "";
      for (char letter: str) {
         char upper = (char) toupper((int) letter);
         if (upper == 'A' || upper == 'E' || upper == 'I' || upper == 'O' || upper == 'U')
         {
            onlyVowels += letter;
         }
      }
      if(!in.eof())
         onlyVowels += "\n";

      pos = in.tellg();
      in.close();
      in.open(vowel, std::fstream::out | std::fstream::app);
      in << onlyVowels;
      in.close();
      in.open(fileName);
      in.seekg(pos);

   }

   return 0;
}