/******************************************************************
 * FileName : spfa.cpp
 * Author   : Lishuxiang
 * E-mail   : lishuxiang@cug.edu.cn
 * Time     : Wed 16 Jan 2019 06:45:43 PM CST
 * Function : 
******************************************************************/

#include<iostream>
#include<queue>
#define INFINITE 65535					//定义无穷大，边的权值不能大于该数
using std::cin;
using std::cout;
using std::endl;
using std::queue;

int main(void)
{
	int vertexNum = 0, edgeNum = 0;
	queue < int >q;
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
	int dis[vertexNum];						//起点到各个结点的距离
	bool isInQueue[vertexNum];		//访问标志
	for (int i = 0; i < vertexNum; i++) {
		dis[i] = INFINITE;
		isInQueue[i] = false;
	}
	cout << "起点:";
	cin >> s;
	dis[s] = 0;
	q.push(s);										//起点入队
	isInQueue[s] = true;
	int v = 0;
	while (!q.empty()) {
		//队列非空则循环松弛
		v = q.front();							//v出队
		q.pop();
		isInQueue[v] = false;
		for (int i = 0; i < vertexNum; i++) {	//松弛v邻接的结点
			if (dis[i] > dis[v] + edgeMatrix[v][i]) {
				dis[i] = dis[v] + edgeMatrix[v][i];	//改写路径长度
				if (!isInQueue[i]) {		//不在队列中则入队
					q.push(i);
					isInQueue[i] = true;
				}
			}
		}
	}
	//输出结果
	for (int i = 0; i < vertexNum; i++) {
		if (dis[i] == INFINITE)
			cout << "+∞" << " ";
		else
			cout << dis[i] << " ";
	}
	cout << endl;
	return 0;
}
