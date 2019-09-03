/********************************************

Name:			HARVESTSites.h 

Description:	HARVESTSites

Input:			

Output:			

Date:			Oct. 27, 2003

Last Mod:		

*******************************************/



#ifndef HARVESTSITES_H

#define HARVESTSITES_H



#include <stdio.h>

//<Add By Qia on Nov 07 2008>

#include <vector>

#include <list>

//</Add By Qia on Nov 07 2008>







class HARVESTSite

{

public:

	int itsMaxAge;

    unsigned char updateFlag;



	short	harvestType;

    short	lastHarvest;

    short	harvestExpirationDecade;

	//<Add By Qia on Nov 07  2008>

	int numofsites;

	//</Add By Qia on Nov 07 2008>



	void	setUpdateFlag	();

 	void	update			(int, int);   

	int		getHarvestType	();

    int		getHarvestDecade();

    int		getMaxAge		(int, int);

    int		canBeHarvested	(int, int);

    int		wasRecentlyHarvested();

	HARVESTSite& operator=(const HARVESTSite&);

};



//<Add By Qia on Nov 07 2008>

typedef std::vector<HARVESTSite *>  SortedHarvestSITE;

//</Add By Qia on Nov 07 2008>



class HARVESTSites

{

public:

	

	int				m_iRows;

	int				m_iCols;

	int				inter_number;				//added by houbin chen 4/27/2017

	int*			interval;					//added by houbin chen 4/27/2017
	
	int				biggest_agerange_count;		//add by houbin 11/1/2017

	double GetValueHarvestBA(int i,int j);

	int		SetValueHarvestBA(int i,int j,double value);

	int		AddMoreValueHarvestBA(int i,int j,double value);

	int		clearValueHarvestBA();

	int		clearValueHarvestNUM_BA_BIO();

	int		clearValueHarvestBA_spec();			//add by houbin 10/27/2017
	int		clearValueHarvestBIO_spec();		//add by houbin 10/27/2017
	int		clearValueHarvestNum_spec();		//add by houbin 10/27/2017

	double GetValueHarvestBA_spec(int i,int j,int spec);
	int		SetValueHarvestBA_spec(int i,int j,int spec,double value);
	int		AddMoreValueHarvestBA_spec(int i,int j,int spec,double value);

	int		GetValueHarvestNum_spec(int i, int j, int spec);					//add by houbin 10/27/2017
	int		AddMoreValueHarvestNum_spec(int i, int j, int spec, int value);		//add by houbin 10/27/2017

	double	GetValueHarvestBio_spec(int i, int j, int spec);					//add  by houbin 10/27/2017
	int		AddMoreValueHarvestBio_spec(int i, int j, int spec, double value);	//add  by houbin 10/27/2017

	double GetValueHarvestBA_interval(int i, int j, int interval_index);			//add by houbin chen 4/27/2017
	int		AddMoreValueHarvestBA_interval(int i, int j, int interval_index, double value);

	double		GetValueHarvestBIO_spec_interval(int i, int j, int spec_index, int interval_index);			//add by houbin chen 5/10/2017
	int		AddMorevalueHarvestBIO_spec_interval(int i, int j, int spec_index, int interval_index, double value);

	double		GetValueHarvestBA_spec_interval(int i, int j, int spec_index, int interval_index);			//add  by houbin 10/27/2017
	int		AddMorevalueHarvestBA_spec_interval(int i, int j, int spec_index, int interval_index, double value);//add  by houbin 10/27/2017

	int			GetValueHarvestNum_spec_interval(int i, int j, int spec_index, int interval_index);			//add  by houbin 10/27/2017
	int		AddMorevalueHarvestNum_spec_interval(int i, int j, int spec_index, int interval_index, int value);//add  by houbin 10/27/2017

	//HARVESTSite*	m_pHarvestMap; //original 4.0, commented By Qia on Nov 07 2008

    //<Add By Qia on Nov 07 2008>

	SortedHarvestSITE SortedIndex;

	//</Add By Qia on Nov 07 2008>

	HARVESTSites();			//default constructor

	HARVESTSites(int, int, int);	//constructor, sets m_pBDAMap to be given rows and columns

	~HARVESTSites();		//destructor



	HARVESTSite* operator()	(int, int);  //return a pointer to a singular BDASITE

	

	//<Add by Qia on Nov 07 2008>

	int SITE_compare(HARVESTSite *site1, HARVESTSite *site2);

	int SITE_compare(int site1_x, int site1_y, int site2_x, int site2_y);

	                                   // Compare two sites to see the relation between them

	                                   // return 0:equal; return 1: site1 is bigger; return 2: site2 is bigger; -1: error

	                               

	int SITE_sort();				  // sort the pointers to sites



	int SITE_insert(int pos_sortIndex, HARVESTSite *site, int i, int j);					// insert a site in to list



	int SITE_delete(int pos_sortIndex, HARVESTSite *site, int i, int j);				// remove a site from list



	

	int SITE_LocateinSortIndex(HARVESTSite *site, int *pos, int *ifexist);

	

	void fillinSitePt(int i, int j, HARVESTSite *site);

	HARVESTSite * locateSitePt(int i, int j);

	

	void BefStChg(int i, int j);

	void AftStChg(int i,int j);

	//</Add By Qia on Nov 07 2008>

	

	void	read		(FILE*);

	void	write		(FILE*);

	void	dump		();

	int		number		();			//return total number of BDASites

	int		numRows		();

	int		numColums	();

private:

	//<Add by Qia Nov 07 2008>

	HARVESTSite **map;

	//</Add by Qia on Nov 07 2008>

	HARVESTSite *sitetouse;//Add By Qia on Dec 19 2008

	// HARVESTSite *site;

	double *BA_harvest_output;

	double **BA_harvest_output_spec; //Add By Qia on Aug 13 2011

	double **BIO_harvest_output_spec;	//add by houbin 10/27/2017 
	int    **Num_harvest_output_spec;	//add by houbin 10/27/2017

	double **BA_harvest_output_interval;  //add by houbin chen 4/27/2017

	double ***BIO_harvest_output_spec_interval;   //add by houbin chen 5/3/2017
	double ***BA_harvest_output_spec_interval;	//add by houbin 10/27/2017
	int    ***Num_harvest_output_spec_interval;	//add by houbin 10/27/2017

};





#endif

