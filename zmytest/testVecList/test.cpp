
#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/mappable.hpp"
#include "../../zlasdtest/container/linear.hpp"

#include "../../zlasdtest/vector/vector.hpp"

#include "../../zlasdtest/list/list.hpp"

/* ************************************************************************** */

using namespace std;


void mytestVectorInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector<int> Test:" << endl;
  try {
    {//caso 0
      lasd::SortableVector<int> vec;
      lasd::SortableVector<int> vec2;
      Empty(loctestnum, loctesterr, vec, true);
      Size(loctestnum, loctesterr, vec, true, 0);

      GetFront(loctestnum, loctesterr, vec, false, 0);
      GetBack(loctestnum, loctesterr, vec, false, 0);
      SetAt(loctestnum, loctesterr, vec, false, 1, 0);
      GetAt(loctestnum, loctesterr, vec, false, 2, 0);

      Exists(loctestnum, loctesterr, vec, false, 0);

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 0);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 0);

      EqualVector(loctestnum, loctesterr, vec, vec2, true);
      Size(loctestnum, loctesterr, vec2, true, 0);

    }
    {//caso 1
       lasd::SortableVector<int> vec(1);
      lasd::SortableVector<int> vec2;
      Empty(loctestnum, loctesterr, vec, false);
      Size(loctestnum, loctesterr, vec, true, 1);

      SetAt(loctestnum, loctesterr, vec, true, 0, 1);

      GetFront(loctestnum, loctesterr, vec, true, 1);
      GetBack(loctestnum, loctesterr, vec, true, 1);

      Exists(loctestnum, loctesterr, vec, true, 1);

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 1);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 1);

      EqualVector(loctestnum, loctesterr, vec, vec2, false);
      Size(loctestnum, loctesterr, vec2, true, 0);
    }
    {//caso n
      lasd::SortableVector<int> vec(5);
      lasd::SortableVector<int> vec2(3);
      Empty(loctestnum, loctesterr, vec, false);
      Size(loctestnum, loctesterr, vec, true, 5);

      SetAt(loctestnum, loctesterr, vec, true, 0, 4);
      SetAt(loctestnum, loctesterr, vec, true, 1, 7);
      SetAt(loctestnum, loctesterr, vec, true, 2, 1);
      SetAt(loctestnum, loctesterr, vec, true, 3, 16);
      SetAt(loctestnum, loctesterr, vec, true, 4, 2);

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 30);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 30);

      GetFront(loctestnum, loctesterr, vec, true, 4);
      GetBack(loctestnum, loctesterr, vec, true, 2);

      vec.Sort();

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 30);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<int>, 0, 30);

      GetFront(loctestnum, loctesterr, vec, true, 1);
      GetBack(loctestnum, loctesterr, vec, true, 16);

      SetAt(loctestnum, loctesterr, vec2, true, 0, 4);
      SetAt(loctestnum, loctesterr, vec2, true, 1, 7);
      SetAt(loctestnum, loctesterr, vec2, true, 2, 1);

      TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<int>);

      FoldPreOrder(loctestnum, loctesterr, vec2, true, &FoldAdd<int>, 0, 12);
      FoldPostOrder(loctestnum, loctesterr, vec2, true, &FoldAdd<int>, 0, 12);

      EqualVector(loctestnum, loctesterr, vec, vec2, false);

    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mytestVectorDouble(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector<double> Test:" << endl;
  try {
    {//caso 0
      lasd::SortableVector<double> vec;
      lasd::SortableVector<double> vec2;
      Empty(loctestnum, loctesterr, vec, true);
      Size(loctestnum, loctesterr, vec, true, 0);

      GetFront(loctestnum, loctesterr, vec, false, 0.0);
      GetBack(loctestnum, loctesterr, vec, false, 0.0);
      SetAt(loctestnum, loctesterr, vec, false, 1, 0.0);
      GetAt(loctestnum, loctesterr, vec, false, 2, 0.0);

      Exists(loctestnum, loctesterr, vec, false, 0.0);

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 0.0);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 0.0);

      EqualVector(loctestnum, loctesterr, vec, vec2, true);
      Size(loctestnum, loctesterr, vec2, true, 0);

    }
    {//caso 1
      lasd::SortableVector<double> vec(1);
      lasd::SortableVector<double> vec2;
      Empty(loctestnum, loctesterr, vec, false);
      Size(loctestnum, loctesterr, vec, true, 1);

      SetAt(loctestnum, loctesterr, vec, true, 0, 1.1);

      GetFront(loctestnum, loctesterr, vec, true, 1.1);
      GetBack(loctestnum, loctesterr, vec, true, 1.1);

      Exists(loctestnum, loctesterr, vec, true, 1.1);

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 1.1);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 1.1);

      EqualVector(loctestnum, loctesterr, vec, vec2, false);
      Size(loctestnum, loctesterr, vec2, true, 0);
    }
    {//caso n
      lasd::SortableVector<double> vec(5);
      lasd::SortableVector<double> vec2(3);
      Empty(loctestnum, loctesterr, vec, false);
      Size(loctestnum, loctesterr, vec, true, 5);

      SetAt(loctestnum, loctesterr, vec, true, 0, 4.6);
      SetAt(loctestnum, loctesterr, vec, true, 1, 7.4);
      SetAt(loctestnum, loctesterr, vec, true, 2, 1.8);
      SetAt(loctestnum, loctesterr, vec, true, 3, 16.1);
      SetAt(loctestnum, loctesterr, vec, true, 4, 2.3);

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 32.2);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 32.2);

      GetFront(loctestnum, loctesterr, vec, true, 4.6);
      GetBack(loctestnum, loctesterr, vec, true, 2.3);

      vec.Sort();

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 32.2);
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldAdd<double>, 0.0, 32.2);

      GetFront(loctestnum, loctesterr, vec, true, 1.8);
      GetBack(loctestnum, loctesterr, vec, true, 16.1);

      SetAt(loctestnum, loctesterr, vec2, true, 0, 1.3);
      SetAt(loctestnum, loctesterr, vec2, true, 1, 4.2);
      SetAt(loctestnum, loctesterr, vec2, true, 2, 3.4);

      TraversePreOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, vec2, true, &TraversePrint<double>);

      FoldPreOrder(loctestnum, loctesterr, vec2, true, &FoldAdd<double>, 0.0, 8.9);
      FoldPostOrder(loctestnum, loctesterr, vec2, true, &FoldAdd<double>, 0.0, 8.9);

      EqualVector(loctestnum, loctesterr, vec, vec2, false);

    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mytestVectorString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector<string> Test:" << endl;
  try {
    lasd::SortableVector<string> vec(2);

    Empty(loctestnum, loctesterr, vec, false);
    Size(loctestnum, loctesterr, vec, true, 2);

    SetAt(loctestnum, loctesterr, vec, true, 0, string("A"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("B"));

    GetFront(loctestnum, loctesterr, vec, true, string("A"));
    GetBack(loctestnum, loctesterr, vec, true, string("B"));

    Exists(loctestnum, loctesterr, vec, true, string("A"));

    MapPreOrder(loctestnum, loctesterr, vec, true, [](string & str) { MapStringAppend(str, string(" ")); });
    TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
    FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("X"), string("XA B "));
    FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("X"), string("XB A "));

    Exists(loctestnum, loctesterr, vec, false, string("A"));

    lasd::SortableVector<string> copvec(vec);
    EqualVector(loctestnum, loctesterr, vec, copvec, true);
    MapPreOrder(loctestnum, loctesterr, vec, true, [](string & str) { MapStringAppend(str, string("!")); });
    NonEqualVector(loctestnum, loctesterr, vec, copvec, true);

    copvec = move(vec);
    FoldPreOrder(loctestnum, loctesterr, copvec, true, &FoldStringConcatenate, string("?"), string("?A !B !"));

    lasd::SortableVector<string> movvec(move(vec));
    FoldPreOrder(loctestnum, loctesterr, movvec, true, &FoldStringConcatenate, string("?"), string("?A B "));
    movvec.Sort();
    FoldPreOrder(loctestnum, loctesterr, movvec, true, &FoldStringConcatenate, string("?"), string("?A B "));
    SetAt(loctestnum, loctesterr, vec, false, 1, string(""));
    vec.Resize(1);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("X"));

    movvec.Clear();
    Empty(loctestnum, loctesterr, movvec, true);
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mytestVector(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  mytestVectorInt(loctestnum, loctesterr);
  mytestVectorDouble(loctestnum, loctesterr);
  mytestVectorString(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "Exercise 1A - Vector (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}


void myTestVecList(uint & testnum, uint & testerr) 
{
  mytestVector(testnum, testerr);
  //mytestList(testnum, testerr);
  //stestVectorList(testnum, testerr);
  cout << endl << "My test (Vector/List) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
