/*
 * FairRootManager.cxx
 *
 *  Created on: 15 lip 2019
 *      Author: Daniel Wielanek
 *		E-mail: daniel.wielanek@gmail.com
 *		Warsaw University of Technology, Faculty of Physics
 */
#include "FairRootManager.h"

FairRootManager *FairRootManager::fgInstance = NULL;
FairRootManager::FairRootManager() :fFile(NULL),fTree(NULL),fList(NULL),
fEntries(0){

}

FairRootManager::~FairRootManager() {
	if(fFile){
		fFile->Close();
		delete fFile;
	}
}
FairRootManager* FairRootManager::Instance(){
	if(fgInstance==NULL)
		fgInstance = new FairRootManager();
	return fgInstance;
}
void FairRootManager::LoadFile(const char *name) {
	fFile = new TFile(name);
	TList *list = fFile->GetListOfKeys();
	for(int i=0;i<list->GetEntries();i++){
		TKey *key = (TKey*)list->At(i);
		TObject *obj = fFile->Get(key->GetName());
		if(obj->InheritsFrom("TTree")){
			fTree = (TTree*)obj;
			break;
		}
	}
	TObjArray *branches = fTree->GetListOfBranches();
	fEntries = fTree->GetEntries();
}

Int_t FairRootManager::ReadEvent(Int_t i) {
	if(i<fEntries){
		fTree->GetEntry(i);
		return 1;
	}
	return 0;
}

Int_t FairRootManager::CheckBranch(const char *BrName) {
	TBranch *br = fTree->GetBranch(BrName);
	if(br==NULL) return 0;
	return 1;
}

void FairRootManager::Register(const char *name, const char *Foldername,
		TNamed *obj, Bool_t toFile) {

}

void FairRootManager::Register(const char *name, const char *Foldername,
		TCollection *obj, Bool_t toFile) {
}

TObject* FairRootManager::GetObject(const char *name) {
	TBranch *br = fTree->GetBranch(name);
	return fTree->FindObject(name);
}
