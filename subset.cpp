#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void find_subsets( vector<int> & vec )
{
    int num_subsets = 1 << vec.size(); 
    
    for( int i = 0; i < num_subsets; i++ )
    {
        int pos = 0; //vec.size() - 1; 
        int bitmask = i; 
        
        cout << "{";
        cout.width(2); 
        while( bitmask > 0 )
        {
            if((bitmask & 1) == 1)
            {
                cout << vec.at( pos )-1; 
                if( bitmask != 1 )
                 cout << " "; 
            }
            bitmask >>= 1;  
            pos++;
        }
        cout.width(2); 
        cout << "}" << endl; 
    }
}

int main() 
{
    vector<int> array{1, 2, 3, 4};
    
    find_subsets( array ); 



cout << setw(10) << "This" <<
        setw(10) << "is" <<
        setw(10) << "a" <<
        setw(10) << "test" << '\n';
}


