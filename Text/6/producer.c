while (true)
{
    while (counter == BUFFER_SIZE)
        ;
    buffer[in] = next_produced;
    in = (in + 1) % BUFFER_SIZE;
    counter++;
}