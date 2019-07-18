#ifndef FAIRSOURCE_H
#define FAIRSOURCE_H

#include "TObject.h"

#include <iostream>

class FairEventHeader;

enum Source_Type {kONLINE, kFILE};

class FairSource : public TObject
{
  public:
    FairSource();
    FairSource(const FairSource& source);
    virtual ~FairSource();

    virtual Bool_t Init() = 0;
    virtual Int_t ReadEvent(UInt_t=0) = 0;
    virtual void Close() = 0;

    virtual void Reset() = 0;

    virtual Bool_t   ActivateObject(TObject**, const char*)  { return kFALSE; }
    virtual Bool_t   ActivateObjectAny(void **, const std::type_info &, const char*) { return kFALSE; }

    virtual Source_Type GetSourceType() = 0;

    virtual void SetParUnpackers() = 0;

    virtual Bool_t InitUnpackers() = 0;

    virtual Bool_t ReInitUnpackers() = 0;

    /**Check the maximum event number we can run to*/
    virtual Int_t  CheckMaxEventNo(Int_t=0) {return -1;}
    /**Read the tree entry on one branch**/
    virtual void   ReadBranchEvent(const char*) {return;}
    virtual void   ReadBranchEvent(const char*, Int_t) {return;}
    virtual void FillEventHeader(FairEventHeader* feh);

    void SetRunId(Int_t runId) { fRunId = runId; }
    Int_t GetRunId() const     { return fRunId;  }

  protected:
    Int_t fRunId;

  public:
    ClassDef(FairSource, 2)
};


#endif
