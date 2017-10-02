#include "projectile.hpp"
#include <cmath>

const double m = 1;
const double E_0 = 1;
const double w = 2;
const double k = .5;
const double dt = 0.001;
const double q  = 1;

enum class Type{
  EULER, VERLET
};

auto force(TState s) {

  double x = E_0 * std::cos(k * s.position.z - w * t) / sqrt(2);
  double y = E_0 * std::sin(k * s.position.z - w * t) / sqrt(2);

  return VecR3<double>{x, y , 0} * q;
 }

auto euler_step(TState s, VecR3<double> accel) {
  TState next;
  next.t = s.t + dt;
  next.position = s.position + (s.velocity * dt);
  next.velocity = s.velocity + (accel * dt);
  return next;
}

auto verlet_step(Tstate s, VecR3<double> accel){
  TState next;
  next.t = s.t + dt;

  return next;
}

void n_steps(unsigned n, TState state0, Type type)  {
  print_tstate(state0);
  if (n == 0)
    return;
  else {
    auto state = state0;

    switch (type){

      case EULER:
      for (unsigned k = 0; k < n; ++k) {
        state = euler_step(state, force(state) / m);
        print_tstate(state);
      }
      break;

      case VERLET:
      for (unsigned k = 0; k < n; ++k) {
        state = verlet_step(state, force(state) / m);
        print_tstate(state);
      }
      break;
    }
  }
}

int main(char c) {
  if(c == 'E' || c == 'e')
    n_steps(12000, TState{0., {-E_0 / (w * w * sqrt(2)), 0, 0}, {0, E_0 / (w * sqrt(2), -.25)}}, Type::EULER);
  else (c == 'V' || c == 'v')
      n_steps(12000, TState{0., {-E_0 / (w * w * sqrt(2)), 0, 0}, {0, E_0 / (w * sqrt(2), -.25)}}, Type::VERLET);
  return 0;
}
