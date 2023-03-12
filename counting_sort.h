int f[100000005];

void countingSort(int v[], int n)
{
    int maxim = v[0], minim = v[0];
    for(int i=1; i<n; i++)
    {
        if(v[i] > maxim)
            maxim = v[i];
        if(v[i] < minim)
            minim = v[i];
    }

    for(int i=0; i<n; i++)
        f[v[i]] ++;

    int k = 0;
    for(int i=minim; i<=maxim; i++)
    {
        while(f[i] > 0)
        {
            v[k] = i;
            k ++;
            f[i] --;
        }
    }
}