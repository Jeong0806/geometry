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

TEST(GeometryDistance, GetValue) {
  for (uint32_t i; i < kTestCount; ++i) {
    const auto kValue = static_cast<double>(std::rand());

    Distance distance1(static_cast<double>(kValue),
                       Distance::DistanceType::kKilometer);
    EXPECT_EQ(kValue, distance1.GetValue(Distance::DistanceType::kKilometer));

    Distance distance2(static_cast<double>(kValue),
                       Distance::DistanceType::kMeter);
    EXPECT_EQ(kValue, distance2.GetValue(Distance::DistanceType::kMeter));

    Distance distance3(static_cast<double>(kValue),
                       Distance::DistanceType::kCentimeter);
    EXPECT_EQ(kValue, distance3.GetValue(Distance::DistanceType::kCentimeter));

    Distance distance4(static_cast<double>(kValue),
                       Distance::DistanceType::kMillimeter);
    EXPECT_EQ(kValue, distance4.GetValue(Distance::DistanceType::kMillimeter));

    Distance distance5(static_cast<double>(kValue),
                       Distance::DistanceType::kMicrometer);
    EXPECT_EQ(kValue, distance5.GetValue(Distance::DistanceType::kMicrometer));

    Distance distance6(static_cast<double>(kValue),
                       Distance::DistanceType::kNanometer);
    EXPECT_EQ(kValue, distance6.GetValue(Distance::DistanceType::kNanometer));
  }
}

TEST(GeometryDistance, SetValue) {
  for (uint32_t i; i < kTestCount; ++i) {
    const auto kValue = static_cast<double>(std::rand());

    Distance distance1;
    distance1.SetValue(kValue, Distance::DistanceType::kKilometer);
    EXPECT_EQ(kValue, distance1.GetValue(Distance::DistanceType::kKilometer));

    Distance distance2;
    distance2.SetValue(kValue, Distance::DistanceType::kMeter);
    EXPECT_EQ(kValue, distance2.GetValue(Distance::DistanceType::kMeter));

    Distance distance3;
    distance3.SetValue(kValue, Distance::DistanceType::kCentimeter);
    EXPECT_EQ(kValue, distance3.GetValue(Distance::DistanceType::kCentimeter));

    Distance distance4;
    distance4.SetValue(kValue, Distance::DistanceType::kMillimeter);
    EXPECT_EQ(kValue, distance4.GetValue(Distance::DistanceType::kMillimeter));

    Distance distance5;
    distance5.SetValue(kValue, Distance::DistanceType::kMicrometer);
    EXPECT_EQ(kValue, distance5.GetValue(Distance::DistanceType::kMicrometer));

    Distance distance6;
    distance6.SetValue(kValue, Distance::DistanceType::kNanometer);
    EXPECT_EQ(kValue, distance6.GetValue(Distance::DistanceType::kNanometer));
  }
}
}  // namespace Jeong0806::geometry