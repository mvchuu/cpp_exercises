#include <iostream>
#include <fstream>
const int alphabetSize = 26;

using namespace std;

void countFrequency(const string& filename, int frequency[]) {
    ifstream file(filename, ios::binary);
    if(!file) {
        cerr << "Nie można otworzyć pliku!" << endl;
        return;
    }
    char ch;
    while(file.get(ch)) {
        if(ch >='a' && ch <= 'z') {
            frequency[ch - 'a']++;
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
    for(int i =0; i <= alphabetSize; ++i) {
        outfile << static_cast<char>('a' + i) << ": " << frequenccy[i] << endl;
    }
    outfile.close();
}

int main()
{

    string inputFile = "Alpha.bin";
    string outputFile = "beta.txt";

    int frequency[alphabetSize] = {0};

    countFrequency(inputFile, frequency);
    saveFrequency(outputFile, frequency);

    return 0;
}
