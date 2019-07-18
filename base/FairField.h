#ifndef FAIRFIELD_H
#define FAIRFIELD_H 1
#include <iosfwd>                       // for ostream
#include "Rtypes.h"                     // for Double_t, Bool_t, etc
#include "TVirtualMagField.h"

#include <stdio.h>                      // for printf
#include <iostream>

class FairField : public TVirtualMagField
{

  public:

    /** Default constructor **/
    FairField();


    /** Constructor with name and title **/
    FairField(const char* name, const char* title = "FAIR Magnetic Field");

    FairField& operator=(const FairField&) {return *this;}

    /** Destructor **/
    virtual ~FairField();


    /** Intialisation. E.g. read in the field map. If needed, to be
     ** implemented in the concrete class.
     **/
    virtual void Init() { };

    /** Test whether field type is Constant **/
    Bool_t IsConst();


    /** Test whether field typ is Map **/
    Bool_t IsMap();


    /** Field type ( 0=constant, 1=map, 2=map sym2, 3 = map sym3 ) **/
    Int_t GetType() const { return fType; }


    /** Get x component of magnetic field [kG]
     ** @param x,y,z    Position [cm]
     **/
    virtual Double_t GetBx(Double_t, Double_t, Double_t) {return 0;}


    /** Get y component of magnetic field [kG]
     ** @param x,y,z    Position [cm]
     **/
    virtual Double_t GetBy(Double_t, Double_t, Double_t) {return 0;}

    /** Get z component of magnetic field [kG]
     ** @param x,y,z    Position [cm]
     **/
    virtual Double_t GetBz(Double_t, Double_t, Double_t) { return 0;}


    /** Get magnetic field. For use of Geant3
     ** @param point            Coordinates [cm]
     ** @param bField (return)  Field components [kG]
     **/
    virtual void GetFieldValue(const Double_t point[3], Double_t* bField);


    void Field(const Double_t point[3], Double_t* B) {GetFieldValue(point,B);}


    /** Screen output. To be implemented in the concrete class. **/
    virtual void  Print(Option_t*) const {;}
    virtual void GetBxyz(const Double_t[3], Double_t*) {}



    /**Fill Paramater*/

    virtual void FillParContainer() {}
  protected:

    /** Field type. 1 = constant field, 2 = field map. **/
    Int_t fType;

  private:
    FairField(const FairField&);
    //    FairField& operator=(const FairField&);
    //TODO: Check why the htrack needs this
    ClassDef(FairField,4);

};




#endif
