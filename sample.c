#include <stdio.h>
int main()
{
    printf("----------First Fit----------\n");
    int count = 1;
    int size = 1;
    int waste = 0;
    int i, j;
    int m_no = 5;
    int m[] = {1, 2, 3, 4, 5};
    for (j = 0; j < m_no; j++)
    {
        int flagi = 0;
        printf("Enter the size of process %d: ", count);
        scanf("%d", &size);
        int flag = 0;
        for (i = 0; i < m_no; i++)
        {
            printf("%d: size:%d \n", i, m[i]);
            if (m[i] == 0)
            {
                flag = 1;
                if (m[i] >= size)
                {
                    m[i] = 1;
                    printf("Process is allocated\n");
                    waste += m[i] - size;
                    flagi = 1;
                    break;
                }
            }
        }
        if (flagi == 0)
        {
            printf("Process is not alloacted\n");
        }
        // if (flag == 0)
        // {
        //     printf("All memmory blocks occupied\n");
        //     break;
        // }
        count++;
    }
    printf("Internal fragmentation waste: %d\n", waste);

return 0;
}