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

			unsigned long long antidisestablishment[5];
			unsigned int index = 4;
			unsigned int six_counter = 0;
			unsigned long long curr = 0;
			unsigned long long power = 1;
			for(int i = 0; i < 5; i++) {
				antidisestablishment[i] = 0;
			}
			for(int i = k.length() - 1; i >= 0; i--) {
				six_counter++;
				curr += power*letterDigitToNumber(k[i]);		
				power = power *36;
				if(six_counter == 6){
					antidisestablishment[index] = curr;
					power = 1;
					curr = 0;
					six_counter = 0;
					index= index - 1;
				}
			}

            
			if (index >= 0 && six_counter < 6) {
				antidisestablishment[index] = curr;
			}
		
			HASH_INDEX_T val = 0;
			for (int i = 0; i < 5; i++) {
				val += (rValues[i] * antidisestablishment[i]);
			}
        
		return val;
    }

    // A likely helper function is to convert a-z,0-9 to an integral value 0-35
    HASH_INDEX_T letterDigitToNumber(char letter) const
    {
        // Add code here or delete this helper function if you do not want it
				HASH_INDEX_T fred;
				if (letter >= 97 and letter <=122){
							fred = letter-97;
							return fred;
						}
				if (letter >= 48 and letter <=57){
					fred = letter-22;
					return fred;
				}
				if(letter >=65 && letter <= 90){
					fred = letter-65;
					return fred;
				}
				else{
					fred = -1;
					return fred;
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
