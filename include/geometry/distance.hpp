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

  /**
   * @brief Get the distance value for distance type
   * @param type The distance type
   * @return double The distance value
   */
  [[nodiscard]] auto GetValue(const DistanceType& type) const -> double;
  /**
   * @brief Set the distance value for distance type
   * @param value The distance value
   * @param type The distance type
   */
  auto SetValue(double value, const DistanceType& type) -> void;

  /**
   * @brief Compare with other distance object for equality
   * @param other The other distance object
   * @return true If equal
   * @return false If not equal
   */
  auto operator==(const Distance& other) const -> bool;
  /**
   * @brief Compare with other distance object for equality
   * @param other The other distance object
   * @return true If not equal
   * @return false If equal
   */
  auto operator!=(const Distance& other) const -> bool;
  /**
   * @brief Compare with other distance object for less
   * @param other The other distance object
   * @return true true If less
   * @return false false If bigger or equal
   */
  auto operator<(const Distance& other) const -> bool;
  /**
   * @brief Compare with other distance object for less or equal
   * @param other The other distance object
   * @return true true true If less of eqaul
   * @return false false If bigger
   */
  auto operator<=(const Distance& other) const -> bool;
  /**
   * @brief Compare with other distance object for bigger
   * @param other The other distance object
   * @return true true If bigger
   * @return false false If less or equal
   */
  auto operator>(const Distance& other) const -> bool;
  /**
   * @brief Compare with other distance object for bigger or equal
   * @param other The other distance object
   * @return true true If bigger or equal
   * @return false false If less
   */
  auto operator>=(const Distance& other) const -> bool;

  /**
   * @brief Add other distance object
   * @param other The other distance object
   * @return Distance The result of addition
   */
  auto operator+(const Distance& other) const -> Distance;
  /**
   * @brief Subtract other distance object
   * @param other The other distance object
   * @return Distance The result of subtraction
   */
  auto operator-(const Distance& other) const -> Distance;
  /**
   * @brief Multiply by scale
   * @param scale The value for multiplication
   * @return Distance The result of multiplication
   */
  auto operator*(double scale) const -> Distance;
  /**
   * @brief Divide by scale
   * @param scale The value for division
   * @return Distance The result of division
   */
  auto operator/(double scale) const -> Distance;

  /**
   * @brief Add other distance object
   * @param other The other distance object
   */
  auto operator+=(const Distance& other) -> void;
  /**
   * @brief Subtract other distance object
   * @param other The other distance object
   */
  auto operator-=(const Distance& other) -> void;
  /**
   * @brief Multiply by scale
   * @param scale The value for multiplication
   */
  auto operator*=(double scale) -> void;
  /**
   * @brief Divide by scale
   * @param scale The value for division
   */
  auto operator/=(double scale) -> void;

 protected:
 private:
  int64_t nanometer_{0};
};
}  // namespace Jeong0806::geometry

#endif  // Jeong0806_GEOMETRY_DISTANCE_HPP_
