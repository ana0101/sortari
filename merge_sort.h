int aux[10000005];

void interclasare(int v[], int st, int mij, int dr)
{
    int i = st, j = mij+1, k = 0;
    //int aux[dr-st+2];
    while(i <= mij && j <= dr)
    {
        if(v[i] <= v[j])
        {
            aux[k] = v[i];
            i ++;
            k ++;
        }
        else
        {
            aux[k] = v[j];
            j ++;
            k ++;
        }
    }

    while(i <= mij)
    {
        aux[k] = v[i];
        i ++;
        k ++;
    }

    while(j <= dr)
    {
        aux[k] = v[j];
        j ++;
        k ++;
    }

    k = 0;
    for(int i=st; i<=dr; i++)
    {
        v[i] = aux[k];
        k ++;
    }
}


void mergeSort(int v[], int st, int dr)
{
    if(st < dr)
    {
        int mij = (st+dr)/2;

        mergeSort(v, st, mij);
        mergeSort(v, mij+1, dr);

        interclasare(v, st, mij, dr);
    }
}