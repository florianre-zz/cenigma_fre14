#include "Enigma.hpp"

Enigma::Enigma()
{
  // Created empty vectors of pointers of Rotors
  p_rotors = new vector<Rotor *>;
}

Enigma::~Enigma()
{
  p_rotors->clear();
  delete p_rotors;
  delete p_plugboard;
  delete p_reflector;
}

void Enigma::setPlugboard(Plugboard *p)
{
  p_plugboard = p;
}

void Enigma::setReflector()
{
  p_reflector = new Reflector();
}

void Enigma::addRotor(Rotor* r)
{
  p_rotors->push_back(r);
}

void Enigma::rotateRotors()
{
  for (vector<Rotor *>::iterator it = p_rotors->begin(); it != p_rotors->end(); ++it)
  {
    (*it)->rotate();
    if ((it + 1) != p_rotors->end())
    {
      (*(it + 1))->adjustAfterRotation();
    }
    if (!(*it)->hasCompletedARevolution())
    {
      break;
    }
  }
}

void Enigma::encrypt(int &letter)
{
  p_plugboard->encode(letter);
  for (vector<Rotor *>::iterator it = p_rotors->begin(); it != p_rotors->end(); ++it)
  {
    (*it)->encode(letter);
  }
  p_reflector->encode(letter);
  for (vector<Rotor *>::reverse_iterator rit = p_rotors->rbegin(); rit != p_rotors->rend(); ++rit)
  {
    (*rit)->inverseEncode(letter);
  }
  p_plugboard->encode(letter);
  rotateRotors();
}
