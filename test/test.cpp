#include "test.h"
#include "test_p.h"
namespace qstd
{

  Test::Test() : d_ptr(new TestPrivate(this))
  {
  }

  Test::~Test()
  {
  }

  bool Test::Create()
  {
#if 1
    Q_D(Test)
    d->Init();
#else
    d_func()->Init();
#endif
    return false;
  }
} // namespace qstd
