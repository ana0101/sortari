int mediana(int e1, int e2, int e3)
{
    if((e1 <= e2) ^ (e1 <= e3))
        return e1;
    else
    {
        if((e2 <= e1) ^ (e2 <= e3))
            return e2;
        else
            return e3;
    }
}


void quickSort2(int v[], int n)
{
    if(n >= 2)
    {
        int inc = 0, sf = n-1;
        int pivot = mediana(v[inc], v[(inc+sf)/2], v[sf]);
        ordonare(v, pivot, inc, sf);
        
        quickSort2(v, sf+1);
        quickSort2(&v[inc], n-inc);
    }
}