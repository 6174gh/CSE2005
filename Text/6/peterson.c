do
{
    flag[i] = true;
    turn = j;
    while (flag[j] && turn == j)
        ;
    // Critical section comes here
    flag[i] = false;
    // remainder section comes here
}