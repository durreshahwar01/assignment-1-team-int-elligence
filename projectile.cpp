#include "projectile.hpp"
#include <cmath>

const double m = 1;
const double E_0 = 1;
const double w = 2;
const double k = .5;
const double dt = 0.001;

enum class Type{
  EULER, VERLET;
}

auto force(TState s) {

  double x = ;
  double y;

  return VecR3<double>{0, -m * g, 0};

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

int main() {
  n_steps(1200, TState{0., {0, 0, 0}, {0, 0, -.25}}, Type::EULER);
  return 0;
}
