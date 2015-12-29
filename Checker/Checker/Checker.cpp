// Checker.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

class Checker {
public:
	bool checkDuplicate(vector<int> a, int n) {
		// write code here
		if (a.size() <= 1)
		{
			return false;
		}
		heapSort(a, n);
		for (int i = 0; i < n - 1; ++i)
		{
			if (a[i] == a[i+1])
			{
				return true;
			}
		}
		return false;
	}

	void heapSort(vector<int> &a, int n) {
		// write code here
		for (int j = 0; j < n; ++j)
		{
			heapify(a, 0, n - j);
			swap(a[0], a[n - j - 1]);
		}
	}

	void heapify(vector<int> &a, int j, int n)
	{
		for (int i = n / 2 - 1; i >= j; i--)
		{
			int Left = 2 * i + 1;
			int Right = 2 * i + 2;
			int large = i;
			int cur = i;

			while (Left < n || Right < n)
			{
				if (Left < n && a[cur] < a[Left])
				{
					large = Left;
					if (Right < n && a[large] < a[Right])
					{
						large = Right;
					}
				}
				else if (Right < n && a[cur] < a[Right])
				{
					large = Right;
				}

				if (large != cur)
				{
					swap(a[cur], a[large]);
					cur = large;
					Left = 2 * cur + 1;
					Right = 2 * cur + 2;
				}
				else
				{
					break;
				}
			}
		}
	}

	void swap(int &a, int &b)
	{
		int temp = 0;
		temp = a;
		a = b;
		b = temp;
	}
};

int main()
{
	
	int b[1479] = { 5342, 6593, 1038, 5017, 3744, 1256, 7281, 5657, 639, 1244, 1364, 1222, 693, 4161, 243, 5064, 5749, 1330, 2865,
		707, 5652, 7095, 3718, 5744, 4923, 4301, 44, 850, 4091, 918, 2597, 1477, 3559, 7184, 5859, 2178, 1819, 3662,
		1037, 2137, 5088, 4050, 2905, 376, 1839, 7209, 3617, 2459, 1008, 164, 6947, 7148, 6730, 3051, 2723, 1912,
		3170, 3787, 7241, 7346, 1410, 4055, 2120, 5192, 2842, 1161, 4386, 1057, 4457, 350, 5575, 5772, 3878, 7128,
		7217, 4696, 6782, 6175, 602, 1813, 128, 4704, 4039, 7392, 793, 2161, 542, 5454, 2670, 932, 3928, 7398, 2065,
		6145, 668, 3458, 6954, 1920, 324, 1240, 3041, 3207, 510, 262, 4734, 2722, 6144, 1933, 2508, 2711, 5656, 5229,
		4223, 6075, 5515, 6794, 5660, 254, 1636, 5667, 7085, 1114, 3836, 2473, 4147, 4869, 4855, 4382, 5159, 509, 3214,
		6286, 4082, 6062, 4282, 6388, 1006, 4863, 3141, 3919, 3609, 2411, 5829, 4813, 2721, 4284, 4623, 2737, 6157, 3960,
		4262, 3379, 269, 2724, 7065, 4617, 4401, 2719, 4950, 5589, 4194, 1659, 7084, 581, 3579, 3545, 879, 6205, 112,
		3517, 4016, 5472, 4211, 3975, 6439, 4067, 6746, 2146, 216, 7272, 5334, 5947, 4013, 333, 3702, 5609, 297, 1431,
		3165, 848, 1204, 2009, 3287, 4041, 2750, 3914, 2102, 6454, 6732, 7033, 1380, 3171, 6674, 3929, 4460, 695, 3963,
		1085, 3242, 18, 121, 2114, 1891, 4751, 2181, 120, 5814, 5869, 3081, 6764, 3816, 3636, 365, 3568, 6472, 6505, 561,
		1863, 5936, 1540, 1221, 3243, 7227, 7166, 5466, 4560, 3112, 6255, 6955, 2538, 3866, 1718, 1756, 1011, 5960, 178,
		4631, 1383, 7121, 5292, 2298, 1587, 2314, 826, 5644, 959, 4854, 3215, 6236, 2556, 5366, 589, 6852, 4703, 2874,
		2030, 4660, 3931, 4612, 2134, 2790, 3703, 3782, 1107, 1589, 3452, 5571, 7160, 3101, 4958, 511, 1366, 2781, 843,
		3511, 103, 2085, 5157, 4680, 498, 2517, 5664, 5011, 4642, 2836, 6808, 4417, 1145, 4068, 7156, 550, 4028, 4852,
		1970, 2304, 3575, 7401, 2566, 313, 890, 7129, 2038, 6912, 1286, 3967, 1267, 3832, 2423, 7233, 5183, 5578, 429,
		7234, 1613, 2327, 7271, 2180, 3380, 3837, 4935, 5719, 3302, 407, 2755, 1667, 1304, 946, 364, 6201, 4903, 5085,
		5375, 4858, 6318, 7137, 2026, 3917, 6597, 6569, 334, 4940, 6566, 41, 3484, 1773, 6163, 4726, 6381, 1071, 5294,
		557, 2029, 6351, 5943, 5606, 4546, 6783, 3349, 1317, 2526, 7141, 529, 7152, 5412, 2980, 4773, 3710, 6923, 6779,
		4627, 2573, 4583, 6827, 46, 5501, 5752, 5401, 1218, 359, 5083, 2071, 1268, 4519, 2938, 1494, 6241, 2442, 6147,
		1283, 4895, 3158, 5003, 4488, 5798, 3886, 536, 5390, 970, 5861, 59, 1733, 4410, 2999, 3724, 5044, 5980, 2378,
		625, 4337, 4698, 3339, 4880, 321, 4214, 2732, 4087, 11, 6982, 5242, 1344, 5807, 4778, 3354, 4595, 7005, 1654,
		2374, 1166, 1120, 6501, 1481, 2242, 5598, 1519, 1299, 2562, 5678, 4098, 3460, 5766, 150, 1710, 3037, 6180, 3124,
		1156, 2424, 1191, 5913, 466, 6167, 6981, 3918, 4832, 6458, 2636, 1947, 2983, 1353, 3751, 4633, 6548, 5617, 1199,
		2567, 5691, 1216, 2543, 3074, 1583, 6489, 6419, 2596, 5189, 384, 5054, 6585, 4264, 7431, 5200, 62, 5063, 2031,
		2785, 4273, 835, 1443, 1874, 341, 1035, 3681, 477, 5614, 5653, 2335, 2557, 1314, 1523, 2817, 1522, 902, 4008,
		7377, 3, 3140, 1909, 3016, 4002, 6952, 5648, 1332, 2531, 4413, 2250, 7017, 5397, 6618, 1083, 6360, 590, 2834,
		6171, 1446, 6017, 3347, 2032, 2150, 66, 2669, 4603, 2127, 6570, 5761, 6735, 4461, 3295, 303, 2040, 6824, 1154,
		924, 4531, 1205, 2088, 3110, 4385, 4799, 1173, 6024, 5288, 5136, 6391, 790, 931, 2213, 1685, 3672, 1515, 2123,
		2821, 147, 6443, 5374, 1918, 4356, 5863, 5402, 7416, 4542, 5458, 5879, 7308, 7049, 2823, 3490, 5596, 266, 2609,
		6575, 5742, 1997, 6178, 2212, 820, 4942, 7229, 654, 5028, 5012, 4344, 4004, 5001, 165, 6878, 7253, 4473, 1550,
		773, 5419, 6067, 125, 1397, 1044, 1642, 438, 5732, 5892, 1547, 3570, 5425, 6810, 5714, 3146, 6877, 3216, 7312,
		5432, 1432, 4816, 5797, 2953, 6320, 4114, 7423, 7098, 3391, 2130, 256, 6095, 7264, 3013, 1741, 1287, 4359, 5622,
		2499, 105, 4210, 2878, 2518, 2268, 1371, 855, 4122, 3191, 347, 4505, 5287, 1618, 7325, 3371, 7262, 2096, 382, 5973,
		5267, 1838, 2546, 1848, 6629, 3927, 455, 77, 4918, 3325, 5150, 4492, 886, 394, 7074, 5349, 5740, 923, 1953, 1225,
		6667, 2153, 144, 3311, 3097, 3213, 3472, 2093, 7175, 5917, 7140, 1649, 2398, 6152, 273, 3009, 5013, 2301, 3903,
		2333, 6063, 2959, 3415, 673, 2010, 6819, 1164, 4153, 132, 6471, 964, 7070, 2494, 2590, 1810, 3479, 5963, 1588,
		99, 2471, 3522, 564, 5870, 967, 6105, 1684, 4483, 3388, 4474, 7385, 6626, 3229, 2845, 705, 4975, 3846, 5690, 4023,
		2613, 2560, 3795, 5899, 2307, 5238, 6281, 4276, 5363, 592, 5487, 4738, 4897, 1142, 489, 4340, 4785, 1977, 6169,
		6200, 4886, 356, 7177, 432, 4525, 6695, 1201, 2199, 657, 3254, 2743, 1016, 6270, 4057, 2062, 463, 1941, 5746,
		5925, 6218, 2890, 800, 5195, 2468, 1576, 111, 6895, 7408, 3762, 1842, 6213, 1137, 2571, 3293, 797, 2177, 1712,
		2988, 6115, 6137, 1562, 1614, 2044, 6287, 4440, 2236, 1901, 4404, 4498, 6996, 2689, 738, 7257, 3281, 2780, 4662,
		6631, 6812, 2697, 4246, 5093, 5072, 5645, 916, 4155, 6315, 414, 268, 5212, 519, 2639, 2747, 204, 5202, 3280, 2985,
		5208, 6037, 5488, 3760, 2395, 3896, 4700, 6475, 4961, 1740, 1207, 6709, 3509, 1328, 5918, 4088, 1318, 6689, 1572,
		1688, 2296, 5825, 3431, 277, 6507, 1394, 7053, 736, 6998, 1955, 4373, 1474, 4764, 6557, 2064, 2975, 1013, 5651,
		149, 4452, 4218, 3708, 4748, 5070, 1157, 2646, 6911, 379, 758, 7001, 137, 9, 591, 7317, 2117, 1249, 4346, 2046,
		632, 7283, 6104, 4929, 6965, 4960, 3989, 6007, 7208, 3119, 5568, 2136, 6969, 2544, 1264, 6972, 404, 7179, 6530,
		6082, 4358, 2638, 4330, 6785, 2837, 1558, 6493, 4079, 1527, 7407, 6511, 2053, 1065, 1581, 2977, 4599, 7294, 2655,
		1786, 6860, 5180, 614, 2873, 1354, 4737, 4233, 2322, 3704, 1697, 513, 5323, 2709, 5733, 1887, 4060, 5692, 7414,
		416, 6131, 844, 159, 6332, 7164, 6938, 2854, 5522, 5236, 752, 7363, 2958, 5771, 4697, 5127, 7194, 5969, 5997, 6289,
		5802, 5795, 2712, 2891, 7372, 915, 395, 339, 157, 775, 6076, 2593, 618, 4165, 5543, 5590, 3606, 2814, 3300, 6372,
		1812, 3761, 4251, 3987, 7314, 36, 2936, 5629, 3159, 812, 5424, 3696, 3139, 5265, 6932, 7252, 5115, 6041, 4713,
		3390, 38, 5837, 5737, 1845, 4567, 689, 5313, 5380, 1313, 3924, 2690, 2727, 238, 4487, 607, 6703, 4033, 3826, 245,
		4341, 1979, 3548, 224, 1911, 1923, 5774, 1464, 6012, 3449, 5089, 5496, 7172, 2313, 6025, 3323, 5662, 1090, 6542,
		6851, 162, 5750, 3801, 4619, 4984, 6141, 5057, 5260, 3869, 1169, 2558, 7187, 5756, 6330, 2829, 4335, 2648, 210,
		5138, 1465, 3202, 4616, 4676, 2510, 6503, 3092, 2875, 1766, 1936, 5637, 3091, 2011, 6279, 5049, 4646, 5478, 3467,
		5745, 1526, 4220, 6276, 709, 6761, 1215, 4128, 4733, 2045, 6935, 4675, 4465, 7064, 5264, 389, 43, 5023, 7278, 7041,
		6614, 4117, 1638, 3677, 6371, 3507, 2580, 261, 5014, 5413, 4425, 2249, 3488, 411, 875, 3443, 508, 3424, 2425, 5722,
		4503, 1598, 2200, 5711, 7225, 4873, 2742, 3743, 7309, 5440, 3222, 2765, 6512, 1062, 2259, 1788, 57, 3163, 5384,
		1787, 5319, 5962, 865, 7212, 2943, 6297, 1496, 2237, 6889, 4747, 4577, 7068, 3615, 4300, 367, 26, 2563, 10, 3621,
		4722, 5449, 6301, 4970, 2013, 2319, 7430, 4384, 3904, 6745, 5367, 5612, 7055, 2080, 3029, 3453, 4347, 2682, 6473,
		6784, 7389, 3961, 2430, 584, 966, 1508, 6551, 2657, 3717, 4196, 3990, 4824, 870, 1435, 4255, 6562, 2262, 6721,
		1758, 3528, 3355, 4320, 229, 1043, 6728, 6951, 5674, 4797, 1108, 2703, 824, 2516, 6153, 4590, 6715, 1342, 2290,
		494, 5060, 6664, 5141, 4618, 7374, 4580, 1724, 3053, 3304, 2541, 7349, 2533, 3384, 6611, 5783, 4375, 6449, 907,
		4639, 817, 6866, 2574, 4821, 7151, 3366, 815, 4378, 740, 188, 48, 3608, 4152, 6021, 2435, 3297, 4198, 2210, 658,
		2099, 5420, 1999, 1622, 6950, 2744, 5706, 7081, 4085, 1987, 747, 3489, 4245, 3603, 7126, 1988, 7195, 4150, 2800,
		7412, 3808, 4239, 7259, 4167, 691, 2922, 5865, 353, 2076, 1500, 5853, 1420, 5975, 6809, 7267, 6775, 3872, 3320,
		2341, 906, 1875, 1184, 5930, 4348, 7171, 1384, 5847, 3818, 3052, 4304, 4959, 241, 5977, 1764, 40, 1967, 1802, 1549,
		6039, 6402, 3455, 4001, 2475, 4256, 3860, 6174, 770, 3368, 2054, 833, 6252, 1460, 2879, 6242, 5566, 3632, 3626,
		4368, 1723, 2028, 2487, 4527, 893, 5672, 1505, 5935, 2860, 1905, 4917, 4850, 535, 1337, 4059, 6379, 1219, 540,
		7147, 3652, 3566, 6949, 5615, 3648, 42, 690, 1358, 1511, 6077, 5196, 6953, 3473, 7260, 823, 2020, 3228, 3470,
		6523, 1029, 4711, 4749, 4846, 2528, 4859, 5602, 638, 2797, 422, 1868, 4609, 4266, 6729, 4931, 4507, 4776, 2275,
		1381, 3127, 1615, 3955, 6349, 847, 1254, 3137, 6050, 1880, 7094, 2521, 6359, 3224, 3723, 7086, 1580, 4321, 880,
		4801, 5348, 257, 3843, 3746, 2116, 5276, 6452, 4445, 3551, 1560, 2700, 528, 4769, 3730, 814, 3252, 5882, 6600,
		2608, 1493, 1689, 5979, 617, 2057, 2052, 430, 987, 5984, 6433, 4673, 6085, 3152, 2714, 5524, 3790, 5585, 640,
		1561, 5876, 2568, 5007, 1175, 1907, 5663, 3151, 4829, 648, 310, 5914, 6803, 5881, 577, 4102, 7422, 3109, 3345,
		1306, 3825, 2948, 474 };

	vector<int> init_Array;
	for (int i = 0; i < 1479; ++i)
	{
		init_Array.push_back(b[i]);
	}

	Checker sort;
	bool result = true;
	result = sort.checkDuplicate(init_Array, init_Array.size());
	for (int i = 0; i < init_Array.size(); ++i)
	{
		cout << init_Array[i] << endl;
	}
	return 0;
}