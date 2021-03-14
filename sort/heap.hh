#include <iostream>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
void heap( T *arr, int *args ) {

    int n = args[0];
    int i = args[1];

    int high = i;
    int l = 2*i + 1;
    int r = 2*i + 2;


    if(( l < n ) && ( arr[l] > arr[high] )) {
        high = l;
    }

    if(( r < n ) && ( arr[r] > arr[high] )) {
        high = r;
    }

    if( high != i ) {

        int new_args[] = { n, high };

        swap( arr[i], arr[high] );
        heap( arr, new_args );
    }
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
void heapSort( T *arr, int *args ) {

    int n = args[0];

    for( int i = n / 2 - 1; i >= 0; i-- ) {
        int new_args[] = { n, i };
        heap( arr, new_args );
    }

    for( int i = n - 1; i >= 0; i-- ) {

        int new_args[] = { i, 0 };

        swap( arr[0], arr[i] );
        heap( arr, new_args );
    }
}