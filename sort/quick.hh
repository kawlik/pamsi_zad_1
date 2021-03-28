#include <iostream>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
int devide( T *arr, int *args ) {

    int left = args[0];
    int right = args[1];

    int i, j;

    i = left;
    j = right;

    T tmp = arr[left];

    do {

        while( arr[i] < tmp ) {
            i++;
        }

        while( arr[j] > tmp ) {
            j--;
        }

        if( i < j ) {
            
            swap( arr[i], arr[j] );
            i++;
            j--;

        } else {
            
            //  Breaks the loop
            return j;
        }

    } while( true );
}


template <typename T>
void quickSort2( T *arr, int *args ) {

    int left = args[0];
    int right = args[1];

    if( left < right ) {

        int m_args[] = { left, right };
        int mid = devide( arr, m_args );

        int args_1[] = { left, mid };
        quickSort2( arr, args_1 );

        int args_2[] = { mid + 1, right };
        quickSort2( arr, args_2 );
    }
}


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