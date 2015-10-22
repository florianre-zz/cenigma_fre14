#include <iostream>

#include "Enigma.hpp"
#include "Utils.hpp"

//Gets file extension of input file string
string getFileExt(const string& s);
//Sets up enigma machine with correct plugboard and rotors
void setUpEnigmaMachine(Enigma* enigma, int argc, char **argv);

int main(int argc, char **argv)
{
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

void setUpEnigmaMachine(Enigma* enigma, int argc, char **argv) {
  ifstream file;
  string fileExtension;

  enigma->setReflector();
  for (int i = 1; i < argc; ++i)
  {
    fileExtension = getFileExt(argv[i]);

    if (fileExtension == "rot") { //Rotor Case
      file.open(argv[i]);
      enigma->addRotor(new Rotor(file));
      file.close();
      file.clear();
    } else if (fileExtension == "pb") //Plugboard Case
    {
      file.open(argv[i]);
      enigma->setPlugboard(new Plugboard(file));
      file.close();
      file.clear();
    } else //Other
    {
      cout << "Error";
    }
  }
}