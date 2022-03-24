while (true)
{
    while (counter == 0)
        ;
    next_consumed = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    counter--;
}