/**
 * @file geometry/point2d.hpp
 * @author Jeong Seong In (0806jsi@gmail.com)
 * @brief Point class declaration with 2-dimension
 * @version 1.0.0
 * @date 2023-12-22
 * @copyright Copyright (c) 2023 Jeong0806, All Rights Reserved.
 */

// Copyright (c) 2023 Jeong0806, All Rights Reserved.
// Author Jeong Seong In (0806jsi@gmail.com)

#ifndef Jeong0806_GEOMETRY_POINT_2D_HPP_
#define Jeong0806_GEOMETRY_POINT_2D_HPP_

namespace Jeong0806::geometry {
/**
 * @brief Point class with 2-demension
 */
class Point2D {
 public:
  /**
   * @brief Construct a new Point2D object
   */
  Point2D() = default;
  /**
   * @brief Construct a new Point2D object with x, y coordinate values
   * @param x Double type x coordinate value
   * @param y Double type y coordinate value
   */
  Point2D(double x, double y);
  /**
   * @brief Copy construct a new Point2D object with other Point2D object
   * @param other Point2D object
   */
  Point2D(const Point2D& other) = default;
  /**
   * @brief Move construct a new Point2D object with other Point2D object
   * @param other Point2D object
   */
  Point2D(Point2D&& other) noexcept = default;
  /**
   * @brief Destroy the Point2D object
   */
  virtual ~Point2D() = default;

  /**
   * @brief Copy assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  auto operator=(const Point2D& other) -> Point2D& = default;
  /**
   * @brief Move assignment operator
   * @param other Point2D object
   * @return Point2D& Reference of Point2D object
   */
  auto operator=(Point2D&& other) -> Point2D& = default;

  /**
   * @brief Clculate distance between this point and target point
   * @param target Other Point2D object to calculate distance
   * @return double Euclidean distance betwwen this point and target point
   */
  auto CalculateDistance(const Point2D& target) const -> double;
  /**
   * @brief Clculate distance between lhs point and rhs point
   * @param lhs Left hand side Point2D object
   * @param rhs Right hand side Point2D object
   * @return double double Euclidean distance betwwen lhs point and rhs point
   */
  [[nodiscard]] static auto CalculateDistance(const Point2D& lhs,
                                              const Point2D& rhs) -> double;

  /**
   * @brief Set x coordinate value
   * @param x Double type input x coordinate value
   */
  auto SetX(double x) -> void;
  /**
   * @brief Set y coordinate value
   * @param y Double type input y coordinate value
   */
  auto SetY(double y) -> void;
  /**
   * @brief Get x coordinate value of this point
   * @return double x coordinate value of this point
   */
  [[nodiscard]] auto GetX() const -> double;
  /**
   * @brief Get y coordinate value of this point
   * @return double y coordinate value of this point
   */
  [[nodiscard]] auto GetY() const -> double;
  /**
   * @brief Add the x and y coordinates of this and target object respectively
   * @param other Point2D object
   * @return Point2D Point2D& Reference of Point2D object
   */
  auto operator+(const Point2D& other) const -> Point2D;
  /**
   * @brief Subtract the x and y coordinates of this and target object respectively
   * @param other Point2D object
   * @return Point2D Point2D& Reference of Point2D object
   */
  auto operator-(const Point2D& other) const -> Point2D;
  /**
   * @brief Add target object's x, y coordinates in this object's
   * @param other Point2D object
   */
  auto operator+=(const Point2D& other) -> void;
  /**
   * @brief Subtract target object's x, y coordinates in this object's
   * @param other Point2D object
   */
  auto operator-=(const Point2D& other) -> void;
  /**
   * @brief Multiply scalar by the coordinates x and y of this
   * @param scalar Double type operand
   * @return Point2D Point2D& Reference of Point2D object
   */
  auto operator*(double scalar) const -> Point2D;
  /**
   * @brief Divide scalar by the coordinates x and y of this
   * @param scalar Double type operand
   * @return Point2D Point2D& Reference of Point2D object
   * @throws invalid_argument If operand is zero, nan, or inf
   */
  auto operator/(double scalar) const -> Point2D;
  /**
   * @brief Check if the coordinates x and y of this and target object have the same values
   * @param other Point2D object
   * @return true If this and target object's x, y coordinates is equal
   * @return false If this and target object's x, y coordinates is not equal
   */
  auto operator==(const Point2D& other) const -> bool;
  /**
   * @brief Check if the coordinates x and y of this and target object have the different values
   * @param other Point2D object
   * @return true If this and target object's x, y coordinates is not equal
   * @return false If this and target object's x, y coordinates is equal
   */
  auto operator!=(const Point2D& other) const -> bool;

 protected:
 private:
  double x_{0.0};  ///< x coordinate
  double y_{0.0};  ///< y coordinate
};
}  // namespace Jeong0806::geometry

#endif  // Jeong0806_GEOMETRY_POINT_2D_HPP_
