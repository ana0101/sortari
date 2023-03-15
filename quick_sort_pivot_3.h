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


void quickSort2(int v[], int inc, int sf)
{
    if(inc < sf)
    {
        int pivot = mediana(v[inc], v[(inc+sf)/2], v[sf]);
        int poz[3];
        ordonare(v, inc, sf, pivot, poz);
        int lim1 = poz[0], lim2 = poz[1];
        quickSort2(v, inc, lim1-1);
        quickSort2(v, lim2, sf);
    }
}