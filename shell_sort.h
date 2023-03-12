void shellSort(int v[], int n)
{
    for(int h=n/2; h>0; h/=2)
    {
        for(int i=h; i<n; i++)
        {
            int aux = v[i];
            int j = i - h;
            while(j>=0 && v[j]>aux)
            {
                v[j+h] = v[j];
                j -= h;
            }
            v[j+h] = aux;
        }
    }
}