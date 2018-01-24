#pragma once

#include "AbstractBigIjkGridRepresentationTest.h"
#include <iostream>

namespace common {
	class EpcDocument;
}

namespace resqml2_0_1test {
	class BigIjkGridExplicitRepresentationTest : public AbstractBigIjkGridRepresentationTest {
	public:
		static const char* defaultUuid;
		static const char* defaultTitle;
		static const char* discretePropertyUuid;
		static const char* discretePropertyTitle;
		static const char* continuousPropertyUuid;
		static const char* continuousPropertyTitle;
	
		/**
		* Creation of an explicit IJK grid representation from an EPC document path. Resulting grid is 
		* aligned along axis (I direction along X, J direction along Y and K direction along Z). 
		* Resulting grid carries both discrete and continuous properties on cells.
		* At serialize() call, exising .epc file will be erased. 
		* @param epcDocPath	the path of the .epc file (including .epc extension)
		* @param iCount		number of cells in the I direction.
		* @param jCount		number of cells in the J direction.
		* @param kCount		number of cells in the K direction.
		* @param faultCount	number of faults. Faults are parallel to YZ plane (they fit with i-interfaces). faultCount in [0; iCount[.
		* @param xMin		minimum x value of the grid.
		* @param xMax		maximum x value of the grid.
		* @param yMin		minimum y value of the grid.
		* @param yMax		maximum y value of the grid.
		* @param zMin		minimum z value of the grid (without considering any fault throw).
		* @param zMax		maximum z value of the grid (without considering any fault throw).
		* @param faultThrow	length of the fault throw along z axis. 
		*/
		BigIjkGridExplicitRepresentationTest(
			const std::string & epcDocPath,
			const unsigned int & iCount, const unsigned int & jCount, const unsigned int & kCount, 
			const unsigned int & faultCount, 
			const double & xMin, const double & xMax, const double & yMin, const double & yMax, const double & zMin, const double & zMax,
			const double & faultThrow);

		/**
		* Creation of an explicit IJK grid representation from an existing EPC document. Resulting grid is 
		* aligned along axis (I direction along X, J direction along Y and K direction along Z).
		* Resulting grid carries both discrete and continuous properties on cells. 
		* @param epcDoc		an existing EPC document
		* @param init		true if this object is created for initialization purpose else false if it is 
		*					created for reading purpose. According to init value a iniEpcDoc() or readEpcDoc() is called.
		* @param iCount		number of cells in the I direction.
		* @param jCount		number of cells in the J direction.
		* @param kCount		number of cells in the K direction.
		* @param faultCount	number of faults. Faults are parallel to YZ plane (they fit with i-interfaces). faultCount in [0; iCount[.
		* @param xMin		minimum x value of the grid.
		* @param xMax		maximum x value of the grid.
		* @param yMin		minimum y value of the grid.
		* @param yMax		maximum y value of the grid.
		* @param zMin		minimum z value of the grid (without considering any fault throw).
		* @param zMax		maximum z value of the grid (without considering any fault throw).
		* @param faultThrow	length of the fault throw along z axis.
		*/
		BigIjkGridExplicitRepresentationTest(common::EpcDocument * epcDoc, bool init,
			const unsigned int & iCount, const unsigned int & jCount, const unsigned int & kCount,
			const unsigned int & faultCount,
			const double & xMin, const double & xMax, const double & yMin, const double & yMax, const double & zMin, const double & zMax,
			const double & faultThrow);

	protected:
		void initEpcDocHandler();
		void readEpcDocHandler();
	};
}