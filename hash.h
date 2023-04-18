#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include <random>
#include <chrono>

typedef std::size_t HASH_INDEX_T;

struct MyStringHash {
    HASH_INDEX_T rValues[5] { 983132572, 1468777056, 552714139, 984953261, 261934300 };
    MyStringHash(bool debug = true)
    {
        if(false == debug){
            generateRValues();
        }
    }
    // hash function entry point (i.e. this is h(k))
    HASH_INDEX_T operator()(const std::string& k) const
    {
        // Add your code here
				k = tolower(k);
				unsigned long long antidisestablishmentarianism[5];
				for(int i = 0; i< antidisestablishmentarianism.size();i++){
					antidisestablishmentarianism[i] = 0;
				}
				

    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
				if (letter >= 0 or letter <=9){
					HASH_INDEX_T inde = 0;
					for(char i = '0'; i <= '9'; i++){
						inde++
						if(i == letter){
							return inde+25;
						}
					}
				}
				else{
					HASH_INDEX_T inde = 0;
					for(char i = 'a'; i <= 'z';i++){
						inde++;
						if(i == letter){
							return inde;
						}
					}
				} 
    }

    // Code to generate the random R values
    void generateRValues()
    {
        // obtain a seed from the system clock:
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generator (seed);  // mt19937 is a standard random number generator

        // Simply call generator() [it has an operator()] to get another random number
        for(int i{ 0 }; i < 5; ++i)
        {
            rValues[i] = generator();
        }
    }
};

#endif
