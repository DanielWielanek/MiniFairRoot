/*
 * FairFileSource.h
 *
 *  Created on: 16 lip 2019
 *      Author: Daniel Wielanek
 *		E-mail: daniel.wielanek@gmail.com
 *		Warsaw University of Technology, Faculty of Physics
 */
#ifndef BASE_FAIRFILESOURCE_H_
#define BASE_FAIRFILESOURCE_H_
#include "TObject.h"
#include "FairSource.h"
class FairFileSource : public FairSource{
public:
	FairFileSource();
	virtual ~FairFileSource();
	ClassDef(FairFileSource,1)
};

#endif /* BASE_FAIRFILESOURCE_H_ */
