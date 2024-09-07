#include <iostream>
#include <fstream>
const int range = 100;

using namespace std;

void countFrequency(const string& filename, int frequency[]) {
    ifstream file(filename, ios::binary);
    if(!file) {
        cerr << "Nie można otworzyć pliku!" << endl;
        return;
    }
    int number;
    while(file.read(reinterpret_cast<char*>(&number),sizeof(int))) {
        if(number >=1 && number <= 100) {
            frequency[number - 1]++;
        }
    }
    file.close();
}

void saveFrequency(const string& outputFile, const int frequenccy[]) {
    ofstream outfile(outputFile);
    if(!outfile) {
        cerr << "Nie można utworzyć pliku!" << endl;
        return;
    }
    for(int i =0; i <= range; ++i) {
        outfile << (i+1) << ": " << frequenccy[i] << endl;
    }
    outfile.close();
}

int main()
{

    string inputFile = "Alpha.bin";
    string outputFile = "beta.txt";

    int frequency[range] = {0};

    countFrequency(inputFile, frequency);
    saveFrequency(outputFile, frequency);

    return 0;
}
