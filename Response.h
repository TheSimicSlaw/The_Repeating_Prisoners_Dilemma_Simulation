#include <iostream>

enum Response
{
  COOPERATE,
  DEFECT
};

std::ostream &operator<<(std::ostream &out, Response response)
{
  if (response == COOPERATE)
  {
    out << "COOPERATE";
  }
  else
  {
    out << "DEFECT";
  }

  return out;
}
