#include <algorithm>
#include <ctime>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

#include "source/main.hh"
#include "source/Sort.hh"

#include "sort/bubble.hh"
#include "sort/heap.hh"
#include "sort/quick.hh"
#include "sort/shell.hh"

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int main() {

    srand( time(NULL) );

    Sort<int> sort( 1000, 100 );
    sort.fillSet( 0, sort.getBaseSize() - 1 );

    /*   *   *   *   *   *   *   *   *   *   */

    int args[] = { 0, sort.getBaseSize() - 1 };
    sort.forEach ( quickSort<int>, args, "quickSort rand");

    sort.randomize( 0, sort.getBaseSize() - 1, 250 );
    sort.forEach ( quickSort<int>, args, "quickSort 25%");


    /*   *   *   *   *   *   *   *   *   *   */

    sort.printSet();
}