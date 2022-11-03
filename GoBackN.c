#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
    int seq_bits;
    printf("Enter the number of bits in the sequence number : ");
    scanf("%d",&seq_bits);

    int send_wind_size = ((int)(pow(2,seq_bits)))-1;

    int frames;

    printf("\n\nEnter the number of frames you want to transmit : ");
    scanf("%d",&frames);

    int *assn_seq;

    assn_seq = (int *)malloc(frames*sizeof(int));

    int i,count=0;

    for(i=0;i<=frames-1;i++)
    {
        assn_seq[i]=count;
        count++;
        if(count==send_wind_size+1)
        {
            count=0;
        }

    }
    printf("\n\nFrame array with assigned sequence numbers : \n");
    for(i=0;i<=frames-1;i++)
    {
        printf("%d ",*(assn_seq+i));
    }

    //transmitting part

    int j,frame_no=1,ack,count1;

    printf("\n\nInitial sending window is : \n");
    while(frame_no<=frames)
    {
        for(j=0;j<=send_wind_size-1;j++)
        {
            printf("\n\nTransmitting frame number %d with sequence number %d",frame_no,assn_seq[frame_no-1]);
            frame_no++;
            if(frame_no==frames+1)
            {
                break;
            }
            else
            {
                printf("\nIn the receiving window, sequence number expected is : %d",assn_seq[frame_no-2]);
            }
        }

        //assuming ack doesn't get lost

        printf("\n\n\nEnter Acknowledgement number (receiver's side sends a sequence number to the sender indicating the last frame it has received correctly): ");
        scanf("%d",&ack);



        int compare=frame_no-send_wind_size;

        while(compare<=frame_no)
        {
            if(assn_seq[compare-1]==ack)
            {
                frame_no=compare+1;
                break;
            }
            compare++;
        }
        if(frame_no!=frames+1)
        {
            printf("\nIn the receiving window, sequence number now expected is : %d",assn_seq[frame_no-1]);

            printf("\n\n\nNext Iteration : \n");

        }
    }

    printf("\n\nAll frames have been received successfully\n\n");




}
