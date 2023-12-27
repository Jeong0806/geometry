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

namespace Jeong0806::distance {
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

 protected:
 private:
};
}  // namespace Jeong0806::distance

#endif  // Jeong0806_GEOMETRY_DISTANCE_HPP_
