#ifndef __TEST_H__
#define __TEST_H__

#include "head.hpp"

namespace qstd
{
  class TestPrivate;
  class Test
  {
  public:
    Test();
    ~Test();

  public:
    bool Create();

  private:
    TestPrivate *d_ptr;
    Q_DECLARE_PRIVATE(Test);
  };

} // namespace qstd

#endif // __TEST_H__