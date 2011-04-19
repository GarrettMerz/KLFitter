/*
 * \class KLFitter::SelectionTool
 * \brief A class for object selection
 * \author Kevin Kroeninger
 * \version 1.3
 * \date 03.12.2009
 *
 * This class reads in a set of particles and returns a subset
 * together with a map.
 * 
 */


// --------------------------------------------------------- 

#ifndef SELECTIONTOOL
#define SELECTIONTOOL

// --------------------------------------------------------- 

#include "KLFitter/Particles.h"

#include <vector>

// --------------------------------------------------------- 
 
/*!
 * \namespace KLFitter
 * \brief The KLFitter namespace
 */
namespace KLFitter
{
  
  class SelectionTool  
  {

  public: 

    /**
     * Defines a cut.\n
     * value: 
     */ 
    typedef struct { 
      double value; /**< the value to be cut on, e.g., jet pT. */
      int n; /**< the number of objects required to survive the cut.*/
      int dn; /**< tolerance.*/
    } Cut; 

    /** \name Constructors and destructors */ 
    /* @{ */ 
        
    /** 
     * The default constructor. 
     */ 
    SelectionTool(); 

    /**
     * The default destructor.
     */
    virtual ~SelectionTool();

    /* @} */
    /** \name Member functions (Get)  */
    /* @{ */

    /**
     * Return the selected particles 
     * @return The set of selected particles 
     */ 
    Particles * ParticlesSelected() 
      { return fParticlesSelected; }; 

    /**
     * Return the selected particles 
     * @return The set of selected particles 
     */ 
    Particles ** PParticlesSelected() 
      { return &fParticlesSelected; }; 

    /**
     * Return the map for jets. */ 
    std::vector <int> MapJets() { return fMapJets; }; 

    /**
     * Return the map for electrons. */ 
    std::vector <int> MapElectrons() { return fMapElectrons; }; 

    /**
     * Return the map for muons. */ 
    std::vector <int> MapMuons() { return fMapMuons; }; 

    /**
     * Return the map for photons. */ 
    std::vector <int> MapPhotons() { return fMapPhotons; }; 

    /** 
     * Return the counter variables for events. */ 
    int CounterEvents() { return fCounterEvents; }; 

    /** 
     * Return the counter variables for jets. */ 
    int CounterJets() { return fCounterJets; }; 

    /** 
     * Return the counter variables for electrons. */ 
    int CounterElectrons() { return fCounterElectrons; }; 

    /** 
     * Return the counter variables for muons. */ 
    int CounterMuons() { return fCounterMuons; }; 

    /** 
     * Return the counter variables for photons. */ 
    int CounterPhotons() { return fCounterPhotons; }; 

    /** 
     * Return the counter variables for missing ET. */ 
    int CounterMET() { return fCounterMET; }; 

    /* @} */
    /** \name Member functions (Set)  */
    /* @{ */

    /**
     * Add a cut on the number of jets.
     * @param pt The pt. 
     * @param n The number. 
     * @param dn Tolerance. 
     * @return An error flag. 
     */ 
    int RequireNJetsPt(double pt, int n, int dn = -1); 

    /**
     * Add a cut on the number of electrons.
     * @param pt The pt. 
     * @param n The number. 
     * @return An error flag. */
    int RequireNElectronsPt(double pt, int n);

    /**
     * Add a cut on the number of muons.
     * @param pt The pt. 
     * @param n The number. 
     * @return An error flag. */ 
    int RequireNMuonsPt(double pt, int n); 


    /**
     * Add a cut on the number of photons.
     * @param pt The pt. 
     * @param n The number. 
     * @return An error flag. */ 
    int RequireNPhotonsPt(double pt, int n); 

    /**
     * Add a cut on the missing ET. 
     * @param met The missing ET.
     * @return An error flag. */ 
    int RequireMET(double met); 

    /**
     * Set jet eta cut. 
     * @param eta The eta region (|eta|<x).  . 
     */ 
    void SelectJetEta(double eta) { fJetEta = eta; }; 

    /**
     * Set electron eta cut. 
     * @param eta The eta region (|eta|<x).  . 
     */ 
    void SelectElectronEta(double eta) { fElectronEta = eta; }; 

    /**
     * Set muon eta cut. 
     * @param eta The eta region (|eta|<x).  . 
     */ 
    void SelectMuonEta(double eta) { fMuonEta = eta; }; 

    /**
     * Set photon eta cut. 
     * @param eta The eta region (|eta|<x).  . 
     */ 
    void SelectPhotonEta(double eta) { fPhotonEta = eta; }; 

    /* @} */
    /** \name Member functions (misc)  */
    /* @{ */

    /**
     * Read in a set of particles and return only selected objects.
     * @param particles A set of particles. 
     */ 
    int SelectObjects(KLFitter::Particles * particles); 

    /**
     * Select the events.
     * @param particles The set of particles. 
     * @param MET The missing ET.
     * @return event either passed the selection (1) or not (0) 
     */ 
    int SelectEvent(KLFitter::Particles * particles, double MET = 0.); 

    /**
     * Number of jets to consider in the fit.
     * @param n The number of jetes.
     */
    void SetMaxNJetsForFit(int n) { fMaxNJetsForFit = n; };

    void ResetMaps(); 

    void ResetCounter(); 

    /* @} */

  protected:

    /**
     * A pointer to the selected particles.
     */ 
    KLFitter::Particles * fParticlesSelected; 

    /**
     * The jet selection criteria: pT.
     */ 
    double fJetPt; 

    /**
     * The jet selection criteria: eta.
     */ 
    double fJetEta; 

    /**
     * The electron selection criteria: pT.
     */ 
    double fElectronPt; 

    /**
     * The electron selection criteria: eta.
     */ 
    double fElectronEta; 

    /**
     * The muon selection criteria: pT.
     */ 
    double fMuonPt; 

    /**
     * The muon selection criteria: eta.
     */ 
    double fMuonEta; 

    /**
     * The photon selection criteria: pT.
     */ 
    double fPhotonPt; 

    /**
     * The photon selection criteria: eta.
     */ 
    double fPhotonEta; 

    /**
     * Event selection criteria for jets.
     */ 
    std::vector <Cut> fNJetsPt; 

    /**
     * Event selection criteria for electrons.
     */ 
    std::vector <Cut> fNElectronsPt; 

    /**
     * Event selection criteria for muons.
     */ 
    std::vector <Cut> fNMuonsPt; 

    /**
     * Event selection criteria for photons.
     */ 
    std::vector <Cut> fNPhotonsPt; 

    /**
     * Event selection criteria for missing ET.
     */ 

    double fMET; 

    /**
     * Counter variables: events
     */ 
    int fCounterEvents; 

    /**
     * Counter variables: jets
     */ 
    int fCounterJets; 

    /**
     * Counter variables: electrons
     */ 
    int fCounterElectrons; 

    /**
     * Counter variables: muons
     */ 
    int fCounterMuons; 

    /**
     * Counter variables: photons
     */ 
    int fCounterPhotons; 

    /**
     * Counter variables: missing ET
     */ 
    int fCounterMET; 

    /**
     * Maps : jets 
     */ 
    std::vector <int> fMapJets; 

    /**
     * Maps : electrons
     */ 
    std::vector <int> fMapElectrons; 

    /**
     * Maps : muons 
     */ 
    std::vector <int> fMapMuons; 

    /**
     * Maps : photons 
     */ 
    std::vector <int> fMapPhotons; 

    /*
     * The number of jets to consider in the fit.
     */
    unsigned int fMaxNJetsForFit;

  private:
                
    /**
     * Helper for finding the object pt selection cut from the event selection cuts on the object
     * @param cuts The object cuts.
     * @return The minimum object pt.
     */
    double ObjectPtCut(std::vector<Cut> const& cuts);

    /**
     * Helper for removing additional particles not requested 
     * @param n Number of jets requested by the cut.
     * @param type Type of the particles to be removed.
     */
    void RemoveAdditionalParticles(int n, KLFitter::Particles::ParticleType type);

  };

}// namespace KLFitter 

#endif 
