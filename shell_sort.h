void shellSort(int v[], int n)
{
    for(int d=n/2; d>0; d/=2)
    {
        for(int i=d; i<n; i++)
        {
            int aux = v[i];
            int j = i - d;
            while(j>=0 && v[j]>aux)
            {
                v[j+d] = v[j];
                j -= d;
            }
            v[j+d] = aux;
        }
    }
}