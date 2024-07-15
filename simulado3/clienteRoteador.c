#include <stdio.h>
#include "tabelaRot.h"

int main() {

    nextHop * nh1 = createNextHop("01.1.1.2", "10.11.0.0/16");
    nextHop * nh2 = createNextHop("99.1.1.9", "01.14.0.0/72");
    nextHop * nh3 = createNextHop("45.1.3.2", "56.44.9.9/16");
    nextHop * nh4 = createNextHop("19.1.7.2", "23.05.0.0/60");

    hashTab * ht = createHash(100);
    insert(ht, nh1);
    insert(ht, nh2);
    insert(ht, nh3);

    char dest1[25] = "10.11.0.0/16";
    char dest2[25] = "23.05.0.0/60";

    search(ht, dest1);
    search(ht, dest2);

    freeHash(ht);
    freeNextHop(nh1);
    freeNextHop(nh2);
    freeNextHop(nh3);
    freeNextHop(nh4);

return 0;
}