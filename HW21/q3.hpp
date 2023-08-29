#pragma once
#include <iostream>
template<typename T, std::size_t N, std::size_t M>

void CopyStockPrices(const T (&source)[N], T (&desination)[M]){
    for (std::size_t i = 0; i < N; i++){
        desination[i] = source[i];
    }
}
int main(){
    int const source_size = 7;
	double source[source_size] = {3, 1, 2, 3, 67, -4, 13};
	int const destination_size = 10;
	double destination[destination_size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double expected[destination_size] =  {3, 1, 2, 3, 67, -4, 13, 8, 9, 10};
	CopyStockPrices(source, destination);
    bool b;
    for (int i = 0; i < destination_size; ++ i) {
        b = (expected[i] == destination[i]);
    }


}