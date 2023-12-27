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
  Point2D point2(0.0, 0.0);
  Point2D point3(point1);
  Point2D point4(std::move(point2));
}

TEST(GeometryPoint2D, AssignmentOperator) {
  Point2D point1;
  auto point2 = point1;
  auto point3 = std::move(Point2D());
}

TEST(GeometryPoint2D, CalculateDistance) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_EQ(std::sqrt(std::pow((kSourceX - kTargetX), 2.0) +
              std::pow((kSourceY - kTargetY), 2.0)),
              source.CalculateDistance(target));
  }
}

TEST(GeometryPoint2D, StaticCalculateDistance) {
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());
    const auto kSourceY = static_cast<double>(std::rand());
    const auto kTargetX = static_cast<double>(std::rand());
    const auto kTargetY = static_cast<double>(std::rand());

    Point2D source(kSourceX, kSourceY);
    Point2D target(kTargetX, kTargetY);

    EXPECT_EQ(std::sqrt(std::pow((kSourceX - kTargetX), 2.0) +
              std::pow((kSourceY - kTargetY), 2.0)),
              Point2D::CalculateDistance(source, target));
  }
}

TEST(GeometryPoint2D, GetX){
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceX = static_cast<double>(std::rand());

    Point2D source(kSourceX, 0.0);

    EXPECT_EQ(source.GetX(), kSourceX);
  }
}

TEST(GeometryPoint2D, GetY){
  for (uint32_t i = 0; i < kTestCount; ++i) {
    const auto kSourceY = static_cast<double>(std::rand());

    Point2D source(0.0, kSourceY);

    EXPECT_EQ(source.GetY(), kSourceY);
  }
}
}  // namespace Jeong0806::geometry
