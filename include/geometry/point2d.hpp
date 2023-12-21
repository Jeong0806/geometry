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
  Point2D() = default;
  Point2D(double x, double y);

  Point2D(const Point2D& other) = default;
  Point2D(Point2D&& other) = default;

  ~Point2D() = default;

 private:
  double x_{0.0};  ///< x coordinate
  double y_{0.0};  ///< y coordinate
};
}  // namespace Jeong0806::geometry

#endif  // Jeong0806_GEOMETRY_POINT_2D_HPP_
