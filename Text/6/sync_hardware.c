boolean test_and_set(boolean *target)
{
    boolean rv = *target;
    *target = true;
    return rv;
}
do
{
    while (test_and_set(&lock))
        ;
    lock = false;

} while (true);