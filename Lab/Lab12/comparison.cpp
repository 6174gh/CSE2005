#include <bits/stdc++.h>
using namespace std;
int lru(int *frame, int *arr, int frame_size, string seq)
{
    int miss = 0;
    // intialize usage array to -1
    int usage[frame_size];
    for (int i = 0; i < frame_size; i++)
    {
        usage[i] = -1;
    }

    int current = 0;
    for (int i = 0; i < seq.length(); i++)
    {
        int flag = 1;

        for (int j = 0; j < frame_size; j++)
        {
            if (arr[i] == frame[j])
            {

                flag = 0;
                // Swap the elemnt in usage array with first element
                int temp = frame[0];
                frame[0] = frame[j];
                frame[j] = temp;
            }
        }
        if (flag)
        {

            miss++;
            frame[current] = arr[i];
            current++;
            current %= frame_size;
            // In array usage
            // Remove elemant at last postion
            // Shift elements
            // add new element to index position
            for (int k = frame_size - 1; k > 0; k--)
            {
                frame[k + 1] = frame[k];
            }
            frame[0] = arr[i];
        }
    }

    return miss;
}
int fifo(int *frame, int *arr, int frame_size, string seq)
{

    int hit = 0, miss = 0;

    // To implement FIFO
    // To keep track of oldest page
    int current = 0;
    for (int i = 0; i < seq.length(); i++)
    {
        int flag = 1;

        for (int j = 0; j < frame_size; j++)
        {
            if (arr[i] == frame[j])
            {

                flag = 0;
            }
        }
        if (flag)
        {
            miss++;
            frame[current] = arr[i];
            current++;
            current %= frame_size;
        }
    }

    return miss;
}
int main()
{
    cout << "Page replacement algorithm FIFO\n";
    int frame_size, page_size;
    cout << "Enter the no of frames (frame size)\n";
    cin >> frame_size;
    cout << "Enter the page sequence(Without spaces)\n";
    string seq;
    cin >> seq;
    // Intialize frames to -1
    int frame[frame_size];
    for (int i = 0; i < frame_size; i++)
    {
        frame[i] = -1;
    }
    // Convert string to integer array
    int arr[seq.length()];
    for (int i = 0; i < seq.length(); i++)
    {
        // Ascii to int
        arr[i] = (seq[i] - 48);
    }
    int fifo_miss = fifo(frame, arr, frame_size, seq);
    int lru_miss = lru(frame, arr, frame_size, seq);
    cout << "No of Miss in FIFO: " << fifo_miss << endl;
    cout << "No of Miss in LRU: " << lru_miss << endl;
    if (fifo_miss < lru_miss)
    {
        cout << "FIFO is efficient" << endl;
    }
    else if (fifo_miss == lru_miss)
    {
        cout << "Both are equally efficient" << endl;
    }
    else
    {
        cout << "LRU is efficient" << endl;
    }
    return 0;
}