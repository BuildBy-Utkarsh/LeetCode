class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //firstly we do transpose of matrix

        for(int i = 0; i < matrix.size() ; i++ ){
            for(int j = i+1; j < matrix.size(); j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        //now reverse the matrix or row  

        for(int row = 0; row < matrix.size(); row++){
           int startCol =0;
           int endCol = matrix.size()-1; 

           while (startCol <= endCol) {
                int temp = matrix[row][startCol];
                matrix[row][startCol] = matrix[row][endCol];
                matrix[row][endCol] = temp;

                startCol++;
                endCol--;
            } 
        }                     
    }
};