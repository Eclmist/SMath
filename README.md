<h1 align="center">
    SMath
  <br>
</h1>
<h4 align="center">A (WIP) C++20 vector/matrix math library for graphics applications.</h4>

<p align="center">
  <a href="https://github.com/Eclmist/SMath/actions">
    <img src="https://github.com/eclmist/SMath/workflows/build/badge.svg" alt="Build Status">
  </a>
  <a href="#------">
    <img src="https://img.shields.io/badge/stability-WIP-orange.svg">
  </a>
  <a href="https://www.gnu.org/licenses/gpl-3.0.en.html">
    <img src="https://img.shields.io/badge/license-GPL3--or--later-blue.svg">
  </a>
</p>

# Introduction
SMath is a simple open-source C++20 math library for graphics applications.

# Requirements
- Only CMake versions 3.8 and up is supported
- If compiling with GCC, use GCC10 and above

# Getting Started
Add all files in `src` into any C++20 project and include `src/smath.h` to get started.

The following are the currently available types, which can be typedef'd to your liking:
```c++
typedef SMath::Vector<double, 2>    Vector2;
typedef SMath::Vector<double, 3>    Vector3;
typedef SMath::Vector<double, 4>    Vector4;
typedef SMath::Vector<int, 2>       Vector2i;
typedef SMath::Vector<int, 3>       Vector3i;
typedef SMath::Point<double, 2>     Point2;
typedef SMath::Point<double, 3>     Point3;
typedef SMath::Point<int, 2>        Point2i;
typedef SMath::Point<int, 3>        Point3i;
typedef SMath::Normal<double, 3>    Normal3;
typedef SMath::Matrix<double, 3>    Matrix3x3;
typedef SMath::Matrix<double, 4>    Matrix4x4;
typedef SMath::Matrix<int, 3>       Matrix3x3i;
typedef SMath::Matrix<int, 4>       Matrix4x4i;

typedef SMath::Ray                  Ray;
typedef SMath::Rect                 Rect;
typedef SMath::Transform            Transform;
```
