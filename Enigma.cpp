#include <iostream>

#include "Enigma.hpp"

Enigma::Enigma()
{
  rotors = new vector<Rotor*>;
}

Enigma::~Enigma()
{
  rotors->clear();
  delete rotors;
  delete plugboard;
  delete reflector;
}

void Enigma::setPlugboard(Plugboard* p)
{
  plugboard = p;
}

void Enigma::setReflector()
{
  reflector = new Reflector();
}

void Enigma::addRotor(Rotor* r)
{
  rotors->push_back(r);

}

void Enigma::rotateRotors()
{
  for (vector<Rotor *>::iterator it = rotors->begin(); it != rotors->end(); ++it)
  {
    int temp = (*it)->getNumberOfRevolutions();
    (*it)->rotate();
    if ((it + 1) != rotors->end())
    {
      (*(it + 1))->adjustAfterRotation();
    }
    if ((*it)->getNumberOfRevolutions() == temp)
    {
      break;
    }
  }
}

void Enigma::encryptLetter(int &letter)
{
  plugboard->encode(letter);
  for (vector<Rotor*>::iterator it = rotors->begin(); it != rotors->end(); ++it)
  {
    (*it)->encode(letter);
  }
  reflector->encode(letter);
  for (vector<Rotor*>::reverse_iterator rit = rotors->rbegin(); rit != rotors->rend(); ++rit)
  {
    (*rit)->inverseEncode(letter);
  }
  plugboard->encode(letter);
  rotateRotors();
}


void Enigma::encryptMessage(string &message)
{
  for (int i = 0; i < message.size(); i++) {
    char& workingLetter = message.at(i);
    if (!isspace(workingLetter))
    {
      int indexInAlp = toInt(workingLetter);
      encryptLetter(indexInAlp);
      workingLetter = toChar(indexInAlp);
    } else {
      workingLetter = '\0';
    }

  }
}
