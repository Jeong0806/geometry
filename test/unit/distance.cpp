// Copyright (c) 2023 Jeong0806, All Rights Reserved.
// Author Jeong Seong In (0806jsi@gmail.com)

#include "geometry/distance.hpp"

#include "gtest/gtest.h"

namespace Jeong0806::geometry {
  TEST(GeometryDistance, Constructor){
    Distance distance1;
    Distance distance2(distance1);
    Distance distance3(std::move(Distance()));
  }

  TEST(GeometryDistance, AssignmentOperator) {
  Distance distance1;
  auto distance2 = distance1;
  auto distance3 = std::move(Distance());
}
}
