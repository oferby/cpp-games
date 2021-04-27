/*
    https://www.techgig.com/practice/question/matrix-and-paths/TWw1MURjNHVVbm9NZ3c4SWoxUXlZVERObS8zK3l2R25RVW81ZUx0WFlzZHZyZjIvTjdQanR2TlpJZUNJNUVWQw==/1?utm_source=TG_batch&utm_medium=email&utm_campaign=practice_2021-04-20

    input to use: 3 3 1 1 0 1 0 1 1 1 1 2 2
*/

#include<iostream>

using namespace std;

// width first
void func(int *arr, int x, int y, 
    int dx, int dy, 
    int *v, int currX, int currY, int steps) {

    int (*arr1)[y] = (int(*)[y]) arr;
    int (*visited)[y] = (int(*)[y]) v;

    int tovisit = 0;
    
    steps++;

    // check up
    if (currX - 1 >= 0) {
        if (arr1[currX-1][currY] == 1) {
            if (visited[currX-1][currY] > steps) {
                visited[currX-1][currY] = steps;
                tovisit = tovisit + (1 << 3);
            }
        } else {
            visited[currX-1][currY] = -1;                        
        }

        
    }

    // check right
    if (currY + 1 <= y) {
        if (arr1[currX][currY+1]==1) {
            if (visited[currX][currY+1] > steps) {
                visited[currX][currY+1] = steps;
                tovisit = tovisit + (1 << 2);
            }
        } else {
            visited[currX][currY+1] = -1;
        }
    }

    // check down
    if (currX + 1 <= x) {
        if (arr1[currX+1][currY] == 1) {
            if (visited[currX+1][currY] > steps) {
                visited[currX+1][currY] = steps;
                tovisit = tovisit + (1 << 1);
            }
        } else {
            visited[currX+1][currY] = -1;                        
        }
    }

    // check left
    if (currY - 1 >= 0) {
        if (arr1[currX][currY-1]==1) {
            if (visited[currX][currY-1] > steps) {
                visited[currX][currY-1] = steps;
                tovisit = tovisit + 1;
            }
        } else {
            visited[currX][currY-1] = -1;
        }
    }

    // next place to check

    if ((tovisit & (1<<3))!=0){
        func(arr, x, y, dx, dy, v, currX - 1, currY, steps);
    }

    if ((tovisit & (1<<2))!=0){
        func(arr, x, y, dx, dy, v, currX, currY + 1, steps);
    }

    if ((tovisit & (1<<1))!=0){
        func(arr, x, y, dx, dy, v, currX + 1, currY, steps);
    }

    if ((tovisit & 1) !=0){
        func(arr, x, y, dx, dy, v, currX, currY - 1, steps);
    }


}


void printMe(int *arr, int x, int y) {

    int (*arr1)[y] = (int(*)[y]) arr;

    for (int i = 0; i < x ; i++) {
        for (int j=0; j< y; j++) {
            cout << arr1[i][j] << " "; 
        }

        cout << "\n";
    }

    cout << "\n";

}




int main() {
    
    int x,y, dx, dy;

    cout << "enter rows and columns: ";    
    cin >> x >> y;

    int *arr = new int[x*y];
    int *visited = new int[x*y];

    // cout << "enter matrix:\n";
    int maxSteps = x * y;
    for (int i = 0; i < x*y; i++ ) {
        cin >> arr[i];
        visited[i] = maxSteps;
    }
    visited[0] = 0;
    
    // cout << "enter destination:\n";
    cin >> dx >> dy;

    if (dx == 0 && dy == 0) {
        cout << 0 << "\n";
        exit(0);
    }   

    int steps = 0;

    func(arr, x, y, dx, dy, visited, 0, 0, steps);

    // cout << "\n";
    // printMe(arr, x,y);
    // printMe(visited,x,y);

    cout << "steps: " << visited[dx*y+dy] << "\n";
    // cout << "done!\n";

}