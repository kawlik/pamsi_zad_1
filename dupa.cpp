#include <iostream>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

void f_callback( void ) {
    cout << "Jestem callbackiem!" << endl;
}

void u_callback( void( *callback )( void ) ) {
    callback();
}

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

int main() {

    u_callback( f_callback );
}