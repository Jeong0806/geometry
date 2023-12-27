// Copyright (c) 2023 Jeong0806, All Rights Reserved.
// Author Jeong Seong In (0806jsi@gmail.com)

#include "geometry/point2d.hpp"

#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <limits>
#include <stdexcept>

#include "gtest/gtest.h"

namespace {
constexpr uint32_t kTestCount = 1000U;
}

namespace Jeong0806::geometry {
TEST(GeometryPoint2D, Constructor) {
  Point2D point1;
  Point2D point2(0.0,0.0);
}
}  // namespace jeong0806::geometry
