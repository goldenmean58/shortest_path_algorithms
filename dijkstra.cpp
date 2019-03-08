/******************************************************************
 * FileName : dijkstra.cpp
 * Author   : Lishuxiang
 * E-mail   : lishuxiang@cug.edu.cn
 * Time     : Wed 16 Jan 2019 07:29:14 PM CST
 * Function : 
******************************************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::make_heap;
using std::pop_heap;
using std::sort_heap;
#define MAX_ELE 100
#define INFINITE 65535

int main(void)
{
	int vertexNum = 0, edgeNum = 0;
	cout << "顶点数:";
	cin >> vertexNum;							// 输入结点数与边数
	cout << "边数:";
	cin >> edgeNum;
	int edgeMatrix[vertexNum][vertexNum];
	for (int i = 0; i < vertexNum; i++) {	//初始化邻接矩阵
		for (int j = 0; j < vertexNum; j++) {
			edgeMatrix[i][j] = i == j ? 0 : INFINITE;	//对角线权值为0 其余为无穷大
		}
	}
	cout << "边数据(边起点 边终点 权值):" << endl;
	for (int i = 0; i < edgeNum; i++) {
		int va, vb, value;
		cin >> va >> vb >> value;		//a点到b点的边的权值为value
		edgeMatrix[va][vb] = value;
	}
	int s = 0;
    int e = 0;
	int dis[vertexNum];						//起点到各个结点的距离
	bool vis[vertexNum];					//访问标志
    int pre[vertexNum]; //前驱结点用于倒序输出终点到起点的最短路径
	for (int i = 0; i < vertexNum; i++) {
		dis[i] = INFINITE;
		vis[i] = false;
        pre[i] = 0;
	}
	cout << "起点:";
	cin >> s;
    cout << "终点:";
    cin >> e;
	int v = s;
	dis[s] = 0;
	vis[s] = true;
	int min_path = 0;
	int min = INFINITE;
	do {
		for (int i = 0; i < vertexNum; i++) {	//松弛相邻结点
			if (dis[i] > dis[v] + edgeMatrix[v][i]) {
				dis[i] = dis[v] + edgeMatrix[v][i];
                pre[i] = v; //记录最终松弛前驱结点
			}
		}
		min = INFINITE;
		for (int i = 0; i < vertexNum; i++) {	//找最小的没被访问过的结点作为下一结点
			if (dis[i] <= min && !vis[i]) {
				min_path = i;
				min = dis[i];
			}
		}
		vis[v] = true;
		v = min_path;
	} while (min != INFINITE);		//能找到下一结点
    cout << "起点到各结点的最短路径长度:"<<endl;
	for (int i = 0; i < vertexNum; i++) {
		if (dis[i] == INFINITE)
			cout << "+∞" << " ";
		else
			cout << dis[i] << " ";
	}
    cout << endl;
    cout << "起点到终点的最短路径:"<<endl;
	for (int i = 0; i < vertexNum; i++) {
        cout << pre[i] << " ";
    }
	cout << endl;
	return 0;
}
