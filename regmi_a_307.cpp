/**
* a framework for exhaustive-search discrete knapsack 
* @author originally written by Jon Beck
* @author modified by Arjan Regmi
* @version 03/07/2017
*/
#include <climits>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

typedef unsigned int uint;

/**
* raise an unsigned integer to an unsigned power
* C++ has pow, but it accepts and returns floating point values
* @param base the base to be raised to a power
* @param exp the exponent to which to reaise the base
* @return base ^ exp
*/
uint ipow( uint base, uint exp )
{
  if( base == 0 )
    return 1;
  uint result = 1;
  while( exp > 0 )
  {
    if( (exp & 1) == 1 )
      result *= base;
    exp >>= 1;
    base *= base;
  }
  return result;
}

/**
* generate all the subsets of the items
* along with the total weight and value and output 
* with an appropriate allignment
* Performs exhaustive search to solve the knapsack
* Generates number of basic operation and the input size 
* @param weight the vector containing the weight of the items
* @param value the vector containing the value of the items 
*/
void generate_result( vector<uint> & weight, vector<uint> & value, uint & capacity )
{
  weight.insert( weight.begin(), 0 ); 
  value.insert( value.begin(), 0 );

  uint num_subsets = ipow( 2, (weight.size()-1) );
  vector<uint> subset_value;
  int count = 0; 

  for( uint j = 0; j < num_subsets; j++ )
  {
    subset_value.push_back( j );
  }

  for( uint i = 0; i < uint(subset_value.size()); i++ )
  {
    uint pos = 0;
    uint bitmask = (uint)subset_value.at( i ); 

    uint sum_weight = 0;
    uint sum_value = 0;
    uint space_count = 0; 

    cout << "{";
    cout.width( 2 ); 

    count++;
    while( bitmask > 0 )
    {
      if( (bitmask & 1) == 1 )
      {
        cout << ( subset_value.at( pos ) );
        count++;
        sum_weight += weight.at( pos+1 );
        sum_value += value.at( pos+1 );
        space_count += 1; 
        if( bitmask != 1 )
          cout << " "; 
      }
      bitmask >>= 1;  
      pos++;
    }
    cout.width( 2 ); 
    cout << "}";
    cout << setw( 25 - (space_count*2) ) << '\t' << "  " << sum_weight;
    if( sum_weight > capacity )
    {
      cout << setw( 15 - (to_string(sum_weight).length()) ) << "NF" << endl;
    }
    else
    {
      cout << setw( 15 - ( to_string(sum_weight).length()) ) << sum_value << endl;  
    } 
  }
  uint input_size = (weight.size()-1);
  cerr << input_size; 
  cerr << setw(8) << count; 
}

/*
* standard input must be of the form
* capacity
* weight value
* weight value
* ...
*/
int main()
{
  uint capacity;
  cin >> capacity;

  vector<uint> weights;
  vector<uint> values;

  while( !cin.eof() )
  {
    uint weight;
    uint value;
    cin >> weight >> value;
    if( !cin.eof() )
    {
      weights.push_back( weight );
      values.push_back( value ); 
    }
  }
  generate_result( weights, values, capacity );
  return 0; 
}






