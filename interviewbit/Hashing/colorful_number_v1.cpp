int Solution::colorful(int A) {
    if(A == 0 || A == 1)
        return 1;

    int digit[10] = {0};
    int orig[10], idx = 0;
    int hsh[73] = {0};
    while(A)
    {
        digit[A%10]++;
        if(digit[A%10] > 1)
            return 0;
        hsh[A%10]++;
        orig[idx++] = A%10;
        A = A/10;
    }

    if(digit[0] != 0 || digit[1] != 0)
        return 0;

    for(int i = 0; i < idx - 1; i++)
    {
        int val = orig[i] * orig[i+1];
        hsh[val]++;
        if(hsh[val] > 1)
            return 0;
    }
    return 1;
    
}

