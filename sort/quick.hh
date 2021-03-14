#include <iostream>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */


template <typename T>
void quickSort( T *arr, int *args ) {

    int left = args[0];
    int right = args[1];


    int i, j, pivot;

    i = (left + right) / 2;
    j = left;

    pivot = arr[i];
    arr[i] = arr[right];

    for( i = left; i < right; i++ ) {
        if( pivot > arr[i] ) {
            swap( arr[i], arr[j] );
            j++;
        }
    }


    arr[right] = arr[j];
    arr[j] = pivot;

    if( left < j - 1 ) {
        int new_args[] = { left, j - 1 };
        quickSort<T>( arr, new_args );
    }

    if( right > j + 1 ) {
        int new_args[] = { j + 1, right };
        quickSort<T>( arr, new_args );
    }
}