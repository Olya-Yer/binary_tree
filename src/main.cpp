#include <tree.hpp>
#include <iostream>
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono> 

int main()
{
	std::array<int,20> a {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle (a.begin(), a.end(), std::default_random_engine(seed));
	Tree* t = new Tree();
	std::cout << "Adding elements to the tree" << std::endl;
	for(int i = 0; i < 20; ++i ) {
	    std::cout <<"inserting valye "<<a[i] << std::endl;
	    t->insert(a[i]);
	    t->print();
	    std::cout <<"<=======================================>" << std::endl;
	}
	return 0;
}

