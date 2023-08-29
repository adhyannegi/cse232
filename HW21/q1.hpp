#pragma once

void CopyStockPrices(double * source, double * destination){
    while (*source >= 0){
        *destination = *source;
        destination++;
        source++;
    }
    *destination = *source;
}