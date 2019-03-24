int Solution::colorful(int A) {

    set<long> AVL;
    set<long>::iterator it;
    vector<int> digits;
    while(A)
    {
        digits.push_back(A%10);
        A = A/10;
    }
    int sz = digits.size();
    
    for(int i = 0; i < sz; i++)
    {
        long v = digits[i];

        if(AVL.find(v) != AVL.end())
            return 0;
        AVL.insert(v);
        for(int j = i+1; j < sz; j++)
        {
            v = v * digits[j];
            if(AVL.find(v) != AVL.end())
                return 0;
            AVL.insert(v);
        }
    }
    return 1;
}
