/*
 * FairRunAna.cxx
 *
 *  Created on: 15 lip 2019
 *      Author: Daniel Wielanek
 *		E-mail: daniel.wielanek@gmail.com
 *		Warsaw University of Technology, Faculty of Physics
 */
#include "FairRunAna.h"
#include "FairRootManager.h"
#include <iostream>

FairRunAna* FairRunAna::fgInstance = NULL;

FairRunAna::FairRunAna() :fArray(NULL){
	fArray  = new TObjArray();
}

FairRunAna::~FairRunAna() {
	delete fArray;
}


FairRunAna *FairRunAna::Instance(){
	if(fgInstance==NULL)
		fgInstance = new FairRunAna();
	return fgInstance;
}
void FairRunAna::AddTask(FairTask *task) {
	fArray->AddLast(task);
}

void FairRunAna::Run() {
	FairRootManager *mngr = FairRootManager::Instance();
	for(int i=0;i<mngr->GetEntries();i++){
		mngr->ReadEvent(i);
		for(int a=0;a<fArray->GetEntriesFast();a++){
			FairTask *task = (FairTask*)fArray->At(i);
			task->Exec("");
		}
	}
}

void FairRunAna::Init(){
	FairRootManager *mngr= FairRootManager::Instance();
	mngr->LoadFile(fFileIn);
	for(int i=0;i<fArray->GetEntries();i++){
		FairTask *task = (FairTask*)fArray->At(i);
		InitStatus stat =task->Init();
		if(stat==kFATAL){
			std::cout<<"FATAL ERROR"<<std::endl;
			exit(0);
		}
	}
}

void FairRunAna::Finish() {
	TFile *f = new TFile(fFileOut,"recreate");
	for(int i=0;i<fArray->GetEntries();i++){
		FairTask *task = (FairTask*)fArray->At(i);
		task->FinishTask();
	}
	f->Close();
}
