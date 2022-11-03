#include <bits/stdc++.h>
using namespace std;

int main() {
    string ip, ipclass, head, mask,tail,s;
    int no_of_ip_addresses_possible;
    cout<<"Enter the ip address: "<<endl;
    cin>>ip;

    for(int i=0; i<3; i++)
    {
        head = head + ip[i];
    }
    int h = stoi(head);

    if(h>=0 && h<=127)
    {
        ipclass = 'A';
        mask = "255.0.0.0";
        no_of_ip_addresses_possible = 16777216;
    }
    else if(h>=128 && h<=191)
    {
        ipclass = 'B';
        mask = "255.255.0.0";
        no_of_ip_addresses_possible = 65536;
    }
    else if(h>=192 && h<=223)
    {
        ipclass = 'C';
        mask = "255.255.255.0";
        no_of_ip_addresses_possible = 256;
    }
    else if(h>=224 && h<=239)
    {
        ipclass = 'D';
    }
    else if(h>=240 && h<=255)
    {
        ipclass = 'E';
    }
    else
    {
        cout<<"Invalid! Range should be between 0 and 255"<<endl;
    }

    cout<<"\nNet id: "<<ip<<endl;
    cout<<"Class "<<ipclass<<endl;
    cout<<"No of ip addresses possible: "<<no_of_ip_addresses_possible<<endl;
    cout<<"Network Mask: "<<mask<<endl;

    int subnets;
    cout<<"\nEnter the no of subnets: "<<endl;
    cin>>subnets;
    int subnetip = no_of_ip_addresses_possible/subnets;
    cout<<"Total no of ip addresses possible in each subnet: "<<subnetip<<endl;

    cout<<"The no of bits in the subnet id: "<<log2(subnets)<<endl;
    for(int i = 12; i<15; i++)
        {
            tail = tail+ip[i];
        }

    for(int i = 0; i<12; i++)
        {
            s = s +ip[i];
        }

    int num = stoi(tail);
    int n = 000;
    int x = subnetip - 1;
    for(int i=0; i<subnets; i++)
    {
        cout<<"\nFor subnet "<<i+1<<endl;

        cout<<"Subnet address: "<<s+to_string(n)<<endl;

        cout<<"Broadcast address: "<<s+to_string(x)<<endl;

        cout<<"valid range: "<<endl;
        cout<<s+to_string(n+1)<<" to "<<s+to_string(x-1)<<endl;
        n = n + subnetip;
        x = x + subnetip;

    }


    return 0;
}
