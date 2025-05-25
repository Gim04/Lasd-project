
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
    {// Caso 0
      lasd::SortableVector<string> vec0(0);
      Empty(loctestnum, loctesterr, vec0, true);
      Size(loctestnum, loctesterr, vec0, true, 0);
      GetFront(loctestnum, loctesterr, vec0, false, string(""));
      GetBack(loctestnum, loctesterr, vec0, false, string(""));
      Exists(loctestnum, loctesterr, vec0, false, string("any"));
    }

    {// Caso stringhe vuote
      lasd::SortableVector<string> vec(2);
      SetAt(loctestnum, loctesterr, vec, true, 0, string(""));
      SetAt(loctestnum, loctesterr, vec, true, 1, string("Test"));

      FoldPreOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("X"), string("XTest"));
      FoldPostOrder(loctestnum, loctesterr, vec, true, &FoldStringConcatenate, string("X"), string("XTest"));
    }
    {// Caso case sensitivity nel sort
      lasd::SortableVector<string> vec(3);
      SetAt(loctestnum, loctesterr, vec, true, 0, string("banana"));
      SetAt(loctestnum, loctesterr, vec, true, 1, string("Apple"));
      SetAt(loctestnum, loctesterr, vec, true, 2, string("cherry"));
      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);

      vec.Sort();

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      GetFront(loctestnum, loctesterr, vec, true, string("Apple"));
      GetBack(loctestnum, loctesterr, vec, true, string("cherry"));
    }
    {// Caso n e case sensitive
      lasd::SortableVector<string> vec(7);

      SetAt(loctestnum, loctesterr, vec, true, 0, string("b"));
      SetAt(loctestnum, loctesterr, vec, true, 1, string("E"));
      SetAt(loctestnum, loctesterr, vec, true, 2, string("A"));
      SetAt(loctestnum, loctesterr, vec, true, 3, string("g"));
      SetAt(loctestnum, loctesterr, vec, true, 4, string("F"));
      SetAt(loctestnum, loctesterr, vec, true, 5, string("c"));
      SetAt(loctestnum, loctesterr, vec, true, 6, string("d"));

      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);

      vec.Sort();
      TraversePreOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);
      TraversePostOrder(loctestnum, loctesterr, vec, true, &TraversePrint<string>);

      GetFront(loctestnum, loctesterr, vec, true, string("A"));
      GetBack(loctestnum, loctesterr, vec, true, string("g"));

      lasd::SortableVector<string> copyvec(vec);
      copyvec = move(vec);
      FoldPreOrder(loctestnum, loctesterr, copyvec, true, &FoldStringConcatenate, string("X"), string("XAEFbcdg")); 
      MapPreOrder(loctestnum, loctesterr, copyvec, true, [](string & str) { MapStringAppend(str, string("X")); });
      TraversePreOrder(loctestnum, loctesterr, copyvec, true, &TraversePrint<string>);
    }

  } catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
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
  cout << endl << "My test - Vector (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

void mytestListInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of List<int> Test:" << endl;
  try 
  {//caso 0
  {
    lasd::List<int> list;
    Empty(loctestnum, loctesterr, list, true);
    Size(loctestnum, loctesterr, list, true, 0);

    GetFront(loctestnum, loctesterr, list, false, 0);
    GetBack(loctestnum, loctesterr, list, false, 0);

    Exists(loctestnum, loctesterr, list, false, 0);

    TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);
    FoldPreOrder(loctestnum, loctesterr, list, true, &FoldAdd<int>, 0, 0);
    FoldPostOrder(loctestnum, loctesterr, list, true, &FoldAdd<int>, 0, 0);

    RemoveFromBack(loctestnum, loctesterr, list, false);
    BackNRemove(loctestnum, loctesterr, list, false, 0);
  }
  {//caso 1
    lasd::List<int> list;
    InsertAtFront(loctestnum, loctesterr, list, true, 42);
    Size(loctestnum, loctesterr, list, true, 1);
    
    TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);
    FoldPreOrder(loctestnum, loctesterr, list, true, &FoldAdd<int>, 0, 42);
    FoldPostOrder(loctestnum, loctesterr, list, true, &FoldAdd<int>, 0, 42);

    RemoveFromFront(loctestnum, loctesterr, list, true);
    TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);

    Empty(loctestnum, loctesterr, list, true);
  }
  {//caso n
    lasd::List<int> list;
    InsertAtBack(loctestnum, loctesterr, list, true, 10);
    InsertAtFront(loctestnum, loctesterr, list, true, 3);
    InsertAtBack(loctestnum, loctesterr, list, true, 5);
    InsertAtFront(loctestnum, loctesterr, list, true, 1);
    InsertAtFront(loctestnum, loctesterr, list, true, 7);

    GetFront(loctestnum, loctesterr, list, true, 7);
    GetBack(loctestnum, loctesterr, list, true, 5);
    SetFront(loctestnum, loctesterr, list, true, 8);
    SetBack(loctestnum, loctesterr, list, true, 6);

    GetAt(loctestnum, loctesterr, list, true, 2, 3);  
    SetAt(loctestnum, loctesterr, list, true, 2, 4);

    Exists(loctestnum, loctesterr, list, true, 4);  
    
    TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);
    TraversePostOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);
    FoldPreOrder(loctestnum, loctesterr, list, true, &FoldAdd<int>, 0, 29); 
    FoldPostOrder(loctestnum, loctesterr, list, true, &FoldMultiply<int>, 1, 1920);
    
    RemoveFromBack(loctestnum, loctesterr, list, true); 
    BackNRemove(loctestnum, loctesterr, list, true, 10); 
    TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<int>);
    FoldPreOrder(loctestnum, loctesterr, list, true, &FoldMultiply<int>, 1, 32);
    
    lasd::List<int> coplst2(list);
    EqualList(loctestnum, loctesterr, list, coplst2, true);
    MapPostOrder(loctestnum, loctesterr, list, true, &MapIncrement<int>);
    NonEqualList(loctestnum, loctesterr, list, coplst2, true);

    lasd::List<int> list2;
    InsertAtBack(loctestnum, loctesterr, list2, true, 1);
    InsertAtBack(loctestnum, loctesterr, list2, true, 2);
    InsertAtBack(loctestnum, loctesterr, list2, true, 3);

    lasd::List<int> copylist(std::move(list2));

    Empty(loctestnum, loctesterr, list2, true);
    Size(loctestnum, loctesterr, list2, true, 0);

    Size(loctestnum, loctesterr, copylist, true, 3);
    FoldPreOrder(loctestnum, loctesterr, copylist, true, &FoldAdd<int>, 0, 6);
      
  }
  {//caso con piu remove
    lasd::List<int> lst;
    InsertAtFront(loctestnum, loctesterr, lst, true, 5);

    RemoveFromBack(loctestnum, loctesterr, lst, true);
    InsertAtFront(loctestnum, loctesterr, lst, true, 5);
    BackNRemove(loctestnum, loctesterr, lst, true, 5);
    BackNRemove(loctestnum, loctesterr, lst, false, 3);
    TraversePreOrder(loctestnum, loctesterr, lst, true, &TraversePrint<int>);
  }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of List<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mytestListDouble(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of List<double> Test:" << endl;
  try 
  {
    {
    lasd::List<double> list;
    Empty(loctestnum, loctesterr, list, true);
    Size(loctestnum, loctesterr, list, true, 0);

    GetFront(loctestnum, loctesterr, list, false, 0.0);
    GetBack(loctestnum, loctesterr, list, false, 0.0);

    Exists(loctestnum, loctesterr, list, false, 0.0);

    TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);
    TraversePostOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);
    FoldPreOrder(loctestnum, loctesterr, list, true, &FoldAdd<double>, 0.0, 0.0);
    FoldPostOrder(loctestnum, loctesterr, list, true, &FoldAdd<double>, 0.0, 0.0);

    RemoveFromBack(loctestnum, loctesterr, list, false);
    BackNRemove(loctestnum, loctesterr, list, false, 0.0);
    }
    { //caso 1
      lasd::List<double> list;
      InsertAtFront(loctestnum, loctesterr, list, true, 42.1);
      Size(loctestnum, loctesterr, list, true, 1);
      
      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);
      FoldPreOrder(loctestnum, loctesterr, list, true, &FoldAdd<double>, 0.0, 42.1);
      FoldPostOrder(loctestnum, loctesterr, list, true, &FoldAdd<double>, 0.0, 42.1);

      RemoveFromFront(loctestnum, loctesterr, list, true);
      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);

      Empty(loctestnum, loctesterr, list, true);
    }
    {//caso n
      lasd::List<double> list;
      InsertAtBack(loctestnum, loctesterr, list, true, 10.1);
      InsertAtFront(loctestnum, loctesterr, list, true, 3.1);
      InsertAtBack(loctestnum, loctesterr, list, true, 5.1);
      InsertAtFront(loctestnum, loctesterr, list, true, 1.1);
      InsertAtFront(loctestnum, loctesterr, list, true, 7.1);

      GetFront(loctestnum, loctesterr, list, true, 7.1);
      GetBack(loctestnum, loctesterr, list, true, 5.1);
      SetFront(loctestnum, loctesterr, list, true, 8.1);
      SetBack(loctestnum, loctesterr, list, true, 6.1);

      GetAt(loctestnum, loctesterr, list, true, 2, 3.1);  
      SetAt(loctestnum, loctesterr, list, true, 2, 4.1);

      Exists(loctestnum, loctesterr, list, true, 4.1);  
      
      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);
      TraversePostOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);
      FoldPreOrder(loctestnum, loctesterr, list, true, &FoldAdd<double>, 0.0, 29.5); 
      
      RemoveFromBack(loctestnum, loctesterr, list, true); 
      BackNRemove(loctestnum, loctesterr, list, true, 10.1); 
      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);
      FoldPreOrder(loctestnum, loctesterr, list, true, &FoldMultiply<double>, 1.0, 36.531);
      
      lasd::List<double> coplst2(list);
      EqualList(loctestnum, loctesterr, list, coplst2, true);
      MapPostOrder(loctestnum, loctesterr, list, true, &MapIncrement<double>);
      NonEqualList(loctestnum, loctesterr, list, coplst2, true);

      lasd::List<double> list2;
      InsertAtBack(loctestnum, loctesterr, list2, true, 1.1);
      InsertAtBack(loctestnum, loctesterr, list2, true, 2.1);
      InsertAtBack(loctestnum, loctesterr, list2, true, 3.2);

      lasd::List<double> movedList(std::move(list2));

      Empty(loctestnum, loctesterr, list2, true);
      Size(loctestnum, loctesterr, list2, true, 0);

      Size(loctestnum, loctesterr, movedList, true, 3);
      FoldPreOrder(loctestnum, loctesterr, movedList, true, &FoldAdd<double>, 0.0, 6.4);
        
    }
    {//caso con piu remove
      lasd::List<double> list;
      InsertAtFront(loctestnum, loctesterr, list, true, 5.1);

      RemoveFromBack(loctestnum, loctesterr, list, true);
      InsertAtFront(loctestnum, loctesterr, list, true, 5.1);
      BackNRemove(loctestnum, loctesterr, list, true, 5.1);
      BackNRemove(loctestnum, loctesterr, list, false, 3.1);
      TraversePreOrder(loctestnum, loctesterr, list, true, &TraversePrint<double>);
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of List<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mytestListString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of List<string> Test:" << endl;
  try 
  {
    {//caso 0
      lasd::List<string> emptyList;
      Empty(loctestnum, loctesterr, emptyList, true);
      Size(loctestnum, loctesterr, emptyList, true, 0);
      FoldPostOrder(loctestnum, loctesterr, emptyList, true, &FoldStringConcatenate, string("Z"), string("Z"));
    }
    {//caso 1
      lasd::List<string> list;
      InsertAtFront(loctestnum, loctesterr, list, true, string("One"));
      Size(loctestnum, loctesterr, list, true, 1);
      GetFront(loctestnum, loctesterr, list, true, string("One"));
      GetBack(loctestnum, loctesterr, list, true, string("One"));
      Exists(loctestnum, loctesterr, list, true, string("One"));
      FoldPreOrder(loctestnum, loctesterr, list, true, &FoldStringConcatenate, string("?"), string("?One"));
      SetFront(loctestnum, loctesterr, list, true, string("New"));
      GetFront(loctestnum, loctesterr, list, true, string("New"));
      RemoveFromFront(loctestnum, loctesterr, list, true);
      Empty(loctestnum, loctesterr, list, true);
    }
    {//caso n
      lasd::List<string> list;
      InsertAtBack(loctestnum, loctesterr, list, true, string("First"));
      InsertAtBack(loctestnum, loctesterr, list, true, string("Second"));
      lasd::List<string> copylist(std::move(list));
      Size(loctestnum, loctesterr, copylist, true, 2);
      FoldPreOrder(loctestnum, loctesterr, copylist, true, &FoldStringConcatenate, string("Start "), string("Start FirstSecond"));
      Empty(loctestnum, loctesterr, list, true); 
      
      GetFront(loctestnum, loctesterr, copylist, true, string("First"));
      GetBack(loctestnum, loctesterr, copylist, true, string("Second"));

      Exists(loctestnum, loctesterr, copylist, true, string("First"));
      Exists(loctestnum, loctesterr, copylist, true, string("Second"));
      Exists(loctestnum, loctesterr, copylist, false, string("Third"));

      InsertAtFront(loctestnum, loctesterr, copylist, true, string("Zero"));
      InsertAtBack(loctestnum, loctesterr, copylist, true, string("Third"));
      Size(loctestnum, loctesterr, copylist, true, 4);

      SetFront(loctestnum, loctesterr, copylist, true, string("Start"));
      SetBack(loctestnum, loctesterr, copylist, true, string("End"));
      GetFront(loctestnum, loctesterr, copylist, true, string("Start"));
      GetBack(loctestnum, loctesterr, copylist, true, string("End"));

      GetAt(loctestnum, loctesterr, copylist, true, 2, string("Second"));
      SetAt(loctestnum, loctesterr, copylist, true, 2, string("Middle"));
      GetAt(loctestnum, loctesterr, copylist, true, 2, string("Middle"));

      TraversePreOrder(loctestnum, loctesterr, copylist, true, &TraversePrint<string>);
      FoldPostOrder(loctestnum, loctesterr, copylist, true, &FoldStringConcatenate, string("X"), string("XEndMiddleFirstStart"));

      RemoveFromFront(loctestnum, loctesterr, copylist, true);
      FrontNRemove(loctestnum, loctesterr, copylist, true, string("First"));
      Size(loctestnum, loctesterr, copylist, true, 2);
    }
  }
  catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of List<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}

void mytestList(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  mytestListInt(loctestnum, loctesterr);
  mytestListDouble(loctestnum, loctesterr);
  mytestListString(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "My test - List (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}

void mytestVectorListInt(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector/List<int> Test:" << endl;
  try 
  {
    {// Caso 0 
    lasd::SortableVector<int> vec0;
    lasd::List<int> lst0;
    EqualLinear(loctestnum, loctesterr, vec0, lst0, true);
    }
    {// Caso 1 
    lasd::SortableVector<int> vec1(1);
    SetAt(loctestnum, loctesterr, vec1, true, 0, 42);
    lasd::List<int> lst1;
    InsertAtFront(loctestnum, loctesterr, lst1, true, 42);
    EqualLinear(loctestnum, loctesterr, vec1, lst1, true);
    }
    {// Caso n 
    lasd::SortableVector<int> vec(3);
    SetAt(loctestnum, loctesterr, vec, true, 0, 10);
    SetAt(loctestnum, loctesterr, vec, true, 1, 20);
    SetAt(loctestnum, loctesterr, vec, true, 2, 30);
    
    lasd::List<int> lst;
    InsertAtFront(loctestnum, loctesterr, lst, true, 30);
    InsertAtFront(loctestnum, loctesterr, lst, true, 20);
    InsertAtFront(loctestnum, loctesterr, lst, true, 10);

    EqualLinear(loctestnum, loctesterr, vec, lst, true);

    lasd::SortableVector<int> copvec(lst);
    EqualVector(loctestnum, loctesterr, vec, copvec, true);
    lasd::SortableVector<int> copvecx(vec);
    EqualVector(loctestnum, loctesterr, copvecx, copvec, true);

    lasd::List<int> coplst(vec);
    EqualList(loctestnum, loctesterr, lst, coplst, true);
    lasd::List<int> coplstx(lst);
    EqualList(loctestnum, loctesterr, coplstx, coplst, true);
    }
  } catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector/List<int> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}


void mytestVectorListDouble(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector/List<double> Test:" << endl;
  try {
    // caso 0 
    lasd::SortableVector<double> vec0;
    lasd::List<double> lst0;
    EqualLinear(loctestnum, loctesterr, vec0, lst0, true);

    // caso 1 
    lasd::SortableVector<double> vec1(1);
    SetAt(loctestnum, loctesterr, vec1, true, 0, 8.12);
    lasd::List<double> lst1;
    InsertAtBack(loctestnum, loctesterr, lst1, true, 8.12);
    EqualLinear(loctestnum, loctesterr, vec1, lst1, true);

    // caso n 
    lasd::SortableVector<double> vec(3);
    SetAt(loctestnum, loctesterr, vec, true, 0, 1.4);
    SetAt(loctestnum, loctesterr, vec, true, 1, 2.8);
    SetAt(loctestnum, loctesterr, vec, true, 2, 3.6);

    lasd::List<double> lst;
    InsertAtBack(loctestnum, loctesterr, lst, true, 1.4);
    InsertAtBack(loctestnum, loctesterr, lst, true, 2.8);
    InsertAtBack(loctestnum, loctesterr, lst, true, 3.6);

    EqualLinear(loctestnum, loctesterr, vec, lst, true);

    lasd::SortableVector<double> copvec(lst);
    EqualVector(loctestnum, loctesterr, vec, copvec, true);
    lasd::SortableVector<double> copvecx(vec);
    EqualVector(loctestnum, loctesterr, copvecx, copvec, true);

    lasd::List<double> coplst(vec);
    EqualList(loctestnum, loctesterr, lst, coplst, true);
    lasd::List<double> coplstx(lst);
    EqualList(loctestnum, loctesterr, coplstx, coplst, true);

  } catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector/List<double> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}


void mytestVectorListString(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  cout << endl << "Begin of Vector/List<string> Test:" << endl;
  try {
    // caso 0 
    lasd::SortableVector<string> vec0;
    lasd::List<string> lst0;
    EqualLinear(loctestnum, loctesterr, vec0, lst0, true);

    // caso 1
    lasd::SortableVector<string> vec1(1);
    SetAt(loctestnum, loctesterr, vec1, true, 0, string("Apple"));
    lasd::List<string> lst1;
    InsertAtBack(loctestnum, loctesterr, lst1, true, string("Apple"));
    EqualLinear(loctestnum, loctesterr, vec1, lst1, true);

    // caso n 
    lasd::SortableVector<string> vec(3);
    SetAt(loctestnum, loctesterr, vec, true, 0, string("Violin"));
    SetAt(loctestnum, loctesterr, vec, true, 1, string("Flaute"));
    SetAt(loctestnum, loctesterr, vec, true, 2, string("Guitar"));

    lasd::List<string> lst;
    InsertAtFront(loctestnum, loctesterr, lst, true, string("Guitar"));
    InsertAtFront(loctestnum, loctesterr, lst, true, string("Flaute"));
    InsertAtFront(loctestnum, loctesterr, lst, true, string("Violin"));

    EqualLinear(loctestnum, loctesterr, vec, lst, true);

    lasd::SortableVector<string> copvec(lst);
    EqualVector(loctestnum, loctesterr, vec, copvec, true);
    lasd::SortableVector<string> copvecx(vec);
    EqualVector(loctestnum, loctesterr, copvecx, copvec, true);

    lasd::List<string> coplst(vec);
    EqualList(loctestnum, loctesterr, lst, coplst, true);
    lasd::List<string> coplstx(lst);
    EqualList(loctestnum, loctesterr, coplstx, coplst, true);

    lasd::List<string> movlst(std::move(vec));
    Size(loctestnum, loctesterr, movlst, true, 3);
    TraversePreOrder(loctestnum, loctesterr, movlst, true, &TraversePrint<string>);

    lasd::SortableVector<string> movvec(std::move(lst));
    Size(loctestnum, loctesterr, movvec, true, 3);
    TraversePreOrder(loctestnum, loctesterr, movvec, true, &TraversePrint<string>);

  } catch (...) {
    loctestnum++; loctesterr++;
    cout << endl << "Unmanaged error! " << endl;
  }
  cout << "End of Vector/List<string> Test! (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
  testnum += loctestnum;
  testerr += loctesterr;
}


void mytestVectorList(uint & testnum, uint & testerr) {
  uint loctestnum = 0, loctesterr = 0;
  mytestVectorListInt(loctestnum, loctesterr);
  mytestVectorListDouble(loctestnum, loctesterr);
  mytestVectorListString(loctestnum, loctesterr);
  testnum += loctestnum;
  testerr += loctesterr;
  cout << endl << "My test (Vector/List) (Errors/Tests: " << loctesterr << "/" << loctestnum << ")" << endl;
}


void myTestVecList(uint & testnum, uint & testerr) 
{
  mytestVector(testnum, testerr);
  mytestList(testnum, testerr);
  mytestVectorList(testnum, testerr);
  cout << endl << "My test (Vector-List-Vec/List) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
