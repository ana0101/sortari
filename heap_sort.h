void heapify(int h[], int n, int nod)
{
    if(nod*2 <= n && nod*2+1 > n)
    {
        if(h[nod] < h[nod*2])
            std::swap(h[nod], h[nod*2]);
    }
    else
    {
        if(nod*2 <= n && nod*2+1 <= n)
        {
            int maxim;
            if(h[nod*2] > h[nod*2+1])
                maxim = nod*2;
            else
                maxim = nod*2+1;

            if(h[nod] < h[maxim])
            {
                std::swap(h[nod], h[maxim]);
                heapify(h, n, maxim);
            }
        }
    }
}


void heapSort(int h[], int n)
{
    for(int nod=n/2; nod>=1; nod--)
        heapify(h, n, nod);

    for(int nod=n; nod>1; nod--)
    {
        std::swap(h[nod], h[1]);
        heapify(h, nod-1, 1);
    }
}