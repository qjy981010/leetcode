/*对图还不够熟悉，用的深度优先搜索一直向前找，把找到的节点在onstack数组里标为true，
直到遇到以前走过的节点，即在onstack为true的节点则返回false，不可完成，
《算法》中图的章节提到了这一方法，但是效率和下面的方法差的远*/

/*note: 见下面更巧妙的方法*/

class Solution {
private:
	struct node{
        int val;
        node* next;
    };
    
public:
	bool canFinish(int numCourses, vector< pair<int, int> >& prerequisites) {
    	node* neighbor_list[numCourses];
        bool onstack[numCourses];
        int i;
        for (i = 0; i != numCourses; ++i) {
            onstack[i] = false;
            neighbor_list[i] = 0;
        }
        for (i = 0; i != prerequisites.size(); ++i) {
            node* newone = new node;
            newone->val = prerequisites[i].second;
            if (neighbor_list[prerequisites[i].first]) {
                newone->next = neighbor_list[prerequisites[i].first]->next;
                neighbor_list[prerequisites[i].first]->next = newone;
            }
            else {
            	newone->next = 0;
                neighbor_list[prerequisites[i].first] = newone;
            }
        }
		for (i = 0; i != numCourses; ++i)
			if (!onstack[i] && have_cycle(i, neighbor_list, onstack)) return false;
		return true;
    }
	
	bool have_cycle(int i, node** neighbor_list,bool* onstack) {
		onstack[i] = true;
		for (node* ptr = neighbor_list[i]; ptr; ptr = ptr->next) {
			if (onstack[ptr->val] || have_cycle(ptr->val, neighbor_list, onstack)) return true;
            onstack[ptr->val] = false;
		}
        onstack[i] = false;
		return false;
	}
};

// beats 21.23 % of cpp submissions.


/* https://www.hrwhisper.me/leetcode-graph/
 a more simple one which can beats 95%.
 循环，每次把图中入度为0的点相邻的边删除，并把此点存入*/

class SolutionPerfect {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int> > g(numCourses);
		vector<int> in_degree(numCourses, 0);
		for (int i = 0; i < prerequisites.size(); i++){ // 建立邻接链表，以尾为索引
			g[prerequisites[i].second].push_back(prerequisites[i].first);
			in_degree[prerequisites[i].first]++;
		}
		queue<int> q;
		int cnt = 0;
		for (int i = 0; i < numCourses; i++) if (in_degree[i] == 0) q.push(i);
		while (!q.empty()){ // 循环直到没有入度为0的点
			int cur = q.front();
			q.pop();
			for (auto it = g[cur].begin(); it != g[cur].end(); it++)
				if (--in_degree[*it] == 0) q.push(*it);
		}
 
		for (int i = 0; i < numCourses; i++) if (in_degree[i] != 0) return false; // 如果还有边，就说明有环，否则无环
		return true;
	}
};
