boolean test_and_set(boolean *target)
{
    boolean rv = *target;
    *target = true;
    return rv;
}
do
{
    waiting[i] = true;
    key = true;
    while (waiting[i] && key)
        key = test_and_set(&lock);
    waiting[i] = false
        // criticals section
    j = (i + 1) % n;
    while ((j != i) && !waiting[j])
        j = (j + 1) % n;
    if (j == i)
        lock = false;
    else
        waiting[j] = false;
    // remainder section
} while (true);