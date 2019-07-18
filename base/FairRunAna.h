/*
 * FairRunAna.h
 *
 *  Created on: 15 lip 2019
 *      Author: Daniel Wielanek
 *		E-mail: daniel.wielanek@gmail.com
 *		Warsaw University of Technology, Faculty of Physics
 */
#ifndef BASE_FAIRRUNANA_H_
#define BASE_FAIRRUNANA_H_

#include "FairTask.h"
#include "FairRun.h"
#include "FairField.h"

class FairRunAna : public FairRun{
	TObjArray *fArray;
	TString fFileIn;
	TString fFileOut;
	void Finish();
	static FairRunAna *fgInstance;
public:
	FairRunAna();
	static FairRunAna *Instance();
	void SetInFile(TString inputfile){fFileIn = inputfile;};
	void SetOutputFile(TString outfile){fFileOut = outfile;};
	void AddTask(FairTask *task);
	void Init();
	void Run();
	FairField *GetField(){return NULL;};
	virtual ~FairRunAna();
	ClassDef(FairRunAna,1)
};

#endif /* BASE_FAIRRUNANA_H_ */
