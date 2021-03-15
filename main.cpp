#include <algorithm>
#include <ctime>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

#include "source/main.hh"
#include "source/Sort.hh"

#include "sort/bubble.hh"
#include "sort/heap.hh"
#include "sort/quick.hh"
#include "sort/shell.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
void conductTest( unsigned int baseSize, unsigned int dataSetSize, int range_min, int range_max, string fileName ) {

    Sort<T> sort( baseSize, dataSetSize );

    int args_heap[] = { sort.getBaseSize() };
    int args_quick[] = { 0, sort.getBaseSize() - 1 };
    int args_shell[] = { sort.getBaseSize() };

    /*   *   *   *   *   *   *   *   *   *   */

    if( range_min > range_max ) { swap( range_min, range_max ); }

    int min = range_min > 0 ? range_min : 0;
    int max = range_max > 0 ? range_max : sort.getBaseSize() - 1;

    /*   *   *   *   *   *   *   *   *   *   */

    sort.fillSet( min, max );
    sort.forEach ( heapSort<T>, args_heap, "heapSort rand");

    sort.randomize( 0, sort.getBaseSize() - 1, 250 );
    sort.forEach ( heapSort<T>, args_heap, "heapSort 25.0%");

    sort.randomize( 0, sort.getBaseSize() - 1, 500 );
    sort.forEach ( heapSort<T>, args_heap, "heapSort 50.0%");

    sort.randomize( 0, sort.getBaseSize() - 1, 550 );
    sort.forEach ( heapSort<T>, args_heap, "heapSort 75.0%");

    sort.randomize( 0, sort.getBaseSize() - 1, 950 );
    sort.forEach ( heapSort<T>, args_heap, "heapSort 95.0%");
    
    sort.randomize( 0, sort.getBaseSize() - 1, 990 );
    sort.forEach ( heapSort<T>, args_heap, "heapSort 99.0%");

    sort.randomize( 0, sort.getBaseSize() - 1, 997 );
    sort.forEach ( heapSort<T>, args_heap, "heapSort 99.7%");

    sort.reverse();
    sort.forEach ( heapSort<T>, args_heap, "heapSort reverse");

    /*   *   *   *   *   *   *   *   *   *   */

    sort.fillSet( 0, sort.getBaseSize() - 1 );
    sort.forEach ( quickSort<T>, args_quick, "quickSort rand");

    sort.randomize( 0, sort.getBaseSize() - 1, 250 );
    sort.forEach ( quickSort<T>, args_quick, "quickSort 25.0%");

    sort.randomize( 0, sort.getBaseSize() - 1, 500 );
    sort.forEach ( quickSort<T>, args_quick, "quickSort 50.0%");

    sort.randomize( 0, sort.getBaseSize() - 1, 550 );
    sort.forEach ( quickSort<T>, args_quick, "quickSort 75.0%");

    sort.randomize( 0, sort.getBaseSize() - 1, 950 );
    sort.forEach ( quickSort<T>, args_quick, "quickSort 95.0%");
    
    sort.randomize( 0, sort.getBaseSize() - 1, 990 );
    sort.forEach ( quickSort<T>, args_quick, "quickSort 99.0%");

    sort.randomize( 0, sort.getBaseSize() - 1, 997 );
    sort.forEach ( quickSort<T>, args_quick, "quickSort 99.7%");

    sort.reverse();
    sort.forEach ( quickSort<T>, args_quick, "quickSort reverse");

    /*   *   *   *   *   *   *   *   *   *   */

    sort.fillSet( 0, sort.getBaseSize() - 1 );
    sort.forEach ( shellSort<T>, args_shell, "shellSort rand");

    sort.randomize( 0, sort.getBaseSize() - 1, 250 );
    sort.forEach ( shellSort<T>, args_shell, "shellSort 25.0%");

    sort.randomize( 0, sort.getBaseSize() - 1, 500 );
    sort.forEach ( shellSort<T>, args_shell, "shellSort 50.0%");

    sort.randomize( 0, sort.getBaseSize() - 1, 550 );
    sort.forEach ( shellSort<T>, args_shell, "shellSort 75.0%");

    sort.randomize( 0, sort.getBaseSize() - 1, 950 );
    sort.forEach ( shellSort<T>, args_shell, "shellSort 95.0%");
    
    sort.randomize( 0, sort.getBaseSize() - 1, 990 );
    sort.forEach ( shellSort<T>, args_shell, "shellSort 99.0%");

    sort.randomize( 0, sort.getBaseSize() - 1, 997 );
    sort.forEach ( shellSort<T>, args_shell, "shellSort 99.7%");

    sort.reverse();
    sort.forEach ( shellSort<T>, args_shell, "shellSort reverse");

    /*   *   *   *   *   *   *   *   *   *   */

    sort.printSet( true, fileName );
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int main( int argc, char *argv[] ) {

    srand( time(NULL) );

    /*   *   *   *   *   *   *   *   *   *   */
        
    if( argc < 6 ) {
        cout << "Not enough data!" << endl;
        return 2;
    }

    unsigned int baseSize = atoi( argv[1] );
    unsigned int dataSetSize = atoi( argv[2] );

    int range_min = atoi( argv[3] );
    int range_max = atoi( argv[4] );

    string fileName = argv[5];

    /*   *   *   *   *   *   *   *   *   *   */

    conductTest<int>( baseSize, dataSetSize, range_min, range_max, fileName );    
}