#ifndef __HEAD_H__
#define __HEAD_H__
namespace qstd
{
    template <typename T>
    inline T *qGetPtrHelper(T *ptr) { return ptr; }

    template <typename Ptr>
    inline auto qGetPtrHelper(const Ptr &ptr) -> decltype(ptr.operator->()) { return ptr.operator->(); }

#define Q_DECLARE_PRIVATE(Class)                                                                                           \
    inline Class##Private *d_func() { return reinterpret_cast<Class##Private *>(qGetPtrHelper(d_ptr)); }                   \
    inline const Class##Private *d_func() const { return reinterpret_cast<const Class##Private *>(qGetPtrHelper(d_ptr)); } \
    friend class Class##Private;

#define Q_DECLARE_PRIVATE_D(Dptr, Class)                                                                                  \
    inline Class##Private *d_func() { return reinterpret_cast<Class##Private *>(qGetPtrHelper(Dptr)); }                   \
    inline const Class##Private *d_func() const { return reinterpret_cast<const Class##Private *>(qGetPtrHelper(Dptr)); } \
    friend class Class##Private;

#define Q_DECLARE_PUBLIC(Class)                                                      \
    inline Class *q_func() { return static_cast<Class *>(q_ptr); }                   \
    inline const Class *q_func() const { return static_cast<const Class *>(q_ptr); } \
    friend class Class;

#define Q_D(Class) Class##Private *const d = d_func();
#define Q_Q(Class) Class *const q = q_func();

}

#endif // __HEAD_H__