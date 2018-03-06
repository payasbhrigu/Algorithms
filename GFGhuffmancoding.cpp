#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
typedef struct node
{
    struct node*left,*right;
    char data;
    int freq;
}node;
node* arr[100];
node* newarr[100];
int n,len=0;
int minheapify(int i)
{
    int s=i;
    int l=2*i+1,r=2*i+2;
    if(l<n&&arr[l]->freq<arr[s]->freq)
        s=l;
    if(r<n&&arr[r]->freq<arr[s]->freq)
        s=r;
    if(s!=i)
        {
            node* p=arr[i];
            arr[i]=arr[s];
            arr[s]=p;
            minheapify(s);
        }
    if(l<n&&r<n&&arr[l]->freq>arr[r]->freq)
    {
            node* p=arr[l];
            arr[l]=arr[r];
            arr[r]=p;
            minheapify(l);
            minheapify(r);
    }
    return 0;
}

node* extractMin()
{
    node*p=arr[0];
    arr[0]=arr[n-1];
    n--;
    minheapify(0);
    return p;
}

int buildheap()
{
    int i;
    for(i=(n-1)/2;i>=0;i--)
        minheapify(i);
    /*for(i=0;i<n;i++)
        cout<<arr[i]->data<<' '<<arr[i]->freq<<'\n';*/
    return 0;
}

node* buildminheap()
{
    while(n>1)
    {
        node*l=extractMin();
        node*r=extractMin();
        n++;
        node*temp=(node*)malloc(sizeof(node));
        temp->left=l;temp->right=r;
        arr[n-1]=temp;
        arr[n-1]->freq=l->freq+r->freq;
        arr[n-1]->data='$';
        buildheap();
    }
    return extractMin();
}

int printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", a[i]);

    printf("\n");
    return 0;
}

int printCodes(node* root, int a[], int top)
{
    if (root->left) {

        a[top] = 0;
        printCodes(root->left, a, top + 1);
    }
    if (root->right) {

        a[top] = 1;
        printCodes(root->right, a, top + 1);
    }

    if (root->left==NULL&&root->right==NULL) {

        printf("%c: ", root->data);
        printArr(a, top);
    }
    return 0;
}

int huffman()
{
    buildheap();
    node*root=buildminheap();
    int a[100],top=0;
    printCodes(root,a,top);
    return 0;
}

int main()
{
    string s;
    getline(cin,s);
    //cout<<s<<'\n';
    m.insert(pair<char,int>('@',0));
    int i=0;
    map<char,int>::iterator it;
    while(s[i]!='\0')
    {
        it=m.find(s[i]);
        if(it==m.end()&&s[i]!=' ')
        {
            int c=count(s.begin(),s.end(),s[i]);
            m.insert(pair<char,int>(s[i],c));
        }
        if(s[i]==' ')
        m['@']+=1;
        i++;
    }
    i=0;
    for(it=m.begin();it!=m.end();++it)
        {
            //cout<<it->first<<' '<<it->second<<'\n';
            node *p=(node*)malloc(sizeof(node));
            p->data=it->first;
            p->freq=it->second;
            p->left=p->right=NULL;
            //cout<<p<<'\n';
            arr[i++]=p;
        }
    n=i;
    /*for(i=0;i<n;i++)
        cout<<arr[i]->data<<' '<<arr[i]->freq<<'\n';*/
    huffman();
    return 0;
}
//huuffffmaannnnncccod
//aaaaabbbbbbbbbccccccccccccdddddddddddddeeeeeeeeeeeeeeeefffffffffffffffffffffffffffffffffffffffffffff
