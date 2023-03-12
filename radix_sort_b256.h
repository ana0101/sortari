void radixSortB256(int v[], int n)
{
    int maxim = 0, baza = 256; //2^8;
    for(int i=0; i<n; i++)
        if(v[i] > maxim)
            maxim = v[i];

    for(long long putere=1; maxim/putere>0; putere*=baza)
        countingSort(v, n, putere, baza);
}