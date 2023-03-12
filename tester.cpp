#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include "merge_sort.h"
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
        clock_t start = clock();
        heapSort(v, nrNumere);
        clock_t stop = clock();
        if(verificare2(v, nrNumere) == true)
            fout << stop - start << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "Merge sort: ";
        start = clock();
        mergeSort(v, 0, nrNumere-1);
        stop = clock();
        if(verificare1(v, nrNumere) == true)
            fout << stop - start << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "Shell sort: ";
        start = clock();
        shellSort(v, nrNumere);
        stop = clock();
        if(verificare1(v, nrNumere) == true)
            fout << stop - start << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];
        
        fout << "Counting sort: ";
        start = clock();
        countingSort(v, nrNumere);
        stop = clock();
        if(verificare1(v, nrNumere) == true)
            fout << stop - start << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "Radix sort baza 10: ";
        start = clock();
        radixSortB10(v, nrNumere);
        stop = clock();
        if(verificare1(v, nrNumere) == true)
            fout << stop - start << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "Radix sort baza 2^8: ";
        start = clock();
        radixSortB256(v, nrNumere);
        stop = clock();
        if(verificare1(v, nrNumere) == true)
            fout << stop - start << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "Radix sort baza 2^16: ";
        start = clock();
        radixSortB65536(v, nrNumere);
        stop = clock();
        if(verificare1(v, nrNumere) == true)
            fout << stop - start << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];

        fout << "C++ sort: ";
        start = clock();
        sort(v, v+nrNumere);
        stop = clock();
        if(verificare1(v, nrNumere) == true)
            fout << stop - start << " ms\n";
        else
            fout << "incorect\n";

        fout << "\n";
    }

    fout.close();
    fin.close();

    return 0;
}