#ifndef SDF_MAP_INTERFACE_H
#define SDF_MAP_INTERFACE_H


#include <Eigen/Core>
#include <Eigen/Geometry>

#include <sdf_tracker/sdf_camera.h>
/** Abstract class for deriving TSDF maps.
  * Must provide all interfaces in implementation
  */
class SDFMap {

    public:
	/**compute a gradient at a point x
	  *@param x: location to check gradient
	  *@param g: resulting gradient
	  *@return true if valid gradient, false otherwise
	*/
	virtual bool getGradient(const Eigen::Vector3d &x, Eigen::Vector3d &g) = 0;

	/**compute a gradient at a point x, along a particular dimension
	  @param x: location to check gradient
	  @param d: dimension (1,2 or 3)
	  @param g: resulting gradient for dimension
	  @return true if valid gradient, false otherwise
	*/
	virtual bool getGradient(const Eigen::Vector3d &x, size_t d, Eigen::Vector3d &g) = 0;

	/// Returns the signed distance at the given location x 
	virtual double SDF(const Eigen::Vector3d &x) = 0;

	/// Fuses the depth map @param depth from a camera with parameters @cam_param taken from camera pose @param T  
	virtual void updateWithDepth(const Eigen::MatrixXd &depth, const SDF_CamParameters &cam_param, const Eigen::Affine3d &T) = 0;
	
	/// Fuses the point cloud @param pc from a sensor pose @param T  
	virtual void updateWithPC(const Eigen::MatrixXd &depth, const Eigen::Affine3d &T) = 0;
	
	/// Render a virtual depth map in @param depth, using camera parameters @param cam_param. Eigen matrix should be properly allocated outside otherwise @return is set to false!
	virtual bool renderDepthMap(Eigen::MatrixXd &depth, const SDF_CamParameters &cam_param) = 0;

	

//--------- IO ------------//

	/// Saves the current map.
	virtual void saveMap(const std::string &filename = std::string("sdf_volume.vti")) = 0;

	/// Loads a maps from disk. 
	virtual void loadMap(const std::string &filename) = 0;

	/// Resets the map 
	virtual void resetMap() = 0;

	/// dumps the map into a string for transfer over a network
	virtual void serialize(std::string &buffer) = 0;

	/// loads up a map from a string
	virtual void deSerialize(const std::string &buffer) = 0;
  

	///saves a triangle mesh to file @param filename
	void saveTriangles(const std::string filename = std::string("triangles.obj"));
};

/** stores common parameters for initializing an SDFMap derived class
  */
class SDFMapParameters {


};

#endif
