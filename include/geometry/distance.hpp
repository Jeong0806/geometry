/**
 * @file geometry/distance.hpp
 * @author Jeong Seong In (0806jsi@gmail.com)
 * @brief Distance class declaration for abstract distance
 * @version 1.0.0
 * @date 2023-12-27
 * @copyright Copyright (c) 2023 Jeong0806, All Rights Reserved.
 */

// Copyright (c) 2023 Jeong0806, All Rights Reserved.
// Author Jeong Seong In (0806jsi@gmail.com)

#ifndef Jeong0806_GEOMETRY_DISTANCE_HPP_
#define Jeong0806_GEOMETRY_DISTANCE_HPP_

#include <cstdint>
namespace Jeong0806::geometry {
/**
 * @brief Distance class for abstract distance
 */
class Distance {
 public:
  /**
   * @brief The enum class for distance type
   */
  enum class DistanceType {
    kKilometer = 0,
    kMeter = 1,
    kCentimeter = 2,
    kMillimeter = 3,
    kMicrometer = 4,
    kNanometer = 5
  };

  /**
   * @brief Construct a new Distance object
   */
  Distance() = default;
  /**
   * @brief
   * @param value
   * @param type
   */
  Distance(double value, DistanceType type = DistanceType::kMeter);
  /**
   * @brief Copy construct a new Distance object with other Distance object
   * @param other Distance object
   */
  Distance(const Distance& other) = default;
  /**
   * @brief Move construct a new Distance object with other Distance object
   * @param other Distance object
   */
  Distance(Distance&& other) noexcept = default;
  /**
   * @brief Destroy the Distance object
   */
  virtual ~Distance() = default;

  /**
   * @brief Copy assignment operator
   * @param other Distance object
   * @return Distance& Reference of Distance object
   */
  auto operator=(const Distance& other) -> Distance& = default;
  /**
   * @brief Move assignment operator
   * @param other Distance object
   * @return Distance& Reference of Distance object
   */
  auto operator=(Distance&& other) -> Distance& = default;

 protected:
 private:
  int64_t nanometer_{0};
};
}  // namespace Jeong0806::geometry

#endif  // Jeong0806_GEOMETRY_DISTANCE_HPP_