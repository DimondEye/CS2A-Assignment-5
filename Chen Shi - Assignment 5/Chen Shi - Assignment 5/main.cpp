//
//  By Chen Shi - Assignment 5
//
//  This program will search for a given certain character in a given string,
//  mask, remove and/or count it.
//

#include <iostream>
#include <string>
using namespace std;

// Method prototypes
char getKeyCharacter();
string getString();
string maskLetter(string theString, char keyCharacter);
string removeCharacter(string theString, char keyCharacter);
int countKey(string theString, char keyCharacter);

// Global variables
char keyCharacter;
string theString;

int main()
{
   string result;
   int count;

   keyCharacter = getKeyCharacter();
   theString = getString();
   result = maskLetter(theString, keyCharacter);
   cout << "\nString with key character, '" << keyCharacter << "' masked: \n"
      << result << endl;
   result = removeCharacter(theString, keyCharacter);
   cout << "\nString with key character, '" << keyCharacter << "' removed: \n"
      << result << endl;
   count = countKey(theString, keyCharacter);
   cout << "\n# of occurrences of the key character, '" << keyCharacter
      << "': " << count << endl << endl;
}

// Ask user to input a single character
char getKeyCharacter()
{
   string temp;
   double length;

   do {
      cout << "Please enter a SINGLE Character to act as key: ";
      getline(cin, temp);
      length = temp.length();
   } while (length > 1 || length == 0);

   return temp[0];
}

// Ask user to input a phrase or sentence >= 4 characters
string getString()
{
   string temp;
   do {
      cout << "Please enter a phrase or sentence >= 4 characters: \n";
      getline(cin, temp);
   } while (temp.length() < 4);

   return temp;
}

// Mask the given character with dash
string maskLetter(string theString, char keyCharacter)
{
   string temp = "";

   for (int i = 0; i < theString.length(); i++)
   {
      if (theString[i] == keyCharacter) {
         temp = temp + "-";
      }
      else
         temp = temp + theString[i];
   }

   return temp;
}

// Remove the given character
string removeCharacter(string theString, char keyCharacter)
{
   string temp = "";

   for (int i = 0; i < theString.length(); i++) {
      if (theString[i] != keyCharacter) {
         temp = temp + theString[i];
      }
   }

   return temp;
}

// Count the occurrences of the given character
int countKey(string theString, char keyCharacter)
{
   int count = 0;

   for (int i = 0; i < theString.length(); i++) {
      if (theString[i] == keyCharacter) {
         count++;
      }
   }

   return count;
}

/* ------------------------RUN #1-----------------------------

Please enter a SINGLE Character to act as key: hello
Please enter a SINGLE Character to act as key: Hello Kitty
Please enter a SINGLE Character to act as key: 12345
Please enter a SINGLE Character to act as key: 
Please enter a SINGLE Character to act as key: m
Please enter a phrase or sentence >= 4 characters: 
mm
Please enter a phrase or sentence >= 4 characters: 
123
Please enter a phrase or sentence >= 4 characters: 

Please enter a phrase or sentence >= 4 characters: 
Good morning!

String with key character, 'm' masked: 
Good -orning!

String with key character, 'm' removed: 
Good orning!

# of occurrences of the key character, 'm': 1

------------------------------------------------------------ */

/* ------------------------RUN #2-----------------------------

Please enter a SINGLE Character to act as key: A
Please enter a phrase or sentence >= 4 characters: 
Percy Jackson and The Olympians

String with key character, 'A' masked: 
Percy Jackson and The Olympians

String with key character, 'A' removed: 
Percy Jackson and The Olympians

# of occurrences of the key character, 'A': 0

------------------------------------------------------------ */

/* ------------------------RUN #3-----------------------------
 
Please enter a SINGLE Character to act as key: 0
Please enter a phrase or sentence >= 4 characters: 
The secret code is 101 010 110 001 111 ABA.

String with key character, '0' masked: 
The secret code is 1-1 -1- 11- --1 111 ABA.

String with key character, '0' removed: 
The secret code is 11 1 11 1 111 ABA.

# of occurrences of the key character, '0': 6

------------------------------------------------------------ */

/*  ------------------------RUN #4-----------------------------

Please enter a SINGLE Character to act as key:  
Please enter a phrase or sentence >= 4 characters: 
{ { T h i s _ i s _ a _ l o n g _ s e n t e n c e. } }

String with key character, ' ' masked: 
{-{-T-h-i-s-_-i-s-_-a-_-l-o-n-g-_-s-e-n-t-e-n-c-e.-}-}

String with key character, ' ' removed: 
{{This_is_a_long_sentence.}}

# of occurrences of the key character, ' ': 26

------------------------------------------------------------ */















