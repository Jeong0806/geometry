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
constexpr int64_t kKilometerToNanometer{static_cast<int64_t>(1.0e+12)};
constexpr int64_t kMeterToNanometer{static_cast<int64_t>(1.0e+9)};
constexpr int64_t kCentimeterToNanometer{static_cast<int64_t>(1.0e+7)};
constexpr int64_t kMillimeterToNanometer{static_cast<int64_t>(1.0e+6)};
constexpr int64_t kMicrometerToNanometer{static_cast<int64_t>(1.0e+3)};

constexpr double kNonometerToKillometer{1.0e-12};
constexpr double kNonometerToMeter{1.0e-9};
constexpr double kNonometerToCentimeter{1.0e-7};
constexpr double kNonometerToMillimeter{1.0e-6};
constexpr double kNonometerToMicrometer{1.0e-3};

auto ScaleDistanceToNanometer(double value,
                              Jeong0806::geometry::Distance::DistanceType type)
    -> int64_t {
  int64_t result;
  switch (type) {
    case Jeong0806::geometry::Distance::DistanceType::kKilometer:
      result = static_cast<int64_t>(value * kKilometerToNanometer);
      break;
    case Jeong0806::geometry::Distance::DistanceType::kMeter:
      result = static_cast<int64_t>(value * kMeterToNanometer);
      break;
    case Jeong0806::geometry::Distance::DistanceType::kCentimeter:
      result = static_cast<int64_t>(value * kCentimeterToNanometer);
      break;
    case Jeong0806::geometry::Distance::DistanceType::kMillimeter:
      result = static_cast<int64_t>(value * kMillimeterToNanometer);
      break;
    case Jeong0806::geometry::Distance::DistanceType::kMicrometer:
      result = static_cast<int64_t>(value * kMicrometerToNanometer);
      break;
    case Jeong0806::geometry::Distance::DistanceType::kNanometer:
      result = static_cast<int64_t>(value);
      break;
    default:
      result = static_cast<int64_t>(value * kMeterToNanometer);
      break;
  }
  return result;
}
}  // namespace

namespace Jeong0806::geometry {
Distance::Distance(double value, DistanceType type)
    : nanometer_(ScaleDistanceToNanometer(value, type)) {}
auto Distance::GetValue(const DistanceType &type) const -> double {
  auto result = static_cast<double>(nanometer_);
  switch (type) {
    case DistanceType::kKilometer:
      result *= kNonometerToKillometer;
      break;
    case DistanceType::kMeter:
      result *= kNonometerToMeter;
      break;
    case DistanceType::kCentimeter:
      result *= kNonometerToCentimeter;
      break;
    case DistanceType::kMillimeter:
      result *= kNonometerToMillimeter;
      break;
    case DistanceType::kMicrometer:
      result *= kNonometerToMicrometer;
      break;
    case DistanceType::kNanometer:
      break;
    default:
      result *= kNonometerToMeter;
      break;
  }
  return result;
}

auto Distance::SetValue(double value, const DistanceType &type) -> void {
  nanometer_ = ScaleDistanceToNanometer(value, type);
}

auto Distance::operator==(const Distance &other) const -> bool {
  return (nanometer_ == other.nanometer_);
}

auto Distance::operator!=(const Distance &other) const -> bool {
  return (nanometer_ != other.nanometer_);
}

auto Distance::operator<(const Distance &other) const -> bool {
  return (nanometer_ < other.nanometer_);
}

auto Distance::operator<=(const Distance &other) const -> bool {
  return (nanometer_ <= other.nanometer_);
}

auto Distance::operator>(const Distance &other) const -> bool {
  return (nanometer_ > other.nanometer_);
}

auto Distance::operator+(const Distance &other) const -> Distance {
  return Distance(static_cast<double>(nanometer_ + other.nanometer_),
                  DistanceType::kNanometer);
}
}  // namespace Jeong0806::geometry
