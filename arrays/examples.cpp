#include<iostream>

using namespace std;


void func(int **arr) {
    cout << "in\n";

}


void func(int *arr, int x, int y) {

    int (*arr5)[y] = (int(*)[y]) arr;

    for (int i = 0; i < x ; i++) {
        for (int j=0; j< y; j++) {
            cout << arr5[i][j] << " "; 
        }

        cout << "\n";
    }

}


int main() {

    // initialization
    int arr10[2][2] = {{1,2},{3,4}}; 
    int arr11[2][2] = {1,2,3,4};  // the same

    int x,y;
    
    cin >> x >> y;

    int arr1[x][y];
    int arr2[x][y];


    for (int i = 0; i < x; i++ ) {
        for (int j = 0; j < y; j++) {
            arr1[i][j]=i*x+j;
            arr2[i][j]=i*x*2+j;
        }
    }


    // option

    int **arr3 = 0;
    arr3 = new int *[x]; // memory for rows

    // memory for columns
    for (int i = 0; i < x; i++) {
        arr3[i] = new int [y];
    }
   
    func(arr3);


    // another option

    int *arr4 = new int[x*y];

    for (int i = 0; i < x*y; i++ ) {
        arr4[i] = i;
    }

    func(arr4, x, y);

    cout << "done!\n";

}