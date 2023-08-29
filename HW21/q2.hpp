#pragma once

void CopyStockPrices(double * source, double * destination){
    double size = *source;
    *destination = *source;
    source++;
    destination++;
    for (double i = 0; i < size; i++){
        *destination = *source;
        destination++;
        source++;
    }
}