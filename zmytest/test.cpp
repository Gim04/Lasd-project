#include "testVecList/test.hpp"
#include "testSet/test.hpp"

/* ************************************************************************** */

#include <iostream>

using namespace std;

/* ************************************************************************** */

void mytest() {
  cout << endl << "~*~#~*~ Welcome to the LASD My test Suite ~*~#~*~ " << endl;

  uint loctestnum, loctesterr;
  uint stestnum = 0, stesterr = 0;


  loctestnum = 0; loctesterr = 0;
  myTestVecList(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;

  loctestnum = 0; loctesterr = 0;
  myTestSet(loctestnum, loctesterr);
  stestnum += loctestnum; stesterr += loctesterr;


  cout << endl << "My test (Errors/Tests: " << stesterr << "/" << stestnum << ")";

  cout << endl << "Goodbye!" << endl;
}
