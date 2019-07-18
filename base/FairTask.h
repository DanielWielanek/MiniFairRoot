/*
 * FairTask.h
 *
 *  Created on: 15 lip 2019
 *      Author: Daniel Wielanek
 *		E-mail: daniel.wielanek@gmail.com
 *		Warsaw University of Technology, Faculty of Physics
 */
#ifndef BASE_FAIRTASK_H_
#define BASE_FAIRTASK_H_
#include "TTask.h"
#include "FairLogger.h"

enum InitStatus {kSUCCESS, kERROR, kFATAL};

class FairTask : public TTask{
public:
	FairTask();
	FairTask(const char *name):FairTask(){};
	InitStatus Init(){return kSUCCESS;};
	virtual void FinishTask(){};
	virtual ~FairTask();
	ClassDef(FairTask,1)
};

#endif /* BASE_FAIRTASK_H_ */
