#ifndef SDF_REGISTRATION_H
#define SDF_REGISTRATION_H

#include<sdf_tracker/sdf_map.h>
#include<sdf_tracker/sdf_grid.h>

/** base class for registering data into an SDFMap.
  * specialized classes are derived for different SDFMap derivations
  */
class SDFRegistration {

    private:
	SDFMap *map;
    
    public:
	inline SDFMap* getMap() {
	    return map;
	}

	virtual void initialize(SDFMapParameters &map_params) = 0;

};

class SDFGridRegistration {

};

#endif
