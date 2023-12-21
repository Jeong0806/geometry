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

 private:
  double x_{0.0};  ///< x coordinate
  double y_{0.0};  ///< y coordinate
};
}  // namespace Jeong0806::geometry

#endif  // Jeong0806_GEOMETRY_POINT_2D_HPP_
