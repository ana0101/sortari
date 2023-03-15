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
#include "radix_sort_b10.h"
#include "radix_sort_b256.h"
#include "radix_sort_b65536.h"
using namespace std;

ifstream fin("teste.in");
ofstream fout("rezultate.out");
ofstream fout2("numere.out");

int v[100000005], w[100000005], v2[100000005];

bool verificare1(int v[], int v2[], int n)
{
    bool ok = true;
    for(int i=0; i<n; i++)
        if(v[i] != v2[i])
            ok = false;
    return ok;
}

bool verificare2(int v[], int v2[], int n)
{
    bool ok = true;
    for(int i=1; i<=n; i++)
        if(v[i] != v2[i-1])
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
        {
            w[j] = v[j];
            v2[j] = v[j];
        }

        sort(v2, v2+nrNumere);


        fout << "Heap sort: ";
        for(int j=nrNumere-1; j>=0; j--)
            v[j+1] = v[j];
        auto start = std::chrono::high_resolution_clock::now();
        try
        {
            heapSort(v, nrNumere);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        auto stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durata = stop - start;
        if(verificare2(v, v2, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];


        fout << "Merge sort: ";
        start = std::chrono::high_resolution_clock::now();
        try
        {
            mergeSort(v, 0, nrNumere-1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, v2, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];


        fout << "Quick sort pivot random: ";
        start = std::chrono::high_resolution_clock::now();
        try
        {
            quickSort1(v, 0, nrNumere-1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, v2, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];


        fout << "Quick sort pivot mediana din 3: ";
        start = std::chrono::high_resolution_clock::now();
        try
        {
            quickSort2(v, 0, nrNumere-1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, v2, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];


        fout << "Shell sort: ";
        start = std::chrono::high_resolution_clock::now();
        try
        {
            shellSort(v, nrNumere);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, v2, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];


        fout << "Radix sort baza 10: ";
        start = std::chrono::high_resolution_clock::now();
        try
        {
            radixSortB10(v, nrNumere);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, v2, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];


        fout << "Radix sort baza 2^8: ";
        start = std::chrono::high_resolution_clock::now();
        try
        {
            radixSortB256(v, nrNumere);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, v2, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];


        fout << "Radix sort baza 2^16: ";
        start = std::chrono::high_resolution_clock::now();
        try
        {
            radixSortB65536(v, nrNumere);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, v2, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        for(int j=0; j<nrNumere; j++)
            v[j] = w[j];


        fout << "C++ sort: ";
        start = std::chrono::high_resolution_clock::now();
        try
        {
            sort(v, v+nrNumere);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        stop = std::chrono::high_resolution_clock::now();
        durata = stop - start;
        if(verificare1(v, v2, nrNumere) == true)
            fout << durata.count() * 1000 << " ms\n";
        else
            fout << "incorect\n";

        fout << "\n";
    }

    fout.close();
    fin.close();

    return 0;
}