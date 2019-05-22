#include <iostream>
#include <vector>
using namespace std; 

const int		  number = 7;	    //����� ����
	  int		  c[number];		//�湮 ó��
	  vector<int> a[8];		        //7���� ��尡 ���� ������ ��带 ���� �� �ֵ��� �Ѵ�. 

void dfs(int x) {

	if (c[x]) return;				//���� ��带 �湮(c[x] = true�� )�ߴٸ� return 
	
	c[x] = true;					//��带 ó�� �湮 
	cout << x << ' ';				//�湮 ��� ��� 
	
	for (int i = 0; i < a[x].size(); i++) {		//a[x].size(), �� x��° ��忡 ���ؼ� ����ִ� ���� ��(������ ��� ��)��ŭ ��ȸ�ϰ� �ȴ�.
		int y = a[x][i];						//������忡 ���ؼ� dfs ���� 
												//���� �迭 ���� �� ���ҿ� ���� 		
		dfs(y);
	}
}

int main(){
 
	//1�� 2�� �����Ѵ�. 
	a[1].push_back(2);
	a[2].push_back(1);
	
	//1�� 3�� �����Ѵ�. 
	a[1].push_back(3);
	a[3].push_back(1);
	
	//2�� 3�� �����Ѵ�. 
	a[2].push_back(3);
	a[3].push_back(2);
	
	//2�� 4�� �����Ѵ�. 
	a[2].push_back(4);
	a[4].push_back(2);
	
	//2�� 5�� �����Ѵ�.
	a[2].push_back(5);
	a[5].push_back(2);
	
	//3�� 6�� �����Ѵ�.
	a[3].push_back(6);
	a[6].push_back(3);
	
	//3�� 7�� �����Ѵ�.
	a[3].push_back(3);
	a[7].push_back(7);
	
	//4�� 5�� �����Ѵ�.
	a[4].push_back(5);
	a[5].push_back(4);
	
	//6�� 7�� �����Ѵ�. 
	a[6].push_back(7);
	a[7].push_back(6);

	//������ ��� ���� ���� ������ �ٸ� ���� Ž�� ����� �޶�����. 
	//Ž�� ����� 1 - 2 - 3 - 6 - 7 - 4 - 5 ���� ���Ϳ� 2��� 3�� ���� �ִ´ٸ� 
	//Ž�� ����� 1 - 3 - 2 - 4 - 5 - 6 - 7 �� �ٲ�� �ȴ�. 
	dfs(1);
}

