
#ifndef _AKEE_BASIC_THREADLOCAL_H_
#define _AKEE_BASIC_THREADLOCAL_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#if defined(_MSC_VER)
  #define AKEE_THREAD_LOCAL     __declspec(thread)
#elif defined(__GNUC__)
  #define AKEE_THREAD_LOCAL     __thread
#elif defined(CXX11_HAVE_THREAD_LOCAL_DECLEAR)
  #define AKEE_THREAD_LOCAL     thread_local
#else
  #define AKEE_THREAD_LOCAL
#endif

#endif  /* _AKEE_BASIC_THREAD_LOCAL_H_ */
