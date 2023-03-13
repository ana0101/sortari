int mediana(int e1, int e2, int e3)
{
    if((e1 <= e2) ^ (e1 <= e2))
        return e1;
    else
    {
        if((e2 <= e1) ^ (e2 <= e3))
            return e2;
        else
            return e3;
    }
}


void quickSort2(int v[], int st, int dr)
{
    if(st < dr)
    {
        int pivot = mediana(v[st], v[(st+dr)/2], v[dr-1]);
        int poz_pivot;
        if(pivot == v[st])
            poz_pivot = st;
        else
        {
            if(pivot == v[(st+dr)/2])
                poz_pivot = (st+dr)/2;
            else
                poz_pivot = dr-1;
        }
        poz_pivot = ordonare(v, st, dr, poz_pivot);
        quickSort2(v, st, poz_pivot);
        quickSort2(v, poz_pivot+1, dr);
    }
}