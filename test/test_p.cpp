#include "test_p.h"

#include "test.h"

namespace qstd
{

  TestPrivate::TestPrivate(Test *q) : q_ptr(q)
  {
  }

  TestPrivate::~TestPrivate()
  {
  }

  void TestPrivate::Init()
  {
#if 1
    Q_Q(Test);
    q->Create();
#else
    q_func()->Create();
#endif
  }

} // namespace qstd
