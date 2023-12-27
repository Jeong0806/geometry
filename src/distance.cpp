/**
 * @file geometry/src/distance.cpp
 * @author Jeong Seong In (0806jsi@gmail.com)
 * @brief Distance class developments for abstract distance
 * @version 1.0.0
 * @date 2023-12-27
 * @copyright Copyright (c) 2023 Jeong0806, All Rights Reserved.
 */

// Copyright (c) 2023 Jeong0806, All Rights Reserved.
// Author Jeong Seong In (0806jsi@gmail.com)

#include "geometry/distance.hpp"

#include <cstdint>

namespace {
auto ScaleDistanceToNanometer(double value,
                              Jeong0806::geometry::Distance::DistanceType type)
    -> int64_t {
  int64_t result;
  switch (type) {
    case Jeong0806::geometry::Distance::DistanceType::kKilometer:
      result = static_cast<int64_t>(value * 1.0e+12);
      break;
    case Jeong0806::geometry::Distance::DistanceType::kMeter:
      result = static_cast<int64_t>(value * 1.0e+9);
      break;
    case Jeong0806::geometry::Distance::DistanceType::kCentimeter:
      result = static_cast<int64_t>(value * 1.0e+7);
      break;
    case Jeong0806::geometry::Distance::DistanceType::kMillimeter:
      result = static_cast<int64_t>(value * 1.0e+6);
      break;
    case Jeong0806::geometry::Distance::DistanceType::kMicrometer:
      result = static_cast<int64_t>(value * 1.0e+3);
      break;
    case Jeong0806::geometry::Distance::DistanceType::kNanometer:
      result = static_cast<int64_t>(value);
      break;
    default: result = static_cast<int64_t>(value * 1.0e+9);
      break;
  }
  return result;
}
}  // namespace

namespace Jeong0806::geometry {
Distance::Distance(double value, DistanceType type)
    : nanometer_(ScaleDistanceToNanometer(value, type)) {}
}  // namespace Jeong0806::geometry
