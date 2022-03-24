boolean compare_and_swap(int *value, int expected, int new_value)
{
    int temp = *value;
    if (*value == expected)
    {
        *value = new_value;
    }
    return temp;
}
do
{
    while (compare_and_swap(&lock, 0, 1) != 0)
        ;
    // critical section
    lock = 0;
    // remainder section
}