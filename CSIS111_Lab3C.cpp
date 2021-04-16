// CSIS111_Lab3C.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

vector<vector<int>> readIn(string fileName) {

    string myNum;
    vector<vector<int>> end;
    //read from the text file
    ifstream MyReadFile(fileName);
    //use a while loop together with the getline() function to read the file line by line
    cout << "\nReading in numbers from: " << fileName << endl;
    //int c = 0;
    int dec;
    //output the text from the file
    for (int i = 0; i < 3; i++) {
        vector<int> temp;
        for (int j = 0; j < 4; j++) {
            getline(MyReadFile, myNum);
            int dec = stoi(myNum);
            temp.push_back(dec);
        }
        end.push_back(temp);
    }
    //c++;
    return end;

}
int main()
{
    vector<vector<int>> a = readIn("a.txt");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    getchar();
    vector<vector<int>> b = readIn("b.txt");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    getchar();
    cout << "\nCreating c\n";
    vector<vector<int>> c;
    for (int i = 0; i < 3; i++) {
        vector<int> temp;
        for (int j = 0; j < 4; j++) {
            temp.push_back(fmax(a[i][j], b[i][j]));
            cout << fmax(a[i][j], b[i][j]) << " ";
        }
        c.push_back(temp);
        cout << endl;
    }
    ofstream Myfile("c.txt");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            Myfile << c[i][j] << endl;
        }
        cout << endl;
    }
    Myfile.close();
    
}

