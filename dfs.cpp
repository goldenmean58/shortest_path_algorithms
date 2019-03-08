/******************************************************************
 * FileName : dfs.cpp
 * Author   : Lishuxiang
 * E-mail   : lishuxiang@cug.edu.cn
 * Time     : Fri 08 Mar 2019 09:02:49 AM CST
 * Function : 
******************************************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stack>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::stack;
using std::make_heap;
using std::pop_heap;
using std::sort_heap;
#define MAX_ELE 100

int main(void)
{
    freopen("dfs_input.txt","r",stdin);
	int vertexNum = 0, edgeNum = 0;
	cout << "顶点数:";
	cin >> vertexNum;							// 输入结点数与边数
	cout << "边数:";
	cin >> edgeNum;
	int edgeMatrix[vertexNum][vertexNum];
	for (int i = 0; i < vertexNum; i++) {	//初始化邻接矩阵
		for (int j = 0; j < vertexNum; j++) {
			edgeMatrix[i][j] = 0;
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
	bool vis[vertexNum];					//访问标志
    int pre[vertexNum];
	for (int i = 0; i < vertexNum; i++) {
		vis[i] = false;
        pre[i] = 0;
	}
	cout << "起点:";
	cin >> s;
    cout << "终点:";
    cin >> e;
	int v = s;
    vector<vector<int> > paths;
    vector<int> path;
    vector<int> len;
    stack<int> sk;
    sk.push(v);
    //dfs
    int i=0;
	do {
        for(;i<vertexNum;i++){
            if(edgeMatrix[v][i]>0 && !vis[i]){
                //邻接且没有被访问
                vis[i]=true; //访问
                pre[i]=v;
                if(i==e){
                    //目标结点 记录路径
                    int j=i;
                    int length=0;
                    path.clear();
                    path.push_back(i);
                    do{
                        path.push_back(pre[j]);
                        length+=edgeMatrix[pre[j]][j];
                        if(pre[j]==0) {
                            break;
                        }
                        j=pre[j];
                    }while(true);
                    vis[i]=false; //最后一个结点在每条路径查找时应是未被访问的
                    reverse(path.begin(),path.end());
                    paths.push_back(path);
                    len.push_back(length);
                    continue;
                }
                sk.push(i); //记录i用于上一层恢复
                v=i;
                break;
            }
        }
        if(i==vertexNum){ //s a
            i=sk.top();
            vis[i]=false;
            sk.pop();
            if(sk.empty()) break;
            i++;
            v=sk.top();
        }else i=0;
	} while (true);		//能找到下一结点
    cout << "所有路径:" <<endl;
    for(auto i : paths){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    int min_index=0,max_index=0;
    int min=len[0],max=len[0];
    cout<<"最短路径:"<<endl;
    for(int i=0;i<(int)len.size();i++){
        if(len[i]<min){
            min_index=i;
            min=len[i];
        }
    }
    for(auto j : paths[min_index]){
        cout<<j<<" ";
    }
    cout<<endl;
    cout<<"长度为:"<<min<<endl;
    cout<<"最长路径:"<<endl;
    for(int i=0;i<(int)len.size();i++){
        if(len[i]>max){
            max_index=i;
            max=len[i];
        }
    }
    for(auto j : paths[max_index]){
        cout<<j<<" ";
    }
    cout<<endl;
    cout<<"长度为:"<<max<<endl;
	return 0;
}
