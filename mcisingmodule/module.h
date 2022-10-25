#pragma once

#include "lattice.h"
#include <stdio.h>

void run_mc_sweeps(IsingLattice&, const IsingLattice::value_type&, const IsingLattice::value_type&, const unsigned int&);