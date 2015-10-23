#include <iostream>
#include <assert.h>
#include <sys/stat.h>

#include "Enigma.hpp"

//Gets file extension of input file string
string getFileExt(const string &s);
//Checks if input file exists
bool fileExists(const char *file);
//Sets up enigma machine with correct plugboard and rotors
void setUpEnigmaMachine(Enigma *enigma, int numberOfEnigmaElements, char **enigmaElements);

int main(int argc, char **argv)
{
  assert(argc > 1 && "Error: arguments missing");

  //Initialise enigma
  Enigma* pEnigma = new Enigma();
  setUpEnigmaMachine(pEnigma, argc, argv);

  //Input message - encrypt message - output encryption

    string message;
    while(!cin.eof()) {
      cin >> ws;
      getline(cin, message);
      pEnigma->encryptMessage(message);
      cout << message;
    }
//  getline(cin, message);
//  pEnigma->encryptMessage(message);
//  cout << message << endl;
//  char inputLetter;
//  do
//  {
//    inputLetter = getchar();
//    if (!isspace(inputLetter))
//    {
//      int indexedLetter = toInt(inputLetter);
//      pEnigma->encryptLetter(indexedLetter);
//      inputLetter = toChar(indexedLetter);
//    }
//    putchar(inputLetter);
//  } while (!cin.eof());

  //Clear memory
  delete pEnigma;
  return 0;
}

string getFileExt(const string &s) {
  size_t i = s.rfind('.', s.length());
  if (i != string::npos) {
    return(s.substr(i + 1, s.length() - i));
  }
  return("");
}

bool fileExists(const char *file) {
  struct stat buf;
  return (stat(file, &buf) == 0);
}

void setUpEnigmaMachine(Enigma *enigma, int numberOfEnigmaElements, char **enigmaElements) {
  ifstream file;
  string fileExtension;

  enigma->setReflector();

  for (int i = 1; i < numberOfEnigmaElements; ++i)
  {
    //Throws error if file does not exist
    if (!fileExists(enigmaElements[i])) {
      throw "File does not exist";
    }

    fileExtension = getFileExt(enigmaElements[i]);

    //Rotor file case
    if (fileExtension == "rot") {
      file.open(enigmaElements[i]);
      if (file){
        enigma->addRotor(new Rotor(file));
        file.close();
        file.clear();
      }

    //Plugboard file case
    } else if (fileExtension == "pb")
    {
      file.open(enigmaElements[i]);
      if (file) {
        enigma->setPlugboard(new Plugboard(file));
        file.close();
        file.clear();
      }

    //Other
    } else
    {
      throw "Wrong type of file";
    }
  }
}