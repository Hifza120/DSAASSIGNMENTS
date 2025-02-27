#include "myStack.h"
#include <stdexcept>
#include <fstream>
bool openFileInput(const ifstream& fin) {
    if (!fin.is_open()) {
        throw runtime_error("File Not Found");
    }
    return true;
}
bool openFileOutput(const ofstream& fout) {
    if (!fout.is_open()) {
        throw runtime_error("File Not Found");
    }
    return true;
}
bool isBinary(char ch) {
    return ch == '0' || ch == '1';
}

int main() {
    const int N = 4;
    int maze[N][N] = { 0 }; 
    //File reading
    try {
        ifstream fin("input.txt");
        if (openFileInput(fin)) {
            int row = 0;
            int col = 0;
            char ch;
            while (fin.get(ch)) {
                if (ch == '\n') {
                    row++;
                    col = 0;
                }
                if (isBinary(ch)) {
                           maze[row][col] = ch - '0';
                        col++;
                    
                }
            }
        }
        fin.close();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
    }
    myStack<char> S(16);
    int i = 0, j = 0;
    //Start Point 
    if (maze[0][0] == 1) {
        maze[0][0] = -1;  
    }
    bool pathFound = false;
//DOWN-D,forward-F,Up-U,Back-B
    while (i < N && j < N) {
        if (i + 1 < N && maze[i + 1][j] == 1) { 
            S.push('D');
            maze[i][j] = -1;  
            i++;
        }
        else if (j + 1 < N && maze[i][j + 1] == 1) { 
            S.push('F');
            maze[i][j] = -1;  
            j++;
        }
        else if (i - 1 >= 0 && maze[i - 1][j] == 1) { 
            S.push('U');
            maze[i][j] = -1;  
            i--;
        }
        else if (j - 1 >= 0 && maze[i][j - 1] == 1) { 
            S.push('B');
            maze[i][j] = -1;  
            j--;
        }
        else {
            pathFound = false;
            break; 
        }

        if (i == N - 1 && j == N - 1) {
            pathFound = true;
            break; 

        }
    }

    myStack<char> S1(16);
    //reverse stack
    while (!S.isEmpty()) {
        S1.push(S.pop());
    }
        ofstream fout("Output.txt");
        //File Writing
        try {
            if (openFileOutput(fout)) {
                if (pathFound) {
                    while (!S1.isEmpty()) {
                        fout << S1.pop() << "    ";
                    }
                }
                else {
                    fout << "Path Not Found" << endl;
                }
            }
            fout.close();
        }
        catch (const exception& e) {
            cout << e.what() << endl;
        }
    


    return 0;
}
