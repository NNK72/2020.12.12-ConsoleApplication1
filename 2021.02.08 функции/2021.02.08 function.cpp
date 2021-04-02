#include <iostream>
#include<random>
#include <ctime>
#include <vector>
#include<iomanip>
#include <string>
#include <chrono>
#include <thread>

using namespace std;
void firstField(string** field, string* num, int size, int numcell) {
    cout << "enter random number:" << endl;
    int* numRand = new int[numcell - 1];
    int err = 0, n=0;
    for (int i = 0; i < numcell - 1; i++) {
        do {
            err = 0;
            numRand[i] = (rand() % (numcell-1)) + 1;
            for (int j = 0; j < numcell - 1; j++) {
                if ((i != j) && (numRand[i] == numRand[j])) err = 1;
            }
        } while (err);
        if (numRand[i] < 10) num[i] = (numRand[i] + 48);
        else { num[i] = ""; num[i] = num[i] + (char)(numRand[i] / 10 + 48)+ (char)(numRand[i]%10 + 48);  }
    }
    delete[]numRand;
 
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i % 2 == 0) field[i][j] = "--";
            else if (i%2!=0 && j%2==0) field[i][j] = "|";
            else {field[i][j] = num[n]; n++;}
        }
    }

}
void output(string** field,int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)  {
            if (field[i][j] == "X") cout << setw(2) << " ";
            else cout <<setw(2)<< field[i][j];
        }
    cout << endl;
    }
}
void game(string** field, int size, int action) {
    switch (action)
    {
    case 4: {
        for (int i = 0; i < size; i++) {
       int exit = 0;
            for (int j = 0; j < size; j++)  {
                if (field[i][j] == "X" && j != 1) { field[i][j] = field[i][j - 2]; field[i][j - 2] = "X"; exit = 1; break; }
                if (field[i][j] == "X" && j == 1) cout << "enter error>size field!" << endl;
            }
            if (exit) break;
        }
        break;
    }
    case 6: {
        for (int i = 0; i < size; i++) {
            int exit = 0;
            for (int j = 0; j < size; j++) {
                if (field[i][j] == "X" && j != size-2) { field[i][j] = field[i][j + 2]; field[i][j + 2] = "X"; exit = 1; break; }
                if (field[i][j] == "X" && j == size-2) cout << "enter error>size field!" << endl;
            }
            if (exit) break;
        }
        break;
    }
    case 8: {
        for (int i = 0; i < size; i++) {
            int exit = 0;
            for (int j = 0; j < size; j++) {
                if (field[i][j] == "X" && i != 1) { field[i][j] = field[i-2][j]; field[i-2][j] = "X"; exit = 1; break; }
                if (field[i][j] == "X" && i == 1) cout << "enter error>size field!" << endl;
            }
            if (exit) break;
        }
        break;
    }
    case 2: {
        for (int i = 0; i < size; i++) {
            int exit = 0;
            for (int j = 0; j < size; j++) {
                if (field[i][j] == "X" && i != size - 2) { field[i][j] = field[i+2][j]; field[i+2][j] = "X"; exit = 1; break; }
                if (field[i][j] == "X" && i == size - 2) cout << "enter error>size field!" << endl;
            }
            if (exit) break;
        }
        break;
    }
    default:
        break;
    }
}
int main() {
    srand(time(NULL));
    int const SIZE = 9, numcell=16;
    int action = 1, stat=0;
    string** field = new string*[SIZE];
    for (int i = 0; i < SIZE; i++) {
        field[i] = new string [SIZE];
    }
    string*num=new string[numcell]{"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","X"};
    firstField(field,num, SIZE, numcell);
    output(field, SIZE);
    while (action!=0) {
        cout << "enter action (4-left / 6-right / 2-down / 8-up ) or 0-exit: "; cin >> action;
       cout<<"quantity motion: "<<++stat<<endl<<endl;
        if (action != 4 && action != 6 && action != 2 && action != 8 && action != 0) { cout << "enter error! "; continue; }
        game(field, SIZE, action);
        output(field, SIZE);

    }


    cout << endl<<endl;

    for (int i = 0; i < SIZE; i++) delete[] field[i];
    delete[] field; delete[] num;
    system("pause");
    return 0;
}