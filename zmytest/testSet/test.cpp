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


void myTestSet(uint & testnum, uint & testerr) {
 //MytestSetInt(testnum, testerr);
 // MytestSetFloat(testnum, testerr);
 // MytestSetString(testnum, testerr);
  cout << endl << "My test (Set) (Errors/Tests: " << testerr << "/" << testnum << ")" << endl;
}
