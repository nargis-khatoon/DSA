//An Interesting Method to Generate Binary Numbers from 1 to n
//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	vector<string> ans;
	queue<string> q;
	q.push("1");
	while(ans.size()<N && !q.empty()){
	    string s=q.front();
	    string temp=s;
	    q.pop();
	    ans.push_back(s);
	    s.append("0");
	    q.push(s);
	    temp.append("1");
	    q.push(temp);
	}
	return ans;
	
}