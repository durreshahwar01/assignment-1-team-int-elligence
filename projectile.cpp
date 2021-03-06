#include "projectile.hpp"
#include <cmath>
#include <string>
#include <iostream>

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

  double x = E_0 * std::cos(k * s.position.z - w * s.t) / sqrt(2);
  double y = E_0 * std::sin(k * s.position.z - w * s.t) / sqrt(2);

  return VecR3<double>{x, y , 0} * q;
 }

auto euler_step(TState s, VecR3<double> accel) {
  TState next;
  next.t = s.t + dt;
  next.position = s.position + (s.velocity * dt);
  next.velocity = s.velocity + (accel * dt);
  return next;
}

auto verlet_step(TState s, VecR3<double> accel){
  TState next;
  next.t = s.t + dt;
  next.position = s.position +(s.velocity *dt) + 0.5*accel*dt*dt;
  VecR3<double> accelDt = force(next)/m;
  next.velocity = s.velocity + (0.5*(accel + accelDt))*dt;
  return next;
}

void n_steps(unsigned n, TState state0, Type type)  {
  print_tstate(state0);
  if (n == 0)
    return;
  else {
    auto state = state0;

    switch (type){

      case Type::EULER:
      for (unsigned k = 0; k < n; ++k) {
        state = euler_step(state, force(state) / m);
        print_tstate(state);
      }
      break;

      case Type::VERLET:
      for (unsigned k = 0; k < n; ++k) {
        state = verlet_step(state, force(state) / m);
        print_tstate(state);
      }
      break;
    }
  }
}

int main(int argc, char* argv[]) {

  if (argc == 1){
    std::cout << "Enter an algorithm" << std::endl;
    return 0;
  } else if (argc > 2) {
    std::cout << "Only one type of algorithm is supported" << std::endl;
    return 0;
  }

  if (argv[1] == std::string("-v") || argv[1] == std::string("-V"))
    n_steps(12000, TState{0., {-E_0 / (w * w * sqrt(2)), 0, 0}, {0, E_0 / (w * sqrt(2)), -.25}}, Type::VERLET);
  else if (argv[1] == std::string("-e") || argv[1] == std::string("-E"))
    n_steps(12000, TState{0., {-E_0 / (w * w * sqrt(2)), 0, 0}, {0, E_0 / (w * sqrt(2)), -.25}}, Type::EULER);
  return 0;
}
