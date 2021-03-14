#include <iostream>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
void bubbleSort( T *arr, int *args ) {

    unsigned int lenght = args[0];

    for( unsigned int i = 0; i < lenght; i++ ) {
        for( unsigned int j = 0; j < lenght - 1; j++ ) {
            if( arr[i] < arr[j] ) { swap( arr[i], arr[j] );}
        }
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
void bubbleSortRange( T *arr, int *args ) {

    unsigned int lenght = args[0];
    unsigned int left = args[1];
    unsigned int right = args[2];

    for( unsigned int i = left; i < right - 1; i++ ) {
        for( unsigned int j = left; j < right - 1; j++ ) {
            swap( arr[i], arr[j] );
        }
    }
}