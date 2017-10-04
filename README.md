# `livecode-projectile`
---
![](https://travis-ci.org/SOFE-2850U/assignment-1-team-int-elligence.svg?branch=master)

An implementation of an integrator for a particle. The main purpose of this is to show the path of the particle based on its force. It has the option to show the path using an Euler integration algorithm, or the more accurate integration algorithm: Verlet.

This code was based off of GitHub user TimTro's livecode-projectile repository. This can be found at <link href= "https://github.com/Timtro/livecode-projectile/" />


## Compilation

Compile with
```bash
clang++ -std=c++14 -o projectile projectile.cpp
```
or
```bash
g++ -std=c++14 -o projectile projectile.cpp
```
and run as
```bash
./projectile
```
and watch your terminal fill with numbers.

## Output

The output will be six columns of numbers with the following order:
```
time [s], x-position [m], y-position [m], x-speed [m/s], y-speed [m/s]
```
Plot the, you get the familiar parabolic trajectory, which will depend on your constants:  
![](example.jpg)
