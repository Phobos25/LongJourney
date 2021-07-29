#include "test_runner.h"
inline void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}
// comment