#ifndef STAND_H

#define STAND_H



#include "point.h"

#include "List.h"

#include "IntArray.h"



class StandIterator;

class STANDS;



class Stand {

friend class StandIterator;

friend class STANDS;

public :

    Stand();

    virtual ~Stand() {}



    void setUpdateFlag();



    int getId();

    int getManagementAreaId();

    LDPOINT getMinPoint();

    LDPOINT getMaxPoint();



    void setRank(int rank);

    int getRank();



    void reserve();

    void unreserve();

    int isReserved();



    int getAge();

    

    int canBeHarvested();

    int wasRecentlyHarvested();

    int neighborsWereRecentlyHarvested();

    

    int inStand(int r, int c);

    int numberOfSites();

    int numberOfActiveSites();



    LDPOINT getRandomPoint();

    //<Add By Qia on August 03 2009>

	long ComputeStandVolume();

	long ComputeStandVolume(int low,int high);

	//</Add By Qia on August 03 2009>

private :

    void update();

    int isNeighbor(int r, int c);

    void addNeighbor(int id);



    int itsId;

    int itsManagementAreaId; 

    LDPOINT itsMinPoint;

    LDPOINT itsMaxPoint;

    int itsTotalSites;

    int itsActiveSites;

    int itsHarvestableSites;

    int itsMeanAge;

    unsigned char itsUpdateFlag;

    List<int> itsNeighborList;

    int itsRecentHarvestFlag;

    int itsRank;

    int itsReserveFlag;

	//<Add By Qia on August 03 2009>

	long HarvestStandVolume;

	//</Add By Qia on August 03 2009>

};



#endif

