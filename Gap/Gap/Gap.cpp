// Gap.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Gap {
public:
	int maxGap(vector<int> A, int n)
	{
		// write code here
		int MAX = A[0];
		int MIN = A[0];
		for (int i = 0; i < n; ++i)
		{
			if (A[i] < MIN)
			{
				MIN = A[i];
			}
			if (A[i] > MAX)
			{
				MAX = A[i];
			}
		}

		double GAP = (double)(MAX - MIN) / n;
		vector<int> *B = new vector<int>[n + 1];

		for (int i = 0; i < n; ++i)
		{
			int num = (A[i] - MIN) / GAP;
			B[num].push_back(A[i]);
		}

		int max_temp1 = B[0][0];
		int min_temp1 = B[0][0];
		int max_temp2 = 0;
		int min_temp2 = 0;
		int max_Gap = 0;
		int count = 0;
		while (count < n + 1)
		{
			if (B[count].size() != 0)
			{
				max_temp2 = B[count][0];
				min_temp2 = B[count][0];
				for (int j = 0; j < B[count].size(); ++j)
				{
					if (B[count][j] > max_temp2)
					{
						max_temp2 = B[count][j];
					}
					if (B[count][j] < min_temp2)
					{
						min_temp2 = B[count][j];
					}
				}

				if (max_Gap <= min_temp2 - max_temp1)
				{
					max_Gap = min_temp2 - max_temp1;
				}

				max_temp1 = max_temp2;
				min_temp1 = min_temp2;
			}
			count++;
		}
		return max_Gap;
	}
};

int main()
{
	int temp[260] = { 7236,7022,857,3633,8052,8670,6025,6722,9050,1464,1985,5145,4158,
		2759,2251,6613,7240,7237,2812,5426,9237,8510,4462,8341,9984,9002,9841,1785,5057,
		1758,6434,4778,4503,6586,8959,2465,1063,8876,6550,7477,4167,7278,7763,5784,4503,
		5382,5517,9327,3678,2241,6545,4055,9752,9152,294,673,8604,1312,51,2043,985,3502,
		9493,7638,1041,9668,3814,7048,2219,7302,6935,6530,8385,266,7274,4320,3706,8997,
		8677,3120,4108,3244,1714,6256,692,2520,8992,9592,6842,8453,9377,7946,4003,6749,
		2447,5742,9412,3221,3900,6691,2023,9660,5919,8725,8825,8800,4708,2749,1716,1342,
		2896,7831,5933,1232,8043,2272,6286,8109,1840,2498,4808,7210,7670,6795,2888,8614,
		8395,8054,1603,5407,7999,2381,1536,1102,3294,7421,6841,3477,7480,1387,6407,7497,
		8654,2062,2507,7873,2468,8496,3483,9336,1593,7200,3378,1782,5630,6036,7417,5387,
		2253,5938,5413,5885,2949,8468,7723,8868,3821,9940,2956,5707,3085,8281,6311,684,
		3800,989,3064,8125,8691,141,7685,5360,1805,9913,4696,5534,2338,7751,3283,216,
		7433,3854,3756,6657,377,7736,6793,8627,7789,7607,5498,4610,744,9038,2000,9819,
		6848,2761,8394,7388,6756,4828,8652,3564,6302,7058,5714,342,4418,5309,5624,4894,
		6098,8234,5059,5684,5983,8042,6172,4193,1446,8928,9738,781,2773,2777,761,6002,
		4616,1694,7154,1362,2893,8051,2302,1766,5894,4569,5255,7438,9095,6043,3339,5159,
		3373,7833,6126,2821,1357,2815 };
	vector<int> init_Array;
	for (int i = 0; i < 260; ++i)
	{
		init_Array.push_back(temp[i]);
	}
	int B = 0;
	Gap gap;
	B = gap.maxGap(init_Array, init_Array.size());

	cout << B << endl;

	return 0;
}
