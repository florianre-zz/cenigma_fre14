#include <vector>

#ifndef MAPPER_HPP
#define MAPPER_HPP

using namespace std;

class Mapper
{
protected:
  /* Vector of pairs of integers (between 0 and 25) where the first element of a pair is the original letter
   * and the second element the encoded letter */
  vector<pair<int, int> >* p_mapper;
public:
  Mapper();
  ~Mapper();
  // Inserts a pair consisting of letter and encryptedLetter in the vector
  void insertInMapper(int letter, int encryptedLetter);
  // Encodes the input letter
  virtual void encode(int& letter) =0;
};

#endif
