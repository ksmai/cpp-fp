#ifndef _MEMOIZE_H_
#define _MEMOIZE_H_

#include <functional>
#include <map>

namespace fp {
  template<typename A, typename R>
  class Memoized {
  public:
    Memoized(std::function<R(A)> fn): fn{fn} {
    }

    R operator()(A a) {
      if (cache.find(a) != cache.end()) {
        return cache[a];
      }
      return cache[a] = fn(a);
    }

  private:
    std::function<R(A)> fn;
    std::map<A, R> cache;
  };

  template <typename A, typename R>
  std::function<R(A)> memoize(std::function<R(A)> f) {
    return Memoized<A, R>{f};
  }
}

#endif
