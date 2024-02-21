#ifndef __TESTPRIVATE_H__
#define __TESTPRIVATE_H__

#include "head.hpp"
namespace qstd
{
  class Test;
  class TestPrivate
  {
  public:
    TestPrivate(Test* q);
    ~TestPrivate();

   private:
   void Init(); 

  private:
    Test *q_ptr;
    Q_DECLARE_PUBLIC(Test);

  private:
    bool m_bCreate;
  };

} // namespace qstd

#endif // __TESTPRIVATE_H__