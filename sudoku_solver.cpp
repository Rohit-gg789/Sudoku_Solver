#include<iostream>

bool fill();
bool checkRows(int r);
bool checkColumns(int c);
void display();
bool checkbox(int i, int j);
bool checkfork(int r,int c,int k);
bool check(int r,int c);
void input();


int a[9][9] = {0};


int main()
{
    std::cout<<"*******************************************************\n";
    std::cout<<"****************** SUDOKU SOLVER **********************\n";
    std::cout<<"*******************************************************\n";
    std::cout<<'\n';
    
    input();

    if(fill())
    {
        display();
    }
    else
    {
        std::cout<<"invalid input";
    }
    return 0;
}

bool fill()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[i][j]==0)
            {
                for(int k=1;k<10;k++)
                {
                    if(checkfork(i,j,k))
                    {
                        if(fill())
                        {
                            return true;
                        }
                        else
                        {
                            a[i][j]=0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool checkRows(int r)
{
    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(a[r][i]==a[r][j] && a[r][i]!=0 && a[r][j]!=0)
            {
                return false;
            }
        }
    }
    return true;
}

bool checkColumns(int c)
{
    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(a[i][c]==a[j][c] && a[i][c]!=0 && a[j][c]!=0)
            {
                return false;
            }
        }
    }
    return true;
}

bool checkbox(int i, int j)
{
    if(i>=0 && i<=2 && j>=0 && j<=2)
    {
        for(int k=0;k<=2;k++)
        {
            for(int l=0;l<=2;l++)
            {
                if(a[i][j]==a[k][l] && i!=k && j!=l)
                {
                    return false;
                }
            }
        }
    }

    else if(i>=0 && i<=2 && j>=3 && j<=5)
    {
        for(int k=0;k<=2;k++)
        {
            for(int l=3;l<=5;l++)
            {
                if(a[i][j]==a[k][l] && i!=k && j!=l)
                {
                    return false;
                }
            }
        }
    }

    else if(i>=0 && i<=2 && j>=6 && j<=8)
    {
        for(int k=0;k<=2;k++)
        {
            for(int l=6;l<=8;l++)
            {
                if(a[i][j]==a[k][l] && i!=k && j!=l)
                {
                    return false;
                }
            }
        }
    }

    else if(i>=3 && i<=5 && j>=0 && j<=2)
    {
        for(int k=3;k<=5;k++)
        {
            for(int l=0;l<=2;l++)
            {
                if(a[i][j]==a[k][l] && i!=k && j!=l)
                {
                    return false;
                }
            }
        }
    }

    else if(i>=3 && i<=5 && j>=3 && j<=5)
    {
        for(int k=3;k<=5;k++)
        {
            for(int l=3;l<=5;l++)
            {
                if(a[i][j]==a[k][l] && i!=k && j!=l)
                {
                    return false;
                }
            }
        }
    }

    else if(i>=3 && i<=5 && j>=6 && j<=8)
    {
        for(int k=3;k<=5;k++)
        {
            for(int l=6;l<=8;l++)
            {
                if(a[i][j]==a[k][l] && i!=k && j!=l)
                {
                    return false;
                }
            }
        }
    }

    else if(i>=6 && i<=8 && j>=0 && j<=2)
    {
        for(int k=6;k<=8;k++)
        {
            for(int l=0;l<=2;l++)
            {
                if(a[i][j]==a[k][l] && i!=k && j!=l)
                {
                    return false;
                }
            }
        }
    }

    else if(i>=6 && i<=8 && j>=3 && j<=5)
    {
        for(int k=6;k<=8;k++)
        {
            for(int l=3;l<=5;l++)
            {
                if(a[i][j]==a[k][l] && i!=k && j!=l)
                {
                    return false;
                }
            }
        }
    }
    
    else if(i>=6 && i<=8 && j>=6 && j<=8)
    {
        for(int k=6;k<=8;k++)
        {
            for(int l=6;l<=8;l++)
            {
                if(a[i][j]==a[k][l] && i!=k && j!=l)
                {
                    return false;
                }
            }
        }
    }

    return true;
}

void display()
{
    std::cout<<'\n';
    std::cout<<"-------------------------------------------------------";
    std::cout<<'\n';
    for(int i=0;i<9;i++)
    {
        std::cout<<"|  ";
        for(int j=0;j<9;j++)
        {
            std::cout<<a[i][j]<<"  |  ";
        }
        std::cout<<'\n';
        std::cout<<"-------------------------------------------------------";
        std::cout<<'\n';
    }
    std::cout<<'\n';
}

bool checkfork(int r,int c, int k)
{
    a[r][c]=k;
    if(checkRows(r) && checkColumns(c) && checkbox(r,c))
    {
        return true;
    }
    else
    {
        a[r][c]=0;
        return false;
    }
}

bool check(int r,int c)
{
    if(checkRows(r) && checkColumns(c) && checkbox(r,c))
    {
        return true;
    }
    return false;
    
}

void input()
{
    char ans;
    do
    {
        int r,c,v;
        std::cout<<"Enter the coordinates\n";
        std::cout<<"Enter row (1-9): ";
        std::cin>>r;
        r--;
    
        std::cout<<"Enter column (1-9): ";
        std::cin>>c;
        c--;

        std::cout<<"Enter the value: ";
        std::cin>>v;
        a[r][c] = v;

        std::cout<<"wanna add more(y/n): ";
        std::cin>>ans;
    }
    while(ans=='y');
    std::cout<<'\n';
}