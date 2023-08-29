#include <iostream>
int main() {
	int num{0};
	while (std::cin >> num) {
        int root{100};
        if (num < 0){
            break;
        }
        else if ((num) < 100){
            root = num;
        }
        else {
            while (root > 99){
                root = 0;
                while (num != 0){
                    root += num % 100;
                    num /= 100;
                }
                num = root;
            }
        }
		std::cout << root << std::endl;
	}
}