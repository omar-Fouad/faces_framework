/*
 * ModernPosit.h
 *
 *  Created on: 22.10.2010
 *      Author: pwohlhart
 */

#ifndef MODERN_POSIT_H
#define MODERN_POSIT_H

#include <vector>
#include <opencv2/opencv.hpp>

/**
 * POSIT is a fast iterative algorithm for finding the pose (rotation and translation)
 * of an object or scene with respect to a camera when points of the object are given
 * in some object coordinate system and these points are visible in the camera image
 * and recognizable, so that corresponding image points and object points can be listed
 * in the same order.
 */
class ModernPosit
{
public:
  ModernPosit() {};

  virtual
  ~ModernPosit() {};

  static cv::Mat
  run
    (
    const std::vector<cv::Point3f> &world_pts,
    const std::vector<cv::Point2f> &image_pts,
    const cv::Mat &cam_matrix,
    int max_iters = 100
    );

  static cv::Vec3d
  getEulerAngles
    (
    cv::Mat &rot_matrix
    );
};

#endif /* MODERN_POSIT_H */