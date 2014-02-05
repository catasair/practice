/* Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

vector<vector<int> > subsets(vector<int> &S) {
    vector<vector<int>> result;
    vector<int> temp;
    result.push_back(temp);//push empty subset
    
    sort(S.begin(), S.end());//sort the vector into ascending order 

    for (int i=0; i<S.size(); i++){
        int preSize = result.size();

        for (int j=0; j<preSize; j++){
            //for each previous subsets, append the new number to the right
            temp = result.at(j);
            temp.push_back(S.at(i));
            result.push_back(temp);
        }
    }

    return result;
}
