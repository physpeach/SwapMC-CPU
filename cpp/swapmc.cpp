#include "../hpp/swapmc.hpp"

namespace PhysPeach {
    void createSwapMC(SwapMC* s){
        createParticles(&s->p);
        s->L = pow(s->p.V/Phi_init, 1./(double)D);
        scatterParticles(&s->p, s->L, createCells(&s->c, s->L));
        return;
    }

    void deleteSwapMC(SwapMC* s){
        deleteParticles(&s->p);
        deleteCells(&s->c);
        return;
    }
}