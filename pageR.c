#include <stdio.h>
#include <stdlib.h>

void fifo(int incomingStream[], int pages, int frames)
{

    int pageFaults = 0;
    int m, n, s;

    printf("Incoming\t\tFrame 1\t\tFrame 2\tFrame 3\n");

    int temp[frames];
    for (m = 0; m < frames; m++)
    {
        temp[m] = -1; // Initialize the frames with -1 to indicate they are empty.
    }

    for (m = 0; m < pages; m++)
    {
        s = 0;

        for (n = 0; n < frames; n++)
        {
            if (incomingStream[m] == temp[n])
            {
                s++;
                break; // Add this line to exit the loop when a match is found.
            }
        }

        if (s == 0)
        {
            // If the page is not already in the frames, replace the oldest page.
            temp[pageFaults % frames] = incomingStream[m];
            pageFaults++;
        }

        printf("%d\t\t", incomingStream[m]);
        for (n = 0; n < frames; n++)
        {
            if (temp[n] != -1)
                printf("%d\t\t", temp[n]);
            else
                printf("-\t\t");
        }
        printf("\n");
    }

    printf("\n");
    printf("Total Page Faults:\t%d\n", pageFaults);
}
int checkHit(int incomingPage, int queue[], int occupied)
{

    for (int i = 0; i < occupied; i++)
    {
        if (incomingPage == queue[i])
            return 1;
    }

    return 0;
}

void printFrame(int queue[], int occupied)
{
    for (int i = 0; i < occupied; i++)
        printf("%d\t\t\t", queue[i]);
}

void lru(int pages[], int total_pages, int total_frames)
{

    int m, n, position, k, l;
    int a = 0, b = 0, page_fault = 0;

    int frames[total_frames];
    int temp[total_frames];

    printf("Page\t Frame1 \t Frame2 \t Frame3\n");
    for (m = 0; m < total_frames; m++)
    {
        frames[m] = -1;
    }

    for (n = 0; n < total_pages; n++)
    {
        printf("%d:\n", pages[n]);
        a = 0, b = 0;
        for (m = 0; m < total_frames; m++)
        {
            if (frames[m] == pages[n])
            {
                a = 1;
                b = 1;
                break;
            }
        }
        if (a == 0)
        {
            for (m = 0; m < total_frames; m++)
            {
                if (frames[m] == -1)
                {
                    frames[m] = pages[n];
                    b = 1;
                    page_fault++;
                    break;
                }
            }
        }
        if (b == 0)
        {
            for (m = 0; m < total_frames; m++)
            {
                temp[m] = 0;
            }
            for (k = n - 1, l = 1; l <= total_frames - 1; l++, k--)
            {
                for (m = 0; m < total_frames; m++)
                {
                    if (frames[m] == pages[k])
                    {
                        temp[m] = 1;
                    }
                }
            }
            for (m = 0; m < total_frames; m++)
            {
                if (temp[m] == 0)
                    position = m;
            }
            frames[position] = pages[n];
            page_fault++;
        }
        for (m = 0; m < total_frames; m++)
        {
            printf("%d\t", frames[m]);
        }
        printf("\n");
    }
    printf("\nTotal Number of Page Faults:\t%d\n", page_fault);
}

void Optimal(int pages[], int no_of_pages, int no_of_frames)
{
    int frames[20];
    int flag1, i, flag2, flag3, temp[10], j, k, pos, max, faults = 0;
    for (i = 0; i < no_of_frames; ++i)
    {
        frames[i] = -1;
    }

    for (i = 0; i < no_of_pages; ++i)
    {
        flag1 = flag2 = 0;

        for (j = 0; j < no_of_frames; ++j)
        {
            if (frames[j] == pages[i])
            {
                flag1 = flag2 = 1;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (j = 0; j < no_of_frames; ++j)
            {
                if (frames[j] == -1)
                {
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            flag3 = 0;

            for (j = 0; j < no_of_frames; ++j)
            {
                temp[j] = -1;

                for (k = i + 1; k < no_of_pages; ++k)
                {
                    if (frames[j] == pages[k])
                    {
                        temp[j] = k;
                        break;
                    }
                }
            }
            for (j = 0; j < no_of_frames; ++j)
            {
                if (temp[j] == -1)
                {
                    pos = j;
                    flag3 = 1;
                    break;
                }
            }
            if (flag3 == 0)
            {
                max = temp[0];
                pos = 0;

                for (j = 1; j < no_of_frames; ++j)
                {
                    if (temp[j] > max)
                    {
                        max = temp[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            faults++;
        }

        printf("\n");

        for (j = 0; j < no_of_frames; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }

    printf("\n\nTotal Page Faults = %d", faults);
}

int main()
{
    // Write C code here
    int pages;
    int *arr;
    int frames;
    printf("Enter the total number of pages \n");
    scanf("%d", &pages);

    printf("Enter the number of frames \n");
    scanf("%d", &frames);

    printf("Enter the pages \n");
    arr = (int *)malloc(pages * sizeof(int));

    for (int i = 0; i < pages; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Select the method to \n1)FIFO\n2)LRU\n3)OPtimal\n");
    int option;
    printf("Enter one option: ");

    scanf("%d", &option);

    if (option == 1)
    {
        fifo(arr, pages, frames);
    }
    else if (option == 2)
    {
        lru(arr, pages, frames);
    }
    else if (option == 3)
    {
        Optimal(arr, pages, frames);
    }
    else
    {
        printf("Select proper option!!!\n");
    }

    return 0;
}