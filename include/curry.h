#ifndef _CURRY_H_
#define _CURRY_H_

#include <functional>

namespace fp {
  template <typename A, typename B, typename R>
  std::function<std::function<R(B)>(A)> curry(std::function<R(A, B)> f) {
    return [=](A a) {
      return [=](B b) {
        return f(a, b);
      };
    };
  }
}

#endif
