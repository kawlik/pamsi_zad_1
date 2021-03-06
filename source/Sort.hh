#include <algorithm>
#include <ctime>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template<typename T>
class Sort {

    private:

        unsigned int baseSize;
        unsigned int dataSetSize;

        T **dataSet;

        vector<pair<string, int>> outcome;

    /*   *   *   *   *   *   *   *   *   *   */

    public:
        
        Sort( unsigned int baseSize, unsigned int dataSetSize );
        ~Sort();

        int getBaseSize() {return this->baseSize;}
        int getDataSetSize() {return this->dataSetSize;}

        bool isSortValid( unsigned int index );

        void fillSet( int min, int max );
        void forEach( function<void( T *, int * )> callback, int *args, string name );
        void printSet( bool printAll, string fileName );
        void pushData( string name, long unsigned int time, bool isValid );
        void randomize( int min, int max, int offset );
        void reverse();
};

/*   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   */

template <typename T>
Sort<T>::Sort( unsigned int baseSize, unsigned int dataSetSize ) {
    
    this->baseSize = baseSize;
    this->dataSetSize = dataSetSize;

    this->dataSet = new T *[dataSetSize];

    for( unsigned int i = 0; i < dataSetSize; i++ ) {
        this->dataSet[i] = new T [baseSize];
    }
}

template <typename T>
Sort<T>::~Sort() {

    for( unsigned int i = 0; i < dataSetSize; i++ ) {
        delete [] this->dataSet[i];
    }

    delete [] this->dataSet;
}

/*   *   *   *   *   *   *   *   *   *   */

template <typename T>
bool Sort<T>::isSortValid( unsigned int index ) {

    for( unsigned int i = 1; i < this->baseSize; i++ ) {
        if( this->dataSet[index][i - 1] > this->dataSet[index][i] ) { return false; }
    }

    return true;
}

/*   *   *   *   *   *   *   *   *   *   */

template <typename T>
void Sort<T>::fillSet( int min, int max ) {

    for( unsigned int i = 0; i < this->dataSetSize; i++ ) {
        for( unsigned int j = 0; j < this->baseSize; j++ ) {
            this->dataSet[i][j] = getRand<T>( min, max );
        }
    }
}

template <typename T>
void Sort<T>::forEach( function<void( T *, int * )> callback, int *args, string name ) {

    bool isValid = true;
    clock_t start, stop;
    
    start = clock();

    for( unsigned int i = 0; i < this->dataSetSize; i++ ) {
        callback( this->dataSet[i], args );
    }

    stop = clock();

    
    for( unsigned int i = 0; i < this->dataSetSize; i++ ) {
        isValid = this->isSortValid(i);
        if(!isValid) {break;}
    }

    long unsigned int time = stop - start;
    this->pushData( name, time, isValid );
}

template <typename T>
void Sort<T>::printSet( bool printAll, string fileName ) {

    if( printAll ) {

        for( unsigned int i = 0; i < this->dataSetSize; i++ ) {
            for( unsigned int j = 0; j < this->baseSize; j++ ) {
                cout << this->dataSet[i][j] << ' ';
            }
            cout << endl << endl;
        }
    }
    
    fstream file( fileName, fstream::out );
    file << "CLOCKS_PER_SEC = " << CLOCKS_PER_SEC << endl << endl;

    for( unsigned int i = 0; i < this->outcome.size(); i++ ) {
        cout << this->outcome[i].first << this->outcome[i].second << endl;
        file << this->outcome[i].first << this->outcome[i].second << endl;
    }

    file.close();
}

template <typename T>
void Sort<T>::pushData( string name, long unsigned int time, bool isValid ) {

    string save = name + (isValid ? " - VALID - " : " - NOT VALID - ");
    this->outcome.push_back( make_pair( save, time ));
}

template <typename T>
void Sort<T>::randomize( int min, int max, int offset ) {

    for( unsigned int i = 0; i < this->dataSetSize; i++ ) {
        for( unsigned int j = 0; j < this->baseSize; j++ ) {
            if( getRand<T>( 1, 1000 ) > offset ) {
                this->dataSet[i][j] = getRand<T>( min, max );
            }
        }
    }
}

template <typename T>
void Sort<T>::reverse() {

    for( unsigned int i = 0; i < this->dataSetSize; i++ ) {
        for( unsigned int j = 0; j < this->baseSize; j++ ) {
            this->dataSet[i][j] = this->baseSize - j - 1;
        }
    }
}