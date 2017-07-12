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


/* a more simple one which can beats 95%.

class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int> > g(numCourses);
		vector<int> in_degree(numCourses, 0);
		for (int i = 0; i < prerequisites.size(); i++){
			g[prerequisites[i].second].push_back(prerequisites[i].first);
			in_degree[prerequisites[i].first]++;
		}
		queue<int> q;
		int cnt = 0;
		for (int i = 0; i < numCourses; i++) if (in_degree[i] == 0) q.push(i);
		while (!q.empty()){
			int cur = q.front();
			q.pop();
			for (auto it = g[cur].begin(); it != g[cur].end(); it++)
				if (--in_degree[*it] == 0) q.push(*it);
		}
 
		for (int i = 0; i < numCourses; i++) if (in_degree[i] != 0) return false;
		return true;
	}
};
*/
 