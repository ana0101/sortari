void ordonare(int v[], int pivot, int &inc, int &sf)
{
    while (inc <= sf)
    {
        while (v[inc] < pivot)
            inc++;
        while (v[sf] > pivot)
            sf--;
        if (inc <= sf)
        {
            std::swap(v[inc], v[sf]);
            inc++;
            sf--;
        }
    }
}

void quickSort1(int v[], int n)
{
    if (n >= 2)
    {
        int inc = 0, sf = n - 1;
        srand(time(0));
        int poz_pivot = rand() % (n - 1);
        int pivot = v[poz_pivot];
        ordonare(v, pivot, inc, sf);

        quickSort1(v, sf + 1);
        quickSort1(&v[inc], n - inc);
    }
}