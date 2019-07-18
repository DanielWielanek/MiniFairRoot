/*
 * FairRun.h
 *
 *  Created on: 16 lip 2019
 *      Author: Daniel Wielanek
 *		E-mail: daniel.wielanek@gmail.com
 *		Warsaw University of Technology, Faculty of Physics
 */
#ifndef BASE_FAIRRUN_H_
#define BASE_FAIRRUN_H_

#include <TObject.h>

class FairRun :public TObject{
public:
	FairRun();
	virtual ~FairRun();
	ClassDef(FairRun,1)
};

#endif /* BASE_FAIRRUN_H_ */
