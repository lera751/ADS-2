int count(int arr[], const int el, const int size)
{
    int count = 1;
    int* l = nullptr;
    if (el > 0)
    {
        l = &arr[el - 1];
        while (*l == arr[el])
        {
            ++count;
            if (l != &arr[0])
                --l;
            else break;
        }
    }
    int* r = nullptr;
    if (el + 1 < size)
    {
        r = &arr[el + 1];
        while (*r == arr[el])
        {
            ++count;
            if (r != &arr[size])
                ++r;
            else break;
        }
    }
    return count;
}

int cbinsearch(int arr[], int size, int key)
{
    int r = 0;
    int l = size;
    while (r <= l)
    {
        int el = (r + l) / 2;
        if (arr[el] > key)
            l = el - 1;
        else if (arr[el] < key)
            r = el + 1;
        else return count(arr, el, size);
    }
    return 0;
}

int countPairs1(int* arr, int len, int value)
{
    int count{ 0 };
    for (int i = 0; i < len; ++i)
    {
        int dif = value - arr[i];
        for (int j = 0; j < len && (i != j); ++j)
            if (arr[j] == dif)
            {
                ++count;
            }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) 
{
    int count{ 0 };
    for (int i = 0; i < len;++i)
    {
        int def = value - arr[i];
        for (int j = i + 1; j < len && arr[j] <= def; ++j)
            if (def == arr[j])
            {
                ++count;;
            }
        for (int j = i - 1; j >= 0 && arr[j] >= def; --j)
            if (def == arr[j])
            {
                ++count;
            }
    }
    return count/2;
}

int countPairs3(int* arr, int len, int value)
{
    int count{ 0 };
    for (int i = 0; i < len; ++i)
    {
        int def = value - arr[i];
        count += cbinsearch(arr, len, def);
        if (def == arr[i])
            --count;
    }
    return count/2;
}
