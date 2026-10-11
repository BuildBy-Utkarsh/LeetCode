class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> ans;
      int row = matrix.size();
      int col = matrix[0].size();  


      //index intialization
      int startingRow = 0;
      int startingCol = 0;
      int endingRow = row -1;
      int endingCol = col -1;

    while (startingRow <= endingRow && startingCol <= endingCol){

        //print starting row 
        for(int index =startingCol; startingRow <= endingRow && index <= endingCol; index++){
            ans.push_back(matrix[startingRow][index]);
        }
        startingRow++;

        //print ending col
        for(int index =startingRow; startingCol <= endingCol &&  index <= endingRow; index++ ){
            ans.push_back(matrix[index][endingCol]);
        }
        endingCol--;

        //print ending row
        for(int index =endingCol; startingRow <= endingRow &&  index >= startingCol; index--){
            ans.push_back(matrix[endingRow][index]);
        }
        endingRow--;

        //print starting col 
        for(int index =endingRow; startingCol <= endingCol &&  index >= startingRow; index--){
            ans.push_back(matrix[index][startingCol]);
        }
        startingCol++;
    }    
    return ans;

    
    }

   
};