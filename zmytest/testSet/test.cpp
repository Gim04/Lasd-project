#include <iostream>

/* ************************************************************************** */

#include "../../zlasdtest/container/container.hpp"
#include "../../zlasdtest/container/traversable.hpp"
#include "../../zlasdtest/container/testable.hpp"
#include "../../zlasdtest/container/dictionary.hpp"
#include "../../zlasdtest/container/linear.hpp"

#include "../../zlasdtest/vector/vector.hpp"
#include "../../zlasdtest/list/list.hpp"
#include "../../zlasdtest/set/set.hpp"

#include "../../set/lst/setlst.hpp"
#include "../../set/vec/setvec.hpp"

/* ************************************************************************** */

using namespace std;

void mytestSetInt(lasd::Set<int> & set, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    {//caso 0
     
      Empty(loctestnum, loctesterr, set, true);
      Size(loctestnum, loctesterr, set, true, 0);

      Exists(loctestnum, loctesterr, set, false, 0);
      Remove(loctestnum, loctesterr, set, false, 0);
      Min(loctestnum, loctesterr, set, false, 0);
      Max(loctestnum, loctesterr, set, false, 0);
      Predecessor(loctestnum, loctesterr, set, false, 0, -1);
      Successor(loctestnum, loctesterr, set, false, 0, 1);
      TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
      FoldPreOrder(loctestnum, loctesterr, set, true, &FoldAdd<int>, 0, 0);
    }
    {//caso 1
      InsertC(loctestnum, loctesterr, set, true, 10);
      Empty(loctestnum, loctesterr, set, false);
      Size(loctestnum, loctesterr, set, true, 1);
      Exists(loctestnum, loctesterr, set, true, 10);

      Min(loctestnum, loctesterr, set, true, 10);
      Max(loctestnum, loctesterr, set, true, 10);
      Predecessor(loctestnum, loctesterr, set, false, 10, 9);
      Successor(loctestnum, loctesterr, set, false, 10, 11);

      FoldPreOrder(loctestnum, loctesterr, set, true, &FoldAdd<int>, 0, 10);

      Remove(loctestnum, loctesterr, set, true, 10);
      Exists(loctestnum, loctesterr, set, false, 10);
      Empty(loctestnum, loctesterr, set, true);
    }
    {//caso n
      InsertC(loctestnum, loctesterr, set, true, 10);
      InsertC(loctestnum, loctesterr, set, true,5);
      InsertC(loctestnum, loctesterr, set, true,15);
      InsertC(loctestnum, loctesterr, set, true,20);
      InsertC(loctestnum, loctesterr, set, true,8);
      InsertC(loctestnum, loctesterr, set, true,30);
      InsertC(loctestnum, loctesterr, set, true,12);

      Size(loctestnum, loctesterr, set, true, 7);
      Empty(loctestnum, loctesterr, set, false);

      TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
      TraversePostOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);

      Min(loctestnum, loctesterr, set, true, 5);
      Max(loctestnum, loctesterr, set, true, 30);

      RemoveMin(loctestnum, loctesterr, set, true);
      MinNRemove(loctestnum, loctesterr, set, true, 8);

      InsertC(loctestnum, loctesterr, set, true, 3);
      InsertC(loctestnum, loctesterr, set, true, 25);
      InsertC(loctestnum, loctesterr, set, false, 10);

      MaxNRemove(loctestnum, loctesterr, set, true, 30);

      Exists(loctestnum, loctesterr, set, true, 25);
      Exists(loctestnum, loctesterr, set, false, 30);
      Exists(loctestnum, loctesterr, set, true, 3);
      Exists(loctestnum, loctesterr, set, false, 100);

      Remove(loctestnum, loctesterr, set, true, 3);
      Remove(loctestnum, loctesterr, set, false, 999);
      Exists(loctestnum, loctesterr, set, false, 3);

      Predecessor(loctestnum, loctesterr, set, true, 20, 15);
      Predecessor(loctestnum, loctesterr, set, false, 5, 4);
      Successor(loctestnum, loctesterr, set, true, 15, 20);
      Successor(loctestnum, loctesterr, set, false, 25, 30);

      TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<int>);
      FoldPreOrder(loctestnum, loctesterr, set, true, &FoldAdd<int>, 0, 82);
      FoldPostOrder(loctestnum, loctesterr, set, true, &FoldAdd<int>, 0,82);

      set.Clear();
      Empty(loctestnum, loctesterr, set, true);
      Size(loctestnum, loctesterr, set, true, 0);
    }

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Set<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mytestSetInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Set<int> Test" << endl;
  try {

    lasd::Vector<int> vec(6);
    SetAt(loctestnum, loctesterr, vec, true, 0, 7);
    SetAt(loctestnum, loctesterr, vec, true, 1, 3);
    SetAt(loctestnum, loctesterr, vec, true, 2, 9);
    SetAt(loctestnum, loctesterr, vec, true, 3, 1);
    SetAt(loctestnum, loctesterr, vec, true, 4, 5);
    SetAt(loctestnum, loctesterr, vec, true, 5, 8);


    cout << endl << "Begin of SetVec<int> Test:" << endl;
    lasd::SetVec<int> setvec;
    mytestSetInt(setvec, loctestnum, loctesterr);
    cout << endl << "Begin of SetLst<int> Test:" << endl;
    lasd::SetLst<int> setlst;
    mytestSetInt(setlst, loctestnum, loctesterr);
    cout << "\n";
    
    setlst.InsertAll(vec);
    setvec.InsertAll(vec);

    lasd::SetLst<int> lstA(setlst); 
    EqualSetLst(loctestnum, loctesterr, setlst, lstA, true);

    lasd::SetLst<int> lstB = lstA; 
    EqualSetLst(loctestnum, loctesterr, lstA, lstB, true);

    lasd::SetLst<int> lstC(std::move(lstB)); 
    Empty(loctestnum, loctesterr, lstB, true);
    Size(loctestnum, loctesterr, lstB, true, 0);
    EqualSetLst(loctestnum, loctesterr, lstA, lstC, true);

    lasd::SetLst<int> tmpLst = std::move(lstA);
    lstB = tmpLst; 
    EqualSetLst(loctestnum, loctesterr, lstB, lstC, true);

    lasd::SetVec<int> vecX(setvec); 
    EqualSetVec(loctestnum, loctesterr, setvec, vecX, true);

    lasd::SetVec<int> vecY = vecX; 
    EqualSetVec(loctestnum, loctesterr, vecX, vecY, true);

    lasd::SetVec<int> vecZ(std::move(vecY)); 
    Empty(loctestnum, loctesterr, vecY, true);
    Size(loctestnum, loctesterr, vecY, true, 0);
    EqualSetVec(loctestnum, loctesterr, vecX, vecZ, true);

    vecY = std::move(vecX);
    Empty(loctestnum, loctesterr, vecX, true);
    Size(loctestnum, loctesterr, vecX, true, 0);
    EqualSetVec(loctestnum, loctesterr, vecY, vecZ, true);

    EqualLinear(loctestnum, loctesterr, vecZ, lstB, true);
        
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Set<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mytestSetDouble(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Set<double> Test" << endl;
  try {
    {//caso 0
      lasd::SetVec<double> setvec0;
      lasd::SetLst<double> setlst0;

      Empty(loctestnum, loctesterr, setvec0, true);
      Empty(loctestnum, loctesterr, setlst0, true);
      Size(loctestnum, loctesterr, setvec0, true, 0);
      Size(loctestnum, loctesterr, setlst0, true, 0);

      EqualSetVec(loctestnum, loctesterr, setvec0, setvec0, true);
      EqualSetLst(loctestnum, loctesterr, setlst0, setlst0, true);
    }
    {//caso 1
      lasd::SetVec<double> setvec1;
      lasd::SetLst<double> setlst1;

      InsertC(loctestnum, loctesterr, setvec1, true, 3.14);
      InsertC(loctestnum, loctesterr, setlst1, true, 3.14);

      Size(loctestnum, loctesterr, setvec1, true, 1);
      Size(loctestnum, loctesterr, setlst1, true, 1);
      Empty(loctestnum, loctesterr, setvec1, false);
      Empty(loctestnum, loctesterr, setlst1, false);

      EqualSetVec(loctestnum, loctesterr, setvec1, setvec1, true);
      EqualSetLst(loctestnum, loctesterr, setlst1, setlst1, true);

      lasd::SetVec<double> setvec1move(move(setvec1));
      Empty(loctestnum, loctesterr, setvec1, true);
      Size(loctestnum, loctesterr, setvec1, true, 0);
      Size(loctestnum, loctesterr, setvec1move, true, 1);

      lasd::SetLst<double> setlst1move(move(setlst1));
      Empty(loctestnum, loctesterr, setlst1, true);
      Size(loctestnum, loctesterr, setlst1move, true, 1);
    }
    {//caso n
      lasd::Vector<double> vec(5);
      SetAt(loctestnum, loctesterr, vec, true, 0, 2.82);
      SetAt(loctestnum, loctesterr, vec, true, 1, 1.41);
      SetAt(loctestnum, loctesterr, vec, true, 2, 0.57);
      SetAt(loctestnum, loctesterr, vec, true, 3, 4.16);
      SetAt(loctestnum, loctesterr, vec, true, 4, 1.73);

      lasd::SetVec<double> setvec;
      setvec.InsertAll(vec);

      lasd::SetVec<double> setvecCopy(setvec);
      EqualSetVec(loctestnum, loctesterr, setvec, setvecCopy, true);

      lasd::SetVec<double> setvecMove(move(setvecCopy));
      Empty(loctestnum, loctesterr, setvecCopy, true);
      Size(loctestnum, loctesterr, setvecMove, true, 5);

      lasd::SetLst<double> setlst;
      setlst.InsertAll(vec);

      lasd::SetLst<double> setlstCopy(setlst);
      EqualSetLst(loctestnum, loctesterr, setlst, setlstCopy, true);

      Remove(loctestnum, loctesterr, setlstCopy, true, 2.82);
      NonEqualSetLst(loctestnum, loctesterr, setlst, setlstCopy, true);
      InsertC(loctestnum, loctesterr, setlstCopy, true, 2.82);
      EqualSetLst(loctestnum, loctesterr, setlst, setlstCopy, true);

      lasd::SetLst<double> setlstMove(move(setlstCopy));
      Empty(loctestnum, loctesterr, setlstCopy, true);
      Size(loctestnum, loctesterr, setlstMove, true, 5);

      EqualLinear(loctestnum, loctesterr, setvecMove, setlstMove, true);
    }

  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Set<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mytestSetString(lasd::Set<string> & set, uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  try {
    TraversePreOrder(loctestnum, loctesterr, set, true, &TraversePrint<string>);
    FoldPreOrder(loctestnum, loctesterr, set, true, &FoldStringConcatenate, string("?"), string("?ABCDE"));
    FoldPostOrder(loctestnum, loctesterr, set, true, &FoldStringConcatenate, string("?"), string("?EDCBA"));
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Set<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mytestSetString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Set<string> Test" << endl;
  try {
    {
      lasd::SetVec<string> setvec0;
      lasd::SetLst<string> setlst0;

      Empty(loctestnum, loctesterr, setvec0, true);
      Empty(loctestnum, loctesterr, setlst0, true);
      Size(loctestnum, loctesterr, setvec0, true, 0);
      Size(loctestnum, loctesterr, setlst0, true, 0);

      EqualSetVec(loctestnum, loctesterr, setvec0, setvec0, true);
      EqualSetLst(loctestnum, loctesterr, setlst0, setlst0, true);
    }

    // Caso 1 elemento
    {
      lasd::SetVec<string> setvec1;
      lasd::SetLst<string> setlst1;

      InsertC(loctestnum, loctesterr, setvec1, true, string("ferrari"));
      InsertC(loctestnum, loctesterr, setlst1, true, string("ferrari"));

      Size(loctestnum, loctesterr, setvec1, true, 1);
      Size(loctestnum, loctesterr, setlst1, true, 1);
      Empty(loctestnum, loctesterr, setvec1, false);
      Empty(loctestnum, loctesterr, setlst1, false);

      EqualSetVec(loctestnum, loctesterr, setvec1, setvec1, true);
      EqualSetLst(loctestnum, loctesterr, setlst1, setlst1, true);

      lasd::SetVec<string> setvec1move(move(setvec1));
      Empty(loctestnum, loctesterr, setvec1, true);
      Size(loctestnum, loctesterr, setvec1move, true, 1);

      lasd::SetLst<string> setlst1move(move(setlst1));
      Empty(loctestnum, loctesterr, setlst1, true);
      Size(loctestnum, loctesterr, setlst1move, true, 1);
    }

    // Caso N elementi
    {
      lasd::Vector<string> vec(5);
      SetAt(loctestnum, loctesterr, vec, true, 0, string("redbull"));
      SetAt(loctestnum, loctesterr, vec, true, 1, string("mclaren"));
      SetAt(loctestnum, loctesterr, vec, true, 2, string("mercedes"));
      SetAt(loctestnum, loctesterr, vec, true, 3, string("williams"));
      SetAt(loctestnum, loctesterr, vec, true, 4, string("alfa"));

      lasd::SetVec<string> setvec;
      setvec.InsertAll(vec);

      lasd::SetVec<string> setvecCopy(setvec);
      EqualSetVec(loctestnum, loctesterr, setvec, setvecCopy, true);

      Remove(loctestnum, loctesterr, setvecCopy, true, string("williams"));
      NonEqualSetVec(loctestnum, loctesterr, setvec, setvecCopy, true);
      InsertC(loctestnum, loctesterr, setvecCopy, true, string("williams"));
      EqualSetVec(loctestnum, loctesterr, setvec, setvecCopy, true);

      lasd::SetVec<string> setvecMove(move(setvecCopy));
      Empty(loctestnum, loctesterr, setvecCopy, true);
      Size(loctestnum, loctesterr, setvecMove, true, 5);

      lasd::SetLst<string> setlst;
      setlst.InsertAll(vec);

      lasd::SetLst<string> setlstCopy(setlst);
      EqualSetLst(loctestnum, loctesterr, setlst, setlstCopy, true);

      Remove(loctestnum, loctesterr, setlstCopy, true, string("redbull"));
      NonEqualSetLst(loctestnum, loctesterr, setlst, setlstCopy, true);
      InsertC(loctestnum, loctesterr, setlstCopy, true, string("redbull"));
      EqualSetLst(loctestnum, loctesterr, setlst, setlstCopy, true);

      lasd::SetLst<string> setlstMove(move(setlstCopy));
      Empty(loctestnum, loctesterr, setlstCopy, true);
      Size(loctestnum, loctesterr, setlstMove, true, 5);

      EqualLinear(loctestnum, loctesterr, setvecMove, setlstMove, true);
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Set<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void myTestSet(uint & testnum, uint & testerr) {
  mytestSetInt(testnum, testerr);
  mytestSetDouble(testnum, testerr);
  mytestSetString(testnum, testerr);
  cout << endl << "My test (Set) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
