#include<bits/stdc++.h>
using namespace std;

#define PI acos(-1)
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'

typedef long long int ll;
typedef unsigned long long int llu;

typedef vector<ll> vii;
typedef vector<int> vi;

int Binary_search(int arr[],int low,int high,int sv)
{

    while(low<=high)
    {
        int mid= (low+high)/2;

        if(arr[mid]==sv) return mid;

        else if(arr[mid]<sv) low = mid+1;

        else high= mid-1;
    }
    return -1;
}

int main()
{
    int s;
    cout<<"Enter the size of Array: ";
    cin>>s;
    int arr[s];
    cout<<"Enter the value of array: ";
    for(int i=0;i<s;i++)
    {
        cin>>arr[i];
    }
    cout<<"Array is: ";
    for(int i=0;i<s;i++)
    {
        cout<<arr[i]<<" ";
    }

    int len = sizeof(arr)/sizeof(arr[0]);
    int sv;
    cout<<endl<<"Enter the Searching Value of array: ";
    cin>>sv;
    int position= Binary_search(arr,0,len,sv);

    if(position != -1)
    cout<<sv<<" is present at index "<<position+1<<endl;
    else cout<<sv<<" is not present in Array"<<endl;

    //cout<<endl<<PI<<endl;
return 0;
}
