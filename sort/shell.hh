#include <iostream>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
void shellSort( T *arr, int *args ) {

    int l = args[0];
    int m = l / 2;

    while( m > 0 ) {

        int j = 0;

        for( int i = m; i < l; i++ ) {

            T tmp = arr[i];

            for( j = i; (j >= m) && (arr[j - m] > tmp); j -= m) {
                arr[j] = arr[j - m];
            }

            arr[j] = tmp;
        }

        m = m / 2;
    }
}