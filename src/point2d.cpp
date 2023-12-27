/**
 * @file geometry/src/point2d.cpp
 * @author Jeong Seong In (0806jsi@gmail.com)
 * @brief Point class developments with 2-dimension
 * @version 1.0.0
 * @date 2023-12-27
 * @copyright Copyright (c) 2023 Jeong0806, All Rights Reserved.
 */

// Copyright (c) 2023 Jeong0806, All Rights Reserved.
// Author Jeong Seong In (0806jsi@gmail.com)

#include "geometry/point2d.hpp"

#include <cmath>

namespace Jeong0806::geometry {
Point2D::Point2D(double x, double y) : x_(x), y_(y) {}

auto Point2D::CalculateDistance(const Point2D& target) const -> double {
  return Point2D::CalculateDistance(*this, target);
}

auto Point2D::CalculateDistance(const Point2D& lhs, const Point2D& rhs)
    -> double {
  return std::sqrt(std::pow((lhs.x_ - rhs.x_), 2.0) +
                   std::pow((lhs.y_ - rhs.y_), 2.0));
}

auto Point2D::GetX() const -> double { return x_; }

auto Point2D::GetY() const -> double { return y_; }

auto Point2D::SetX(double x) -> void { x_ = x; }
auto Point2D::SetY(double y) -> void { y_ = y; }
}  // namespace Jeong0806::geometry
