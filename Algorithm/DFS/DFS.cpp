#include <iostream>
#include <vector>
using namespace std; 

const int		  number = 7;	    //노드의 개수
	  int		  c[number];		//방문 처리
	  vector<int> a[8];		        //7개의 노드가 각각 인접한 노드를 가질 수 있도록 한다. 

void dfs(int x) {

	if (c[x]) return;				//현재 노드를 방문(c[x] = true면 )했다면 return 
	
	c[x] = true;					//노드를 처음 방문 
	cout << x << ' ';				//방문 노드 출력 
	
	for (int i = 0; i < a[x].size(); i++) {		//a[x].size(), 즉 x번째 노드에 대해서 들어있는 원소 수(인접한 노드 수)만큼 순회하게 된다.
		int y = a[x][i];						//인접노드에 대해서 dfs 실행 
												//벡터 배열 내에 들어간 원소에 접근 		
		dfs(y);
	}
}

int main(){
 
	//1과 2를 연결한다. 
	a[1].push_back(2);
	a[2].push_back(1);
	
	//1과 3을 연결한다. 
	a[1].push_back(3);
	a[3].push_back(1);
	
	//2과 3을 연결한다. 
	a[2].push_back(3);
	a[3].push_back(2);
	
	//2와 4를 연결한다. 
	a[2].push_back(4);
	a[4].push_back(2);
	
	//2와 5를 연결한다.
	a[2].push_back(5);
	a[5].push_back(2);
	
	//3과 6을 연결한다.
	a[3].push_back(6);
	a[6].push_back(3);
	
	//3과 7를 연결한다.
	a[3].push_back(3);
	a[7].push_back(7);
	
	//4와 5를 연결한다.
	a[4].push_back(5);
	a[5].push_back(4);
	
	//6과 7를 연결한다. 
	a[6].push_back(7);
	a[7].push_back(6);

	//벡터의 들어 가는 값의 순서가 다를 수록 탐색 결과는 달라진다. 
	//탐색 결과가 1 - 2 - 3 - 6 - 7 - 4 - 5 지만 벡터에 2대신 3을 먼저 넣는다면 
	//탐색 결과가 1 - 3 - 2 - 4 - 5 - 6 - 7 로 바뀌게 된다. 
	dfs(1);
}

