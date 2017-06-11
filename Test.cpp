#include "Test.h"

int** _initGraph(int size)
{
    int **answer = new int* [size];
    for(int i=0;i<size;i++)
    {
        answer[i]=new int[size];
        for(int j=0;j<size;j++)
        {
            answer[i][j]=-1;
        }
    }
    return answer;
}

bool compare(int**g1, int**g2, int size)
{
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            if(g1[i][j]!=g2[i][j])
                return false;
    return true;
}

void test()
{
    int** g1 = _initGraph(5);
    g1[0][1]=4;
    g1[1][0]=4;

    g1[0][2]=2;
    g1[2][0]=2;

    g1[1][2]=4;
    g1[2][1]=4;

    g1[1][3]=6;
    g1[3][1]=6;

    g1[2][3]=8;
    g1[3][2]=8;

    g1[1][4]=6;
    g1[4][1]=6;

    g1[3][4]=9;
    g1[4][3]=9;

    vector<Edge*>e1;
    e1.push_back(new Edge(0,2,2));
    e1.push_back(new Edge(0,1,4));
    e1.push_back(new Edge(1,2,4));
    e1.push_back(new Edge(1,3,6));
    e1.push_back(new Edge(1,4,6));
    e1.push_back(new Edge(2,3,8));
    e1.push_back(new Edge(3,4,9));

    int** r1 = _initGraph(5);
    r1[0][1]=4;
    r1[0][2]=2;
    r1[1][0]=4;
    r1[1][3]=6;
    r1[1][4]=6;
    r1[2][0]=2;
    r1[3][1]=6;
    r1[4][1]=6;

    int **a1=getKruskalMST(g1,5,e1);

    int** g2 = _initGraph(5);
    g2[3][0]=13;
    g2[0][3]=13;

    g2[3][1]=13;
    g2[1][3]=13;

    g2[3][2]=19;
    g2[2][3]=19;

    g2[3][4]=19;
    g2[4][3]=19;

    g2[0][1]=24;
    g2[1][2]=24;

    g2[1][2]=22;
    g2[2][1]=22;

    g2[0][4]=22;
    g2[4][0]=22;

    g2[0][2]=13;
    g2[2][0]=13;

    g2[1][4]=13;
    g2[4][1]=13;

    g2[2][4]=14;
    g2[4][2]=14;

    vector<Edge*>e2;
    e2.push_back(new Edge(3,0,13));
    e2.push_back(new Edge(3,1,13));
    e2.push_back(new Edge(0,2,13));
    e2.push_back(new Edge(1,4,13));

    e2.push_back(new Edge(2,4,14));

    e2.push_back(new Edge(3,2,19));
    e2.push_back(new Edge(3,4,19));

    e2.push_back(new Edge(2,1,22));
    e2.push_back(new Edge(0,4,22));

    e2.push_back(new Edge(0,1,24));

    int **a2=getKruskalMST(g2,5,e2);

    int** r2 = _initGraph(5);
    r2[3][0]=13;
    r2[0][3]=13;

    r2[3][1]=13;
    r2[1][3]=13;

    r2[0][2]=13;
    r2[2][0]=13;

    r2[1][4]=13;
    r2[4][1]=13;

    if(a1 && a2
       && compare(a1,r1,5)
        && compare(a2,r2,5))
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
