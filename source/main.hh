#include <ctime>
#include <iostream>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template<typename T>
T getRand( int min, int max ) {

    T tmp = (rand() % ( max - min )) + min;
    return tmp;
}