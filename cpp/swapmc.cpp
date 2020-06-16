#include "../hpp/swapmc.hpp"

namespace PhysPeach {
    void createSwapMC(SwapMC* s){
        createParticles(&s->p);
        createCells(&s->c);
        return;
    }

    void deleteSwapMC(SwapMC* s){
        deleteParticles(&s->p);
        deleteCells(&s->c);
        return;
    }
}