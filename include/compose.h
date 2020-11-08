#ifndef _COMPOSE_H_
#define _COMPOSE_H_

#include <functional>

template <typename X, typename Y, typename Z>
std::function<Z(X)> compose(std::function<Z(Y)> f, std::function<Y(X)> g) {
  return [f, g](X x) {
    return f(g(x));
  };
}

#endif
