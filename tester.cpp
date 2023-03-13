#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <chrono>
#include "merge_sort.h"
#include "quick_sort_pivot_random.h"
#include "quick_sort_pivot_3.h"
#include "heap_sort.h"
#include "shell_sort.h"
#include "counting_sort.h"
#include "radix_sort_b10.h"
#include "radix_sort_b256.h"
#include "radix_sort_b65536.h"
using namespace std;

ifstream fin("teste.in");
ofstream fout("rezultate.out");

int v[10000005], w[10000005];

bool verificare1(int v[], int n)
{
    bool ok = true;
    for(int i=0; i<n-1; i++)
        if(v[i] > v[i+1])
            ok = false;
    return ok;
}

bool verificare2(int v[], int n)
{
    bool ok = true;
    for(int i=1; i<n; i++)
        if(v[i] > v[i+1])
            ok = false;
    return ok;
}


int main()
{
    int nrTeste, nrNumere, nrMax;
    fin >> nrTeste;
    for(int i=0; i<nrTeste; i++)
    {
        fin >> nrNumere >> nrMax;
        fout << "Test " << i+1 << ": " << nrNumere << " numere, " << nrMax << " numar maxim\n";
        srand(time(NULL));

        for(int j=0; j<nrNumere; j++)
            v[j] = rand() % nrMax;

        for(int j=0; j<nrNumere; j++)
            w[j] = v[j];


        fout << "Heap sort: ";
        auto start = std::chrono::high_resolution_clock::now();
        heapSort(v, nrNumere);
        auto stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durata = stop - start;
        if(verificare2(v, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "Merge sort: ";
        start = std::chrono::high_resolution_clock::now();
        mergeSort(v, 0, nrNumere-1);
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "Quick sort pivot random: ";
        start = std::chrono::high_resolution_clock::now();
        quickSort1(v, 0, nrNumere);
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "Quick sort pivot mediana din 3: ";
        start = std::chrono::high_resolution_clock::now();
        quickSort2(v, 0, nrNumere);
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "Shell sort: ";
        start = std::chrono::high_resolution_clock::now();
        shellSort(v, nrNumere);
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];
        
        fout << "Counting sort: ";
        start = std::chrono::high_resolution_clock::now();
        countingSort(v, nrNumere);
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "Radix sort baza 10: ";
        start = std::chrono::high_resolution_clock::now();
        radixSortB10(v, nrNumere);
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "Radix sort baza 2^8: ";
        start = std::chrono::high_resolution_clock::now();
        radixSortB256(v, nrNumere);
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "Radix sort baza 2^16: ";
        start = std::chrono::high_resolution_clock::now();
        radixSortB65536(v, nrNumere);
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "C++ sort: ";
        start = std::chrono::high_resolution_clock::now();
        sort(v, v+nrNumere);
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        fout << "\n";
    }

    fout.close();
    fin.close();

    return 0;
}