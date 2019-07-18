/*
 * FairRootManager.h
 *
 *  Created on: 15 lip 2019
 *      Author: Daniel Wielanek
 *		E-mail: daniel.wielanek@gmail.com
 *		Warsaw University of Technology, Faculty of Physics
 */
#ifndef BASE_FAIRROOTMANAGER_H_
#define BASE_FAIRROOTMANAGER_H_

#include <RtypesCore.h>
#include <TObject.h>
#include <TFile.h>
#include <TTree.h>
#include <TChain.h>

class FairRootManager : public TObject{
	TFile *fFile;
	TTree *fTree;
	TList *fList;
	Int_t fEntries;
	static FairRootManager *fgInstance;
public:
	FairRootManager();
	static FairRootManager *Instance();
	void LoadFile(const char *name);
	Int_t ReadEvent(Int_t i=0);
	Int_t CheckBranch(const char* BrName);
	   /**create a new branch in the output tree
	     *@param name            Name of the branch to create
	     *@param Foldername      Folder name containing this branch (e.g Detector name)
	     *@param obj             Pointer of type TNamed (e.g. MCStack object)
	     *@param toFile          if kTRUE, branch will be saved to the tree*/
	void Register(const char* name, const char* Foldername, TNamed* obj, Bool_t toFile);
	    /**create a new branch in the output tree
	    *@param name            Name of the branch to create
	    *@param Foldername      Folder name containing this branch (e.g Detector name)
	    *@param obj             Pointer of type TCollection (e.g. TClonesArray of hits, points)
	    *@param toFile          if kTRUE, branch will be saved to the tree*/
	void Register(const char* name,const char* Foldername ,TCollection* obj, Bool_t toFile);
	/**
	 *
	 * @param name
	 * @return obj from tree
	 */
	TObject *GetObject(const char *name);
	void SetInChain (TChain* tempChain, Int_t ident=-1){};
	TFile *GetInFile()const{return fFile;};
	Int_t GetEntries()const{return fEntries;};
	virtual ~FairRootManager();
	ClassDef(FairRootManager,1)
};

#endif /* BASE_FAIRROOTMANAGER_H_ */
