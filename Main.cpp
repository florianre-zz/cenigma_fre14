#include <iostream>
#include <assert.h>
#include <sys/stat.h>

#include "Enigma.hpp"
#include "Utils.hpp"

//Gets file extension of input file string
string getFileExt(const string& s);
//Checks if input file exists
bool fileExists(const char* file);
//Sets up enigma machine with correct plugboard and rotors
void setUpEnigmaMachine(Enigma* enigma, int argc, char **argv);

int main(int argc, char **argv)
{
  assert(argc > 1 && "Error: arguments missing");

  //Initialise enigma
  Enigma* pEnigma = new Enigma();
  setUpEnigmaMachine(pEnigma, argc, argv);

  //Encrypt input message
  string message;
  getline(cin, message);

  for (int i = 0; i < message.size(); i++) {
    if (message.at(i) != ' ')
    {
      int indexInAlp = toInt(message.at(i));
      pEnigma->encryptLetter(indexInAlp);
      message.at(i) = toChar(indexInAlp);
    }
  }

  cout << message << endl;

  //Clear memory
  delete pEnigma;
  return 0;
}

string getFileExt(const string& s) {
  size_t i = s.rfind('.', s.length());
  if (i != string::npos) {
    return(s.substr(i+1, s.length() - i));
  }
  return("");
}

bool fileExists(const char* file) {
  struct stat buf;
  return (stat(file, &buf) == 0);
}

void setUpEnigmaMachine(Enigma* enigma, int argc, char **argv) {
  ifstream file;
  string fileExtension;

  enigma->setReflector();
  for (int i = 1; i < argc; ++i)
  {
    if (!fileExists(argv[i])) {
      cerr << "File does not exist" << endl;
      throw;
    }

    fileExtension = getFileExt(argv[i]);

    if (fileExtension == "rot") {
      file.open(argv[i]);
      if (file){
        enigma->addRotor(new Rotor(file));
        file.close();
        file.clear();
      }

    } else if (fileExtension == "pb")
    {
      file.open(argv[i]);
      if (file) {
        enigma->setPlugboard(new Plugboard(file));
        file.close();
        file.clear();
      }
    } else //Other
    {
      cout << "Error";
    }
  }
}