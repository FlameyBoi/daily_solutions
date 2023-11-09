#define MODULO (1000000007)
int countHomogenous(char* s) {
    long count = 0, seq = 0;
    char cur = '\0';
    while (*s)
    {
        if (*s == cur)
        {
            seq++;
        }
        else
        {
            count += (seq + 1) * seq / 2;
            count %= MODULO;
            seq = 1;
            cur = *s;
        }
        s++;
    }
    count += (seq + 1) * seq / 2;
    count %= MODULO;
    return (int)count;
}