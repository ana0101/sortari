void countingSort(int v[], int n, int putere, int baza)
{
    int f[baza+2] = {0};
    for(int i=0; i<n; i++)
        f[(v[i] / putere) % baza] ++;

    for(int i=1; i<baza; i++)
        f[i] += f[i-1];

    for(int i=n-1; i>=0; i--) 
    {
        aux[f[(v[i] / putere) % baza] - 1] = v[i];
        f[(v[i] / putere) % baza] --;
    }
 
    for(int i=0; i<n; i++)
        v[i] = aux[i];
}


void radixSortB10(int v[], int n)
{
    int maxim = 0, baza = 10;
    for(int i=0; i<n; i++)
        if(v[i] > maxim)
            maxim = v[i];

    for(long long putere=1; maxim/putere>0; putere*=baza)
        countingSort(v, n, putere, baza);
}