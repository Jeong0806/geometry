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

TEST(GeometryDistance, OperatorEual) {
  for (uint32_t i; i < kTestCount; ++i) {
    const auto kValue = static_cast<double>(std::rand());

    Distance distance_by_killometer(kValue, Distance::DistanceType::kKilometer);

    Distance distance_by_meter(kValue * 1.0e+3, Distance::DistanceType::kMeter);
    EXPECT_TRUE(distance_by_killometer == distance_by_meter);

    Distance distance_by_centimeter(kValue * 1.0e+5,
                                    Distance::DistanceType::kCentimeter);
    EXPECT_TRUE(distance_by_killometer == distance_by_centimeter);

    Distance distance_by_millimetero(kValue * 1.0e+6,
                                     Distance::DistanceType::kMillimeter);
    EXPECT_TRUE(distance_by_killometer == distance_by_millimetero);

    Distance distance_by_micrometer(kValue * 1.0e+9,
                                    Distance::DistanceType::kMicrometer);
    EXPECT_TRUE(distance_by_killometer == distance_by_micrometer);

    Distance distance_by_nanometer(kValue * 1.0e+12,
                                   Distance::DistanceType::kNanometer);
    EXPECT_TRUE(distance_by_killometer == distance_by_nanometer);
  }
}

TEST(GeometryDistance, operatorAdd) {
  for (uint32_t i; i < kTestCount; ++i) {
    const auto kValue = static_cast<double>(std::rand());

    Distance distance_by_killometer(kValue, Distance::DistanceType::kKilometer);
    Distance distance_by_meter(kValue * 1.0e+3, Distance::DistanceType::kMeter);
    Distance distance_by_centimeter(kValue * 1.0e+5,
                                    Distance::DistanceType::kCentimeter);
    Distance distance_by_millimetero(kValue * 1.0e+6,
                                     Distance::DistanceType::kMillimeter);
    Distance distance_by_micrometer(kValue * 1.0e+9,
                                    Distance::DistanceType::kMicrometer);
    Distance distance_by_nanometer(kValue * 1.0e+12,
                                   Distance::DistanceType::kNanometer);

    const auto distance1 = distance_by_killometer + distance_by_meter;
    const auto distance2 = distance_by_killometer + distance_by_centimeter;
    const auto distance3 = distance_by_killometer + distance_by_millimetero;
    const auto distance4 = distance_by_killometer + distance_by_micrometer;
    const auto distance5 = distance_by_killometer + distance_by_nanometer;

    EXPECT_DOUBLE_EQ(distance1.GetValue(Distance::DistanceType::kKilometer),
                     kValue * 2.0);
    EXPECT_DOUBLE_EQ(distance2.GetValue(Distance::DistanceType::kKilometer),
                     kValue * 2.0);
    EXPECT_DOUBLE_EQ(distance3.GetValue(Distance::DistanceType::kKilometer),
                     kValue * 2.0);
    EXPECT_DOUBLE_EQ(distance4.GetValue(Distance::DistanceType::kKilometer),
                     kValue * 2.0);
    EXPECT_DOUBLE_EQ(distance5.GetValue(Distance::DistanceType::kKilometer),
                     kValue * 2.0);
  }
}
}  // namespace Jeong0806::geometry