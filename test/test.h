#ifndef __TEST_H__
#define __TEST_H__

#include "head.hpp"

namespace qstd
{
  class TestPrivate;
  class Test
  {
    Q_DECLARE_PRIVATE(TestPrivate)
  public:
    Test();
    ~Test();

  private:
  };

} // namespace qstd

#endif // __TEST_H__