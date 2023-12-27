// Copyright (c) 2023 Jeong0806, All Rights Reserved.
// Author Jeong Seong In (0806jsi@gmail.com)

#include "geometry/distance.hpp"

#include <cstdint>

#include "gtest/gtest.h"

namespace {
constexpr uint32_t kTestCount = 1000U;
}

namespace Jeong0806::geometry {
TEST(GeometryDistance, Constructor) {
  Distance distance1;
  Distance distance2(distance1);
  Distance distance3(std::move(Distance()));
}

TEST(GeometryDistance, ConstructorWithValue) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    Distance distance1(static_cast<double>(std::rand()));
    Distance distance2(static_cast<double>(std::rand()),
                       Distance::DistanceType::kKilometer);
    Distance distance3(static_cast<double>(std::rand()),
                       Distance::DistanceType::kMeter);
    Distance distance4(static_cast<double>(std::rand()),
                       Distance::DistanceType::kCentimeter);
    Distance distance5(static_cast<double>(std::rand()),
                       Distance::DistanceType::kMillimeter);
    Distance distance6(static_cast<double>(std::rand()),
                       Distance::DistanceType::kMicrometer);
    Distance distance7(static_cast<double>(std::rand()),
                       Distance::DistanceType::kNanometer);
  }
}

TEST(GeometryDistance, AssignmentOperator) {
  Distance distance1;
  auto distance2 = distance1;
  auto distance3 = std::move(Distance());
}
}  // namespace Jeong0806::geometry
