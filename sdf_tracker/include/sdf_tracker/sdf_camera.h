#ifndef _SDF_CAMERA_H
#define _SDF_CAMERA_H

#include<Eigen/Core>
#include<Eigen/Geometry>

class SDF_CamParameters
{

//members
public:
  int image_height;
  int image_width;
  double fx;
  double fy;
  double cx;
  double cy;
  SDF_CamParameters();

//methods
public:
  /**inverse projection for this camera
     @param x: 3D point to project back onto the camera plane
     @param T: Camera transformation
     @param u: resulting pixel along x
     @param v: resulting pixel along y
     @return true is within image boundary, false otherwise
  */
  inline bool back_project(const Eigen::Vector3d &x, const Eigen::Affine3d &T, int &u, int &v) {

  }

  /** forward projection of a depth pixel. Note, in camera frame, so 
    transform by camera pose after obtaining the result.
    @param pv: pixel value
    @param u: x-coordinate of pixel
    @param v: y coordinate of pixel
    @param x: resulting 3D point
    @return true is within image boundary, false otherwise
   */
  inline bool project(const double &pv, const int &u, const int &v, Eigen::Vector3d &x) {

  } 
 
};

#endif
