#include<iostream>
int menu();
void llenar(int m[][6], int ven, int pro, int total);
void mostrar(int m[][6], int rt);
void mostrar(int m[][6], int rt);
void producto(int m[][6], int rt);
void vendedor(int m[][6], int rt);
using namespace std;
int main () {
    int op, m[5][6]={0}, v,p,t;

    do
    {
        op=menu();

        switch(op)
        {
        case  1:

            cout<<"Numero del vendedor"<<endl;
            cin>>v;
            cout<<"Numero del producto"<<endl;
            cin>>p;
            cout<<"Cantidad vendida"<<endl;
            cin>>t;

            llenar(m,v,p,t);

            break;

        case 2:
            producto(m,5);
            vendedor(m,5);
            mostrar(m,5);

            break;
        }
    }
    while(op!=0);

    return 0;
}

int menu()
{
    cout<<"1. Llenar"<<endl;
    cout<<"2.Mostrar"<<endl;

    int m;

    cin>>m;

    return m;
}

void llenar(int m[][6], int ven, int pro, int total)
{
    if(pro<=5 && ven<=4)
    {
        m[ven-1][pro-1]+=total;
    }
    else
    {
        cout<<"No existe ese vendedor o producto"<<endl;
    }
}

void mostrar(int m[][6], int rt)
{

    for(int v=0; v<rt; v++)
    {
        cout<<"\nVendedor"<<v<<":"<<" ";
        for(int p=0; p<6; p++)
        {
            cout<<m[v][p]<<"\t";
        }
        cout<<endl;
    }
}

void vendedor(int m[][6], int rt)
{
    int con=0;
    for(int r=0; r<rt-1; r++)
    {
        m[r][rt]=0;
        for(int c=0; c<rt; c++)
        {
            m[r][rt]+=m[r][c];
        }
    }
}

void producto(int m[][6], int rt)
{
    int resultado=0;
    for(int c=0; c<5; c++)
    {
        m[rt-1][c]=0;
        for(int r=0; r<rt-1; r++)
        {
            m[rt-1][c]+=m[r][c];
        }
    }
}

