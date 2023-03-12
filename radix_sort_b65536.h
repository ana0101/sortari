void radixSortB65536(int v[], int n)
{
    int maxim = 0, baza = 65536; //2^16;
    for(int i=0; i<n; i++)
        if(v[i] > maxim)
            maxim = v[i];

    for(long long putere=1; maxim/putere>0; putere*=baza)
        countingSort(v, n, putere, baza);
}