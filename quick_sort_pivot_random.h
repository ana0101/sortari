void ordonare(int v[], int inc, int sf, int pivot, int poz[])
{
    int lim1 = inc, lim2 = inc, lim3 = sf;
    //inc - lim1: < pivot
    //lim1 - lim2: == pivot
    //lim2 - lim3: neprocesate inca
    //lim3 - sf: > pivot
    while(lim2 <= lim3)
    {
        if(v[lim2] < pivot)
        {
            std::swap(v[lim1], v[lim2]);
            lim1 ++;
            lim2 ++;
        }
        else
        {
            if(v[lim2] > pivot)
            {
                std::swap(v[lim2], v[lim3]);
                lim3 --;
            }
            else
                lim2 ++;
        }
    }
    poz[0] = lim1, poz[1] = lim2;
}


void quickSort1(int v[], int inc, int sf)
{
    if(inc < sf)
    {
        srand(time(0));
        int poz_pivot = inc + rand() % (sf-inc);
        int pivot = v[poz_pivot];
        int poz[3];
        ordonare(v, inc, sf, pivot, poz);
        int lim1 = poz[0], lim2 = poz[1];
        quickSort1(v, inc, lim1-1);
        quickSort1(v, lim2, sf);
    }
}