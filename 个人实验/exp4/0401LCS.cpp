//求最长公共子序列 
#include <iostream> 
#include <utility> 
#include <vector> 
#include <algorithm> 
using namespace std;

void getLCS(string S1, string S2)
{
    int L1 = S1.length();
    int L2 = S2.length();

    int C[L2 + 1][L1 + 1] ;
    
    for(int i = 0; i < L2 + 1; i++)//初始化 第一行第一列代表与空串的LCS，一定是0 
    	C[i][0] = 0;
    for(int i = 0; i < L1 + 1; i++)
    	C[0][i] = 0;   	
    	
    for (int i = 1; i <= L1; i++)//填LCS表格 
    {
        for (int j = 1; j <= L2; j++)
        {
            if (S1[i - 1] == S2[j - 1])
            {
                C[i][j] = C[i - 1][j - 1] + 1;
            }
            else
            {
                C[i][j] = max(C[i][j - 1], C[i - 1][j]);
            }
        }
    }
    
    for(int i = 0; i < L1 + 1; i++)
    {
    	for(int j = 0; j < L2 + 1; j++)
    	{
    		//cout << C[i][j] << "  ";
		}
		//cout << "\n";
	}
	
    string LCS = "";

    while (L1 != 0)
    {
        if (C[L1][L2] == C[L1 - 1][L2])
        {
            L1--;
            continue;
        }
        if (C[L1][L2] == C[L1][L2 - 1])
        {
            L2--;
            continue;
        }
        if (C[L1][L2] == C[L1 - 1][L2 - 1] + 1)
        {
            LCS += S1[L1 - 1];
            L1--;
            L2--;
        }
    }

    reverse(LCS.begin(), LCS.end());
    cout << "\n\n最长公共子序列是："<< LCS << endl;
}

int main()
{
//	string S1, S2;
//	cin >> S1;
//	cin >> S2;

//    string S1 = "ABCPDSFJGODIHJOFDIUSHGD";
//    string S2 = "OSDIHGKODGHBLKSJBHKAGHI";
// 
//	string S1 = "SHFFAHTUFQED";
//    string S2 = "OSDFHAURRQDE";  
    	string S1 = "ABACAD";
    string S2 = "ABCD"; 
	getLCS(S1, S2);
} 

