int ordonare(int v[], int st, int dr, int poz_pivot)
{
    int j = 0;
    for(int i=st; i<dr; i++)
        if(v[i] <= v[poz_pivot] && i != poz_pivot)
        {
            aux[j] = v[i];
            j ++;
        }

    aux[j] = v[poz_pivot];
    int poz_pivot2 = j + st;
    j ++;
    
    for(int i=st; i<dr; i++)
        if(v[i] > v[poz_pivot])
        {
            aux[j] = v[i];
            j ++;
        }

    for(int i=st; i<dr; i++)
        v[i] = aux[i-st];

    return poz_pivot2;
}


void quickSort1(int v[], int st, int dr)
{
    if(st < dr)
    {
        srand(time(0));
        int poz_pivot = st + rand() % (dr-st);
        poz_pivot = ordonare(v, st, dr, poz_pivot);
        quickSort1(v, st, poz_pivot);
        quickSort1(v, poz_pivot+1, dr);
    }
}